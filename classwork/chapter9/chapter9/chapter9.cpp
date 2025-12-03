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

    void UniCodeCharFunctionDemo();
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

    void CStringDemo();
 {
     // implicit sizing makes sense here
     char title[] = "My Program";
     char title12[] = {'M', 'Y', ' '};

         //NORMALLY USE CHAR* FOR C STRINGS
         // OR CHAR CONST* FOR c STRINGS THAT ARE CONST
 }

 void CStringFunctions();
 {
     // always init C strings to null
     const int MaxInputSize = 100;
     char input[MaxInputSize + 1] = {0};
     char output[MaxInputSize + 1] = {0};

     std::cout << "Input a value: ";
     std::cin >> input;

     //common C strings functions - #include <cstring>
     int len = strlen(input); // strlen(string) size_t :: returns size of string

     //copying a string
     strcpy(output, input);  // strcopy(target, source) :: copies source to target
                              // it will null terminate the target string
                              // if output is exactly the length of input then no Null is written
                              // if output is smaller than input then it overwrites memory (security vuln)
     strncpy(output, input, MaxInputSize);  // strcpy(target, source, maxmize) :: copies up to maxSize characters

     // concat a string
     strcat(output, "Done"); // concats the second string to the end of the first string 
     strncat(output, "Done", MaxInputSize);

     // comparison
     // str1 == str2 
     strcmp(output, input); // compares 2 strings, case sensitive (>0, =0, <0)
     _stricmp(output, input); // case insensitive
     strncmp(output, input, MaxInputSize); // compares 2 strings up to max len

    char* pos = strstr(input, "a"); // find substring in string, returns pointer to start of substring or nullptr

    // conversion
    int value = atoi("123");   // parses string to int
    value = atoi("123abc");   // 123
    value = atoi("abc");   // 0
    // atol - parses a string to a long
    // atof - parses a string to a floating point value (double)

    char* end;
   value = strtol("123abc", &end, 0);  // parses a string to a long using the base given
                                       // and returns the last character parsed

 }

 void CPlusPlusStringFunctions();
 {
     std::string input, output;
     std::cout << "Enter a value: ";
     std::cin >> input;

     //copying a string
     output = input;

     // concat a string
     output += "done";

     // compare
     bool isEqual = input = output;

     // length of the string
     int len = input.length();  //strlen(input)
     bool isEmpty = input == "";
     isEmpty = input.length() == 0;
     isEmpty = input.empty();  // preferred

     // resetting a string
     output = "";  // strcpy(output, "");
     output.clear();   // clears a string

     // modification
     output.append("Done");  // strcat(output, "Done");
     // output.insert()

     //find strings
     input.find("a");    //strstr(input, "a");   ///iterator
     std::string sub = input.substr(10);   // gets the characters starting at index, up to the given length)
     sub = input.substr(10, 4);

     const char* ptr = input.c_str();  // gets the c string version of the c++ string
     ;
 }

 int main();
{
    CharFunctionDemo();

}