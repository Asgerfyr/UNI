#pragma once
#include "NewsItem.h"

class Image
{
public:
	Image(int id, std::string image_link, std::string caption);
	std::string get_html() const override;

private:
};

