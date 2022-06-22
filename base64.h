// ***************************************** //
//       AUTOR: Marco Aurélio Lima           //
//      GITHUB: github.com/marcoaurelima     //
// ***************************************** //
#ifndef BASE64_H
#define BASE64_H
#include <sstream>
#include <iostream>

std::string base64encoder(const std::string& input);
std::string base64decoder(const std::string& input);

bool isBase64String(const std::string& input);

#endif
