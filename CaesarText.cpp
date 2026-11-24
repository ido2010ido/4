#include "CaesarText.h"

CaesarText::CaesarText(const std::string& text) : ShiftText(text, 3)
{
}

// Caesar uses the same shift with a fixed key of 3.
std::string CaesarText::encrypt(const std::string& text)
{
    return ShiftText::encrypt(text, 3);
}

std::string CaesarText::decrypt(const std::string& text)
{
    return ShiftText::decrypt(text, 3);
}

std::string CaesarText::encrypt()
{
    return ShiftText::encrypt();
}

std::string CaesarText::decrypt()
{
    return ShiftText::decrypt();
}

std::ostream& operator<<(std::ostream& out, const CaesarText& text)
{
    return out << "Ceasar\n" << (text.isEncrypted() ? text.getText() : CaesarText::encrypt(text.getText()));
}
