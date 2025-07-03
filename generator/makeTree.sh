#!/bin/bash

echo "Building tree..."

echo "	1/3 Compiling tree text generator."
g++ tree.cpp -o builds/tree
echo "	2/3 Generating tree text."
./builds/tree > tree.dot
echo "	3/3 Making image from tree text."
dot -Tpng tree.dot -o tree.png

echo "Done."

eog tree.png &
echo "Visual openned."
