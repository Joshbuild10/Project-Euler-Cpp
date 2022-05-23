#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <iterator>

// Generates a list of prime numbers from 2 to stop
std::vector<int> genPrimes(int stop)
{
    int sqrtstop = ceil(sqrt(stop));
    std::vector<int> primes = {};
    bool *sieveArr = new bool[stop + 1];
    memset(sieveArr, 1, sizeof(*sieveArr) * (stop + 1));
    // Uses Sieve of Eratothenes implementation to generate prime numbers from 2 to stop
    for (int i = 2; i <= stop; i++)
    {
        if (sieveArr[i]) // If prime number (if true in sieve array)
        {
            primes.emplace_back(i); // Adds prime number to list
            // Sieves out multiples of current prime (if less than sqrt of end)
            if (i < sqrtstop)
            {
                for (int j = i * i; j <= stop; j += i)
                {
                    sieveArr[j] = false;
                }
            }
        }
    }
    return primes;
}

// Returns the LCM (lowest common multiple) of the numbers in range start to stop (inclusive)
uint64_t LCM(int start, int stop)
{
    uint64_t commonFactor = 1, num, curPrime;
    std::vector<int> primes = genPrimes(stop);
    for (int i = start; i <= stop; i++)
    {
        curPrime = 2;
        num = i;
        while (commonFactor % i)
        {
            for (int j = 1; num % curPrime; j++)
            {
                curPrime = primes[j];
            }
            commonFactor *= curPrime;
        }
    }
    return commonFactor;
}
int main()
{
    int start, stop;
    std::cout << "Enter your start number \n";
    std::cin >> start;
    std::cout << "Enter your stop number \n";
    std::cin >> stop;
    std::cout << LCM(start, stop);
    return 0;
}