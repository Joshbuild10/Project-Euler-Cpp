#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>

std::vector<std::string> splitString(std::string input, char delim)
{
    std::stringstream ss(input);
    std::string tempStr;
    std::vector<std::string> out;
    while (!ss.eof()) 
    {
        std::getline(ss, tempStr, delim);
        out.push_back(tempStr);
    }
    return out;
}
#endif