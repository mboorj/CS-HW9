#include "cities.hh"
#include <cmath>

double Cities::total_path_distance(const permutation_t& ordering) const {
    double pair_dist(coord1, coord2) {  // Used to calculate the distance between
        // two city's coordinates
        return std::sqrt(std::sqr(coord1.first - coord2.first) +
            std::sqr(coord1.second - coord2.second));
    }
    coord_t currentCity; // Current city will be set in loop automatically
    coord_t lastCity = cityVect_[ordering.front()];    // We set the last city as the
        // first so that it calculates a distance of 0 to get to the first
    double distance = 0;    // The total distance to traverse the cities in the
        // order given by the permutation
    for (c : ordering) {
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
