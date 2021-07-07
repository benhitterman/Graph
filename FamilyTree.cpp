//
//  FamilyTree.cpp
//  COEN244ProjectGood
//
//  Created by Ben Hitterman on 2021-03-15.
//  Copyright © 2021 Ben Hitterman. All rights reserved.
//

#include "FamilyTree.hpp"
#include <stdexcept>

using namespace std;

FamilyTree::FamilyTree()
{}

FamilyTree::FamilyTree(const FamilyTree& other)
    : people(other.people), relationships(other.relationships)
{}

FamilyTree::~FamilyTree()
{
    for (size_t i = 0; i < relationships.size(); i++)
    {
        delete relationships[i];
    }
}

bool FamilyTree::addPerson(Person& p)
{
    if (searchPerson(p))
    {
        throw std::invalid_argument("Person already exists in family tree");
    }
    people.push_back(p);
    return true;
}

bool FamilyTree::addPeople(Person* pArray, size_t pCount)
{
    for (size_t i = 0; i < pCount; i++)
    {
        if (searchPerson(pArray[i]))
        {
            throw std::invalid_argument("Person already exists in family tree, no one from this array will be added");
        }
    }
    for (size_t i = 0; i < pCount; i++)
    {
        addPerson(pArray[i]);
    }
    
    return true;
}

bool FamilyTree::addParenthood(Parenthood& p)
{
    if (searchParenthood(p))
    {
        throw std::invalid_argument("Parenthood relationship already exists in family tree");
    }
    Parenthood* copy = new Parenthood(p);
    relationships.push_back(copy);
    return true;
}

bool FamilyTree::removePerson(Person& p)
{
    for (size_t i = 0; i < people.size(); i++)
    {
        if (people[i] == p)
        {
            std::vector<size_t> edgesToRemove;
            Relationship* reference;
            for (size_t j = 0; j < relationships.size(); j++)
            {
                reference = relationships[j];
                Parenthood* converted = dynamic_cast<Parenthood*>(reference); //casting the relationship to type parenthood
                if (converted && (converted->getParent() == people[i] || converted->getChild() == people[i]))
                {
                    edgesToRemove.push_back(j); //adding the relationships of type parenthood to remove to a vector
                }
            }
            people.erase(people.begin() + i); //getting rid of person

            for (size_t k = 0; k < edgesToRemove.size(); k++)
            {
                // Since we "new" a copy when adding the parenthood, we have to free that memory before removing it from the vector
                auto iterator = relationships.begin() + edgesToRemove[k] - k;
                delete *(iterator);
                relationships.erase(iterator); //getting rid any relationships of type parenthood that were connected to that person
            }
            return true;
        }
    }
    throw std::invalid_argument("Person does not exist therefore it cannot be removed");
}

bool FamilyTree::removeParenthood(Parenthood& p)
{
    for (size_t i = 0; i < relationships.size(); i++)
    {
        Parenthood* converted = dynamic_cast<Parenthood*>(relationships[i]); //casting the relationship to type parenthood
        if (converted && *converted == p)
        {
            // Since we "new" a copy when adding the parenthood, we have to free that memory before removing it from the vector
            auto iterator = relationships.begin() + i;
            delete *(iterator);
            relationships.erase(iterator);
            return true;
        }
    }
    throw std::invalid_argument("Parenthood relationship does not exist therefore it cannot be removed");
}

bool FamilyTree::searchPerson(const Person& p)
{
    for (size_t i = 0; i < people.size(); i++)
    {
        if (people[i] == p)
            return true;
    }
    return false;
}

bool FamilyTree::searchParenthood(const Parenthood& p)
{
    for (size_t i = 0; i < relationships.size(); i++)
    {
        // Check if the relationship is a parenthood using dynamic_cast
        Parenthood* cast = dynamic_cast<Parenthood*>(relationships[i]);
        if (cast)
        {
            // If cast != nullptr then check if the parenthoods are equal (i.e. same parent, same child)
            if (*cast == p)
            {
                return true;
            }
        }
    }
    return false;
}

string FamilyTree::FindDescendants(const Person& p) const
{
    stringstream tree;
    FindDescendantsInner(tree, p, 0);
    return tree.str();
}

std::string FamilyTree::BuildTree() const
{
    // We find each root of the tree (i.e. a person with no parents in the tree).
    vector<const Person*> roots;
    for (size_t i = 0; i < people.size(); i++)
    {
        bool isRoot = true;
        for (size_t j = 0; j < relationships.size(); j++)
        {
            Parenthood* ph = dynamic_cast<Parenthood*>(relationships[j]);
            if (ph && ph->getChild() == people[i])
            {
                isRoot = false;
                break;
            }
        }

        if (isRoot)
        {
            roots.push_back(&people[i]);
        }
    }

    stringstream fullTree;
    for (size_t i = 0; i < roots.size(); i++)
    {
        FindDescendantsInner(fullTree, *roots[i], 0);
    }
    return fullTree.str();
}

void FamilyTree::FindDescendantsInner(stringstream& tree, const Person& p, int charDepth) const
{
    // Declare a vector to store all edges that point from this person to one of their children.
    vector<Parenthood*> edgesToChildren;

    for (size_t i = 0; i < relationships.size(); i++)
    {
        Parenthood* ph = dynamic_cast<Parenthood*>(relationships[i]);
        if (ph && ph->getParent() == p)
        {
            edgesToChildren.push_back(ph);
        }
    }

    // If we go through the entire vector and find no edges such that this person is the parent, we've reached the bottom of a branch.
    if (edgesToChildren.empty())
    {
        // Insert a line break so that when we return up the recursion chain, the next call prints on a new line.
        tree << endl;
    }
    else
    {
        // This person has at least one child. We begin by printing out the relationship to the first child on the same line, and calling this function recursively.
        string firstChildString = edgesToChildren[0]->toString() + " | ";
        tree << firstChildString;
        FindDescendantsInner(tree, edgesToChildren[0]->getChild(), charDepth + firstChildString.length());

        // If there are more children to print, we know that the previous call would have hit the end of a branch and inserted a line break.
        // Thus, we print out spaces to the character depth, print out the relationship, then call the function recursively once again.
        if (edgesToChildren.size() > 1)
        {
            for (size_t i = 1; i < edgesToChildren.size(); i++)
            {
                string childString = edgesToChildren[i]->toString() + " | ";
                tree << string(charDepth, ' ') << childString;
                FindDescendantsInner(tree, edgesToChildren[i]->getChild(), charDepth + childString.length());
            }
        }
    }
}
