#ifndef TP_ALGORITHMS_DS_3_ARCGRAPH_H
#define TP_ALGORITHMS_DS_3_ARCGRAPH_H

#include "IGraph.h"

#include <vector>

class ArcGraph : public IGraph {
public:
    ArcGraph(int count);
    ArcGraph(const IGraph& graph);
    virtual ~ArcGraph();

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::pair<int, int>> pairset;
    int vertices;
};

#endif //TP_ALGORITHMS_DS_3_ARCGRAPH_H
