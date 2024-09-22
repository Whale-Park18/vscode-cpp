#include <format>
#include <iostream>

#define WORK_PLACE 1
int main()
{
    std::cout << std::format("workplace version {}", WORK_PLACE) << std::endl;
}