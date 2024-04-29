//
//  main.cpp
//  CS2LabProject
//
//  Created by Mika on 24/04/2024.
//

#include "Graph.hpp"
#include <iostream>
using namespace std;


int main()
{
    int choice;

    //call function to load and read file
    //create graph from data in the file

    cout << "--------------MINI WASALNY APPLICATION--------------" << endl << endl;

    cout << "Please select an option:" << endl
        << "(1) Display available cities" << endl //displaygraph
        << "(2) Enter a city" << endl
        << "(3) Remove a city" << endl
        << "(4) Navigate between two cities" << endl
        << "(5)                 " << endl //update
        << "(6) Exit Program" << endl << endl;

    cin >> choice;

    //exception handling

    switch (choice)
    {
        case(1): //display
            break;
        case(2): //addcity
            break;
        case(3): //removecity
            break;
        case(4): //findshortest
            break;
        case(5): //update
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
