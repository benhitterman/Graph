//
//  main.cpp
//  COEN244ProjectGood
//
//  Created by Ben Hitterman on 2021-03-15.
//  Copyright © 2021 Ben Hitterman. All rights reserved.
//

#include <iostream>
#include <stdexcept>
#include "FamilyTree.hpp"

using namespace std;

void checkAddPerson();
void checkAddPeople();
void checkAddParenthood();
void checkRemovePerson();
void checkRemoveParenthood();
void checkSearchPerson();
void checkSearchParenthood();
void checkFindDescendants();
void checkBuildTree();


int main()
{
    
    checkAddPerson();
    checkAddPeople();
    checkAddParenthood();
    checkRemovePerson();
    checkRemoveParenthood();
    checkSearchPerson();
    checkSearchParenthood();
    checkFindDescendants();
    checkBuildTree();


    return 0;
}


void checkAddPerson()
{
    Person p1(1, "John Doe", 1990);
    Person p2(2, "Jane Doe", 2015);
    Person p21(2, "Jane Doe", 2015);
    
    FamilyTree tree;
    cout << "Adding person 1: " <<boolalpha <<tree.addPerson(p1) <<endl;
    cout << "Adding person 2: " <<boolalpha <<tree.addPerson(p2) <<endl;
    
    try
    {
        tree.addPerson(p21);
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }
    
}
void checkAddPeople()
{
    Person p3(3, "John Smith", 2018);
    Person p4(4, "Jake Brady", 2006);
    Person p5(5, "Michael Scott", 2003);
    
    const size_t ARRAYSIZE = 2;
    Person pArray[ARRAYSIZE] = { p3, p4 };
    Person pArray2[ARRAYSIZE] = { p3, p5 };
    
    FamilyTree tree;
    cout <<"Adding people p3:" <<boolalpha <<tree.addPeople(pArray, ARRAYSIZE) <<endl;
    
    try
    {
        tree.addPeople(pArray2, ARRAYSIZE);
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }
}
void checkAddParenthood()
{
    Person p1(1, "John Doe", 1990);
    Person p2(2, "Jane Doe", 2015);
    Person p6(6, "Zach Efron", 2005);
    Person p7(7, "Barry Efron", 1975);

    FamilyTree tree;
    
    Parenthood e1(p1, p2);
    cout <<"Adding parenthood 1:" <<boolalpha <<tree.addParenthood(e1) <<endl;

    Parenthood e2(p1, p2);
    
    try
    {
        tree.addParenthood(e2);
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }
}
void checkRemovePerson()
{
    Person p1(1, "John Doe", 1990);
    Person p2(2, "Jane Doe", 2015);
    Person p3(3, "John Smith", 2018);
    
    FamilyTree tree;
    tree.addPerson(p1);
    tree.addPerson(p2);
    
    cout <<"Removing person 2:" <<boolalpha <<tree.removePerson(p2) <<endl;
    
    try
    {
        tree.removePerson(p3);
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }
}
void checkRemoveParenthood()
{
    Person p1(1, "John Doe", 1990);
    Person p2(2, "Jane Doe", 2015);
    Person p6(6, "Zach Efron", 2005);
    Person p7(7, "Barry Efron", 1975);
    
    FamilyTree tree;
    Parenthood e1(p1, p2);
    cout <<"Removing parenthood 1:" <<boolalpha <<tree.addParenthood(e1) <<endl;

    Parenthood e2(p6, p7);
    
    try
    {
        tree.removeParenthood(e2);
    }
    catch (const invalid_argument& e)
    {
        cout << e.what() << endl;
    }
    
}
void checkSearchPerson()
{
    Person p1(1, "John Doe", 1990);
    Person p2(2, "Jane Doe", 2015);
    FamilyTree tree;
    tree.addPerson(p1);
    
    cout << "Searching for person 1: " << boolalpha << tree.searchPerson(p1) << endl;
    cout << "Searching for person 2: " << boolalpha << tree.searchPerson(p2) << endl;
}
void checkSearchParenthood()
{
    Person p1(1, "John Doe", 1990);
    Person p2(2, "Jane Doe", 2015);
    Person p6(6, "Zach Efron", 2005);
    Person p7(7, "Barry Efron", 1975);
    
    FamilyTree tree;
    Parenthood e1(p1, p2);
    tree.addParenthood(e1);

    Parenthood e2(p6, p7);
    
    cout << "Searching for parenthood 1: " << boolalpha << tree.searchParenthood(e1) << endl;
    cout << "Searching for parenthood 2: " << boolalpha << tree.searchParenthood(e2) << endl;
}
void checkFindDescendants()
{
    Person f1(1, "John Doe", 1990);
    Person f2(2, "Jane Doe", 2015);
    Person f3(3, "Bob Jones", 2040);
    Person f4(4, "Billy Phillips", 2045);
    Person f5(5, "Amanda Murphy", 2070);
    Person f6(6, "Andrew Stewart", 2072);
    Person f7(7, "Francis Wright", 2090);

    Person f8(8, "Christina Davis", 2001);
    Person f9(9, "Ernest Rogers", 2025);
    Person f10(10, "Jason Perez", 2030);

    Parenthood r1(f1, f2);
    Parenthood r2(f2, f3);
    Parenthood r3(f2, f4);
    Parenthood r4(f4, f5);
    Parenthood r5(f4, f6);
    Parenthood r6(f5, f7);
    Parenthood r7(f8, f9);
    Parenthood r8(f8, f10);

    FamilyTree tree2;
    tree2.addPerson(f1);
    tree2.addPerson(f2);
    tree2.addPerson(f3);
    tree2.addPerson(f4);
    tree2.addPerson(f5);
    tree2.addPerson(f6);
    tree2.addPerson(f7);
    tree2.addPerson(f8);
    tree2.addPerson(f9);
    tree2.addPerson(f10);
    tree2.addParenthood(r1);
    tree2.addParenthood(r2);
    tree2.addParenthood(r3);
    tree2.addParenthood(r4);
    tree2.addParenthood(r5);
    tree2.addParenthood(r6);
    tree2.addParenthood(r7);
    tree2.addParenthood(r8);

    cout <<endl << "Printing the descendants of one person in the tree:\n";
    cout << tree2.FindDescendants(f4);
}
void checkBuildTree()
{
    Person f1(1, "John Doe", 1990);
    Person f2(2, "Jane Doe", 2015);
    Person f3(3, "Bob Jones", 2040);
    Person f4(4, "Billy Phillips", 2045);
    Person f5(5, "Amanda Murphy", 2070);
    Person f6(6, "Andrew Stewart", 2072);
    Person f7(7, "Francis Wright", 2090);

    Person f8(8, "Christina Davis", 2001);
    Person f9(9, "Ernest Rogers", 2025);
    Person f10(10, "Jason Perez", 2030);

    Parenthood r1(f1, f2);
    Parenthood r2(f2, f3);
    Parenthood r3(f2, f4);
    Parenthood r4(f4, f5);
    Parenthood r5(f4, f6);
    Parenthood r6(f5, f7);
    Parenthood r7(f8, f9);
    Parenthood r8(f8, f10);

    FamilyTree tree2;
    tree2.addPerson(f1);
    tree2.addPerson(f2);
    tree2.addPerson(f3);
    tree2.addPerson(f4);
    tree2.addPerson(f5);
    tree2.addPerson(f6);
    tree2.addPerson(f7);
    tree2.addPerson(f8);
    tree2.addPerson(f9);
    tree2.addPerson(f10);
    tree2.addParenthood(r1);
    tree2.addParenthood(r2);
    tree2.addParenthood(r3);
    tree2.addParenthood(r4);
    tree2.addParenthood(r5);
    tree2.addParenthood(r6);
    tree2.addParenthood(r7);
    tree2.addParenthood(r8);

    cout <<endl << "Printing the entire tree:\n";
    cout << tree2.BuildTree() << endl;

}
