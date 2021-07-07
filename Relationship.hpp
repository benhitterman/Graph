//
//  Relationship.hpp
//  COEN244ProjectGood
//
//  Created by Ben Hitterman on 2021-03-15.
//  Copyright © 2021 Ben Hitterman. All rights reserved.
//

#ifndef Relationship_hpp
#define Relationship_hpp
#include "Person.hpp"
#include <iostream>


// Abstract base class for a relationship between two people; acts as edge of the graph
class Relationship
{
public:
    Relationship()
        : person1(), person2()
    {}

    Relationship(Person p1, Person p2)
        : person1(p1), person2(p2)
    {}

    Relationship(const Relationship& other)
        : person1(other.person1), person2(other.person2)
    {}

    virtual ~Relationship() {}

    virtual std::string toString() = 0;

protected:
    Person person1;
    Person person2;
};

#endif /* Relationship_hpp */
