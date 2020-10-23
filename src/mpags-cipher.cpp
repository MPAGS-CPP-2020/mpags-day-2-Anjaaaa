// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// Project headers
#include "TransformChar.hpp"
#include "ProcessCmdLine.hpp"

// Declare transformation function
std::string transformChar(const char in);

// Declare command line processing function
bool processCommandLine(const std::vector<std::string>& args,
                        bool& helpRequested,
                        bool& versionRequested,
                        std::string& inputFileName,
                        std::string& outputFileName);

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};

  // Read command line arguments
  bool cmdline {processCommandLine(cmdLineArgs,
                        helpRequested,
                        versionRequested,
                        inputFile,
                        outputFile)};

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  if (cmdline){
    std::cout << "your inputs are ok" << std::endl;
    // Initialise variables for processing input text
    char inputChar {'x'};
    std::string inputText {""};
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar){
      inputText += transformChar(inputChar);
    }
    std::cout << inputText << std::endl;
  }else{
    std::cout << "your inputs are not ok" << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
