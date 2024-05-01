#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjacencyMatrix;

public:
    Graph(int numVertices) {
        // Initialize the adjacency matrix with zeros
        adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 9999));
    }

    void addEdge(int from, int to, int weight) {
        // Add the edge between 'from' and 'to' with the given weight
        adjacencyMatrix[from][to] = weight;
        adjacencyMatrix[to][from] = weight;
    }

    void printAdjacencyMatrix() {
        // Print the adjacency matrix
        for (size_t i = 0; i < adjacencyMatrix.size(); ++i) {
            for (size_t j = 0; j < adjacencyMatrix[i].size(); ++j) {
                cout << adjacencyMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    void loadgraph(string filename)
    {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
        }
        string line;
        int counter = 0;
        unordered_map<string, int> citiesindex;
        while (getline(file, line)) {
            istringstream iss(line);
            string city1, city2, distanceString;
            iss >> city1 >> city2 >> distanceString;
            if (citiesindex.find(city1) == citiesindex.end()) {
                citiesindex[city1] = counter;
                //cout << city1 << " " << counter << endl;
                counter++;
            }
            if (citiesindex.find(city2) == citiesindex.end()) {
                citiesindex[city2] = counter;
                //cout << city2 << " " << counter << endl;
                counter++;
            }
            int distance = stoi(distanceString);
            this->addEdge(citiesindex[city1], citiesindex[city2], distance);

        }
    }

};
int main() {
        Graph graph(4);
        graph.loadgraph("C:/Users/moham/OneDrive/Desktop/CSlab Final project/Cities.txt");
        graph.printAdjacencyMatrix();
}
