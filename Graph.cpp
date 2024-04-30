#include "Graph.h"
#include <queue>


void Graph::AddCity(const string& city) //adds a city
{
        adjList.insert({ city, vector<pair<string, float>>() });
}

void Graph::AddEdge(const string& citysrc, const string& citydest, float distance) //adds edge between two cities
{
    adjList[citysrc].push_back({ citydest, distance });
    adjList[citydest].push_back({ citysrc, distance });

}


void Graph::DeleteCity(string city)
{
	adjList.erase(city); //removing city from the adjacency list

	//removing all its edges
	for (auto& it : adjList) //iterating over adjList
	{
		auto edges = it.second; //vector of the edges

		vector<pair<string, float>> newEdges; //vector for storing edges after removal

		for (int i = 0; i < edges.size(); i++) //iterating over the vector
		{
			if (edges.at(i).first != city) 
			{
				newEdges.push_back(edges.at(i));
			}
		}

		edges = newEdges; //replacing old edges vector with the new one
	}
}


int Graph::FindShortestDis(vector<vector<Edge>>& graph, string& location, string& destination)
{
    unordered_map<string, int> vertexIndex;

    int numCities = 20; //letting the number of cities 20

    for (int i = 0; i < numCities; ++i)
    {
        vertexIndex[graph[i][0].destination] = i;
    }
    // Initializing distances to infinity (Dijkastra's algorithm)
    vector<int> distance(numCities, INT_MAX);
    // Distance from location to itself is 0
    distance[vertexIndex[location]] = 0;

    queue<int> q;
    q.push(vertexIndex[location]);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        // Visit each city around the current location
        for (int i = 0; i < graph[u].size(); ++i)
        {
            Edge& edge = graph[u][i];
            int v = vertexIndex[edge.destination];
            int weight = edge.weight;

            // if the distance through u less than through v update the distance
            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                q.push(v);
            }
        }
    }


    return distance[vertexIndex[destination]];

}

bool Graph::cityExists(const string& city) //needed for the delete city function and add edge
{
    return (adjList.find(city) != adjList.end()); //returns true if city exists/ false if it does not
}

