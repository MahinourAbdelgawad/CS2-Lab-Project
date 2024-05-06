#ifndef GRAPH_H
#define GRAPH_H

#include <QString>
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

    vector<string> findPath(unordered_map<string, string> previous, const string& location, const string& destination);
public:
    Graph();

    struct Edge
    {
        string destination;
        int weight;
    };

    void AddCity(const string& city);
    void AddEdge(const string& citysrc, const string& citydest, float distance);

    void DeleteCity(const string& city);

    pair<vector<string>, float> FindShortestDis(const string& location, const string& destination);


    void UpdateGraph(const string& city1, const string& city2, float distance);
    void removeEdge(const string& city1, const string& city2);

    void DisplayGraphData();
    void loadGraph(string filename);
    void WriteToFile(const string& filename);

    bool cityExists(const string& city);
    bool edgeExists(const string& city, const string& city2, float distance);
    bool edgeExists(const string& city, const string& city2);
    int count();

};

#endif // GRAPH_H
