#include "cities.hh"

void Cities::operator>>(std::istream& input, Cities& cities) {
    int first;  // Slot to take each first input
    int second; // Slot to take each second input
    while (!(input.eof())) {
        input >> first;
        input >> second;
        cities.add_city(std::make_pair(first, second));
    }
}

void Cities::operator<<(std::ostream& output, Cities& cities) {
    vector<coords_t> const& outputCities = cities.return_cities();
    for (p : outputCities) {    // Prints out each value of the outputCities and prints
        // both parts of the pair with a tab in between them and a new line afterwards
        output << p.first << "\t" << p.second << "\n";
    }
}
