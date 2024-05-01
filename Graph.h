#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
using namespace std;

class Graph
{
	unordered_map<string, vector<pair<string, float>>> adjList;

	//key is the city name (string)
	//value is the vector (which contains list of cities connected to the current city)
	//each entry in the vector contains a pair (name of connected city, and the distance)

public:

	Graph() {} //constructor

	//Edge to be used in finding shortest distance function
	struct Edge
	{
		string destination;
		int weight;
	};


	//change return type and parameters according to what u need
	void AddCity(const string& city); //untested
	void AddEdge(const string& citysrc, const string& citydest, float distance); //untested
	void DeleteCity(string city); //done but untested
	int FindShortestDis(vector<vector<Edge>>& graph, string& source, string& destination);
	void UpdateGraph();
	void loadGraph(string filename);

	bool cityExists(const string& city);


};
