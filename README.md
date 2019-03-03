# PathfindingAlgorithms

This project was built with openFrameworks v0.10.1 and Visual Studio 2017.
To give it a try, place the contents of this repository under your myApps directory!

## Directory Outline

1. src/Behavior
   * DynamicPathFollow.h/.cpp
     * A class that acts as an interface between pathfinding and movement

2. src/Pathfinding
   * DirectedWeightedGraph.h/.cpp
     * A class representing the graph data structure
   * DivisionScheme.h/.cpp
     * An abstract class for different types of Division Schemes
   * Heuristic.h/.cpp
     * A class representing different heuristic approaches
   * Obstacle.cpp/.h
     * A class representing obstacles to account for in graphs and navigation
   * Pathfinding.cpp/.h
     * A namespace for organizing the Dijkstra and A* Algorithms
   * TiledDivisionScheme.cpp/.h
     * A class representing the Tiled Division Scheme

3. main.cpp
   * A file for the entry point into the program
4. ofApp.h/.cpp
   * A class that handles updating, drawing, and handling user input

## Running the Simulation

1. Open the pathfindingAlgorithms.sln
2. Build the project with Visual Studio with these settings:
   * Debug
   * Win32
3. Run the Local Windows Debugger

## Start Pathfinding

After the application loads you can click on white areas of the screens to get the agent to navigate to that location.
Black areas represent obstacles an agent most navigate around.
