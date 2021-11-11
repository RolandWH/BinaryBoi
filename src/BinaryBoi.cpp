#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


// Taken from geeksforgeeks.org
bool InRange(unsigned low, unsigned high, unsigned x)
{
    return (low <= x && x <= high);
}


int GetIndex(int target, int array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }
}


std::vector<int> DecToBin(int dec)
{
    std::vector<int> bin;

    while (dec)
    {
        bin.push_back(dec % 2);
        dec /= 2;
    }

    std::reverse(bin.begin(), bin.end());
    return bin;
}


std::vector<std::string> DecToHex(int dec)
{
    int nums[6] = { 10, 11, 12, 13, 14, 15 };
    char chars[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    std::vector<std::string> hex;

    while (dec)
    {
        if ((dec % 16) < 9)
        {
            hex.push_back(std::to_string(dec % 16));
        }
        else
        {
            int index = GetIndex(dec % 16, nums, 6);
            hex.push_back(std::string(1, chars[index]));
        }
        dec /= 16;
    }
    
    std::reverse(hex.begin(), hex.end());
    return hex;
}


int main(int argc, char** argv)
{
    short choice;
    std::cout << "1: Decimal to Binary" << '\n';
    std::cout << "2: Decimal to Hexadecimal" << '\n';
    std::cout << "Please choose function ";
    std::cin >> choice;
    while (!InRange(1, 2, choice))
    {
        std::cout << "Please enter a valid number between 1 and 2: ";
        std::cin >> choice;
    }

    // Decimal to Binary
    if (choice == 1)
    {
        int dec;
        std::cout << "Enter an integer: ";
        std::cin >> dec;
        std::vector bin = DecToBin(dec);

        std::cout << "In binary that's: ";
        for (int i = 0; i < bin.size(); i++)
        {
            std::cout << bin[i];
        }
    }
    // Decimal to Hex
    else if (choice == 2)
    {
        int dec;
        std::cout << "Enter an integer: ";
        std::cin >> dec;
        std::vector hex = DecToHex(dec);

        std::cout << "In hex that's: ";
        for (int i = 0; i < hex.size(); i++)
        {
            std::cout << hex[i];
        }
    }
}
