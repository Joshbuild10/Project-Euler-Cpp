#include <iostream>

bool isPrime(int n)
{
    if (n == 2 || n == 3)
        return true;

    if (n <= 1 || n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i += 6)
    {
        if (!(n % i) || !(n % (i + 2)))
            return false;
    }
    return true;
}

// Returns the nth prime number
int getPrime(int n)
{
    int count = 0, curNum = 3, off = 4;
    count += (n > 2) + (n > 3);
    while (count < n)
    {
        curNum += (off == 2) ? 4 : 2;
        count += isPrime(curNum);
    }
    return curNum;
}

int main()
{
    int n;
    std::cout << "Enter which prime you want calculated: \n";
    std::cin >> n;
    std::cout << getPrime(n);
    return 0;
}