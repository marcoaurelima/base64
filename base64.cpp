// ***************************************** //
//       AUTOR: Marco Aurélio Lima           //
//      GITHUB: github.com/marcoaurelima     //
// ***************************************** //
#include "base64.h"

using  UCHAR = unsigned char;
std::string b64   = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

std::string base64encoder(std::string input)
{
    std::stringstream output;

    for(size_t i=0;i<input.size()/3;++i)
    {
        UCHAR byte_0 = (input[(3*i)+0] & 0xFC) >> 2;  // 0xFC = 11111100
        UCHAR byte_1 = (input[(3*i)+0] & 0x03) << 4;  // 0x03 = 00000011
        UCHAR byte_2 = (input[(3*i)+1] & 0xF0) >> 4;  // 0xF0 = 11110000
        UCHAR byte_3 = (input[(3*i)+1] & 0x0F) << 2;  // 0x0F = 00001111
        UCHAR byte_4 = (input[(3*i)+2] & 0xC0) >> 6;  // 0xC0 = 11000000
        UCHAR byte_5 = (input[(3*i)+2] & 0x3F) >> 0;  // 0x3F = 00111111

        output << b64[byte_0] << b64[byte_1 + byte_2] << b64[byte_3 + byte_4] << b64[byte_5];
    }

    if(input.size()%3 == 1)
    {
        UCHAR byte_0 = (input[input.size()-1] & 0xFC) >> 2; // 0xFC = 11111100
        UCHAR byte_1 = (input[input.size()-1] & 0x03) << 4; // 0x03 = 00000011
        UCHAR byte_2 = '=';
        UCHAR byte_3 = '=';
        output << b64[byte_0] << b64[byte_1] << byte_2 << byte_3;
    } else
    if(input.size()%3 == 2)
    {
        UCHAR byte_0 = (input[input.size()-2] & 0xFC) >> 2;  // 0xFC = 11111100
        UCHAR byte_1 = (input[input.size()-2] & 0x03) << 4;  // 0x03 = 00000011
        UCHAR byte_2 = (input[input.size()-1] & 0xF0) >> 4;  // 0xF0 = 11110000
        UCHAR byte_3 = (input[input.size()-1] & 0x0F) << 2;  // 0x0F = 00001111
        UCHAR byte_4 = '=';
        output << b64[byte_0] << b64[byte_1 + byte_2] << b64[byte_3] << byte_4;
    }

    return output.str();
}

std::string base64decoder(std::string input)
{
    std::stringstream output;

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

        output << (char)(byte_0 + byte_1) << (char)(byte_2 + byte_3) << (char)(byte_4 + byte_5);
    }

    std::string out = output.str();
    for(size_t i=input.size()-1; i>=input.size()-2; i--)
    {
        if(input[i] == '='){ out.pop_back(); }
    }

    return out;
}
