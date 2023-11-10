#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

auto main(int argc, char **argv) -> int
{
    int count = 66;
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */

    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    /* INSERT YOUR CODE HERE */
    app.add_option("-c,--count", count );

    std::vector<int> einVector(count);
    for (int i = 0; i < count; ++i) 
    {
        einVector[i] = rand() % 100 + 1;
        fmt::print("{}\n", einVector[i]);
    }

    //sortiert
    auto start = std::chrono::system_clock::now();
    std::sort(einVector.begin(), einVector.end());
    auto end = std::chrono::system_clock::now();
    //auto elapsed = end - start;
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    printf("nun nach size sortiert: \n");
    for (int j = 0; j < sizeof(einVector); j++ )
    {
        fmt::print("{}\n", einVector[j]);
    }
    fmt::print("Benoetigte Zeit: {}\n", elapsed);
    /*
    //Alternative BEVORZUGT!!!
    for (int value : einVector) 
    {
        fmt::print("{}\n", value);
    }
    */


    //fmt::print("count = {}", count); //count ausgeben

    return 0; /* exit gracefully*/
}
