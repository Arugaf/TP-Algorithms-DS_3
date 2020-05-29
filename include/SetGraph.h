#ifndef TP_ALGORITHMS_DS_3_SETGRAPH_H
#define TP_ALGORITHMS_DS_3_SETGRAPH_H

#include "IGraph.h"

#include <set>
#include <vector>

class SetGraph : public IGraph {
public:
    SetGraph(int count);
    SetGraph(const IGraph& graph);
    virtual ~SetGraph();

    virtual void AddEdge(int from, int to) override;

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;

private:
    std::vector<std::set<int>> LinkSet;
};

#endif //TP_ALGORITHMS_DS_3_SETGRAPH_H
