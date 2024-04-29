//
//  Graph.hpp
//  CS2LabProject
//
//  Created by Mika on 24/04/2024.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
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

    //Edge to be used in finding shortest distance function
    struct Edge
    {
        string destination;
        int weight;
    };
    //change return type and parameters according to what u need
    void AddCity(const string& citysrc, const string& citydest = "", float distance = 0.0);
    void DeleteCity(string city); //done but untested
    int FindShortestDis(vector<vector<Edge>>& graph, string& source, string& destination);
    void UpdateGraph();
    

};

#endif /* Graph_hpp */
