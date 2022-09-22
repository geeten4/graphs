Graphs

Břetislav Andr

2022

simple graph algorithm library
implemented the Dijsktra algortihm and minimum spanning tree algorithm
To input a graph, use the "input.txt" file with the format specified below.
To use any one of the algorithms, see below the formats of the commands.
To see the actual implementation, see the "shortestPathGraph.cpp" file.

for visualization use for example https://graphonline.ru/en/?graph=weightedGraph

fir dijkstra algortihm, see https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm

for minimum spanning tree algorithm, see https://en.wikipedia.org/wiki/Minimum_spanning_tree



USER MANUAL
-------------------------------------------------------



------------ COMPILATION ------------
to compile, use 

```
make
```

the output file is titled "graphs"



------------ INPUT ------------
to input a graph, use the "input.txt" file where each line
adds a new edge to the graph. use the format

"""
vertexNumber1 vertexNumber2 edgeWeight
"""

where vertexNumber1, vertexNumber2 represent the numbers identifying 
the vertices and edgeWeight sets the weight of the edge connecting
these to vertices.

e.g. 

"""
1 4 10
"""

adds an edge between the vertices with numbers 1 and 4 with a weight of 10.
as an example see the already specified algorithm in "input.txt"


------------ DIJKSTRA ------------
to run the Dijkstra algorithm on the given graph, use the command

```
./graphs dijkstra startingVertexNumber endingVertexNumber
```

where startingVertexNumber represents the number of the vertex from which
we want to find the shortest path, endingVertexNumber represents the number
of the vertex where the shortest path should end.

the output shortest path is printed on the command line in format

"""
vertexNumber1-(edgeWeight1)-vertexNumber2
vertexNumber2-(edgeWeight2)-vertexNumber3
...
"""

where vertexNumber1 is the starting vertex, vertexNumber2 is the second
vertex of that path and edgeWeight1 is the weight of the first edge.
Same goes for the rest of the path.



------------ MINIMUM SPANNING TREE ------------
to run the minimum spanning tree algorithm, use

```
./graphs minSpanTree
```

which prints the minimum spanning tree to the console in the format

"""
vertexNumber1: vertexNumber1-(edgeWeight1)-vertexNumber2 vertexNumber1-(edgeWeight2)-vertexNumber3 ... 
vertexNumber2: vertexNumber1-(edgeWeight1)-vertexNumber2 vertexNumber2-(edgeWeight3)-vertexNumber3 ... 
...
"""

where each line starts with a number of a vertex, followed by the list of
edges connected to that vertex in the minimum spanning tree. The edges are seperated
by spaces, each edge is in the format 

"""
vertexNumber1-(edgeWeight1)-vertexNumber2
"""

where vertexNumber1 represents the number of the first vertex, vertexNumber2 the
number of the second vertex in the given edge and edgeWeight1 represents the
weight of the edge connecting these two vertices.





PROGRAMMERS MANUAL
-------------------------------------------------------

The goal here is to implement a graph structure and to implement the Dijkstra and the minimum
spanning tree algorithm. Lets start with how files are structued, then how a graph is implemented and last about 
the algorithms themselves.

------------ FILES ------------
Each class generally has its own header file and a .cpp file corresponding to it. The exception here
are the template classes, see e.g. "linkedList.h" or "weightedEdge.h". These are standard templates
declared in a header file with the method definitions in a seperate ".tpp" file (always named the same),
which is imported at the end of the file.


------------ GRAPH IMPLEMENTATION ------------
First of all, a graph is composed of vertices and edges. Both of these are made into seperate
classes found in "vertex.h" and "edge.h". Vertex class is the simplest here, any class that would be
used as a vertex in a graph should inherit from this. A vertex is simply a number (which uniquely defines
that vertex) and some state variables (in the algorithms we need to know whether the vertex has been opened,
visited etc.) An edge is now nothing but two pointers to two vertices (and again with a state variable visited.)
Edge class is a template, for we must specify the vertex type it should hold. And again, any class type that
shall be used as a edge type in a graph should inherit from this.
    A graph itself is stored as a 2d array. Ideally, for a given vertex, we want to list out all the adjacent edges
to this vertex, and do this for all the vertices. Yes, we then store each edge twice, but when stored as pointers,
there come no difficulties. First of all, we need a basic list structure. For this we have the LinkedList class 
inside of "linkedList.h" file. It is a standard linked list. We first define a LinkedListNode ("linkedListNode.h" file)
in which we store the each desired member of the list as a pointer value. LinkedListNode furthermore refers to the 
next node in the linked list, which is again a LinkedListNode instance. The LinkedList class then handles these nodes e.g.
adds members, handles the length of the list, returns a member by index, switches two nodes etc. With the linked list
implemented, we are ready for the graph structure itself. For this we use the AdjacencyList and AdjacencyListNode classes
 in "adjacencyList.h" and "adjacencyListNode.h" files respectively. Each AdjacencyListNode stores a vertex pointer
for which we want to list out all the edges. Then an AdjacencyListNode has an edgeList attribute, which is just a 
linked list of the edges incident to the given vertex. AdjacencyList is then just a list of these adjacencyListNodes
of all the vertices in the graph. These are again template classes, as we first want to know what type of edges and
vertices we want to store.
    


------------ ALGORITHMS IMPLEMENTATION ------------
for a detailed version of the algorithms, see wiki links up above. In order to implement both
these algorithms, we always need to select a minimum from a given set of class instances. The minimum heap is implemnted
here in the MinHeap class ("minHeap.h" file). This is a template classes derived from a LinkedList class. Minimum
heap is nothing but a well ordered linked list (for detailed structure see https://en.wikipedia.org/wiki/Min-max_heap), 
when bubbling up or down, we only need to cleverly switch the nodes inside the linked list to keep the heap property. It is 
a template class because we need to know what type of class instances we will be storing. Though the class type must overload
at least the "<" operator, because we are comparing these instances by their values. 
    In order to run the algortithms, we will need a weighted graph. This means each edge should have a extra number
called the weight. This is implemented in the WeightedEdge class ("weightedEdge.h" file). This simply inherits from an Edge
(and is again a template class for which we must specify the vertex type) and adds a special float attribute, the weight.
Now having a weighted edge, we can implement a graph class suited for the algorithms. We do this in the "shortestPath.h" file
in which three classes are declared. First we define a dummy class LinkedListNode. This class instance only stores a length
value and a pointer to some edge. For the Dijkstra algorithm, the length property here should represent the length of the
shortest path that we know of at the given time and the edge property should hold the last edge in the shortest path yet
known. Then running through all the edges adjacent to a given vertex, we set this number to the minimal possible. 
When the vertex is closed (e.g. we have checked all the edges), this number will store the length of the shortest path 
(the sum of all the edge weigths on the shortest path.) Second in the "shortestPath.h" file comes the ShortestPathVertex. 
This inherits from the Vertex class as we will use it in a graph structure. It is simply a vertex, only
extra stores an instance of the ShortestPathNode. Last comes the ShortestPathEdge, which is only a special type of Edge class
which stores two vertices of the ShortestPathVertex type. The ShortestPathVertex and ShortestPathEdge classes will be used in
 the actual graph structure implementing the algorithms. They must be declared in the same file (the "shortestPath.h") because
 of reference errors. Specially see both the ShortestPathEdge and the ShortestPathVertex classes overload the "<", ">" and "==" 
operators, as in the Dijkstra algorithm, we want to find a minimum from the set of ShortestPathVertex instances, in the
minimum spanning tree algorithm we need to find the minimum from the set of ShortestPathEdge instances, so both these
classes should be able to be stored in a MinHeap instance, therefore we must overload these operators.
    For the actual graph instance, we define the ShortestPathGraph in the "shortestPathGraph.h" file. This makes use of the
AdjacencyList class described above. For the AdjacencyList template parameters we use the ShortestPathVertex and ShortestPathEdge
classes just described. Furthermore, this class instance stores the weight of the whole graph (sum of all the edge weights) in 
the weight attribute. As we know all the vertex and edge types, we can easily add an edge to the graph using the 
addEdge(int, int, float) method, which creates two vertices given the two integer numbers as the identifiers of those vertices, 
and an edge connecting these two vertices with the weight as the float number given. On the ShortestPathGraph class we define
the methods Dijkstra and minimalSpanningTree, which finally implement the algorithms originally desired. For a detail of 
the algorithm implementations, see first the wiki links, then the "shortestPathGraph.cpp" file and the method definitions.



------------ PROGRAM IMPLEMENTATION ------------
The main handling class is the Program class in "program.h" file. The start method
initializes everything needed in order to run the algorithms. User input is handled
in the main function in the "graphs.cpp" file. Program.readGraphFromFile() reads
the graph given in the "input.txt" file. Program.Dijkstra() runs the dijsktra 
algorithm on the input graph, Program.minimalSpanningTree() runs the minimum
spanning tree algorithm on the input graph.