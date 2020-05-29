#include "ArcGraph.h"

#include <cassert>

ArcGraph::ArcGraph(int count) : vertices(count) {

};

ArcGraph::ArcGraph(const IGraph& graph) : vertices(graph.VerticesCount()) {
    for (auto i = 0; i < graph.VerticesCount(); i++) {
        std::vector<int> nodes = graph.GetNextVertices(i);
        for (auto j : nodes) {
            pairset.emplace_back(i, j);
        }
    }
}

ArcGraph::~ArcGraph() = default;

void ArcGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < vertices);
    assert(to >= 0 && to < vertices);
    pairset.emplace_back(from, to);
}

int ArcGraph::VerticesCount() const {
    return vertices;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices);
    std::vector<int> res;
    for (auto i : pairset) {
        if (i.first == vertex) {
            res.push_back(i.second);
        }
    }
    return res;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < vertices);
    std::vector<int> res;
    for (auto i : pairset) {
        if (i.second == vertex) {
            res.push_back(i.first);
        }
    }
    return res;
}
