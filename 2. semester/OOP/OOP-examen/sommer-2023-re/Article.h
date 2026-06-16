#pragma once
#include "NewsItem.h"

class Article
{
public:
	Article(int id, std::string head_line);
	void add_item(NewsItem* item);
	std::string get_html() const override;

private:
};

