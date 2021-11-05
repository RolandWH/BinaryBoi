#include <iostream>
#include <vector>


bool InRange(unsigned low, unsigned high, unsigned x)
{
    return (low <= x && x <= high);
}


std::vector<int> DecToBin(int dec)
{
    std::vector<int> bin;

    while (dec)
    {
        bin.push_back(dec % 2);
        dec /= 2;
    }

    return bin;
}


int main(int argc, char** argv)
{
    short choice;
    std::cout << "1: Decimal to Binary" << '\n';
    std::cout << "2: Binary to Decimal" << '\n';
    std::cout << "Please choose function ";
    std::cin >> choice;
    while (!InRange(1, 2, choice))
    {
        std::cout << "Please enter a valid number between 1 and 2: ";
        std::cin >> choice;
    }

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
    else if (choice == 2)
    {
        std::cout << "Not here yet!";
    }
}
