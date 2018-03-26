#pragma once // bliblioteka potrzebna do tworzenia nag³owkow 
#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#define pow2(n) (1 << (n))

class avl_node
{
public:
	int data;
	avl_node *left;
	avl_node *right;
	avl_node(int k)
	{
		left = nullptr;
		right = nullptr;
		data = k;
	}
	~avl_node()
	{	
		delete left;
		delete right;

	}
};
