#include <iostream>

// Returns the sum of even numbers of a fibonacci sequence up to the limit
int evenFibSum(int limit)
{
    int sum = 0, tmpSum = 0;
    int buffer[2] = {1, 2};
    do
    {
        sum += !(buffer[1] % 2) ? buffer[1]: 0; // If current number is even, add to sum

        // Shift buffer values and calculate next number in sequence
        tmpSum = buffer[0] + buffer[1];
        buffer[0] = buffer[1];
        buffer[1] = tmpSum;
    } while (tmpSum < limit);
    return sum;
}
int main()
{
    int limit;
    std::cout << "Enter the limit of the Fibonacci sequence: \n";
    std::cin >> limit;
    std::cout << evenFibSum(limit) << std::endl;
    return 0;
}