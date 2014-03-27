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
		else //( t->child[count] == NULL )
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
	}

	temp->op_type = t->op_type;
	temp->parent = t->parent;
	temp->size = t->size;

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
			//if( temp->child[0] != NULL )
			{
				//Que.push(temp->child[0]);
			}
			//if( temp->child[1] != NULL )
			{
				//Que.push(temp->child[1]);
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
	/* sanity check
	if( children[0] != NULL )
		children[0]->parent = this;
	if( children[1] != NULL )
		children[1]->parent = this;
	if( children[2] != NULL )
		children[2]->parent = this;
	//*/
	switch( op_type )
	{
	case if_food:		// IF FOOD
		ts--;

		switch( m.cardinal )
		{
		case u:
			if( board[(m.coord[0]-1+32)%32][m.coord[1]] == 1 )
			{
				for( int i = 0; i < 32; i++ )
				{
					for( int j = 0; j < 32; j++ )
					{
						children[0]->board[i][j] = board[i][j];
					}
				}
				children[0]->Fitness(ts, m);
			}
			else
			{
				for( int i = 0; i < 32; i++ )
				{
					for( int j = 0; j < 32; j++ )
					{
						children[1]->board[i][j] = board[i][j];
					}
				}
				children[1]->Fitness(ts, m);
			}
			break;

		case d:
			if( board[(m.coord[0]+1+32)%32][m.coord[1]] == 1 )
			{
				for( int i = 0; i < 32; i++ )
				{
					for( int j = 0; j < 32; j++ )
					{
						children[0]->board[i][j] = board[i][j];
					}
				}
				children[0]->Fitness(ts, m);
			}
			else
			{
				for( int i = 0; i < 32; i++ )
				{
					for( int j = 0; j < 32; j++ )
					{
						children[1]->board[i][j] = board[i][j];
					}
				}
				children[1]->Fitness(ts, m);
			}
			break;

		case l:
			if( board[m.coord[0]][(m.coord[1]-1+32)%32] == 1 )
			{
				for( int i = 0; i < 32; i++ )
				{
					for( int j = 0; j < 32; j++ )
					{
						children[0]->board[i][j] = board[i][j];
					}
				}
				children[0]->Fitness(ts, m);
			}
			else
			{
				for( int i = 0; i < 32; i++ )
				{
					for( int j = 0; j < 32; j++ )
					{
						children[1]->board[i][j] = board[i][j];
					}
				}
				children[1]->Fitness(ts, m);
			}
			break;

		case r:
			if( board[m.coord[0]][(m.coord[1]+1+32)%32] == 1 )
			{
				for( int i = 0; i < 32; i++ )
				{
					for( int j = 0; j < 32; j++ )
					{
						children[0]->board[i][j] = board[i][j];
					}
				}
				children[0]->Fitness(ts, m);
			}
			else
			{
				for( int i = 0; i < 32; i++ )
				{
					for( int j = 0; j < 32; j++ )
					{
						children[1]->board[i][j] = board[i][j];
					}
				}
				children[1]->Fitness(ts, m);
			}
			break;
		}
		break;

	case prog2:			// EITHER PROG
	case prog3:
		ts--;
		for( int i = 0; i < 32; i++ )
		{
			for( int j = 0; j < 32; j++ )
			{
				children[0]->board[i][j] = board[i][j];
			}
		}
		children[0]->Fitness(ts,m);
		ts--;
		for( int i = 0; i < 32; i++ )
		{
			for( int j = 0; j < 32; j++ )
			{
				children[1]->board[i][j] = board[i][j];
			}
		}
		children[1]->Fitness(ts,m);
		if( op_type == prog3 )
		{
			ts--;
			for( int i = 0; i < 32; i++ )
			{
				for( int j = 0; j < 32; j++ )
				{
					children[2]->board[i][j] = board[i][j];
				}
			}
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
		}

		if( board[m.coord[0]][m.coord[1]] == 1 )
		{
			board[m.coord[0]][m.coord[1]] = 2;
			m.fitness++;
		}
		else
		{
			// penalty if I have time
			if( board[m.coord[0]][m.coord[1]] != 2)
				board[m.coord[0]][m.coord[1]] = 3;
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

	if( parent != NULL )
	{
		for( int i = 0; i < 32; i++ )
		{
			for( int j = 0; j < 32; j++ )
			{
				parent->board[i][j] = board[i][j];
			}
		}
	}
}

void Node::Full( int depth, Node* p)
{
	parent = p;

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

			children[count]->parent = this;
			count++;
		}
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