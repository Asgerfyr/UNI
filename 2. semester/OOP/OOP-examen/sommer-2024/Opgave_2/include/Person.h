#pragma once
#include <string>

class Person
{
public:
	Person(const std::string& name, const unsigned int age): name(name), age(age)
	{
	}

	std::string name;
	unsigned int age;
};
