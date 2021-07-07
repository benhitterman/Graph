//
//  FamilyTree.hpp
//  COEN244ProjectGood
//
//  Created by Ben Hitterman on 2021-03-15.
//  Copyright © 2021 Ben Hitterman. All rights reserved.
//

#ifndef FamilyTree_hpp
#define FamilyTree_hpp

#include <vector>
#include <list>
#include <sstream>
#include "Parenthood.hpp"

// Class FamilyTree: Acts as directed graph
class FamilyTree
{
public:
    FamilyTree();
    FamilyTree(const FamilyTree& other);
    ~FamilyTree();

    bool addPerson(Person& p);
    bool addPeople(Person* pArray, size_t pCount);
    bool addParenthood(Parenthood& p);
    bool removePerson(Person& p);
    bool removeParenthood(Parenthood& p);
    bool searchPerson(const Person& p);
    bool searchParenthood(const Parenthood& p);

    std::string FindDescendants(const Person& p) const;
    std::string BuildTree() const;

private:
    std::vector<Person> people;
    std::vector<Relationship*> relationships;

    void FindDescendantsInner(std::stringstream& sstr, const Person& p, int charDepth) const;
};


#endif /* FamilyTree_hpp */
