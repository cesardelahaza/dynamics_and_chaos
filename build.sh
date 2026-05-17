#!/bin/bash
clang++ "$1" -std=c++17 \
-I/usr/local/Cellar/sfml/3.0.2/include \
-L/usr/local/Cellar/sfml/3.0.2/lib \
-lsfml-graphics -lsfml-window -lsfml-system \
-o "$2"

# -I: where are the SFML headers
# -L: where are the libraries
# -l: what parts of SFML we use