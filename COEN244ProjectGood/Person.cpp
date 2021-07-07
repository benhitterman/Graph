//
//  Person.cpp
//  COEN244ProjectGood
//
//  Created by Ben Hitterman on 2021-03-15.
//  Copyright © 2021 Ben Hitterman. All rights reserved.
//

#include "Person.hpp"

Person::Person()
    : id(0), name("Missing Name"), yearOfBirth(0)
{}

Person::Person(int i, std::string n, int y)
    : id(i), name(n), yearOfBirth(y)
{}

Person::Person(const Person & other)
    : id(other.id), name(other.name), yearOfBirth(other.yearOfBirth)
{}

int Person::getId() const
{
    return id;
}

void Person::setId(int i)
{
    id = i;
}

std::string Person::getName() const
{
    return name;
}

void Person::setName(std::string n)
{
    name = n;
}

int Person::getYearOfBirth() const
{
    return yearOfBirth;
}

void Person::setYearOfBirth(int y)
{
    yearOfBirth = y;
}

bool Person::operator==(const Person& rhs)
{
    return (id == rhs.id && name == rhs.name && yearOfBirth == rhs.yearOfBirth);
}

bool Person::operator!=(const Person& rhs)
{
    return !(*this == rhs);
}
