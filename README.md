# CS-HW9
Worked on by Mollie Boor and Tiago Beck.

We included a makefile for easy construction.
### Cities
- **constructor:** available as default constructor, or taking a vector of pairs. Stores the vector of pairs as the member cityVect_
- **reorder:** takes a vector of integers and returns an Cities object identical to the one it was called on but with the cities in it ordered in accordance with the vector given
- **pair_dist:** applies the distance formula to two city coordinates.
- **total_path_dist:** takes a route and calculates and sums the length of each edge in the cycle.
- **random_permutation:** constructs a vector from 0 to one fewer than the total number of cities, then uses the computer's random device to shuffle the elements.
- **add_city:** pushes a single city to the back of a Cities object.
- **operator>>:** reads pairs from a file, pushes them into the back of a Cities object.
- **operator<<:** puts the current ordering of coodinates into a file.
### tsp.cc
The main function first checks that it recieved a valid file as input, then initalizes an empty Cities object. The .tsv file is read into the Cities object and the current shortest route is set to the default order given by the file. The, the function loops through random permutations on the Cities object. If the route of the current permutation is shorter than the currently-saved route, the permutation number and length are printed to the console and the ordering is saved. When the loop is finished, the coordinates for the shortest route are saved to a new .tsv file.
