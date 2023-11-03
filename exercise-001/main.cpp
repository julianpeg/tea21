#include <fmt/chrono.h>
#include <fmt/format.h>

#include <iostream>
#include <random>

#include "CLI/CLI.hpp"
#include "config.h"

int foo;
int data = 4711;
const int rodata = 42;

auto main(int argc, char **argv) -> int
{
    fmt::print("Hello, {}!\n", "hellooo");



    fmt::print("value of variable foo {} adaress of variable foo {} \n", foo, fmt::ptr(&foo));

    fmt::print("value of variable foo {} adaress of variable data {} \n", data, fmt::ptr(&data));
    
    fmt::print("value of variable foo {} adaress of variable rodata {} \n", rodata, fmt::ptr(&rodata));

    return 0; 
}
