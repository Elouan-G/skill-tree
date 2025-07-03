#!/bin/bash

echo "1/2 Running app to make tree text."
./app/skill-tree.out > ./app/tree-text.dot
echo "2/2 Making image from tree text."
dot -Tpng ./app/tree-text.dot -o ./app/skill-tree.png

open ./app/skill-tree.png &
echo "Skill tree visual openned."
