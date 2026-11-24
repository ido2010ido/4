#include "FileHelper.h"
#include <fstream>
#include <stdexcept>

std::string FileHelper::readFileToString(const std::string& fileName)
{
    std::ifstream file(fileName);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open input file");
    }
    std::string text;
    char ch;
    while (file.get(ch))
    {
        text += ch;
    }
    file.close();
    return text;
}

void FileHelper::writeWordsToFile(const std::string& inputFileName, const std::string& outputFileName)
{
    std::ifstream input(inputFileName);
    if (!input.is_open())
    {
        throw std::runtime_error("Cannot open input file");
    }
    std::ofstream output(outputFileName);
    if (!output.is_open())
    {
        input.close();
        throw std::runtime_error("Cannot open output file");
    }
    std::string word;
    bool first = true;
    // Write a line break between words, not after the last word.
    while (input >> word)
    {
        if (!first)
        {
            output << '\n';
        }
        output << word;
        first = false;
    }
    input.close();
    output.close();
}

void FileHelper::saveTextInFile(const std::string& text, const std::string& outputFileName)
{
    std::ofstream file(outputFileName);
    if (!file.is_open())
    {
        throw std::runtime_error("Cannot open output file");
    }
    file << text;
    file.close();
}
