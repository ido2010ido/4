#include "SubstitutionText.h"
#include <fstream>
#include <stdexcept>

SubstitutionText::SubstitutionText(const std::string& text, const std::string& dictionaryFileName) : PlainText(text)
{
    _dictionaryFileName = dictionaryFileName;
    encrypt();
}

std::string SubstitutionText::encrypt(const std::string& text, const std::string& dictionaryFileName)
{
    std::ifstream file(dictionaryFileName);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open dictionary");
    }
    char letters[26];
    for (int i = 0; i < 26; i++)
    {
        letters[i] = 'a' + i;
    }
    std::string line;
    // Read the letter pairs from the CSV file.
    while (std::getline(file, line))
    {
        if (line.length() >= 3 && line[0] >= 'a' && line[0] <= 'z' && line[2] >= 'a' && line[2] <= 'z')
        {
            letters[line[0] - 'a'] = line[2];
        }
    }
    file.close();
    std::string result = text;
    for (unsigned int i = 0; i < result.length(); i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
        {
            result[i] = letters[result[i] - 'a'];
        }
    }
    return result;
}

std::string SubstitutionText::decrypt(const std::string& text, const std::string& dictionaryFileName)
{
    std::ifstream file(dictionaryFileName);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open dictionary");
    }
    char letters[26];
    for (int i = 0; i < 26; i++)
    {
        letters[i] = 'a' + i;
    }
    std::string line;
    // Read the letter pairs from the CSV file.
    while (std::getline(file, line))
    {
        if (line.length() >= 3 && line[0] >= 'a' && line[0] <= 'z' && line[2] >= 'a' && line[2] <= 'z')
        {
            letters[line[2] - 'a'] = line[0];
        }
    }
    file.close();
    std::string result = text;
    for (unsigned int i = 0; i < result.length(); i++)
    {
        if (result[i] >= 'a' && result[i] <= 'z')
        {
            result[i] = letters[result[i] - 'a'];
        }
    }
    return result;
}

std::string SubstitutionText::encrypt()
{
    if (!_isEncrypted)
    {
        _text = encrypt(_text, _dictionaryFileName);
        _isEncrypted = true;
    }
    return _text;
}

std::string SubstitutionText::decrypt()
{
    if (_isEncrypted)
    {
        _text = decrypt(_text, _dictionaryFileName);
        _isEncrypted = false;
    }
    return _text;
}

std::ostream& operator<<(std::ostream& out, const SubstitutionText& text)
{
    return out << "Substitution\n" << (text.isEncrypted() ? text.getText() : SubstitutionText::encrypt(text.getText(), text._dictionaryFileName));
}
