use https://github.com/Aparajith-S/Dijkstras_Algorithm to view the Readme online.

# Dijkstras Algorithm implementation
##### Author: Aparajith Sridharan
##### Email: s.aparajith@live.com
##### Date : 26-08-2020

### What I learned : 

#### Choice of Edge List vs Adjacency Matrix (a.k.a Connectivity matrix)  vs Adjacency list

- _Edge list_:  
Largely speaking an Edge list contains `E` element pairs in the list. Where, E is the number of links or paths between nodes. Being one of the most simplest expressions of graph connections, it occupies `O(E)` in space.  
Now, `E` can be a large number. `E` can be `MAX_UINT32` which means the Edge list is going to potentially have `MAX_UINT32` elements.  
This makes us question the time complexity to conduct a linear search for a specific egde between two vertices that costs `O(E)` as well.  
This can be implemented as a vector of pairs like this  
`std::vector<std::pair<unsigned int,unsigned int>>`.  

- _Adjacency Matrix_ :
An Adjacency Matrix is a 2D V x V matrix where V is number of vertices. A boolean 2D array is required.  
let V be the number of vertices then,  
`std::array<std::array<bool,V>,V>` would draw an adjacency matrix.  
This is better than Edge lists as finding if an Egde exists between two vertices will take just O(1) time.  
Space complexity is however, worse at O(V*V) even if there are only a couple of edges between the vertices the entire array has to be constructed.  
This tradeoff is acceptable when the graph is nearly fully connected. However, for sparsely connected graphs it is going to end up in a matrix that is mostly filled with zeroes.  
Additionally, for a undirected graph the matrix is going to be symmetrical which is a property that could be used to find if the graph is directed or undirected, if that is not given.  
  
- _Adjacency List_ :  
An Adjacency list is a hybrid of both worlds solution. Here an array of V elements contain a list of elements that are connected to the vertex.  
This means there is an array of `V` elements containing list of Edges that are connected to that Vertex. As shown below.
`std::vector<std::vector<unsigned int>>`  
This would mean finding the vertex is still going to be a O(1) time complexity and finding an other Vertex in the list if present is going to take O(M) time.  
where, `M` is between `[0,V-1]`. `0` when the vertex is isolated and `V-1` when the vertex is connected with every other vertex.  
So, it is clear that for a fully connected graph this is going to take in the worst case of O(V-1) to find the other vertex. but, occupy the same number of elements as in the Adjacency matrix.  
  
Since the number of vertices in the problem statement is less than `100` and the density of edges can be quite low, the Edge list loses to the Adjacency matrix and due to possible sparseness out of low density of edges, **the Adjacency List is chosen**.
#### References:
- [https://medium.com/basecs/from-theory-to-practice-representing-graphs-cfd782c5be38#:~:text=And%20that's%20exactly%20what%20an,are%20adjacent%20to%20other%20vertices.]
- [https://brilliant.org/wiki/dijkstras-short-path-finder/]

# Requirements
- This application was compiled and run on VS 2017 - VC++ 14.16 compiler.  
  Kindly note that the application was developed with C++11 standards.  
  but, if you use VC10, remember that the compiler does not support all C++11 features.

# Code

- `dijkstra_simulation.h` provides the entry point with the class `DijkstraSimulation` that manages the entire workflow.
Use it to create a randomized graph woth random number of vertices and weights added based on a probability density that can be parameterized.  
- `undirected_graph.h` contains the definitions of the class `Graph` which helps to construct an undirected graph for the purpose of this project.
- `priority_queue.h` contains the class definiton of `PriorityQueue` which is a queue sorted based on the lowest cost.
- `myalgorithm.h` implements a custom binary search with a predicate as it is not a C++11 in-built feature. This is used by the `PriorityQueue`.
- `main.cpp` this file is used to validate/test/run the algorithm.

# Output
The output file is quite large to be as a part of ReadMe in order to be informative.
`output.txt` contains the console output of this application.
