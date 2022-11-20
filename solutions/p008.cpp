#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

// Returns the the greatest product formed from n adjacent digits
uint64_t largestProduct(std::string sequence, int n)
{
    std::vector<std::string> numbers;
    std::string tempStr;
    uint64_t highestProduct = 1, curProduct = 1;
    int16_t index;
    // Adds all substrings containing no 0s to the vector
    for (int i = 0; (i + n - 1) < sequence.length(); i++)
    {
        tempStr = sequence.substr(i, n);
        if (tempStr.find('0') == std::string::npos)
        {
            numbers.push_back(tempStr);
        }
    }
    // Iterates through each substring and calculates the product
    for(std::vector<std::string>::size_type i = 0; i != numbers.size(); i++) 
    {
        curProduct = 1;
        for (char& digit : numbers[i])
        {
            curProduct *= (int8_t)digit - int8_t('0');
        }
        if (curProduct > highestProduct)
        {
            highestProduct = curProduct;
            index = i;
        }
    }
    return highestProduct;
}

void read(std::string& out) //Input parsing
{
    std::string strBuf = "";
    do
    {
        std::getline(std::cin, strBuf);
        out += strBuf;
    } while (!strBuf.empty());
    out.erase(std::remove(out.begin(), out.end(), ' '), out.end());
}
int main()
{
    std::string sequence = "";
    int n;
    std::cout << "Enter your string of number: \n";
    read(sequence);
    std::cout << "Enter the length of group of digits to be checked: \n";
    std::cin >> n;
    std::cout << largestProduct(sequence, n);
}