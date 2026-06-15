#include "Document.h"
#include "StringProcessor.h"

Document::Document(const std::string& text) : text_(text)
{
}

void Document::process()
{
	for (const auto& processor : processors_)
	{
		processor->process(text_);
	}
}


void Document::add(StringProcessor* textProcessor)
{
	processors_.push_back(textProcessor);
}

std::ostream& operator<<(std::ostream& os, const Document& document)
{
	os << document.text_;
	return os;
}
