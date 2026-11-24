#include "PlainText.h"

int PlainText::numOfTexts = 0;

PlainText::PlainText(const std::string& text)
{
    _text = text;
    _isEncrypted = false;
    numOfTexts++;
}

// A copy is also a new text.
PlainText::PlainText(const PlainText& other)
{
    _text = other._text;
    _isEncrypted = other._isEncrypted;
    numOfTexts++;
}

bool PlainText::isEncrypted() const
{
    return _isEncrypted;
}

std::string PlainText::getText() const
{
    return _text;
}

std::ostream& operator<<(std::ostream& out, const PlainText& text)
{
    return out << "PlainText\n" << text.getText();
}
