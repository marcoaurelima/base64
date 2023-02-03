#include <iostream>
#include <string.h>
#include "base64.h"

using namespace std;

int main(int argc , char** argv)
{
    if(argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " [FLAG(--encode --decode)] [STRING]" << std::endl;
        return 0;
    }

    std::string type(argv[1]);
    std::string input(argv[2]);

    if(type == "--encode")
    {
        std::cout << base64encoder(input) << "\n";
    }
    if(type == "--decode")
    {
        std::cout << base64decoder(input) << "\n";
    }

    return 0;
}
