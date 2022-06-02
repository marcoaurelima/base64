#include <iostream>
#include <sstream>
#include <vector>
#include <bitset>

using UCHAR = unsigned char;

using namespace std;

string b64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

string base64encoder(vector<long int> input)
{
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

        cout << "* " << (char) input[(3*i)+2] << "\n";
    }

    puts("");

    if(input.size()%3 == 0)  {
        return result.str();
    }


    if(input.size()%3 == 1)
    {
        UCHAR byte_0 = (input[input.size()-1] & 0xFC) >> 2;
        UCHAR byte_1 = (input[input.size()-1] & 0x03) << 4;
        UCHAR byte_2 = '=';
        UCHAR byte_3 = '=';

        result << b64[byte_0] << b64[byte_1] << byte_2 << byte_3;//<< b64[byte_1 + byte_2] << b64[byte_3] << byte_4 << byte_5;

        cout << "sobrou 1:\n";
        return result.str();
    }

    if(input.size()%3 == 2)
    {

        UCHAR byte_0 = (input[input.size()-1] & 0xFC) >> 2;  // 0xFC = 11111100
        UCHAR byte_1 = (input[input.size()-1] & 0x03) << 4;  // 0x03 = 00000011
        UCHAR byte_2 = (input[input.size()-1] & 0xF0) >> 4;  // 0xF0 = 11110000
        UCHAR byte_3 = (input[input.size()-1] & 0x0F) << 2;  // 0x0F = 00001111
        //UCHAR byte_4 = (input[input.size()-1] & 0xC0) >> 6;  // 0xC0 = 11000000
        //UCHAR byte_5 = (input[input.size()-1] & 0x3F) >> 0;  // 0x3F = 00111111
        UCHAR byte_4 = '=';

        /*
        UCHAR byte_0 = (input[input.size()-1] & 0xFC) >> 2;  // 0xFC = 11111100
        UCHAR byte_1 = (input[input.size()-1] & 0x03) << 4;  // 0x03 = 00000011
        UCHAR byte_2 = (input[input.size()-2] & 0x0F) >> 2;  // 0xF0 = 11110000
        UCHAR byte_3 = (input[input.size()-3] & 0xC0) >> 6;  // 0xC0 = 11000000
        UCHAR byte_4 = '=';*/


        result << b64[byte_0] << b64[byte_1 + byte_2] << b64[byte_3] << byte_4;// b64[byte_5];

        cout << "sobrou 2:\n";
        return result.str();
    }


    return "";

}


int main()
{
    string input = "marco aurelio lima de sousas";
    vector<long int> nome;
    for(auto i : input) { nome.push_back(i); }

    auto res = base64encoder(nome);

    cout << "bWFyY28=\n" << res << "\n";

    return 0;
}
