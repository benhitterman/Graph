//
//  Parenthood.hpp
//  COEN244ProjectGood
//
//  Created by Ben Hitterman on 2021-03-15.
//  Copyright © 2021 Ben Hitterman. All rights reserved.
//

#ifndef Parenthood_hpp
#define Parenthood_hpp
#include "Relationship.hpp"
#include "Person.hpp"
#include <iostream>
using namespace std;

// Derived class of Relationship representing one person as the parent of another person
class Parenthood : public Relationship
{
public:
    Parenthood();
    Parenthood(Person p, Person c);
    Parenthood(const Parenthood& other);

    Person getParent() const;
    void setParent(Person p);
    Person getChild() const;
    void setChild(Person c);

    std::string toString() override;

    bool operator==(const Parenthood& rhs);
};


#endif /* Parenthood_hpp */
