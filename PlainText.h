#pragma once
#include <string>
#include <iostream>

class PlainText
{
protected:
    std::string _text;
    bool _isEncrypted;
public:
    static int numOfTexts;
    PlainText(const std::string& text);
    PlainText(const PlainText& other);
    bool isEncrypted() const;
    std::string getText() const;
};
std::ostream& operator<<(std::ostream& out, const PlainText& text);
