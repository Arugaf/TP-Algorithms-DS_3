#ifndef TP_ALGORITHMS_DS_3_LISTGRAPH_H
#define TP_ALGORITHMS_DS_3_LISTGRAPH_H

#include "IGraph.h"

#include <vector>

class ListGraph : public IGraph {
public:
    ListGraph(int count);
    ListGraph(const IGraph& graph);
    virtual ~ListGraph();

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::vector<int>> adjacencyLists;
};

#endif //TP_ALGORITHMS_DS_3_LISTGRAPH_H
