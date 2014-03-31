#include "StdAfx.h"
#include "Population.h"

Population::Population(void)
{
	// Set the population up with random individuals

	int count = 0;
	while( count < POP_SIZE )
	{
		int type = rand() % NON_TERMS;

		switch(type)
		{
		case if_food:
			pop[count] = new Node(if_food);
			break;
		case prog2:
			pop[count] = new Node(prog2);
			break;
		case prog3:
			pop[count] = new Node(prog3);
			break;
		}

		pop[count]->Full(MAX_DEPTH,NULL);

		count++;
	}

	expected_fitness = 0;
	for( int i = 0; i < 32; i++ )
	{
		for( int j = 0; j < 32; j++ )
		{
			if( pop[0]->board[i][j] == 1 )
			{
				expected_fitness++;
			}
		}
	}

	calc_size();

	// Set avg_fitness

	calc_fitness();

}

Population::~Population(void)
{
	// erase the whole pop
	int count = 0;
	while( count < POP_SIZE )
	{
		pop[count]->erase();
		delete pop[count];
	}
}

void Population::calc_fitness()
{
	// avg / best / expected
	avg_fitness = 0;
	best_fitness = 0;
	// mouse
	mouse m;
	m.cardinal = r;
	m.coord[0] = 0;
	m.coord[1] = 0;
	m.fitness = 0;
	// how long do we go?
	int TS = 600;

	// loop through summing then divide by total individuals

	for( int k = 0; k < POP_SIZE; k++ )
	{
		int ts = TS;

		for( int i = 0; i < 32; i++ )
		{
			for( int j = 0; j < 32; j++ )
			{
				pop[k]->board[i][j] = BOARD[i][j];
			}
		}

		mouse m;
		m.cardinal = r;
		m.coord[0] = 0;
		m.coord[1] = 0;
		m.fitness = 0;

		if( pop[k]->board[m.coord[0]][m.coord[1]] == 1 )
		{
			m.fitness++;
			pop[k]->board[m.coord[0]][m.coord[1]] = 2;
		}
		else
		{
			if( pop[k]->board[m.coord[0]][m.coord[1]] != 2 )
			{
				pop[k]->board[m.coord[0]][m.coord[1]] = 3;
			}
		}

		while( ts > 0 )
		{
			pop[k]->Fitness(ts,m);
		}
		pop[k]->fit = m.fitness;

		/* testing
		if( k == POP_SIZE - 1 )
		{
			for( int i = 0; i < 32; i++ )
			{
				for( int j = 0; j < 32; j++ )
				{
					if( pop[k]->board[i][j] != 0 )
					{
						cout << pop[k]->board[i][j] << " ";
					}
					else
					{
						cout << "  ";
					}
				}
				cout << endl;
			}
			int temp;
			cin >> temp;
		}
		//*/

		if( m.fitness > best_fitness )
		{
			best_fitness = m.fitness;
			best_index = k;
		}
		avg_fitness += m.fitness;
	}
	avg_fitness = avg_fitness / POP_SIZE;
}

void Population::calc_size()
{
	// loop through summing then divide by total individuals
	avg_size = 0;
	for( int k = 0; k < POP_SIZE; k++ )
	{
		avg_size += pop[k]->size_of(pop[k]);
	}
	avg_size = avg_size / POP_SIZE;
}

double Population::get_best_fitness()
{
	calc_fitness();
	return best_fitness;
}

double Population::get_avg_fitness()
{
	// re-calculate before returning
	calc_fitness();
	return avg_fitness;
}

double Population::get_avg_size()
{
	// re-calculate before returning
	calc_size();
	return avg_size;
}

void Population::print_avgs()
{
	// calculate then print
	calc_size();
	calc_fitness();

	cout << "These are the average values:" << endl;
	cout << "Average Size: " << avg_size << endl;
	cout << "Average Fitness: " << avg_fitness << endl;
	cout << "Best Fitness: " << best_fitness << endl;
	cout << "Expected Fitness: " << expected_fitness << endl;
	cout << "The Board:" << endl;
	for( int i = 0; i < 32; i++ )
	{
		for( int j = 0; j < 32; j++ )
		{
			if( BOARD[i][j] != 0 )
				cout << BOARD[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	cout << "Solved Board: 2 is a hit, a 3 is a normal move" << endl;
	for( int i = 0; i < 32; i++ )
	{
		for( int j = 0; j < 32; j++ )
		{
			if( pop[best_index]->board[i][j] != 0 )
				cout << pop[best_index]->board[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void Population::print_avgs(int generation)
{
	// calculate then print
	calc_size();
	calc_fitness();

	cout << "These are the average values for generation:" << generation << endl;
	cout << "Average Size: " << avg_size << endl;
	cout << "Average Fitness: " << avg_fitness << endl;
	cout << "Best Fitness: " << best_fitness << endl;
	cout << "Expected Fitness: " << expected_fitness << endl;
	cout << "The Board:" << endl;

	/* testing
	for( int k = 0; k < POP_SIZE; k++ )
	{
		cout << pop[k]->fit << " ";
	}
	cout << endl;
	//*/
	
	pop[best_index]->print_tree(1);

	for( int i = 0; i < 32; i++ )
	{
		for( int j = 0; j < 32; j++ )
		{
			if( BOARD[i][j] != 0 )
				cout << BOARD[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
	cout << "Solved Board: 2 is a hit, a 3 is a normal move" << endl;
	cout << "Individual #" << best_index << ":" << endl;
	for( int i = 0; i < 32; i++ )
	{
		for( int j = 0; j < 32; j++ )
		{
			if( pop[best_index]->board[i][j] != 0 )
				cout << pop[best_index]->board[i][j] << " ";
			else
				cout << "  ";
		}
		cout << endl;
	}
}

void Population::Evolve(int generations)
{
	int generation = 0;
	
	// filename for graphs
	ofstream o;
	o.open("numbers.txt");
	// filename for fitnesses
	ofstream file;
	char sdate[9];
	char stime[9];
	_strdate_s(sdate);
	_strtime_s(stime);
	string filename = "results";
	filename.append(stime);
	filename.append("_");
	filename.append(sdate);
	filename.append(".txt");
	for(int i = 0; i < filename.length(); ++i)
	{
		if( filename[i] == '/' || filename[i] == ':')
		{
			filename[i] = '-';
		}
	}
	file.open(filename);

	while( generation <= generations )
	{

		calc_fitness();

		calc_size();

		if( generation % (generations / 10) == 0 )
		{
			print_avgs(generation);
		}

		if( FILE_PRINT )
		{
			file << avg_fitness << " " << best_fitness << endl;
			for( int i = 0; i < 32; i++ )
			{
				for( int j = 0; j < 32; j++ )
				{
					if( pop[best_index]->board[i][j] != 0 )
						o << pop[best_index]->board[i][j] << " ";
					else
						o << "  ";
				}
				o << endl;
			}
			o.close();
		}

		Select();

		Crossover();

		GenToPop();

		Mutate();

		generation++;
	}
}

void Population::Select()
{
	for( int i = 0; i < POP_SIZE - ELITES; i++ )
	{
		for( int j = 0; j < N; j++ )
		{
			int random = (int)rand() % POP_SIZE;

			if( j == 0 )
			{
				switch(pop[random]->op_type)
				{
				case if_food:			
					gen[i] = new Node(if_food);
					break;
				case prog2:
					gen[i] = new Node(prog2);
					break;
				case prog3:
					gen[i] = new Node(prog3);
					break;
				case Forward:			
					gen[i] = new Node(Forward);
					break;
				case Left:
					gen[i] = new Node(Left);
					break;
				case Right:
					gen[i] = new Node(Right);
					break;
				}

				gen[i] = pop[random]->copy(pop[random]);
			}
			else
			{

				if( pop[random]->fit < gen[i]->fit )
				{
					gen[i] = pop[random]->copy(pop[random]);
				}

			}
		}
	}
}

void Population::Crossover()
{
	for( int i = 0; i < POP_SIZE - ELITES; i+=2 )
	{
		Node * s1; // source 1
		Node * s2; // source 2
		Node * p1; // parent 1
		Node * p2; // parent 2
		int id1; // child ?
		int id2; // child ?

		int rand1 = (int)rand() % gen[i]->size; // which node to trade
		int rand2 = (int)rand() % gen[i+1]->size; // which node to trade

		s1 = gen[i]->get_node(rand1); // what we swap
		id1 = s1->id;

		s2 = gen[i+1]->get_node(rand2); // what we swap
		id2 = s2->id;

		p1 = s1->parent; // parent
		p2 = s2->parent; // parent

		if( p1 != NULL )
		{
			p1->children[id1] = s2;
			s2->id = id1;
			s2->parent = p1;
		}
		else
		{
			gen[i] = s2;
			s2->id = -1;
			s2->parent = NULL;
		}

		if( p2 != NULL )
		{
			p2->children[id2] = s1;
			s1->id = id2;
			s1->parent = p2;
		}
		else
		{
			gen[i+1] = s1;
			s1->id = -1;
			s1->parent = NULL;
		}
	}
}

void Population::Mutate()
{
	for( int i = 0; i < POP_SIZE - ELITES; i++ )
	{
		double prob = rand();
		if( prob < .1 )
		{
			int value = rand() % pop[i]->size;
			Node * swap = pop[i]->get_node(value);
			Node * p = swap->parent;
			Node * n;
			int id = swap->id;

			int type = rand() % NON_TERMS;
			
			switch(type)
			{
			case if_food:			
				n = new Node(if_food);
				break;
			case prog2:
				n = new Node(prog2);
				break;
			case prog3:
				n = new Node(prog3);
				break;
			case Forward:			
				n = new Node(Forward);
				break;
			case Left:
				n = new Node(Left);
				break;
			case Right:
				n = new Node(Right);
				break;
			}

			n->id = swap->id;
			int count = 0;
			while( count  < 3 )
			{
				n->children[count] = swap->copy(swap->children[count]);
			}
			swap->erase();
			swap = NULL;

			if( p != NULL )
			{
				p->children[id] = n;
				n->parent = p;
			}
			else
			{
				pop[i] = n;
				n->id = -1;
				n->parent = NULL;
			}
		}
	}
}

void Population::GenToPop()
{
	pop[POP_SIZE-1] = pop[best_index]->copy(pop[best_index]);
	best_index = POP_SIZE - 1;

	int i = 0;
	for( i = 0; i < POP_SIZE - ELITES; i++ )
	{
		pop[i] = gen[i]->copy(gen[i]);
	}
	while( i < POP_SIZE )
	{
		pop[i] = pop[POP_SIZE-1]->copy(pop[POP_SIZE-1]);
		i++;
	}

	calc_size();
	calc_fitness();
	//print_avgs();
}