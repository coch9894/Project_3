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
}mouse;

#define TERMS 3
#define NON_TERMS 3
#define MAX_DEPTH 2

class Node
{
public:
	
	Node(op);
	
	~Node(void);

	int size;

	int board[32][32];

	op op_type;
	
	Node* parent;

	Node* children[3];

	int size_of( Node* );

	Node * copy( Node* );

	Node * get_node( int );

	void Full(int, Node*);

	void Fitness( int&, mouse&);

	void erase(void);

	double eval(Node*, double);
};