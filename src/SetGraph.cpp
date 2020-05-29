#include "SetGraph.h"

#include <cassert>

SetGraph::SetGraph(int count) : LinkSet(count) {

}

SetGraph::SetGraph(const IGraph& graph) : SetGraph(graph.VerticesCount()) {
    for (auto i = 0; i < LinkSet.size(); i++) {
        std::vector<int> nodes = graph.GetNextVertices(i);
        for (auto j : nodes) {
            LinkSet[i].insert(j);
        }
    }
}

SetGraph::~SetGraph() = default;

void SetGraph::AddEdge(int from, int to) {
    assert(from >= 0 && from < LinkSet.size());
    assert(to >= 0 && to < LinkSet.size());

    LinkSet[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return LinkSet.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    assert(vertex >= 0 && vertex < LinkSet.size());
    std::vector<int> res;
    for (auto i : LinkSet[vertex]) {
        res.push_back(i);
    }
    return res;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    assert(vertex >= 0 && vertex < LinkSet.size());
    std::vector<int> res;

    for (auto i = 0; i < LinkSet.size(); i++) {
        for (auto j : LinkSet[i]) {
            if (vertex == j) {
                res.push_back(i);
                break;
            }
        }
    }
    return res;
}