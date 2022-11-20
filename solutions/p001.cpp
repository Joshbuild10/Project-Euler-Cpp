#include <iostream>

// Returns the sum of multiples of 3 and 5 below the specified limit
int sumOf3and5(int limit)
{
    int sum = 0;
    --limit;
    int threeCount = limit/3;
    int fiveCount = limit/5;

    // Uses sum of arithmetic progressions formula to add respective sum of multiples
    sum += threeCount/2.0 * (3 * (threeCount + 1));
    sum += fiveCount/2.0 * (5 * (fiveCount + 1));

    // Subtracts duplicate common multiples
    int dupCount = limit/15;
    sum -= dupCount/2.0 * (15 * (dupCount + 1));
    return sum;
}
int main()
{
    int limit;
    std::cout << "Enter the limit of the multiples: \n";
    std::cin >> limit;
    std::cout << sumOf3and5(limit) << std::endl;
    return 0;
}