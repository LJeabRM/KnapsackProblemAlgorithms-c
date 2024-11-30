#ifndef GA_H
#define GA_H

#include "Item.h"

// Updated function declaration
int genetic_algorithm(int capacity, Item* items, int num_items, 
                      int population_size, int generations, 
                      double mutation_rate, int elitism_count);

#endif // GA_H
