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
	struct avl_node *left;
	struct avl_node *right;
};
