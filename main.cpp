#include <format>
#include <iostream>

void printCppVersion(long version)
{
    std::cout << std::format("__cplusplus = {}", version) << std::endl;
}

int main()
{
    printCppVersion(__cplusplus);
}