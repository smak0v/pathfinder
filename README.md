# Pathfinder Project

## Description

Pathfinder project can be used to find all shortest paths from all vertices to all other vertices.

When the program starts, it needs to pass 1 parameter - the name of the file from which to load information for processing. 

The first line of the file should contain a number - the number of vertices. In all the rest, there are paths between vertices in the format ```str1-str2,n```, where: ```str1``` - is the name of vertex 1; ```str2``` - is the name of vertex 2; ```n``` - is the length of the path between two vertices.

## How to use

Compilation:

```
make
```

Reinstalliation:

```
make reinstall
```

Uninstalliation:

```
make uninstall
```

## Usage example

```
./pathfinder file_name
```

## File example

```
4
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
Java-Fraser,5
```

## Output example

```
========================================
Path: Greenland -> Bananal
Route: Greenland -> Bananal
Distance: 8
========================================
========================================
Path: Greenland -> Fraser
Route: Greenland -> Fraser
Distance: 10
========================================
========================================
Path: Greenland -> Java
Route: Greenland -> Fraser -> Java
Distance: 10 + 5 = 15
========================================
========================================
Path: Bananal -> Fraser
Route: Bananal -> Fraser
Distance: 3
========================================
========================================
Path: Bananal -> Java
Route: Bananal -> Fraser -> Java
Distance: 3 + 5 = 8
========================================
========================================
Path: Fraser -> Java
Route: Fraser -> Java
Distance: 5
========================================
```

## Possible errors

1. Invalid number of command-line arguments.
2. The file does not exist.
3. The file is empty.
4. The first line contains something other than digits.
5. One of the remaining lines doesn't match the pattern ```str1-str2,n```.
6. The number received on the first line does not coincide with the number of islands.