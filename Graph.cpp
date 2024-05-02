#include "Graph.h"


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


void Graph::loadGraph(string filename)
{
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Error opening file!" << endl;
	}

	string line;
	while (getline(file, line)) {
		istringstream iss(line);
		string city1, city2, distanceString;
		iss >> city1 >> city2 >> distanceString;

		if (!cityExists(city1)) //if city is not already in the graph, add it
			AddCity(city1);

        if (!city2.empty()) //if city2 is an empty string then city1 has no neighbors and no edges
        {
            if (!cityExists(city2)) //if city 2 is not already in the graph, add it
                AddCity(city2);

            float distance = stoi(distanceString);
            AddEdge(city1, city2, distance); //connect city1 and city2
        }

	}
}
void Graph::void WriteToFile(const string& filename)
{
	ofstream outFile(filename, ios::app); // Open the file in append mode
		if (!outFile.is_open()) {
			cerr << "Error opening file!" << endl;
			return;
		}

		// Check if the file is not empty and we're appending new data
		if (outFile.tellp() != 0) {
			// File is not empty, add a new line before writing
			outFile << endl;
		}

		for (const auto& city : adjList) {
			for (const auto& edge : city.second) {
				outFile << city.first << " " << edge.first << " " << edge.second << endl;
			}
		}

		outFile.close();
}
bool Graph::cityExists(const string& city) //needed for the delete city function and add edge
{
    return (adjList.find(city) != adjList.end()); //returns true if city exists/ false if it does not
}
