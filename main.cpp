#include "ArcGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"

#include <functional>
#include <iostream>
#include <queue>

void BFS(const IGraph &graph, int vertex, std::vector<bool> &visited, std::function<void(int)> &func)
{
    std::queue<int> qu;
    qu.push(vertex);
    visited[vertex] = true;

    while (!qu.empty())
    {
        int currentVertex = qu.front();
        qu.pop();

        func(currentVertex);

        for (int nextVertex: graph.GetNextVertices(currentVertex))
        {
            if (!visited[nextVertex])
            {
                visited[nextVertex] = true;
                qu.push(nextVertex);
            }
        }
    }
}

void mainBFS(const IGraph &graph, std::function<void(int)> func)
{
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); i++)
    {
        if (!visited[i])
            BFS(graph, i, visited, func);
    }
}


int main(int argc, const char * argv[]) {
    ListGraph graph(7);
    graph.AddEdge(0, 1);
    graph.AddEdge(0, 5);
    graph.AddEdge(1, 2);
    graph.AddEdge(1, 3);
    graph.AddEdge(1, 5);
    graph.AddEdge(1, 6);
    graph.AddEdge(3, 2);
    graph.AddEdge(3, 4);
    graph.AddEdge(3, 6);
    graph.AddEdge(5, 4);
    graph.AddEdge(5, 6);
    graph.AddEdge(6, 4);

    std::cout << "List graph: ";
    mainBFS(graph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;

    SetGraph set_graph(graph) ;
    std::cout << "Set graph: ";
    mainBFS(set_graph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;

    ArcGraph arc_graph(graph) ;
    std::cout << "Arc graph: ";
    mainBFS(arc_graph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;

    MatrixGraph matrix_graph(graph) ;
    std::cout << "Matrix graph: ";
    mainBFS(matrix_graph, [](int vertex){ std::cout << vertex << " ";});
    std::cout << std::endl;

    return 0;
}