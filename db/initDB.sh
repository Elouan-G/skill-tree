#!/bin/bash

echo "Setting up DB..."
echo "	1/2 Compiling DB init script."
g++ initDB.cpp -lsqlite3 -o builds/initDB
echo "	2/2 Initialising DB."
./builds/initDB
echo "Done."