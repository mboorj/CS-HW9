#include "cities.hh"
#include <algorithm>
////////////////////////////////////////////////////////////////////////////////
// constructor, creates vector of coordinates
Cities::Cities(std::vector<coord_t> cities)
  :cityVect_(cities)
{}

////////////////////////////////////////////////////////////////////////////////
// Given a permutation, return a new Cities object where the order of the
// cities reflects the original order of this class after reordering with
// the given ordering. So for example, the ordering { 1, 0 } simply swaps
// the first two elements (coordinates) in the new Cities object.
Cities Cities::reorder(const permutation_t& ordering) const {
  std::vector<coord_t> newOrder;
  for (int i : ordering){
    newOrder.push_back(cityVect_[i]);
  }
  return Cities(newOrder);
}

////////////////////////////////////////////////////////////////////////////////
// Used to calculate the distance between two city's coordinates
double pair_dist(Cities::coord_t coord1, Cities::coord_t coord2) {
    return std::sqrt(((coord1.first - coord2.first) * (coord1.first - coord2.first))
        + ((coord1.second - coord2.second) * (coord1.second - coord2.second)));
}

////////////////////////////////////////////////////////////////////////////////
// Loops through a path and determines the distance of the entire cycle
double Cities::total_path_distance(const permutation_t& ordering) const {
    coord_t currentCity; // Current city will be set in loop automatically
    coord_t lastCity = cityVect_[ordering.front()];    // We set the last city as the
        // first so that it calculates a distance of 0 to get to the first
    double distance = 0;    // The total distance to traverse the cities in the
        // order given by the permutation
    for (auto &c : ordering) {
        currentCity = cityVect_[c];
        distance += pair_dist(currentCity, lastCity);    // Adds the distance
                // between the new point and the last
        lastCity = currentCity; // Moves the current city to the last city for
            // the next step
    }
    distance += pair_dist(currentCity, cityVect_[ordering.front()]); // Finally,
        // adds the distance from the last city back to the first
    return distance;
}

////////////////////////////////////////////////////////////////////////////////
// Non-random number generator to call in random_shuffle for testing, depreciated
int debug_generator(int starter){ return starter-1; }

////////////////////////////////////////////////////////////////////////////////
// Random number generator to call in random_shuffle in random_permutation, depreciated
int random_generator(int starter){
  std::default_random_engine generator;
  std::uniform_int_distribution<int> distribution(0, starter);
  return distribution(generator);
}

////////////////////////////////////////////////////////////////////////////////
// Generates and returns a new permutation of all the numbers from 0 to len-1
Cities::permutation_t random_permutation(unsigned len){
  std::vector<unsigned int> perm;
  unsigned i = 0;
  while (i < len){
    perm.push_back(i);
    i++;
  }

  std::random_device rd;
  std::mt19937 g(rd()); // uses computer's randomization device to get create a random number generator

  std::shuffle(perm.begin(), perm.end(), g); // creates a random permutation on numbers 0 to len-1
  return perm;
}

////////////////////////////////////////////////////////////////////////////////
// Takes city coordinates from a file and constructs a Cities object
std::istream& operator>>(std::istream& input, Cities& cities) {
    int first;  // Slot to take each first input
    int second; // Slot to take each second input
    input >> first; // Runs the first reads beforehand so that we can have
        // the others at the end of the loop. That way we don't have to risk
        // still running the loop while reading invalid data
    input >> second;
    while (!(input.eof())) {
        cities.add_city(std::make_pair(first, second));
        input >> first;
        input >> second;
    }
    return input;
}

////////////////////////////////////////////////////////////////////////////////
// Outputs all of the city coordinates to a stream, in the order that they are
// stored in
std::ostream& operator<<(std::ostream& output, Cities& cities) {
    std::vector<Cities::coord_t> const& outputCities = cities.return_cities();
    for (auto &p : outputCities) {    // Prints out each value of the outputCities and prints
        // both parts of the pair with a tab in between them and a new line afterwards
        output << p.first << "\t" << p.second << "\n";
    }
    return output;
}
