/// @brief		Shortest Path class declarations
/// @file		shortest_path.cpp
/// @author		Aparajith Sridharan (s.aparajith@live.com)
/// @date		27-08-2020
/// @details	
/// @history
/// @see ReadMe.md for more details

#pragma once
#include"shortest_path.h"
#include<string>
#include<vector>

std::vector<std::string> ShortestPath::vertices()
{
	std::vector<std::string> nodes;
	for (auto iter = ChildParentMap.begin();
		iter != ChildParentMap.end();
		iter++)
	{
		nodes.push_back(iter->first);
	}
	return nodes;
}

void ShortestPath::ComputeDijkstrasSP(const std::string& u, const std::string& w)
{
	//set the source node cost as 0 because it is the source.
	G.setNodeValue(u, 0.F);

	//create a Priority queue to keep track all the nodes that lead to the shortest path to 'w'
	PriorityQueue<std::string> PQ;
	//insert the first node and make its cost as 0. 
	PQ.insertQ(u, 0.F);

	//empty string to denote the source node has no parent.
	ChildParentMap[u] = std::string();

	while (PQ.size())
	{
		//name is important 
		std::string u_nodename;

		// distance is important
		float u_distance;
		// distance to reach 'u'
		float u_nodevalue;

		// top points to the top most element in the priority Q sorted by min distance
		u_distance = PQ.top().second.first;
		u_nodename = PQ.top().second.second;
		u_nodevalue = G.getNodeValue(u_nodename);

		//Early stopping for Dijsktras Algorithm to improve running efficiency 
		//as the node popped will never be visited again.
		if (u_nodename == w)
		{
			break;
		}

		// pop the first element out 
		static_cast<void>(PQ.minPriority());

		std::vector<std::string> listOfNeighbors = G.neighbors(u_nodename);

		for (auto iter = listOfNeighbors.begin();
			iter != listOfNeighbors.end();
			iter++)
		{
			std::string v_nodename = *iter;
			float v_nodevalue = G.getNodeValue(*iter);
			float distance = G.getEdgeValue(*iter, u_nodename);

			if (v_nodevalue > (u_nodevalue + distance))
			{
				G.setNodeValue(v_nodename, (u_nodevalue + distance));
				PQ.insertQ(v_nodename, (u_nodevalue + distance));
				//set parent of child
				ChildParentMap[v_nodename] = u_nodename;
			}
		}

	}
}

std::vector<std::string> ShortestPath::path(const std::string& u, const std::string& w)
{
	std::vector<std::string> path;

	path.push_back(w);
	// store the src and dst nodes for future uses to improve efficiency
	srcNode = u;
	dstNode = w;

	// computes the Dijstras Shortest path from u till w
	ComputeDijkstrasSP(u, w);

	while (ChildParentMap[path.at(path.size() - 1)].size())
	{
		path.push_back(ChildParentMap[path.at(path.size() - 1)]);
	}

	return path;
}

float ShortestPath::path_size(const std::string& u, const std::string& w)
{
	// run the path finder again if different nodes were chosen as source and destination
	if (srcNode != u || dstNode != w)
	{
		static_cast<void>(path(u, w));
	}
	return G.getNodeValue(w);
}