//
//  Person.hpp
//  COEN244ProjectGood
//
//  Created by Ben Hitterman on 2021-03-15.
//  Copyright © 2021 Ben Hitterman. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <iostream>
#include <string>

// Class Person: Acts as vertex of graph
class Person
{
public:
    Person();
    Person(int i, std::string n, int y);
    Person(const Person& other);

    int getId() const;
    void setId(int);
    std::string getName() const;
    void setName(std::string);
    int getYearOfBirth() const;
    void setYearOfBirth(int);

    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);

private:
    int id;
    std::string name;
    int yearOfBirth;
};

#endif /* Person_hpp */
