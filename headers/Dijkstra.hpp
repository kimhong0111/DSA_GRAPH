#include <vector>

struct pathToResult{
  std::vector<std::string>path;
  double totalTime;
  double totalDistance;
  bool found;

  void print(){
     if(!found){
        std::cout<<"No path Found"<<std::endl;
     }
     std::cout<<"Shortest path found \n";
     for(int i=0;i<path.size();i++){
         std::cout<<path[i];
         if(i<path.size()-1){
           std::cout<<"---";
         }
        }
        std::cout<<"\n";
        std::cout<<"Total Distance "<<totalDistance<<std::endl;
        std::cout<<"Total Time "<<totalDistance<<std::endl;


        
     


  }
};