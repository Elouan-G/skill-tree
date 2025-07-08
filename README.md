# skill-tree
Simple C++ skill tree builder using SQLite and Graphviz

## Requirements

### Mandatory

1. C++ build tools : `sudo apt install build-essential`
2. Generate graph image from textfile : `sudo apt install graphviz`
3. SQLite to store skill-tree : `sudo apt install libsqlite3-dev`

### Optional

1. To visualise SQLite DB in terminal : `sudo apt install sqlite3`
    1. Open DB : `sqlite3 skill-tree.db`
    2. View tables : `.tables`
    3. View table schema : `.schema table_name`
    4. Query data : `SELECT * FROM table_name`
    5. Exit : `.quit`

## Startup guide

### Create and insert test data in DB

1. Go in the db directory : `cd db`
2. Run the make command : `make`
3. Run the create program : `./create.out`
4. Run the insert program : `./insert.out` or `./insert2.out`

### Generate the skill-tree from the DB

1. Go in the generator directory : `cd generator`
2. Run the make command : `make`
3. Go back to the skill-tree directory : `cd ..`
4. Execute the run script : `./run.sh`
