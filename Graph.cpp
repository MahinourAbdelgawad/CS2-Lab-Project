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


void Graph::DeleteCity(const string& city)
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

		it.second = newEdges; //replacing old edges vector with the new one
	}
}



pair<vector<string>, float> Graph::FindShortestDis(const string& location, const string& destination)
{
	if (adjList[location].empty()) //if city has no neighbors, then there is no path and no need to continue the function
		return make_pair(vector<string>(), -1); //returns empty vector and -1

	unordered_map<string, float> distances;
	unordered_map<string, string> previousCities;

	for (const auto& city : adjList)
	{
		distances[city.first] = INT_MAX;
	}

	distances[location] = 0;

	queue<string> q;
	q.push(location);

	while (!q.empty())
	{

		string u = q.front();
		q.pop();

		for (const auto& neighbors : adjList[u])
		{
			string v = neighbors.first;
			float distance = neighbors.second;

			if (distances[u] + distance < distances[v])
			{
				distances[v] = distances[u] + distance;
				previousCities[v] = u;
				q.push(v);

			}
		}
	}


	if (distances[destination] == INT_MAX) //no path exists
		return make_pair(vector<string>(), -1); //returns an empty vector and -1 as the distance

	return make_pair(findPath(previousCities, location, destination), distances[destination]); //findPath creates a vector out of the previousCities map. distances[destination] returns the shortest distance to the destination

}

vector<string> Graph::findPath(unordered_map<string, string> previous, const string& location, const string& destination) //helper function for find shortest dist, returns a vector with the cities in the path
{
	stack<string> cityStack;
	string current = destination;

	while (current != location)
	{
		cout << "in here" << endl;
		current = previous[current];
		cityStack.push(current);
	}

	vector<string> path;

	while (!cityStack.empty())
	{
		path.push_back(cityStack.top());
		cityStack.pop();
	}

	return path;

}


void Graph::UpdateGraph(const string& city1, const string& city2, float distance)
{
	for (auto& edge : adjList[city1]) {
		if (edge.first == city2) {
			edge.second = distance;

			break;
		}
	}

	// update reverse direction 
	for (auto& edge : adjList[city2]) {
		if (edge.first == city1) {
			edge.second = distance;

			break;
		}
	}

}

void Graph::removeEdge(const string& city1, const string& city2)
{
	//delete path from city1 to city2
	vector<pair<string, float>> deletededges1;
	for (const auto& edge : adjList[city1]) {
		if (edge.first != city2) {
			deletededges1.push_back(edge);
		}
	}
	adjList[city1] = deletededges1;

	//delete path from city2 to city1
	vector<pair<string, float>> deletededges2;
	for (const auto& edge : adjList[city2]) {
		if (edge.first != city1) {
			deletededges2.push_back(edge);
		}
	}
	adjList[city2] = deletededges2;

}


void Graph::DisplayGraphData()
{
	for (const auto& city : adjList)
	{
		cout << city.first << endl;
		for (const auto& edge : city.second) {
			cout << "  -> " << edge.first << " (distance: " << edge.second << ")" << endl;
		}
	}

	cout << endl;
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

			float distance = stof(distanceString);
			if (!edgeExists(city1, city2, distance))
				AddEdge(city1, city2, distance); //connect city1 and city2
		}

	}
}

void Graph::WriteToFile(const string& filename)
{
	ofstream outFile(filename, ios::out); // Open the file in out mode
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
		if (city.second.empty()) {
			outFile << city.first << " " << " " << endl;
		}
		else
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

bool Graph::edgeExists(const string& city, const string& city2, float distance) //checks for path AND its weight
{
	for (const auto& edges : adjList[city])
	{
		if (edges.first == city2 && edges.second == distance)
			return true;
	}
	return false;
}

bool Graph::edgeExists(const string& city, const string& city2) //checks for existence of path only
{
	for (const auto& edges : adjList[city])
	{
		if (edges.first == city2)
			return true;
	}
	return false;

}

int Graph::count() //returns number of cities available
{
	return adjList.size();
}