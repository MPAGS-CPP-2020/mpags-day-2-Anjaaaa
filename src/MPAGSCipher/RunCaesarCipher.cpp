#include "RunCaesarCipher.hpp"

std::string runCaesarCipher(const std::string& inputText,
                            const size_t key,
                            // Why is size_t a long here? Isn't an integer enough for 26 letters?
                            const bool encrypt){
    // Create the alphabet container and output string
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    std::string outputString{""};
    signed int shift{0};

    if (encrypt)
    {
        // encryption
        shift = key;
    }else{
        // decryption
        shift = -key;
    }
    
    // Loop over the input text
    for (size_t i = 0; i < inputText.size(); i++)
    {
        // For each character find the corresponding position in the alphabet
        int pos = alphabet.find(inputText[i]);
        // Apply the shift (+veor –vedepending on encrypt/decrypt)
        // to the position, handling correctly potential wrap-around
        // Determine the new character and add it to the output string
        // QUESTION: I used (pos-shift)%alphabet.size() before but it
        // wouldn't use the entire alphabet even tough alphabet.size() was correctly
        // found to be 26. For example A with key=3 would map to P instead of X.
        // Why does that happen?
        outputString += alphabet[((pos-shift)%26+26)%26];
    }
    // Finally (after the loop), return the output string
    return outputString;
}