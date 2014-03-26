#pragma once
#include "Board.h"

typedef enum op
{
	if_food,
	prog2,
	prog3,
	Forward,
	Left,
	Right
}op;

typedef enum direction
{
	u,
	d,
	l,
	r
}direction;

#define TERMS 3
#define NON_TERMS 3
#define MAX_DEPTH 2

class Node
{
public:
	
	Node(op);
	
	~Node(void);

	direction cardinal;

	int coord[2];

	int size;

	double fitness;

	op op_type;
	
	Node* parent;

	Node* children[];

	int size_of( Node* );

	Node * copy( Node* );

	Node * get_node( int );

	void Full(int, Node*);

	double Fitness( Node*, int );

	void erase(void);

	double eval(Node*, double);
};