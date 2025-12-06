#include <string>
#include <vector>
#include <unordered_map>

struct Route{
    
    std::string from, to;
    double distance;
    double time; 

};


struct Location{

    std::string id;
    std::string name;
    char type;

};



class GraphRoute{
    private:
     
     std::unordered_map<std::string, Location> location;
     std::unordered_map<std::string, std::vector<Route>> adjacency;

    public:
    
     void addLocation(std::string id, std::string name, int x, int y, char type);
     void addRoute(std::string from, std::string to);
     double calculateDistance(std::string id1, std::string id2);


};