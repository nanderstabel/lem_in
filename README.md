# lem_in
Lem_in is a [42-network](https://www.codam.nl/en/the-42-network) project which involves discovering and getting acquainted with the concepts of ***graph theory*** and ***flow networks***. The purpose of this project is to write a program that can calculate the fastest combination of paths to travel an amount of ```ants``` through an ```ant-farm```. It must take a file that contains the data of the different ```rooms``` (vertices) and their ```links``` (edges) together with the amount of ants.

For more information about this project, see [lem-in.en.pdf](https://github.com/nanderstabel/lem_in/blob/master/lem-in.en.pdf).

## Compiling
Run ```make```, an executable called ```lem-in``` should compile directly. Please submit an issue if you run into any.

## Ant-farm
In the ```maps/valid_maps``` folder you can find a list of files containing valid ant-farms. Below you can see one of these files. The number in the first line (4) is the number of ants that need to cross the farm to the end. A farm can have several thousands of rooms, but there must always be a ```start``` room and an ```end``` room specified. In this example the rooms between the end and the start are named with numbers from 1 until 6 (the numbers following the roomnames are coördinates, which are not used in this program). After the rooms, the links are notated. Each link is written as two roomnames delimited with a ```-``` character.

```
cat maps/valid_maps/map2.map
4
3 2 2
##start
start 4 0
##end
end 4 6
4 0 4
1 4 2
2 4 4
5 8 2
6 8 4
start-1
3-4
2-4
1-5
6-5
end-6
1-2
2-end
3-start
```

Which corresponds to the following representation:

```
  [start]
   /  |
 [3] [1]--[5]
 /    |    |
[4]--[2]  [6]
      |   /
     [end]
```

## How to use?
After creating the executable file, ```lem-in``` can be executed by giving it an ant-farm e.g.:

```./lem-in < maps/valid_maps/map2.map```

There are some extra options we have added to our project:

```
./lem-in -u
Usage: ./lem-in [-abcdeglpru] < map
Pathfinder which moves 'ants' from a start room to an end room, using a given map, in the least amount of steps
        -a              prints the steps taken during augmenting
        -b              prevents printing output
        -c              adds a turn counter to the output
        -d              prints the steps taken during pathfinding (dfs)
        -e              shows where an error occured, if there was any
        -g              debug mode: shows executed functions in chronological order
        -l              prints hashtables containing all links
        -p              shows all paths ordered by round number
        -r              prints hashtables containing all rooms
        -u              shows usage message
```

## Specifications
The goal of this project is to find the quickest way to get ***n*** ants across the farm, this means that the program's solution must be given in the least amount of lines. Below is our solution to ```maps/valid_maps/map2.map```.

```
L1-1 L2-3
L1-5 L2-4 L3-1 L4-3
L1-6 L2-2 L3-5 L4-4
L1-end L2-end L3-6 L4-2
L3-end L4-end
```

Each line counts as 1 turn, so our program needs 5 turns to get all 4 ants to the end. An antname starts with ```L``` followed by a number. ```L1-1``` means that in this turn the ```L1``` ant travels to room ```1```. Why does our program only move 2 ants in the first turn? According to the rules of the project ants can only travel over one link per turn and there can only be one ant in each room (the vertex capacity and edge capacity are both 1). 

So how do we arrive at this solution? After validating and saving the input data in a graph and two hashtables, the first step of the algorithm is to do a ***breadth-first search*** (BFS) starting at the end room (sink) like so:
![ezgif com-resize](https://user-images.githubusercontent.com/43185740/86123653-2d11ce80-bada-11ea-831f-9f535b3d72b4.gif)



## Challenge
Allowed functions for the mandatory part are ```exit```, ```open```, ```close```, ```write```, ```read```, ```malloc``` and ```free```.

## Takeaways

