#include <iostream>
#include "base64.h"

using namespace std;

int main()
{
    string input = "Olá, mundo!";

    auto cod = base64encoder(input);
    cout << "[cod] " << cod << "\n";
    auto dec = base64decoder(cod);
    cout << "[dec] " << dec << "\n";

    return 0;
}
