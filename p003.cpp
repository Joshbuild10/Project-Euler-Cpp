#include <iostream>
#include <cstring>
#include <cmath>

uint64_t greatestPrimeFactor(uint64_t number)
{
    uint64_t greatestPrime = 0;
    // Allocates memory for Sieve of Eratothenes operation
    uint64_t lim = sqrt(number);
    bool* arr = new bool[lim + 1];
    memset(arr, 1, sizeof(*arr) * (lim + 1));
    // Uses Sieve of Eratothenes implementation to iterate through prime numbers and then checks if the number is divisible by the prime
    for (uint64_t i = 2; i <= lim; i++)
    {
        if (arr[i])
        {
            // Sieves out multiples of current prime
            for (int j = i * i; j <= lim; j += i)
            {
                arr[j] = false;
            }
            // Checks if number is divisible by current prime number then sets the greatest prime number and divides number as much as possible
            while (!(number % i))
            {
                greatestPrime = i;
                number /= i;    
            }
        }
    }
    delete[] arr;
    return greatestPrime;
}

int main()
{
    uint64_t number;
    std::cout << "Enter the number to find the greatest prime factor of: \n";
    std::cin >> number;
    std::cout << greatestPrimeFactor(number) << std::endl;
    return 0;
}