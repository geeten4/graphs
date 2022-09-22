#include "graphs.h"

using namespace std;
using namespace linked_list;
using namespace graph;
using namespace heap;

/*
 * main library file, includes the main function.
 */

int main(int argc, char *argv[])
{
    Program program = Program();
    program.start();

    if(argc == 1)
    {
        cout << "Error: You must specify a command. " << endl;
        cout << "Commands availible: " << endl << endl;
        cout << "  graphs dijkstra startingVertexNumber endVertexNumber" << endl << endl;
        cout << "  graphs minSpanTree" << endl << endl;
        return 0;
    }

    if (strcmp(argv[1], "dijkstra") == 0)
    {
        // run the dijkstra algortihm, starting and ending vertices are parameters
        if (argv[2] == NULL || argv[3] == NULL)
        {
            cout << "Error: Invalid format. For the dijkstra algorithm, use" << endl << endl;
            cout << "  graphs dijkstra startingVertexNumber endVertexNumber" << endl << endl;
            return 0;
        }
        int originVertexNum = atoi(argv[2]);
        int targetVertexNum = atoi(argv[3]);
        program.Dijkstra(originVertexNum, targetVertexNum);

    } else if (strcmp(argv[1], "minSpanTree") == 0)
    {
        // run the minimal spanning tree algortihm
        program.minimalSpanningTree();

    } else {
        cout << "Error: Unknown command." << endl;
        cout << "Commands availible: " << endl << endl;
        cout << "  graphs dijkstra startingVertexNumber endVertexNumber" << endl << endl;
        cout << "  graphs minSpanTree" << endl << endl;

    }
}