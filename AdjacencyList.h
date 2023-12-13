#ifndef PROJECT2_ADJACENCYLIST_H
#define PROJECT2_ADJACENCYLIST_H

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<map>
using namespace std;

// Overall structure modeled after Stepik 7.1.2 and project materials. Credit to instructor(s).
class AdjacencyList
{
private:

    /*============= Variable Declarations =============*/

    // Adjacency list graph. Stores "to" value and vector of pairs of "from"  and connections int.
    map<string, vector<pair<string, int>>> graph;
    // Map of website keys and rank values.
    map<string, double> page_rank;

    /*=============== Helper Functions ===============*/

    // Checks whether edge already exits
    bool AlreadyInserted(string from, string to);
    // Updates values if "from" value if repeated in InsertEdge.
    int UpdateGraph(string from);
    // Creates page rank map with equal values.
    void InitializePageRank();
    // Prints page rank.
    void PrintPageRank();

public:

    /*======= Accessible functions called by main() =======*/

    // Adds new edge to list.
    void InsertEdge(string from, string to);
    //Calculates page rank.
    void CalculatePageRank(int power_iterations);

    /*======= Accessible functions called for testing ======*/

    // Returns vector of adjacent (incoming) vertices. Also used as helper function.
    vector<pair<string, int>> GetAdjacent(string key);
    // Returns page rank for unit testing.
    const map<string, double>& GetPageRank();

};

#endif //PROJECT2_ADJACENCYLIST_H
