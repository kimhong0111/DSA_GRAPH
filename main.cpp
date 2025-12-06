 #include "./Graph/graph.cpp"
  using namespace std;

int main(){
    GraphRoute g1;
    g1.addLocation("pizza_place","Pizza Place",11,6,'R');
    g1.addLocation("alice_place","Alice",10,5,'C');
    g1.addLocation("cafe_place","Cafe",12,7,'R');
    g1.addLocation("burger_place","Burger King",10,10,'R');
    g1.addLocation("Kimhong_place","kimhong",28,32,'C');

    g1.addRoute("pizza_place","cafe_place");
    g1.addRoute("burger_place","alice_place");
    g1.addRoute("pizza_place","burger_place");
    g1.addRoute("cafe_place","alice_place");
    g1.addRoute("cafe_place","Kimhong_place");
    g1.addRoute("burger_place","Kimhong_place");


   std::vector<Route> route1= g1.getNeighbor("burger_place");
   
   
   for(auto it : route1){
    
    std::cout << "To: " << it.to 
              << ", Distance: " << it.distance 
              << ", Time: " << it.time << std::endl;
}
   cout<<"\n";
   cout<<"Show the shortestPath"<<endl;

    pathToResult  r1 = g1.FindShortestPath("pizza_place", "Kimhong_place");
    r1.print();
    

    
    return 0;
}
