#include <iostream>
#include <cmath>

// Takes a 3 digit number and turns it to a 6 digit palindromic number
inline int makePalindrome(int num)
{
    int last3dig = ((num % 10) * 99) + (num % 100) + (num / 100);
    return (num * 1000) + last3dig;
}
// Generates the largest product of 3 digit numbers that is palindromic
int largestPalindrome()
{
    int curNum = 0, greatestPalindrome = 0;
    // Generates 6 digit palindromic numbers from greatest to smallest and returns the first one with two 3 digit factors
    for(int i = 999; i >= 100; i--)
    {
        curNum = makePalindrome(i);
        bool isEven = curNum % 2 ? 0 : 1; // Checks if number is even in order to optimise search time
        for (int j = 999 - isEven; j >= sqrt(curNum); j -= 2) // Iterates through potential divisors
        {
            if(!(curNum % j))
            {
                return curNum;
            }
        }
    }
    return 0;
}
int main()
{
    std::cout << largestPalindrome();
    return 0;
}