#include <format>
#include <iostream>

#define WORK_PLACE 2
int main()
{
    std::cout << std::format("workplace version {}", WORK_PLACE) << std::endl;
}