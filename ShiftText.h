#pragma once
#include "PlainText.h"

class ShiftText : public PlainText
{
private:
    int _key;
    friend std::ostream& operator<<(std::ostream& out, const ShiftText& text);
public:
    ShiftText(const std::string& text, int key);
    static std::string encrypt(const std::string& text, int key);
    static std::string decrypt(const std::string& text, int key);
    std::string encrypt();
    std::string decrypt();
};
std::ostream& operator<<(std::ostream& out, const ShiftText& text);
