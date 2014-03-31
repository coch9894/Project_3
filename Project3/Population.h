#pragma once

#include "Node.h"

#define POP_SIZE 100
#define ELITES 2
#define N 5
#define SIZE 150
#define FILE_PRINT true

class Population
{
public:

	Population(void);

	~Population(void);

	void Evolve(int);

	void print_avgs();

	double get_best_fitness();

	double get_avg_fitness();

	double get_avg_size();

private:

	Node * pop[POP_SIZE];

	Node * gen[POP_SIZE];

	int best_index;

	double expected_fitness;

	double best_fitness;

	double avg_fitness;

	double avg_size;

	void calc_size();

	void calc_fitness();

	void print_avgs(int);

	void Select();

	void Crossover();

	void Mutate();

	void GenToPop();
};

