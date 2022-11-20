#include <iostream>
#include <cmath>

// Calculates the difference between the sum of the squares, and square of the sum of the first n natural numbers
int squareDiff(int n)
{
    int sumOfSquares = (n * (n + 1) * ((2 * n) + 1))/6;
    int squareOfSums = pow(0.5 * n * (n + 1), 2);
    return squareOfSums - sumOfSquares;
}
int main()
{
    int n;
    std::cout << "Provide an n value (the first n natural numbers will have the difference between sum of squares and squares of sums calculated): \n";
    std::cin >> n;
    std::cout << squareDiff(n);
}