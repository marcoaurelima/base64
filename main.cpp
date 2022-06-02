#include <iostream>
#include <vector>
#include <bitset>

using UCHAR = unsigned char;

using namespace std;

string b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

string base64encoder(vector<long int> input)
{

    UCHAR byte_0 = (input[0] & 0xFC) >> 2;  // 0xFC = 11111100
    UCHAR byte_1 = (input[0] & 0x03) << 4;  // 0x03 = 00000011
    UCHAR byte_2 = (input[1] & 0xF0) >> 4;  // 0xF0 = 11110000
    UCHAR byte_3 = (input[1] & 0x0F) << 2;  // 0x0F = 00001111
    UCHAR byte_4 = (input[2] & 0xC0) >> 6;  // 0xC0 = 11000000
    UCHAR byte_5 = (input[2] & 0x3F) >> 0;  // 0x3F = 00111111

    cout << b64[byte_0] << b64[byte_1 + byte_2] << b64[byte_3 + byte_4] << b64[byte_5] << "\n";


    /*
    int count = 0;
    for(auto i=0;i<input.size();i++)
    {
        if(++count == 3)
        {
            unsigned char byte_1 =
        }
    }
*/

    return "";

}


int main()
{
    auto nome = vector<long int>{'m','a','r','c','o','A','U','R','E','L','I','O'};
    base64encoder(nome);

    return 0;
}
