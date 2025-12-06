#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>
#include <unordered_set>  
#include <limits>        
#include <algorithm>      
#include "Dijkstra.hpp"


struct Location {
    std::string id;
    std::string name;
    char type;
    double x, y;

    Location()=default;
   
    Location(std::string id, std::string name, double x, double y, char type)
        : id(id), name(name), type(type), x(x), y(y) {}  
};

struct Route {
    std::string from, to;
    double distance;
    double time; 

    Route()=default;

    Route(std::string from, std::string to, double distance, double time)
        : from(from), to(to), distance(distance), time(time) {} 
};



