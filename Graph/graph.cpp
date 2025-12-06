#include "../headers/graph.hpp"

class GraphRoute{
    private:
     
     std::unordered_map<std::string, Location> location;
     std::unordered_map<std::string, std::vector<Route>> adjacency;

    public:
    
     void addLocation(std::string id, std::string name, double x, double y, char type){
         location[id] = Location{id,name,x,y,type};
         adjacency[id] = std::vector<Route>();


     }
     void addRoute(std::string fromId, std::string toId){
          if(location.find(fromId)==location.end() || location.find(toId)==location.end()){
              std::cout<<"Error : one or both location don't exist !"<<std::endl;
          }
       

          double distance=calculateDistance(fromId,toId);
          double time= distance * 0.4;
         
          Route route(fromId,toId,distance,time);
          adjacency[fromId].push_back(route);

          std::cout << "Route added: " << fromId << " → " << toId 
                  << " (" << distance << " units, " << time << " min)\n";
     }
     double calculateDistance(std::string id1, std::string id2){
        const Location& loc1=location[id1];
        const Location& loc2=location[id2];
        double dx=loc1.x - loc2.x;
        double dy=loc1.y - loc2.y;
        return sqrt(dx*dx + dy*dy);
          
     }

     std::vector<Route>& getNeighbor(std::string nodeId){
        return adjacency[nodeId];
     }

    Location& getLocation(std::string nodeId){
        return location[nodeId];
     }


};
