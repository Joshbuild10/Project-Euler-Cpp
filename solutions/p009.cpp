#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cstdint>

struct pair // Stores the factor pairs making the variables s and t
{
    uint64_t s;
    uint64_t t;
};

struct triple // Stores pythagorean triples
{
    uint64_t a;
    uint64_t b;
    uint64_t c;
};

// Finds the pythagorean triple that adds up to the the given sum using Dickson's method, https://en.wikipedia.org//wiki/Formulas_for_generating_Pythagorean_triples#Dickson's_method
triple tripleFromSum(uint64_t sum) 
{
    uint64_t min = std::nearbyint(sqrt(sum) * 0.5f) * 2 - 2;
    uint64_t max = sum / 3;

    short tmpSum = 0;
    for (int r = min; r <= max; r += 2) // Iterates over (even) values of r
    {
        std::vector<pair> factorPairs = {};

        uint64_t tmpProd = round(pow(r, 2) * 0.5); // Calculates r^2/2
        uint64_t root = sqrt(tmpProd);

        for (uint64_t i = 1; i <= root; i++) // Generates the factor pairs of r^2/2
        {
            if ((tmpProd % i) == 0) 
            {
                factorPairs.push_back({i, tmpProd / i});
            }
        }
        
        for (pair pair: factorPairs)
        {
            tmpSum = (3 * r) + 2 * (pair.s + pair.t);
            // std::cout << r << " " << pair.s << " " << pair.t << " sum:" << tmpSum << "\n";
            if (tmpSum == sum) // If sums are equal, calculate a, b and c, and print out values;
            {
                uint64_t a = r + pair.s;
                uint64_t b = r + pair.t;
                uint64_t c = r + pair.t + pair.s;
                return {a, b, c};
            }
        }

    }
    throw "No pythagorean triples that sum to the input number were found";
}

int main()
{
    uint64_t sum;
    std::cout << "Enter the sum of the pythagorean triplet: \n";
    std::cin >> sum;

    try
    {
        triple triple = tripleFromSum(sum);
        uint64_t product = triple.a * triple.b * triple.c;
        std::cout << "The triple is: a = " << triple.a << " b = " << triple.b << " c = " << triple.c
        << " and their product is: " << product;
    }
    catch (const char* exception)
    {
        std::cerr << "Error: " << exception << std::endl;
    }
    return 0;
}