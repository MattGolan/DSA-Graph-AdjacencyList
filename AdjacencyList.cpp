#include "AdjacencyList.h"
#include <iostream>
#include <iomanip>

/*=================== Helper Functions ===================*/

bool AdjacencyList::AlreadyInserted(string from, string to)
{
    // Iterates through graph to search for "to" vertex.
    auto itr = graph.find(to);
    if (itr != graph.end())
    {
        // If found, iterates through list and compares "from."
        for (unsigned int i = 0; i < itr->second.size(); i++)
        {
            if (itr->second[i].first == from)
            {
                // If a match is found, returns true.
                return true;
            }
        }
    }
    // Otherwise, returns false.
    return false;
}

int AdjacencyList::UpdateGraph(string from)
{
    // variable declaration for return
    int connections = 1;
    map<string, vector<pair<string, int>>> :: iterator itr;

    // Traverses graph keys.
    for (itr = graph.begin(); itr != graph.end(); itr++)
    {
        // Traverses all vectors to update matching "from" strings.
        for (unsigned int i = 0; i < itr->second.size(); i++)
        {
            // Increments both connections variables if "from" value matches a preexisting string in pair.
            if (from == itr->second[i].first)
            {
                itr->second[i].second += 1;
                connections += 1;
            }
        }
    }
    return connections;
}

void AdjacencyList::InitializePageRank()
{
    // Assigns variables.
    double count = graph.size();
    map<string, vector<pair<string, int>>> :: iterator itr;

    // Iterates through graph and creates a page rank key for every vertex with an equal fraction of count.
    for (itr = graph.begin(); itr != graph.end(); itr++)
    {
        page_rank[itr->first] = (1.00 / count);
    }
}

void AdjacencyList::PrintPageRank()
{
    // Rounds off the rank of the page to two decimal places.
    // See https://stackoverflow.com/questions/22515592/how-to-use-setprecision-in-c
    std::cout << fixed << showpoint;
    std::cout << setprecision(2);

    // Iterates through page rank map and prints results.
    map<string, double> :: iterator itr;
    for (itr = page_rank.begin(); itr != page_rank.end(); itr++)
    {
        cout << itr->first << " " << itr->second << endl;
    }
}

/*======= Accessible functions called by main() =======*/

void AdjacencyList::InsertEdge(string from, string to)
{
    if (AlreadyInserted(from, to))
    {
        return;
    }
    // Checks whether the "from" value exists in the map.
    if (graph.find(from) != graph.end())
    {
        // If yes, updates connection int for previous graph entries.
        int connections = UpdateGraph(from);
        // Adds new pair to vector at "to" key. Creates "to" key if not preexisting.
        graph[to].push_back(make_pair(from, connections));

    }
    // If no, adds additional keys to map.
    else
    {
        // Adds new pair to vector at "to" key. Creates "to" key if not preexisting.
        graph[to].push_back(make_pair(from, 1));
        // Creates "from" key with empty vector value.
        if (from != to)
        {
            graph[from] = {};
        }
    }
    // Checks whether the "from" key is preexisting in graph.
    if (graph.find(from) == graph.end())
    {
        // If no, creates "from" key with empty vector value.
        graph[from] = {};
    }
}

void AdjacencyList::CalculatePageRank(int power_iterations)
{
    // Creates map.
    InitializePageRank();

    // Loops proportional to user-inputted power.
    for (unsigned int i = 1; i < power_iterations; i++)
    {
        // Creates a copy so values do not change throughout.
        map<string, double> old_page_rank = page_rank;
        map<string, double> :: iterator itr;

        // Iterates through each unique vertex in map.
        for (itr = page_rank.begin(); itr != page_rank.end(); itr++)
        {
            // Assigns double and copy of adjacent (inbound) vertices.
            double rank = 0;
            vector<pair<string, int>> linker_websites = GetAdjacent(itr->first);

            // Adds fraction of each incoming vertex's rank to rank value.
            for (unsigned int j = 0; j < linker_websites.size(); j++)
            {
                rank += (old_page_rank[linker_websites[j].first] / linker_websites[j].second);
            }
            // Updates page rank for current key.
            page_rank[itr->first] = rank;
        }
    }
    // Prints map.
    PrintPageRank();
}

vector<pair<string, int>> AdjacencyList::GetAdjacent(string key)
{
    // returns vector of pairs associated with key.
    return graph[key];
}

/*======= Accessible functions called for testing ======*/

const map<string, double>& AdjacencyList::GetPageRank()
{
    // Returns page rank for unit testing.
    return page_rank;
}

