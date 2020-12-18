//This project has been created by Dev Tejwani and Barath Dandu
#include <string>
#include <vector>
#include <queue>
#include "Graph.hpp"
#include <map>

//This function is used to print the shortest path
void Graph::DispalyShortestPath(std::map<std::string, std::string> vertexLabeled, std::string endLabel, std::vector<std::string>& path)
{
    if (vertexLabeled[endLabel] == strEmpty)
    {
        return;
    }
    DispalyShortestPath(vertexLabeled, vertexLabeled[endLabel], path);//recurring function
    path.push_back(endLabel);
};


unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string>& path)
{
    std::map<std::string, int> weightMap;
    std::map<std::string, std::string> vertexLabeled;
    std::priority_queue< std::pair<int, std::string>, std::vector <std::pair<int, std::string> >,
        std::greater<std::pair<int, std::string> > > priorityQueue;

    for (auto label : vectorVertex)
    {
        vertexLabeled[label] = strEmpty;
        weightMap[label] = INF;
    }

    priorityQueue.push(make_pair(0, startLabel));
    weightMap[startLabel] = 0;

    while (!priorityQueue.empty())
    {
        std::string labelsTop = priorityQueue.top().second;
        priorityQueue.pop();

        std::string presentVertex;

        for (auto sideNeigh : compsGraph)
        {
            if (sideNeigh->str1 == labelsTop)
            {
                presentVertex = sideNeigh->str2;
            }
            else if (sideNeigh->str2 == labelsTop)
            {
                presentVertex = sideNeigh->str1;
            }
            else
            {
                continue;
            }
            int tmpweight = sideNeigh->weightEdge;
            if (weightMap[labelsTop] + tmpweight < weightMap[presentVertex])
            {
                vertexLabeled[presentVertex] = labelsTop;
                weightMap[presentVertex] = weightMap[labelsTop] + tmpweight;
                priorityQueue.push(make_pair(weightMap[presentVertex], presentVertex));
            }
        }
    }
    path.push_back(startLabel);
    DispalyShortestPath(vertexLabeled, endLabel, path);
    return weightMap[endLabel];
};

void Graph::removeVertex(std::string label)
{
    unsigned int i = 0;
    while (i < vectorVertex.size()) 
    {
        if (vectorVertex.at(i) == label) 
        {
            vectorVertex.erase(vectorVertex.begin() + i);
            unsigned int j = 0;
            while (j < compsGraph.size()) 
            {
                Edge* tmp = new Edge();
                tmp = compsGraph.at(j);
                if (tmp->str1 == label || tmp->str2 == label) 
                {
                    compsGraph.erase(compsGraph.begin() + j);
                }
                j++;
            }
        }
        i++;
    }
};

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) 
{
    bool str1Exists = false;
    bool str2Exists = false;

    unsigned int i = 0;
    while (i < vectorVertex.size()) 
    {
        if (vectorVertex.at(i) == label1)
        {
            str1Exists = true;
        }
        if (vectorVertex.at(i) == label2)
        {
            str2Exists = true;
        }
        i++;
    }

    if (str1Exists == true && str2Exists == true) 
    {
        Edge* nEdge = new Edge();
        nEdge->str1 = label1;
        nEdge->str2 = label2;
        nEdge->weightEdge = weight;
        compsGraph.push_back(nEdge);
    }
};

void Graph::addVertex(std::string label)
{
    unsigned int i = 0;
    while (i < vectorVertex.size())
    {
        if (vectorVertex.at(i) == label) { return; }
        i++;
    }
     vectorVertex.push_back(label);
};

void Graph::removeEdge(std::string label1, std::string label2)
{
    Edge *tmp = new Edge();
    unsigned int i = 0;
    while ( i < compsGraph.size()) 
    {
        tmp = compsGraph.at(i);
        if (tmp->str1 == label1 && tmp->str2 == label2)
        {
            compsGraph.erase(compsGraph.begin() + i);
        }
        i++;
    }
};

