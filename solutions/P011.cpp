#include <iostream> 
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include "util.h"

// Returns the the greatest product formed from adjacent digits
uint64_t largestProduct(std::vector<std::vector<uint64_t>>& grid, int n)
{
    int maxRows = grid.size();
    int maxColumns = grid[0].size();
    uint64_t maxProduct = 1, curProduct = 1;
    for (int row = 0; row < maxRows; ++row)
    {
        for (int column = 0; column < maxColumns; ++column)
        {
            if (row <= (maxRows - n)) // Vertical
            {
                curProduct = 1;
                for (int i = 0; i < n; i++) { curProduct *= grid[row + i][column]; }
                maxProduct = curProduct > maxProduct ? curProduct : maxProduct;
            }
            if (column <= (maxColumns - n)) // Horizontal
            {
                curProduct = 1;
                for (int i = 0; i < n; i++) { curProduct *= grid[row][column + i]; }
                maxProduct = curProduct > maxProduct ? curProduct : maxProduct;
            }
            if ((row <= (maxRows - n)) && (column <= (maxColumns - n))) // Diagonal
            {
                curProduct = 1;
                for (int i = 0; i < n; i++) { curProduct *= grid[row + i][column + i]; }
                maxProduct = curProduct > maxProduct ? curProduct : maxProduct;
            }
            if ((row <= (maxRows - n)) && (column >= (n - 1))) // Diagonal
            {
                curProduct = 1;
                for (int i = 0; i < n; i++) { curProduct *= grid[row + i][column - i]; }
                maxProduct = curProduct > maxProduct ? curProduct : maxProduct;
            }
        }
    }
    return maxProduct;
}

void read(std::vector<std::vector<uint64_t>>& out) //Input parsing
{
    std::string strBuf = "";
    std::vector<uint64_t> row;
    int i = 0;
    std::getline(std::cin, strBuf);
    for (int i = 0; !strBuf.empty(); std::getline(std::cin, strBuf))
    {
        row.clear();
        std::vector<std::string> tempVec = splitString(strBuf, ' ');
        for (std::string number : tempVec)
        {
            row.emplace_back(stoull(number));
        }
        out.emplace_back(row);
        i++;
    }
}
int main()
{
    std::vector<std::vector<uint64_t>> sequence;
    int n;
    std::cout << "Enter your string of numbers: \n";
    read(sequence);
    std::cout << "Enter the length of group of digits to be checked: \n";
    std::cin >> n;
    /* for (std::vector<uint64_t> row : sequence)
    {
        std::string tempStr = "";
        for (uint64_t num : row)
        {
            tempStr += std::to_string(num) + " ";
        }
        std::cout << tempStr << "\n";
    } */
    std::cout << largestProduct(sequence, n);
}