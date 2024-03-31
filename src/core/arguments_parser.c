#include <stdio.h>

#include "arguments_parser.h"

void parse_cli_arguments(const int argc, const char** argv)
{
    if (1 == argc)
        return;

    for (int i = 1; i < argc; ++i)
    {
        puts(argv[i]);
    }
}
