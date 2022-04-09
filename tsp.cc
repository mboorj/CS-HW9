#include "cities.hh"

int main(){
  Cities map;
  // read cities in from file somehow
  auto shortestLen = map.total_path_distance(); // print "0" + tab + len
  auto shortestRoute = map;

  int someMax;
  int i = 1;
  int len = map.return_cities().size();
  while (i < someMax){
    auto newPerm = random_permutation(len)
    auto newCities = map.reorder(newPerm);
    auto newLength = newCities.total_path_distance();
    if (newLength <= shortestLen){
      shortestLen = newLength;
      shortestRoute = newCities;
      // print i + tab + len
    }
    i++;
  }
  // when this loop is done, read shortestRoute out to a file somehow
}
