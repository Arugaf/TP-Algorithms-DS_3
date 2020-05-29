#include "MatrixGraph.h"

#include <cassert>

MatrixGraph::MatrixGraph(int count) : matrix(count) {
    for (auto& row : matrix) {
        row = std::vector<int>(count, 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph)
        : MatrixGraph(graph.VerticesCount()) {
    for (int i = 0; i < graph.VerticesCount(); i++) {
        std::vector<int> vertices = graph.GetNextVertices(i);
        matrix[i] = std::vector<int>(graph.VerticesCount(), 0);
        for (int vertice : vertices) {
            matrix[i][vertice] = 1;
        }
    }
}

MatrixGraph::~MatrixGraph() = default;

void MatrixGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from <= matrix.size());
    assert(to >= 0 && to <= matrix.size());

    matrix[from][to] = 1;
}

void MatrixGraph::AddEdge(int from, int to, int weight) {
    assert(from >= 0 && from < matrix.size());
    assert(to >= 0 && to < matrix.size());

    matrix[from][to] = weight;
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < matrix.size());
    std::vector<int> res;
    for (size_t i = 0; i < matrix.size(); i++)
        if (matrix[vertex][i] != 0) {
            res.push_back(i);
        }
    return res;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < matrix.size());
    std::vector<int> res;
    for (int i = 0; i < matrix.size(); i++)
        if (matrix[i][vertex] != 0) {
            res.push_back(i);
        }
    return res;
}

int MatrixGraph::GetCost(int from, int to) {
    return matrix[from][to];
}