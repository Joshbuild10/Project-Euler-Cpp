#include <iostream>
#include <cstdint>
#include <cmath>
#include <cstring>

uint64_t sumOfPrimes(uint64_t lim) // Returns the sum of all prime numbers less than a given limit
{
    uint64_t sum = 0;

    // Allocates memory for Sieve of Eratothenes operation
    bool* arr = new bool[lim + 1];
    memset(arr, 1, sizeof(*arr) * (lim + 1));

    // Uses Sieve of Eratothenes implementation to iterate through prime numbers and then adds the number to the sum
    for (uint64_t i = 2; i < lim; i++)
    {
        if (arr[i])
        {
            // Sieves out multiples of current prime
            for (uint64_t j = i * i; j < lim; j += i)
            {
                arr[j] = false;
            }
            sum += i;
        }
    }
    return sum;
}

int main()
{
    uint64_t limit;
    std::cout << "Enter the limit of your summation of primes: \n";
    std::cin >> limit;
    std::cout << "The sum of all primes less than the given limit is: " << sumOfPrimes(limit) << "\n";
}