#pragma once
#include "PlainText.h"

class SubstitutionText : public PlainText
{
private:
    std::string _dictionaryFileName;
    friend std::ostream& operator<<(std::ostream& out, const SubstitutionText& text);
public:
    SubstitutionText(const std::string& text, const std::string& dictionaryFileName);
    static std::string encrypt(const std::string& text, const std::string& dictionaryFileName);
    static std::string decrypt(const std::string& text, const std::string& dictionaryFileName);
    std::string encrypt();
    std::string decrypt();
};
std::ostream& operator<<(std::ostream& out, const SubstitutionText& text);
