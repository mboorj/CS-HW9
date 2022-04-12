/*
 * API file for Travelling-Salesperson Cities class and utilities
 */

#pragma once

#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <random>


// Representation of an ordering of cities
class Cities {
 public:
  // A pair of integral coordinates for each city
  using coord_t = std::pair<int, int>;

  // An ordering of cities. Each value represents a unique index
  // into the current city ordering in some container.
  using permutation_t = std::vector<unsigned int>;

  Cities() = default;   // Still allows forming of a blank Cities object
  Cities(std::vector<coord_t> cities);  // Defines a constructor  that takes a
    // vector of coordinates

  // Given a permutation, return a new Cities object where the order of the
  // cities reflects the original order of this class after reordering with
  // the given ordering. So for example, the ordering { 1, 0 } simply swaps
  // the first two elements (coordinates) in the new Cities object.
  Cities reorder(const permutation_t& ordering) const;

  // For a given permutation of the cities in this object,
  // compute how long (distance) it would take to traverse all the cities in the
  // order of the permutation, and then returning to the first city.
  // The distance between any two cities is computed as the Euclidean
  // distance on a plane between their coordinates.
  double total_path_distance(const permutation_t& ordering) const;

  // An accessor to push a city into the cityVect_ of the object
  void add_city(const coord_t newCity);
  // An accessor to get a read only reference to the cityVect_ to look at the
  // cities in it
  const std::vector<coord_t>& return_cities() const {return cityVect_;}
 private:
    std::vector<coord_t> cityVect_;
};

// Even though the input and output functions for this are not methods, it is necessary
// to first define them here in the header so that they can be used in other files
// that use the header
std::istream& operator>>(std::istream& input, Cities& cities);
std::ostream& operator<<(std::ostream& output, Cities& cities);

// Same for random_permutation
Cities::permutation_t random_permutation(unsigned len);
