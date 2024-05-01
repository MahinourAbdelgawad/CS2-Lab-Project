#include "Graph.h"

bool stringTest(string); //function to validate string input

int main()
{

	Graph graph;
	graph.loadGraph("Cities.txt"); //initializes graph with the data in the text file

	int choice;
	string cityName, cityName2;
	float distance;

	cout << "--------------MINI WASALNY APPLICATION--------------" << endl << endl;

	cout << "Please select an option:" << endl
		<< "(1) Display available cities" << endl //displaygraph
		<< "(2) Enter a city" << endl //add city
		<< "(3) Add a direct path between two cities" << endl //add edge
		<< "(4) Update a direct path between two cities" << endl //update
		<< "(5) Remove a city" << endl //delete city
		<< "(6) Navigate between two cities" << endl //find shortest
		<< "(7) Exit Program" << endl << endl;

	cin >> choice;

	//add exception handling for choice here (has to be between 1 and 6. User keeps trying until they enter a valid number)

	switch (choice)
	{
		case(1): //display
		{

		}
			break;
		case(2): //addcity
		{
			cout << "Please enter a city" << endl;
			cin.ignore(); //to empty buffer so that getline is executed
			getline(cin, cityName);
			while (!stringTest(cityName) || cityName.empty()) //name can only be alphabetical, cant be empty
			{ //im considering converting all the validation into exception handling with try/throw/catch at some point
				cout << "Invalid input! Please try again. City name must not be blank and can contain only letters" << endl;
				getline(cin, cityName);
			}
			cout << cityName << " added successfully!" << endl;
		}
			break;
		case(3): //addedge
		{
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
			//add exception handling if the distance is zero or negative here
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

		}
			break;
		case(6): //find shortest
		{

		}
			break;
		default: //exit
		{
			//save data into file
			exit(0);
		}
	}

	//sava data into file
	return main();
}

bool stringTest(string name) //function to validate string input
{
	if (name[0] == ' ') //this handles if the user enters only spaces or if the name starts with a space
		return false;

	string::iterator it;
	for (it = name.begin(); it != name.end(); it++)
	{
		if (!isalpha(*it) && *it != ' ') //to make sure city name is all alphabetical while also allowing 2+ words in name
			return false;
	}
	return true;
}

