#ifndef TP_ALGORITHMS_DS_3_MATRIXGRAPH_H
#define TP_ALGORITHMS_DS_3_MATRIXGRAPH_H

#include "IGraph.h"

#include <vector>

class MatrixGraph : public IGraph {
public:
    MatrixGraph(int count);
    MatrixGraph(const IGraph& graph);
    virtual ~MatrixGraph();

    virtual void AddEdge(int from, int to) override;

    virtual void AddEdge(int from, int to, int weight);

    virtual int VerticesCount() const override;

    virtual std::vector<int> GetNextVertices(int vertex) const override;
    virtual std::vector<int> GetPrevVertices(int vertex) const override;
    virtual int GetCost(int from, int to);

private:
    std::vector<std::vector<int>> matrix;
};

#endif //TP_ALGORITHMS_DS_3_MATRIXGRAPH_H
