# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers

# Building `mpags-cipher`
Compilation of `mpags-cipher` requires a  C++11 compatible compiler
(GCC 4.8 or better, Clang 3.4 or better are recommended) and `make`
on a UNIX operating system.
In order to build the program, run `cmake ../src` in the `build` folder and compile using `make` also in the `build` folder.

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed (or from a file).
To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

The results of this transliteration are encrypted or decrypted (depending on whether
`--encrypt` or `--decrypt` is called (default is encrypt) and output to the output file.
The caesar-cipher key can be set via `--key`.


# Source Code Layout
Under this directory, the code and associated files are organised as
follows:
```
$ tree
.
├── README.md                   Top-level README, describes layout of the repository
├── build                       Folder for build files, ideally empty in git
└── src
    ├── CMakeLists.txt          cmake config file
    ├── MPAGSCipher             folder containing additional files with outsourced functions
    │   ├── ProcessCmdLine.cpp
    │   ├── ProcessCmdLine.hpp
    │   ├── RunCaesarCipher.cpp
    │   ├── RunCaesarCipher.hpp
    │   ├── TransformChar.cpp
    │   └── TransformChar.hpp
    ├── LICENSE                 License file, in our case MIT
    ├── README.md               This file, describes the project
    ├── mpags-cipher.cpp        Main program C++ source file
    └── README.md
```

# Copying
`mpags-cipher` is licensed under the terms of the MIT License. Please see
the file [`LICENSE`](LICENSE) for full details.
