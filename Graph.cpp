#include <iostream>
#include <vector>

using Vertex = size_t;

class IGraph {
public:
    virtual void AddEdge(Vertex from, Vertex to) = 0;
    virtual size_t GetSize() const = 0;
    virtual const std::vector<size_t>& GetAdjacent(Vertex v) const = 0;
    virtual ~IGraph() {}
};

class DirectedMatrixGraph :public IGraph {
public:
    DirectedMatrixGraph(size_t verticesCount) : graph(verticesCount, std::vector<Vertex>(verticesCount, 0)) {}
    size_t GetSize() const override {
        return graph.size();
    }
    void AddEdge(Vertex from, Vertex to) override {
        graph.at(from).at(to) = -1;
        graph.at(to).at(from) = 1;
    }
    const std::vector<Vertex>& GetAdjacent(Vertex v) const override {
        std::vector<Vertex> adj;
        for (Vertex i = 0; i < graph.size(); ++i) {
            if (graph.at(v).at(i) == -1) {
                adj.push_back(i);
            }
        }
        return adj; 
    }
private:
    std::vector<std::vector<Vertex>> graph;
};
