#pragma once
#include "ShiftText.h"

class CaesarText : public ShiftText
{
public:
    CaesarText(const std::string& text);
    static std::string encrypt(const std::string& text);
    static std::string decrypt(const std::string& text);
    std::string encrypt();
    std::string decrypt();
};
std::ostream& operator<<(std::ostream& out, const CaesarText& text);
