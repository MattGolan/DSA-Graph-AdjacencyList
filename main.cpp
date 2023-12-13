#include <iostream>
#include <string>
#include "AdjacencyList.h"
using namespace std;

// Structure of main() taken from template. Credit to instructor(s).
int main() {

    // Variable declarations.
    int num_lines;
    int power_iterations;
    string from;
    string to;
    AdjacencyList current_list;

    // Assignment of int values based on user input.
    cin >> num_lines;
    cin >> power_iterations;

    // Loops based on number of lines.
    for (unsigned int i = 0; i < num_lines; i++)
    {
        // Reads user input for each edge.
        cin >> from;
        cin >> to;

        // Adds to graph if novel edge.
        current_list.InsertEdge(from, to);
    }

    // Performs page rank calculations and prints the results.
    current_list.CalculatePageRank(power_iterations);

    return 0;
}
