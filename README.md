# DSA-Graph-AdjacencyList
Adjacency list graph implementation for data structures and algorithms class project. I implemented a simplified version of Google's PageRank algorithm to organize user-input website links and to determine the value of incoming links for each website. Specifically, the program receives user input on the links between various website addresses as well as the number of power iterations that will be performed. Subsequently, each website is stored within an adjacently list and a ranking is calculated for each website. (Rank(i) = Rank(j)/out_degree(j) + Rank(k)/out_degree(k)). The rank is based on the indegree (the number of nodes pointingto it) and the rank of an incoming node (calculated in the previous iteration). Ultimately, the address and rank of each website is printed. Please see below for a more detailed overview of input, output, and program constraints.

Input 

- Line 1 contains the number of lines (n) that will follow and the number of power iterations (p) you need to perform.
- Each line from 2 to n+1 will contain two URL’s – from_page and to_page separated by a single space.

Output

- Print the PageRank of all pages after p powerIterations in ascending alphabetical order of webpage.
- Also, round off the rank of the page to two decimal places.

Constraints

- 1 <= p <= 10,000
- 1 <= n <= 10,000
- 1 <= Unique webpages or |V| <= 10000
