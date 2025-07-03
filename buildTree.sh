#!/bin/bash

echo "Building tree..."
echo "	1/3 Compiling tree text generator."
g++ generator/tree.cpp -o generator/builds/tree
echo "	2/3 Generating tree text."
./generator/builds/tree > generator/tree.dot
echo "	3/3 Making image from tree text."
dot -Tpng generator/tree.dot -o generator/tree.png
echo "Done."

eog generator/tree.png &
