#ifndef MPAGSCIPHER_CAESARCIPHER_HPP
#define MPAGSCIPHER_CAESARCIPHER_HPP

#include <string>
#include <iostream>
std::string runCaesarCipher(const std::string& inputText,
                            const size_t key,
                            const bool encrypt);
#endif