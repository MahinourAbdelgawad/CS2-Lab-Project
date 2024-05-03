#include "Graph.h"
#include <limits>
bool stringTest(string); //function to validate string input

int main()
{
	Graph graph;
	graph.loadGraph("Cities.txt"); //initializes graph with the data in the text file

	int choice; 
	string cityName, cityName2;
	float distance;
	bool cont = true;

	cout << "--------------MINI WASALNY APPLICATION--------------" << endl << endl;

	while (cont) //to loop until user decides to quit the program
	{

		cout << "Please select an operation:" << endl
			<< "(1) Display available cities" << endl //displaygraph
			<< "(2) Enter a city" << endl //add city
			<< "(3) Add a direct path between two cities" << endl //add edge
			<< "(4) Update a direct path between two cities" << endl //update
			<< "(5) Remove a city" << endl //delete city
			<< "(6) Navigate between two cities" << endl //find shortest
			<< "(7) Exit Program" << endl << endl;

		cin >> choice;

		while (cin.fail() || choice < 1 || choice > 7 ) //to make sure user enters a number from 1 to 7. cin.fail() is in case input is not a number
		{
			cin.clear();
			cin.ignore(INT_MAX, '\n'); 
			cout << "Invalid input. Please enter a number from 1 to 7" << endl;
			cin >> choice;
		}

		switch (choice)
		{
			case(1): //display
			{
				if (graph.count() == 0)
					cout << "No cities available." << endl << endl;
				else
				{
					cout << "Available cities and their neighbors:" << endl;
					graph.DisplayGraphData();
				}
			}
			break;

			case(2): //addcity
			{
				cout << "Please enter a city" << endl;
				cin.ignore(); //to empty buffer so that getline is executed
				getline(cin, cityName);
				while (!stringTest(cityName) || cityName.empty()) //name can only be alphabetical with no spaces and cant be empty
				{ //im considering converting all the validation into exception handling with try/throw/catch at some point
					cout << "Invalid input! Please try again. City name must not have spaces and can contain only letters" << endl;
					getline(cin, cityName);
				}
				if (graph.cityExists(cityName))
				{
					cout << cityName << " already exists in the graph!" << endl << endl;
					break;
				}
				graph.AddCity(cityName);
				cout << cityName << " added successfully!" << endl << endl;
			}
			break;

			case(3): //addedge
			{
				if (graph.count() == 0)
				{
					cout << "Graph is empty. Cannot add edge. Please add at least two cities before using this feature" << endl << endl;
					break;
				}
				if (graph.count() == 1)
				{
					cout << "There is only one city. Cannot add edge. Please add another city before using this feature" << endl << endl;
					break;
				}
				cout << "Please enter the first city" << endl;
				cin.ignore();
				getline(cin, cityName);
				while (!graph.cityExists(cityName))
				{
					cout << "City not found in the graph. Please try again" << endl;
					getline(cin, cityName);
				}

				cout << "Please enter the second city" << endl;
				getline(cin, cityName2);
				while (cityName == cityName2)
				{
					cout << "The two cities cannot be the same. Please try again" << endl;
					getline(cin, cityName2);
				}
				while (!graph.cityExists(cityName2))
				{
					cout << "City not found in the graph. Please try again" << endl;
					getline(cin, cityName2);
				}

				cout << "Please enter the distance in kilometers between " << cityName << " and " << cityName2 << endl;
				cin >> distance;
				while (cin.fail() || distance <= 0) //to make sure distance is not zero or negative, nor non-numeric
				{

					if (cin.fail())
					{
						cout << "Invalid input! Please try again" << endl;
						cin.clear(); //if input is not a number
						cin.ignore(INT_MAX, '\n');
					}

					else
						cout << "Distance cannot be 0 or less! Please try again" << endl;

					cin >> distance;
				}

				if (graph.edgeExists(cityName, cityName2, distance))
				{
					cout << "Path already exists!" << endl << endl;
					break;
				}
				graph.AddEdge(cityName, cityName2, distance);

				cout << "Direct path of " << distance << " kilometers between " << cityName << " and " << cityName2 << " added successfully!" << endl << endl;

			}
			break;

			case(4): //update
			{

			}
			break;

			case(5): //delete
			{
				cout << "Please enter the city you want to remove" << endl;
				cin.ignore();
				getline(cin, cityName);
				if (graph.cityExists(cityName))
				{
					graph.DeleteCity(cityName);
					cout << cityName << " has been removed from the graph" << endl << endl;
				}
				else
					cout << cityName << " is invalid or does not exist in the graph. Please try again" << endl << endl;
			}
			break;

			case(6): //find shortest
			{
				if(graph.count < 2){
					cout<< "There aren't enough cities to perform this action." << endl;
					break;
				}
				
				string srcCity, destCity;
				cout << "Enter the starting city: ";
				cin.ignore();
				getline(cin, srcCity);

				cout << "Enter the destination city: ";
				cin.ignore();
				getline(cin,destCity);

				int shortestDistance = graph.FindShortestDis(graph, srcCity, destCity);

				cout << "The Shortest Distance between " << srcCity << " and " << destCity << " is " << shortestDistance << " km."; 

				
			}
			break;

			default: //exit
			{
				cont = false;
			}
		}

	}
	graph.WriteToFile("Cities.txt");
	return 0;
}

bool stringTest(string name) //function to validate string input
{
	string::iterator it;
	for (it = name.begin(); it != name.end(); it++)
	{
		if (!isalpha(*it) || *it == ' ') //to make sure city name is all alphabetical with no spaces
			return false;
	}
	return true;
}

