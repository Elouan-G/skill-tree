#!/bin/bash

echo "1/2 Running generator to make tree text."
./generator/generator.out > ./generator/tree-text.dot
echo "2/2 Making image from tree text."
dot -Tpng ./generator/tree-text.dot -o ./generator/skill-tree.png

open ./generator/skill-tree.png &
echo "Skill tree visual openned."
