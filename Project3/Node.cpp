#include "StdAfx.h"
#include "Node.h"


Node::Node(op type)
{
	op_type = type;
}

Node::~Node(void)
{
}

/*
int Node::size_of( Node * t )
{
	int count = 0;
	int temp = 1;
	while( count < CHILDREN )
	{
		if( t->child[count] != NULL )
		{
			temp += size_of( t->child[count] );
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

	temp->fitness = t->fitness;
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
			if( temp->child[0] != NULL )
			{
				Que.push(temp->child[0]);
			}
			if( temp->child[1] != NULL )
			{
				Que.push(temp->child[1]);
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

*/

void Node::Full( int depth, Node* p)
{
	parent = p;

	if( depth >= 1 )
	{
		depth--;

		int count = 0;

		while( count < 2 )
		{

			int r = rand() % NON_TERMS;

			switch( r )
			{
			case if_food:			
				children[count] = new Node(if_food);
				children[count]->Full(depth, children[count]);
				break;
			case prog2:
				children[count] = new Node(prog2);
				children[count]->Full(depth, children[count]);
				break;
			case prog3:
				children[count] = new Node(prog3);
				children[count]->Full(depth, children[count]);
				break;
			}

			count++;
			if( parent->op_type == prog3 && count == 2 )
			{
				int r = rand() % NON_TERMS;

				switch( r )
				{
				case if_food:			
					children[count] = new Node(if_food);
					children[count]->Full(depth, children[count]);
					break;
				case prog2:
					children[count] = new Node(prog2);
					children[count]->Full(depth, children[count]);
					break;
				case prog3:
					children[count] = new Node(prog3);
					children[count]->Full(depth, children[count]);
					break;
				}

			}
		}
	}
	else // depth == 0 add the leafs
	{
		depth--;

		int count = 0;

		while( count < 2 )
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
			}

			count++;
			if( parent->op_type == prog3 && count == 2 )
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
				}

			}
		}
	}
}
