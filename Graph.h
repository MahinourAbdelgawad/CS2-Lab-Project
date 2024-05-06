#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <stack>
#include <limits>
using namespace std;

class Graph
{
	unordered_map<string, vector<pair<string, float>>> adjList;

	//key is the city name (string)
	//value is the vector (which contains list of cities connected to the current city)
	//each entry in the vector contains a pair (name of connected city, and the distance)

	vector<string> findPath(unordered_map<string, string> previous, const string& location, const string& destination); //helper function for find shortest dist, returns a vector with the cities in the path


public:

	Graph() {} //constructor

	struct Edge
	{
		string destination;
		int weight;
	};

	void AddCity(const string& city);
	void AddEdge(const string& citysrc, const string& citydest, float distance);

	void DeleteCity(const string& city);

	//void ReadGraphFromFile(const string& filename, vector<vector<Edge>>& graph);
	//int FindShortestDis(vector<vector<Edge>>& graph, string& source, string& destination);

	pair<vector<string>, float> FindShortestDis(const string& location, const string& destination);



	void UpdateGraph(const string& city1, const string& city2, float distance);
	void UpdateGraph(const string& city1, const string& city2); //first one updates weight of path, this one deletes path

	void DisplayGraphData();
	void loadGraph(string filename);
	void WriteToFile(const string& filename);

	bool cityExists(const string& city);
	bool edgeExists(const string& city, const string& city2, float distance);
	bool edgeExists(const string& city, const string& city2);
	int count();


};



