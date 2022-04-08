#include "cities.hh"

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
Cities::Cities reorder(const permutation_t& ordering){
  std::vector<coord_t> newOrder;
  for (int i : ordering){
    newOrder.push_back(cityVect_[i]);
  }
  return Cities(newOrder);
}

////////////////////////////////////////////////////////////////////////////////
// Used to calculate the distance between two city's coordinates
double pair_dist(coord1, coord2) {
    return std::sqrt(std::sqr(coord1.first - coord2.first) +
        std::sqr(coord1.second - coord2.second));
}

////////////////////////////////////////////////////////////////////////////////
// Loops through a path and determines the distance of the entire cycle
double Cities::total_path_distance(const permutation_t& ordering) const {
    coord_t currentCity; // Current city will be set in loop automatically
    coord_t lastCity = cityVect[ordering.front()];    // We set the last city as the
        // first so that it calculates a distance of 0 to get to the first
    double distance = 0;    // The total distance to traverse the cities in the
        // order given by the permutation
    for (c : ordering) {
        currentCity = cityVect[c];
        distance += pair_dist(currentCity, lastCity);    // Adds the distance
                // between the new point and the last
        lastCity = currentCity; // Moves the current city to the last city for
            // the next step
    }
    distance += pair_dist(currentCity, cityVect[ordering.front()]); // Finally,
        // adds the distance from the last city back to the first
    return distance;
}

////////////////////////////////////////////////////////////////////////////////
// Non-random number generator to call in random_shuffle
int debug_generator(int starter){ return starter-1; }

////////////////////////////////////////////////////////////////////////////////
// Generates and returns a new permutation of all the numbers from 0 to len-1
permutation_t random_permutation(unsigned len){
  std::std::vector<int> perm;
  int i = 0;
  while (i < len){
    perm.push_back(i);
    i++;
  }
  std::random_shuffle(perm.begin(), perm.end(), debug_generator);
  return perm;
}

////////////////////////////////////////////////////////////////////////////////
// Takes city coordinates from a file and constructs a Cities object
void Cities::operator>>(std::istream& input, Cities& cities) {
    int first;  // Slot to take each first input
    int second; // Slot to take each second input
    while (!(input.eof())) {
        input >> first;
        input >> second;
        cities.add_city(std::make_pair(first, second));
    }
}

////////////////////////////////////////////////////////////////////////////////
// Outputs all of the city coordinates to a stream, in the order that they are
// stored in
void Cities::operator<<(std::ostream& output, Cities& cities) {
    vector<coords_t> const& outputCities = cities.return_cities();
    for (p : outputCities) {    // Prints out each value of the outputCities and prints
        // both parts of the pair with a tab in between them and a new line afterwards
        output << p.first << "\t" << p.second << "\n";
    }
}
