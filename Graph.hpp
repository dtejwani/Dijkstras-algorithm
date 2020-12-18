//This project has been created by Dev Tejwani and Barath Dandu
#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <iostream>
#include <map>
#include "GraphBase.hpp"
#include "Edge.hpp"
#define INF 100000

class Graph : public GraphBase
{
private:
    friend class Edge;
    std::vector<std::string> vectorVertex;
    std::vector<Edge*> compsGraph;

public:
    //Constructer for graph class
    Graph() 
    {
    };
    //Destructer for graph class
    ~Graph()
    {
        compsGraph.erase(compsGraph.begin(), compsGraph.end());
    };
    void DispalyShortestPath(std::map<std::string, std::string> startLabel, std::string endLabel, std::vector<std::string>& path);
    
    //Calculates the shortest path between the vertex with startLabel and the vertex with endLabel using Dijkstra's Algorithm.
    //A vector is passed into the method that stores the shortest path between the vertices.
    //The return value is the sum of the edges between the start and end vertices on the shortest path.
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string>& path);
   
    //Removes the vertex with label from the graph. Also removes the edges between that vertex and the other vertices of the graph.
    void removeVertex(std::string label);
   
    //Adds an edge of value weight to the graph between the vertex with label1 and the vertex with label2.
    //A vertex with label1and a vertex with label2 must both exist, there must not already bean edge between those vertices, 
    //and a vertex cannot have an edge to itself.
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    
    //Creates and adds a vertex to the graph with label. No two vertices should have the same label
    void addVertex(std::string label);
    
    //Removes the edge from the graph between the vertex with label1and the vertex with label2.
    //A vertex with label1and a vertex with label2 must both existand there must be an edge between those vertices
    void removeEdge(std::string label1, std::string label2);
};

#endif