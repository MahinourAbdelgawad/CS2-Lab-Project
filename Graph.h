#pragma once
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Graph
{
	unordered_map<string, vector<pair<string, float>>> adjList;
	//key is the city name (string)
	//value is the vector (which contains list of cities connected to the current city)
	//each entry in the vector contains a pair (name of connected city, and the distance)

public:

	Graph() {} //constructor

	//change return type and parameters according to what u need
	void AddCity(const string& citysrc, const string& citydest = "", float distance = 0.0);
	void DeleteCity(string city); //done but untested
	void FindShortestDis();
	void UpdateGraph();


};
