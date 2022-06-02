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
    // 0xFC = 11111100
    // 0x03 = 00000011
    // 0xF0 = 11110000
    // 0x0F = 00001111
    // 0xC0 = 11000000
    // 0x3F = 00111111


    UCHAR byte_0 = (input[0] & 0xFC) >> 2;
    UCHAR byte_1 = (input[0] & 0x03) << 4;
    UCHAR byte_2 = (input[1] & 0xF0) >> 4;
    UCHAR byte_3 = (input[1] & 0x0F) << 2;
    UCHAR byte_4 = (input[2] & 0xC0) >> 6;
    UCHAR byte_5 = (input[2] & 0x3F) >> 0;

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

    base64encoder(vector<long int>{'D','f','y',4,5,6});

    return 0;
}
