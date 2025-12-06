#include "./Graph/graph.cpp"



int main(){
    GraphRoute g1;
    g1.addLocation("pizza_place","Pizza Place",10,20,'R');
    g1.addLocation("alice_place","Alice",0,10,'C');

    g1.addRoute("pizza_place","alice_place");
 

   std::vector route1= g1.getNeighbor("pizza_place");

   for(auto it : route1){
    std::cout << "To: " << it.to 
              << ", Distance: " << it.distance 
              << ", Time: " << it.time << std::endl;
}

   Location& l1= g1.getLocation("pizza_place");

   std::cout<<l1.x<<" "<<l1.y<<std::endl;
    
}