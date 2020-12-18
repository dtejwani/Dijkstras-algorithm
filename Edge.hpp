//This project has been created by Dev Tejwani and Barath Dandu
#ifndef EDGE_H
#define EDGE_H
#include <string>
const std::string strEmpty = " ";

class Edge 
{
public:
    Edge()
    {
        str1 = strEmpty;
        str2 = strEmpty;
        weightEdge = 0;
    };
    ~Edge();
    unsigned long weightEdge;
    std::string str1;
    std::string str2;
};
#endif 