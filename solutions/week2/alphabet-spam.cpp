#include <bits/stdc++.h>

int main()
{
    std::string input;
    std::cin >> input;

    int numWhitespace, numLowercase, numUppercase, numSymbols;
    numWhitespace = numLowercase = numUppercase = numSymbols = 0;

    for (char c : input)
    {
        if (c == '_')
        {
            numWhitespace++;
        }
        else if (c >= 'a' && c <= 'z')
        {
            numLowercase++;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            numUppercase++;
        }
        else
        {
            numSymbols++;
        }
    }
    std::cout << std::setprecision(10);
    std::cout << static_cast<double>(numWhitespace) / input.length() << std::endl;
    std::cout << static_cast<double>(numLowercase) / input.length() << std::endl;
    std::cout << static_cast<double>(numUppercase) / input.length() << std::endl;
    std::cout << static_cast<double>(numSymbols) / input.length() << std::endl;

    return 0;
}