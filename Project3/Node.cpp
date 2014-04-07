#include "StdAfx.h"
#include "Node.h"

int BOARD[][32] = { { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0 },
					{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
					{ 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0 },
					{ 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
				};

Node::Node(op type)
{
	op_type = type;
	
	for( int i = 0; i < 3; i++ )
	{
		children[i] = NULL;
	}

	for( int i = 0; i < 32; i++ )
	{
		for( int j = 0; j < 32; j++ )
		{
			board[i][j] = BOARD[i][j];
		}
	}

	id = -2;
}

Node::~Node(void)
{
}

int Node::size_of( Node * t )
{
	int count = 0;
	int temp = 1;
	while(count < 3)
	{
		if( t->children[count] != NULL )
		{
			temp += size_of( t->children[count] );
		}
		else //( t->children[count] == NULL )
		{
			temp = 1;
		}
		count++;
	}
	size = temp;
	return temp;
}

Node * Node::copy( Node * t )
{
	Node * temp;
	switch(t->op_type)
	{
	case if_food:
		temp = new Node(if_food);
		break;
	case prog2:
		temp = new Node(prog2);
		break;
	case prog3:
		temp = new Node(prog3);
		break;
	case Forward:
		temp = new Node(Forward);
		break;
	case Left:
		temp = new Node(Left);
		break;
	case Right:
		temp = new Node(Right);
		break;
	default:
		cout << "ERROR, WHIL WHEATON WAS HERE!" << endl;
		cin >> t->size;
		exit(-1);
	}

	temp->op_type = t->op_type;
	temp->fit = t->fit;
	temp->parent = t->parent;
	temp->size = t->size;
	temp->id = t->id;
	for( int i = 0; i < 32; i++ )
	{
		for( int j = 0; j < 32; j++ )
		{
			temp->board[i][j] = t->board[i][j];
		}
	}

	int count = 0;
	while( count < 3 )
	{
		if( t->children[count] != NULL )
		{
			temp->children[count] = t->copy(t->children[count]);
		}
		else
		{
			temp->children[count] = NULL;
		}
		count++;
	}

	return temp;
}

Node * Node::get_node( int t )
{
	queue<Node*> Que;

	if( t == 0 )
	{
		return this;
	}
	else
	{
		Que.push(this);
		Node * temp;
		while( t != 0 )
		{
			temp = Que.front();
			Que.pop();
			if( temp->children[0] != NULL )
			{
				Que.push(temp->children[0]);
			}
			if( temp->children[1] != NULL )
			{
				Que.push(temp->children[1]);
			}
			if( temp->children[2] != NULL )
			{
				Que.push(temp->children[2]);
			}
			t--;
		}
		while( !Que.empty() )
		{
			Que.pop();
		}
		return temp;
	}
	return 0;
}

void Node::Fitness( int &ts, mouse &m )
{
	switch( op_type )
	{
	case if_food:		// IF FOOD
		ts--;

		switch( m.cardinal )
		{
		case u:
			if( m.board[(m.coord[0]-1+32)%32][m.coord[1]] == 1 )
			{
				children[0]->Fitness(ts, m);
			}
			else
			{
				children[1]->Fitness(ts, m);
			}
			break;

		case d:
			if( m.board[(m.coord[0]+1+32)%32][m.coord[1]] == 1 )
			{
				children[0]->Fitness(ts, m);
			}
			else
			{
				children[1]->Fitness(ts, m);
			}
			break;

		case l:
			if( m.board[m.coord[0]][(m.coord[1]-1+32)%32] == 1 )
			{
				children[0]->Fitness(ts, m);
			}
			else
			{
				children[1]->Fitness(ts, m);
			}
			break;

		case r:
			if( m.board[m.coord[0]][(m.coord[1]+1+32)%32] == 1 )
			{
				children[0]->Fitness(ts, m);
			}
			else
			{
				children[1]->Fitness(ts, m);
			}
			break;
		}
		break;

	case prog2:			// EITHER PROG
	case prog3:
		ts--;
		children[0]->Fitness(ts,m);
		ts--;
		children[1]->Fitness(ts,m);
		if( op_type == prog3 )
		{
			ts--;
			children[2]->Fitness(ts,m);
		}
		break;

	case Forward:		// FORWARD
		ts--;

		switch( m.cardinal )
		{
		case u:
			m.coord[0] = (m.coord[0] - 1+32) % 32;
			break;

		case d:
			m.coord[0] = (m.coord[0] + 1+32) % 32;
			break;

		case l:
			m.coord[1] = (m.coord[1] - 1+32) % 32;
			break;

		case r:
			m.coord[1] = (m.coord[1] + 1+32) % 32;
			break;
		default:
			cout << "BAD FITNESS VALUES!" << endl;
			cin >> ts;
			exit(-1);
		}

		if( m.board[m.coord[0]][m.coord[1]] == 1 )
		{
			m.board[m.coord[0]][m.coord[1]] = 2;
			m.fitness++;
		}
		else
		{
			// penalty if I have time
			if( m.board[m.coord[0]][m.coord[1]] != 2)
				m.board[m.coord[0]][m.coord[1]] = 3;
		}
		break;

	case Left:			// LEFT
		ts--;

		switch( m.cardinal )
		{
		case u:
			m.cardinal = l;
			break;

		case d:
			m.cardinal = r;
			break;

		case l:
			m.cardinal = d;
			break;

		case r:
			m.cardinal = u;
			break;
		}

		break;

	case Right:			// RIGHT
		ts--;

		switch( m.cardinal )
		{
		case u:
			m.cardinal = r;
			break;

		case d:
			m.cardinal = l;
			break;

		case l:
			m.cardinal = u;
			break;

		case r:
			m.cardinal = d;
			break;
		}

		break;
	}
}

void Node::Full( int depth, Node* p)
{
	parent = p;
	if( parent == NULL )
	{
		id = -1;
	}

	if( depth >= 1 )
	{
		depth--;

		int count = 0;

		while( count < 3 )
		{

			int r = rand() % NON_TERMS;

			switch( r )
			{
			case if_food:			
				children[count] = new Node(if_food);
				children[count]->Full(depth, this);
				break;
			case prog2:
				children[count] = new Node(prog2);
				children[count]->Full(depth, this);
				break;
			case prog3:
				children[count] = new Node(prog3);
				children[count]->Full(depth, this);
				break;
			default:
				cout << "THIS IS BROKEN" << endl;
				cin >> count;
				exit(-1);
				break;
			}

			switch( count )
			{
			case 0:
				children[count]->id = 0;
				break;
			case 1:
				children[count]->id = 1;
				break;
			case 2:
				children[count]->id = 2;
				break;
			}

			children[count]->parent = this;
			count++;
		}
	}
	else // depth == 0 add the leafs
	{
		depth--;

		int count = 0;

		while( count < 3 )
		{

			int r = rand() % TERMS;
			r = r + NON_TERMS;

			switch( r )
			{
			case Forward:			
				children[count] = new Node(Forward);
				break;
			case Left:
				children[count] = new Node(Left);
				break;
			case Right:
				children[count] = new Node(Right);
				break;
			default:
				cout << "THIS IS BROKEN" << endl;
				cin >> count;
				exit(-1);
				break;
			}

			switch( count )
			{
			case 0:
				children[count]->id = 0;
				break;
			case 1:
				children[count]->id = 1;
				break;
			case 2:
				children[count]->id = 2;
				break;
			}

			children[count]->parent = this;
			count++;
		}
	}
}

void Node::print_tree(int indent)
{
	switch( op_type )
	{
	case if_food:
		cout << "IF" << endl;
		for( int i = indent; i > 0; i-- )
			cout << " ";
		children[0]->print_tree(indent+1);
		for( int i = indent; i > 0; i-- )
			cout << " ";
		children[1]->print_tree(indent+1);
		cout << endl;
		break;
	case prog2:
		cout << "P2" << endl;
		for( int i = indent; i > 0; i-- )
			cout << " ";
		children[0]->print_tree(indent+1);
		for( int i = indent; i > 0; i-- )
			cout << " ";
		children[1]->print_tree(indent+1);
		cout << endl;
		break;
	case prog3:
		cout << "P3" << endl;
		for( int i = indent; i > 0; i-- )
			cout << " ";
		children[0]->print_tree(indent+1);
		for( int i = indent; i > 0; i-- )
			cout << " ";
		children[1]->print_tree(indent+1);
		for( int i = indent; i > 0; i-- )
			cout << " ";
		children[2]->print_tree(indent+1);
		cout << endl;
		break;
	case Forward:
		cout << "F" << endl;
		break;
	case Left:
		cout << "L" << endl;
		break;
	case Right:
		cout << "R" << endl;
		break;
	}
}

void Node::erase()
{
	for( int i = 0; i < 3; i++ )
	{
		if( children[i] != NULL )
		{
			children[i]->erase();
			children[i] = NULL;
			delete children[i];
		}
	}
}