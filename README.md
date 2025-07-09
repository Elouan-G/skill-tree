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

### Build

- Run the `make` command in the projects root directory

### Create and insert test data in DB

1. Go in the db directory : `cd db`
2. Run the create program : `./create.out`
3. Run the insert program : `./insert.out` or `./insert2.out`

### CLI

- Execute the run script in the projects root directory : `./run.sh`
