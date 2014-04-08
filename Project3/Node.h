#pragma once

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
	r,
	d,
	l
}direction;

// create a "mouse" to use
typedef struct mouse
{
	int coord[2];
	direction cardinal;
	double fitness;
	int board[32][32];
}mouse;

#define TERMS 3
#define NON_TERMS 3
#define MAX_DEPTH 3

int BOARD[][32];

class Node
{
public:
	
	Node(op);
	
	~Node(void);
	
	int id;

	int size;

	double fit;

	int board[32][32];

	op op_type;
	
	Node* parent;

	Node* children[3];

	int size_of( Node* );

	Node * copy( Node* );

	Node * get_node( int );

	void Full(int, Node*);

	void Fitness( int&, mouse&);

	void print_tree( int );

	void erase(void);

	double eval(Node*, double);
};