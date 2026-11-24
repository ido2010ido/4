#include "ShiftText.h"

ShiftText::ShiftText(const std::string& text, int key) : PlainText(text)
{
    _key = key;
    encrypt();
}

std::string ShiftText::encrypt(const std::string& text, int key)
{
    std::string result = text;
    key = (key % 26 + 26) % 26;
    // Move lowercase letters and wrap around the alphabet.
    for (unsigned int i = 0; i < result.length(); i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
        {
            result[i] = 'a' + (result[i] - 'a' + key) % 26;
        }
    }
    return result;
}

std::string ShiftText::decrypt(const std::string& text, int key)
{
    return encrypt(text, -(key % 26));
}

std::string ShiftText::encrypt()
{
    if (!_isEncrypted)
    {
        _text = encrypt(_text, _key);
        _isEncrypted = true;
    }
    return _text;
}

std::string ShiftText::decrypt()
{
    if (_isEncrypted)
    {
        _text = decrypt(_text, _key);
        _isEncrypted = false;
    }
    return _text;
}

std::ostream& operator<<(std::ostream& out, const ShiftText& text)
{
    return out << "Shift\n" << (text.isEncrypted() ? text.getText() : ShiftText::encrypt(text.getText(), text._key));
}
