#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>

using UCHAR = unsigned char;
using namespace std;

string base64encoder(string input)
{
    string b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    stringstream result;

    for(size_t i=0;i<input.size()/3;++i)
    {
        UCHAR byte_0 = (input[(3*i)+0] & 0xFC) >> 2;  // 0xFC = 11111100
        UCHAR byte_1 = (input[(3*i)+0] & 0x03) << 4;  // 0x03 = 00000011
        UCHAR byte_2 = (input[(3*i)+1] & 0xF0) >> 4;  // 0xF0 = 11110000
        UCHAR byte_3 = (input[(3*i)+1] & 0x0F) << 2;  // 0x0F = 00001111
        UCHAR byte_4 = (input[(3*i)+2] & 0xC0) >> 6;  // 0xC0 = 11000000
        UCHAR byte_5 = (input[(3*i)+2] & 0x3F) >> 0;  // 0x3F = 00111111

        result << b64[byte_0] << b64[byte_1 + byte_2] << b64[byte_3 + byte_4] << b64[byte_5];
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
        result << b64[byte_0] << b64[byte_1 + byte_2] << b64[byte_3] << byte_4;
    }

    return result.str();
}

string base64decoder(string input)
{
    string b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    stringstream result;

    for(size_t i=0;i<input.size()/4;++i)
    {
        size_t index_0 = b64.find(input[(4*i)+0]);
        size_t index_1 = b64.find(input[(4*i)+1]);
        size_t index_2 = b64.find(input[(4*i)+2]);
        size_t index_3 = b64.find(input[(4*i)+3]);

        UCHAR byte_0 = (index_0 & 0x3F) << 2;  // 0x3F = 00111111
        UCHAR byte_1 = (index_1 & 0x30) >> 4;  // 0x30 = 00110000
        UCHAR byte_2 = (index_1 & 0x0F) << 4;  // 0x0F = 00001111
        UCHAR byte_3 = (index_2 & 0x3C) >> 2;  // 0x3C = 00111100
        UCHAR byte_4 = (index_2 & 0x03) << 6;  // 0x03 = 00000011
        UCHAR byte_5 = (index_3 & 0x3F) >> 0;  // 0x3F = 00111111

        result << (char)(byte_0 + byte_1) << (char)(byte_2 + byte_3) << (char)(byte_4 + byte_5);
    }

    /*
    if(input.size()%4 == 1)
    {
        UCHAR byte_0 = (input[input.size()-1] & 0xFC) >> 2; // 0xFC = 11111100
        UCHAR byte_1 = (input[input.size()-1] & 0x03) << 4; // 0x03 = 00000011
        UCHAR byte_2 = '=';
        UCHAR byte_3 = '=';
        result << b64[byte_0] << b64[byte_1] << byte_2 << byte_3;
    } else
    if(input.size()%4 == 2)
    {
        UCHAR byte_0 = (input[input.size()-2] & 0xFC) >> 2;  // 0xFC = 11111100
        UCHAR byte_1 = (input[input.size()-2] & 0x03) << 4;  // 0x03 = 00000011
        UCHAR byte_2 = (input[input.size()-1] & 0xF0) >> 4;  // 0xF0 = 11110000
        UCHAR byte_3 = (input[input.size()-1] & 0x0F) << 2;  // 0x0F = 00001111
        UCHAR byte_4 = '=';
        result << b64[byte_0] << b64[byte_1 + byte_2] << b64[byte_3] << byte_4;
    }
*/
    return result.str();
}




int main()
{
    /*
    UCHAR a = 97;
    UCHAR b = 98;
    UCHAR c = 99;

    cout << "inicio: " << bitset<8>(a) << "\n";

    UCHAR byte_0 = (a & 0xFC) >> 2;  // 0xFC = 11111100
    cout << "byte_0: " << bitset<8>(byte_0) << "\n";
    UCHAR byte_1 = (a & 0x03) << 4;  // 0x03 = 00000011
    cout << "byte_1: " << bitset<8>(byte_1) << "\n";
    UCHAR byte_2 = (b & 0xF0) >> 4;  // 0xF0 = 11110000
    cout << "byte_2: " << bitset<8>(byte_2) << "\n";
    UCHAR byte_3 = (b & 0x0F) << 2;  // 0x0F = 00001111
    cout << "byte_3: " << bitset<8>(byte_3) << "\n";
    UCHAR byte_4 = (c & 0xC0) >> 6;  // 0xC0 = 11000000
    cout << "byte_4: " << bitset<8>(byte_4) << "\n";
    UCHAR byte_5 = (c & 0x3F) >> 0;  // 0x3F = 00111111
    cout << "byte_5: " << bitset<8>(byte_5) << "\n";

    return 0;
*/
    string input = "marco aurelio";

    auto cod = base64encoder(input);
    cout << "[cod] " << cod << "\n";

    auto dec = base64decoder(cod);
    cout << "[dec] " << dec << "\n";
    return 0;
}









