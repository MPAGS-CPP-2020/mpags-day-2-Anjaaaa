#include "TransformChar.hpp"

// function transforming the input
std::string transformChar( const char in_char ){
  std::string returnString;
  // Uppercase alphabetic characters
  if (std::isalpha(in_char)) {
    returnString = std::toupper(in_char);
  }

  // Transliterate digits to English words
  switch (in_char) {
    case '0':
    returnString += "ZERO";
    break;
        case '1':
    returnString += "ONE";
    break;
        case '2':
    returnString += "TWO";
    break;
        case '3':
    returnString += "THREE";
    break;
        case '4':
    returnString += "FOUR";
    break;
        case '5':
    returnString += "FIVE";
    break;
        case '6':
    returnString += "SIX";
    break;
        case '7':
    returnString += "SEVEN";
    break;
        case '8':
    returnString += "EIGHT";
    break;
        case '9':
    returnString += "NINE";
    break;
  }
  // If the character isn't alphabetic or numeric, DONT add it.
  // Our ciphers can only operate on alphabetic characters.
  return returnString;
}