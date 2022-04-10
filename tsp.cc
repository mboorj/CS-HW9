#include "cities.hh"

int main(int argc, char* argv[]){
  if (argc < 2) { // Makes sure an input city file was provided in the command line
      std::cerr << "No File Provided\n";
      return 1;
  }
  std::filesystem::path inputCities {argv[1]};   // Sets up the file stream and makes sure it's valid
  std::ifstream readStream {inputCities};
  if (!readStream) {
      std::cerr << "Invalid File Name: " << inputCities.string();
      return 1;
  }
  Cities map;
  readStream >> map;    // Reads in the cities from the given file
  std::vector<unsigned int> shortestRoute;
  for (unsigned i = 0; i < map.return_cities().size(); ++i) {   // Creates the initial
      // route, starting at the first element and going straight through to the last
      shortestRoute.push_back(i);
  }
  double shortestLen = map.total_path_distance(shortestRoute);
  std::cout << "0\t" << shortestLen << "\n";    // Prints the distance of the original setup

  int someMax = 1000000;
  int i = 1;
  int len = map.return_cities().size();
  while (i < someMax){  // Repeatedly makes new random orderings and sees if they
    // have a shorter total distance than the previous one
    Cities::permutation_t newPerm = random_permutation(len);
    double newLength = map.total_path_distance(newPerm);
    if (newLength < shortestLen){
      shortestLen = newLength;
      shortestRoute = newPerm;
      std::cout << i << "\t" << shortestLen << "\n"; // prints the new shortest length
        // and at what iteration it was found
    }
    i++;
  }
  Cities finalCityOrder = map.reorder(shortestRoute); // Gets the final best ordering
    // of them so we can output it

  std::filesystem::path outputOrder {"shortest.tsv"};   // Sets up an output stream
    // to the file "shortest.tsv" and writes the shortest route found to it
  std::ofstream outputOrderStream {outputOrder};
  outputOrderStream << finalCityOrder;

  return 0;
}
