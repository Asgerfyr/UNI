#pragma once
#include <string>
#include <vector>
#include <iostream>


class StringProcessor;

class Document
{
	friend std::ostream& operator<<(std::ostream&, const Document&);

public:
	Document(const std::string& text);
	void add(StringProcessor*);
	void process();

private:
	std::vector<StringProcessor*> processors_;
	std::string text_;
};
