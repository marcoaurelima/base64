#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>

using UCHAR = unsigned char;

using namespace std;



string base64encoder(vector<long int> input)
{
    stringstream result;
    string b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    if(input.size()%3 == 0)
    {
        for(size_t i=0;i<input.size()/3;++i)
        {
            UCHAR byte_0 = (input[(3*i)+0] & 0xFC) >> 2;  // 0xFC = 11111100
            UCHAR byte_1 = (input[(3*i)+0] & 0x03) << 4;  // 0x03 = 00000011
            UCHAR byte_2 = (input[(3*i)+1] & 0xF0) >> 4;  // 0xF0 = 11110000
            UCHAR byte_3 = (input[(3*i)+1] & 0x0F) << 2;  // 0x0F = 00001111
            UCHAR byte_4 = (input[(3*i)+2] & 0xC0) >> 6;  // 0xC0 = 11000000
            UCHAR byte_5 = (input[(3*i)+2] & 0x3F) >> 0;  // 0x3F = 00111111

            result << b64[byte_0] << b64[byte_1+byte_2] << b64[byte_3+byte_4] << b64[byte_5];
        }
    }

    if(input.size()%3 == 1)
    {
        UCHAR byte_0 = (input[input.size()-1] & 0xFC) >> 2; // 0xFC = 11111100
        UCHAR byte_1 = (input[input.size()-1] & 0x03) << 4; // 0x03 = 00000011
        UCHAR byte_2 = '=';
        UCHAR byte_3 = '=';
        result << b64[byte_0] << b64[byte_1] << byte_2 << byte_3;
    } else
    if(input.size()%3 == 2)
    {
        UCHAR byte_0 = (input[input.size()-2] & 0xFC) >> 2;  // 0xFC = 11111100
        UCHAR byte_1 = (input[input.size()-2] & 0x03) << 4;  // 0x03 = 00000011
        UCHAR byte_2 = (input[input.size()-1] & 0xF0) >> 4;  // 0xF0 = 11110000
        UCHAR byte_3 = (input[input.size()-1] & 0x0F) << 2;  // 0x0F = 00001111
        UCHAR byte_4 = '=';
        result << b64[byte_0] << b64[byte_1+byte_2] << b64[byte_3] << byte_4;
    }

    return result.str();
}


int main()
{
    string input = "marcos";
    vector<long int> nome;
    for(auto i : input) { nome.push_back(i); }

    auto res = base64encoder(nome);

    cout << res << "\n";

    return 0;
}
