/// @brief	contains the main function
/// @file	main.cpp
/// @author Aparajith Sridharan (s.aparajith@live.com)
/// @date	25-08-2020
/// @details use this file for testing/running the algorithm
/// @history
/// @see ReadMe.md for more details

#include"dijkstra_simulation.h"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()
#include<iostream>  // printing to and scanning from console

///////////////////////////////////////
// Functions
///////////////////////////////////////

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	// simulation 1: calculate average path cost using
	//  density = 20% 
	//  50 nodes
	//  random weights in [1.0 , 10.0]
	//  source node is always first node
	//  expected 49 runs total.
	////////////// set simulation parameters ///////////////
	uint32 numVertices = 50;
	float prob = 0.2F;
	std::pair<float, float> DistanceRange = { 1.F,10.0F };
	std::string sourceNode = name_generator(0);
	std::cout << "Simulation of Dijkstra Algorithm" << std::endl;
	std::cout << "Simulation 1: " << std::endl;
	std::cout << "density: 20% " << std::endl;
	std::cout << "nodes: 50" << std::endl;
	std::cout << "weights: [1.0,10.0]" << std::endl;
	std::cout << "Source: node A" << std::endl;

	DijkstraSimulation Sim(numVertices, prob, DistanceRange);
	//print the randomly generated graph.
	Sim.printGraph();
	//run the simulation for all nodes and return the cost.
	Sim.runDijkstraAverage(sourceNode);
	///////////////////////////////////////////////	

    // simulation 2: calculate average path cost using
	//  density = 40% 
	//  other parameters same as in simulation 1. 
	////////////// set simulation parameters ///////////////
    prob = 0.4F;
	std::cout << "Simulation of Dijkstra Algorithm" << std::endl;
	std::cout << "Simulation 2: " << std::endl;
	std::cout << "density: 40% " << std::endl;
	std::cout << "nodes: 50" << std::endl;
	std::cout << "weights: [1.0,10.0]" << std::endl;
	std::cout << "Source: node A" << std::endl;

	Sim.reGraph(prob);
	//print the randomly generated graph.
	Sim.printGraph();
	//run the simulation for all nodes and return the cost.
	Sim.runDijkstraAverage(sourceNode);
 	return 0;

}