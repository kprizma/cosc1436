#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
void CharDemo()
{
    // character sets
    // ANSI - 1 byte, char in C++, strinb for string
    // unicode - 2 bytes, wchar_t C++, wstring for string
    char ansiCharacter = 'A';
    wchar_t unicodeCharacter = 'A';

    std::string ansiString = "Bob";
    std::wstring unicodeString = L"Bob";

    // variants
   // char8_t char8Byte;
    char16_t char16Byte;
    char32_t char32Byte;
}
void CharFunctionDemo()
{
    std::string input;

    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    std::cout << "Character "
        << std::setw(15) << "Letter? "
        << std::setw(10) << "Digit? "
        << std::setw(10) << "Letter/Digit? "
        << std::setw(10) << "Lowercase? "
        << std::setw(10) << "To Lower "
        << std::setw(10) << "Uppercase? "
        << std::setw(10) << "To Upper "
        << std::setw(10) << "Space? " << std::endl;
    std::cout << "----------------------------------------" << std::endl;


    // enumerate the characters of the string
    for (int index = 0; index < input.length(); ++index)
    {
        char ch = input[index];
        // ALL CHAR FUNCTION Are from c and therefore accept and return an int, not a char
        // typecast back to char
        std::cout << ch
            << std::setw(15) << isalpha(ch)
            << std::setw(10) << isdigit(ch)
            << std::setw(10) << isalnum(ch)
            << std::setw(10) << islower(ch)
            << std::setw(10) << (char)tolower(ch)
            << std::setw(10) << isupper(ch)
            << std::setw(10) << (char)toupper(ch)
            << std::setw(10) << isspace(ch)
            << std::endl;
    };

 void UniCodeCharFunctionDemo()
 {
        std::wstring input;

        std::cout << "Enter a string: ";
        std::getline(std::wcin, input);
        std::cout << "Character "
            << std::setw(15) << "Letter? "
            << std::setw(10) << "Digit? "
            << std::setw(10) << "Letter/Digit? "
            << std::setw(10) << "Lowercase? "
            << std::setw(10) << "To Lower "
            << std::setw(10) << "Uppercase? "
            << std::setw(10) << "To Upper "
            << std::setw(10) << "Space? " << std::endl;
        std::cout << "----------------------------------------" << std::endl;


        // enumerate the characters of the string
        for (int index = 0; index < input.length(); ++index)
        {
            wchar_t ch = input[index];
            // ALL CHAR FUNCTION Are from c and therefore accept and return an int, not a char
            // typecast back to char
            std::cout << ch
                << std::setw(15) << iswalpha(ch)
                << std::setw(10) << iswdigit(ch)
                << std::setw(10) << iswalnum(ch)
                << std::setw(10) << iswlower(ch)
                << std::setw(10) << (char)towlower(ch)
                << std::setw(10) << iswupper(ch)
                << std::setw(10) << (char)towupper(ch)
                << std::setw(10) << iswspace(ch)
                << std::endl;
        };
    
 }

 void CStringDemo()
 {
     // implicit sizing makes sense here
     char title[] = "My Program";
     char title12[] = {'M', 'Y', ' '};

         //NORMALLY USE CHAR* FOR C STRINGS
         // OR CHAR CONST* FOR c STRINGS THAT ARE CONST
 }
int main()
{
    CharFunctionDemo();

}