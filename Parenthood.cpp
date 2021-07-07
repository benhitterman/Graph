//
//  Parenthood.cpp
//  COEN244ProjectGood
//
//  Created by Ben Hitterman on 2021-03-15.
//  Copyright © 2021 Ben Hitterman. All rights reserved.
//

#include "Parenthood.hpp"
#include <iostream>

Parenthood::Parenthood()
{}

Parenthood::Parenthood(Person p, Person c)
    : Relationship(p, c)
{}

Parenthood::Parenthood(const Parenthood& other)
    : Relationship(other)
{}

Person Parenthood::getParent() const
{
    return person1;
}

void Parenthood::setParent(Person p)
{
    person1 = p;
}

Person Parenthood::getChild() const
{
    return person2;
}

void Parenthood::setChild(Person c)
{
    person2 = c;
}

std::string Parenthood::toString()
{
    return person1.getName() + " --> " + person2.getName();
}

bool Parenthood::operator==(const Parenthood& rhs)
{
    if (this->getParent() != rhs.getParent() || this->getChild() != rhs.getChild())
        return false;

    return true;
}
