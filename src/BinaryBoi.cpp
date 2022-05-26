/*
  * Filename: BinaryBoi.cpp
  * Authors(s): Roland (r.weirhowell@gmail.com)
  * Description: Interactively convert between decimal, hex and binary
  *
  * This Source Code Form is subject to the terms of the Mozilla Public
  * License, v. 2.0. If a copy of the MPL was not distributed with this
  * file, You can obtain one at https://mozilla.org/MPL/2.0/.
*/

#include <iostream>
#include <string>
#include <vector>
#include <cassert>


// 1:1 mapping between binary and hex numbers
const std::string binNums[16] =
{ "0000","0001","0010","0011","0100","0101","0110","0111","1000","1001","1010","1011","1100","1101","1110","1111" };
const std::string hexNums[16] =
{ "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };


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

    return -1;
}


int GetStrIndex(std::string target, std::string array[], int arraySize)
{
    for (int i = 0; i < arraySize; i++)
    {
        if (array[i] == target)
        {
            return i;
        }
    }

    return -1;
}


std::string DecToBin(uint64_t dec)
{
    std::string bin;

    while (dec)
    {
        bin.append(std::to_string(dec % 2));
        dec /= 2;
    }

    std::reverse(bin.begin(), bin.end());
    return bin;
}


std::string DecToHex(uint64_t dec)
{
    const int nums[6] = { 10, 11, 12, 13, 14, 15 };
    const char chars[6] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    std::string hex;

    while (dec)
    {
        if ((dec % 16) < 9)
        {
            hex.append(std::to_string(dec % 16));
        }
        else
        {
            int index = GetIndex(dec % 16, (int*)nums, 6);
            if (index == -1) exit(1);
            hex.append(std::string(1, chars[index]));
        }
        dec /= 16;
    }
    
    std::reverse(hex.begin(), hex.end());
    return hex;
}


std::string BinToHex(std::string bin)
{
    int count = 0;
    std::string hex;

    // Make sure binary number is a multiple of 4
    if (bin.size() % 4)
    {
        const int zerosToAdd = 4 - (bin.size() % 4);
        for (int i = 0; i < zerosToAdd; i++)
        {
            bin.insert(0, "0");
        }
    }

    // TODO: Write this loop in a less stupid way
    while (count < bin.size() / 4)
    {
        std::string target;
        // Split binary "number" into chunks of 4
        for (int i = count  *    4; i < count  *    4 + 4; i++)
        {
            target.push_back(bin[i]);
        }

        /* Search for the current grouping of 4 in the binNums array
         *    and add the corresponding hex digit to the hex vector  */
        int index = GetStrIndex(target, (std::string*)binNums, 16);
        assert(index != -1); // GetStrIndex should NEVER return -1
        hex.append(hexNums[index]);
        count++;
    }

    return hex;
}


std::string HexToBin(std::string hex)
{
    std::string bin;

    for (int i = 0; i < hex.size(); i++)
    {
        int index = GetStrIndex(std::string(1, hex[i]), (std::string*)hexNums, 16);
        assert(index != -1); // GetStrIndex should NEVER return -1
        bin.append(binNums[index]);
    }

    return bin;
}


int main(int argc, char** argv)
{
    short choice;
    std::cout << "1: Decimal to Binary" << '\n';
    std::cout << "2: Decimal to Hexadecimal" << '\n';
    std::cout << "3: Binary to Hexadecimal" << '\n';
    std::cout << "4: Hexadecimal to Binary" << '\n';
    std::cout << "Please choose function: ";
    std::cin >> choice;
    while (!InRange(1, 4, choice))
    {
        std::cout << "Please enter a valid number between 1 and 4: ";
        std::cin >> choice;
    }

    // Decimal to Binary
    if (choice == 1)
    {
        uint64_t dec;
        std::cout << "Enter an integer: ";
        std::cin >> dec;
        std::string bin = DecToBin(dec);
        std::cout << "In binary that's: " << bin << '\n';

        return 0;
    }

    // Decimal to Hex
    else if (choice == 2)
    {
        uint64_t dec;
        std::cout << "Enter an integer: ";
        std::cin >> dec;
        std::string hex = DecToHex(dec);
        std::cout << "In hex that's: " << hex << '\n';

        return 0;
    }

    // Binary to Hex
    else if (choice == 3)
    {
        std::string bin;
        std::cout << "Enter a binary number: ";
        std::cin >> bin;
        std::string hex = BinToHex(bin);
        std::cout << "In hex that's: " << hex << '\n';

        return 0;
    }

    else if (choice == 4)
    {
        std::string hex;
        std::cout << "Enter a hexadecimal number: ";
        std::cin >> hex;
        std::string bin = HexToBin(hex);
        std::cout << "In binary that's: " << bin << '\n';

        return 0;
    }

    else return 1;
}
