#include "../headers/graph.hpp"
#include <queue>

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
          double price = distance * 0.1;
         
          Route route(fromId,toId,distance,time,price);
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
        if(adjacency.find(nodeId)==adjacency.end()){
            std::cout<<"current place doesn't exist"<<std::endl;
        }
        else if(adjacency[nodeId].size()==0){
           std::cout<<"There is no neighbor"<<std::endl;
        }
        return adjacency[nodeId];
     }

    Location& getLocation(std::string nodeId){
        if(location.find(nodeId)==location.end()){
            std::cout<<"current place doesn't exist"<<std::endl;
        }
        return location[nodeId];
     }

     pathToResult FindShortestPath(std::string startId , std::string endId){
         pathToResult result;
         result.found=false;
             if(location.find(startId)==location.end() || location.find(endId)==location.end()){
                std::cout<<"One place or Both places don't exist !"<<std::endl;
             }

             if(startId==endId){
                result.path= {startId};
                result.totalDistance=0;
                result.totalTime=0;
                result.found=true;

                return result;

             }

            const  double INF=std::numeric_limits<double>::max();
            std::unordered_map<std::string,double> distances;
            std::unordered_map<std::string ,std::string> previous;
            std::unordered_set<std::string> visited;

             for(const  auto&[id,loc] : location){
                distances[id]=INF;
             }
             using queueItem = std::pair<double,std::string>;
             std::priority_queue<queueItem,std::vector<queueItem>,std::greater<queueItem>> pq;

             distances[startId]=0;
             pq.push({0,startId});
             while(!pq.empty()){
                const auto [currentDistance, currentId] = pq.top();
                pq.pop();

                if(visited.find(currentId)!=visited.end()){
                    continue;
                }

                visited.insert(currentId);

                if(currentId==endId){
                    break;
                }

                for(Route& route : adjacency[currentId] ){
                    std::string neigborId = route.to;
                    if(visited.find(neigborId)!=visited.end()){
                        continue;
                    }
                    double  newDist = currentDistance + route.distance;
                   if(newDist < distances[neigborId]){
                       distances[neigborId]=newDist;
                       previous[neigborId]=currentId;
                       pq.push({newDist, neigborId});
                   }

                }
             }

         if (distances[endId] == INF) {
            std::cout << "No path from " << startId << " to " << endId << "!\n";
            return result;
        }

     

     std::vector<std::string> backwardPath;
     std::string current = endId;

     while(current!=startId){
         backwardPath.push_back(current);
         current=previous[current];
     }

     backwardPath.push_back(startId);
     std::reverse(backwardPath.begin(),backwardPath.end());

     double totalTime=0;
     double totalDist=0;
     double totalPrice=0;
     for(int i=0;i<backwardPath.size()-1;i++){
         std::string from=backwardPath[i];
         std::string to=backwardPath[i+1];
         
         bool foundRoute=false;
         if(adjacency.find(from)!=adjacency.end()){
             for(const Route& route :adjacency[from]){
                 if(route .to==to){
                    totalDist+=route.distance;
                    totalTime+=route.time;
                    totalPrice+=route.price;
                    foundRoute=true;
                 }
             }
         }

          if (!foundRoute) {
                std::cout << "Warning: Missing route between " 
                          << from << " and " << to << "\n";
            }
        }
        
        result.path = backwardPath;
        result.totalDistance = totalDist;
        result.totalTime = totalTime;
        result.totalPrice=totalPrice;
        result.found = true;
        
        return result;

    }

     
   
};
