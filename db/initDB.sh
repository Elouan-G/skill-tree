#!/bin/bash

echo "Setting up DB..."

echo "	1/4 Compiling DB creation program."
g++ createDB.cpp -lsqlite3 -o builds/createDB
echo "	2/4 Creating DB."
./builds/createDB
echo "	3/4 Compiling DB data insertion program."
g++ insertData.cpp -lsqlite3 -o builds/insertData
echo "	4/4 Adding data to DB."
./builds/insertData

echo "Done."
