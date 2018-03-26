#pragma once // bilbiloteka do naglowkow 

#include "AVLNode.h" // powiazania z klasa wêz³a 
#include <iostream>

using namespace std;

class avlTree
{
public:

	avl_node *korzen; // zmienna typu 

	int wysokosc(avl_node *w); // zwraca wysokosc drzewa
	int wsp_balansu(avl_node *w); // zwraca wspolczynnik blansu dla wezla
	avl_node *rr(avl_node *w); // rotacja prawy prawy
	avl_node *ll(avl_node *w); // rotacja lewy lewy
	avl_node *lr(avl_node *w); // rotacja lewy prawy
	avl_node *rl(avl_node *w); // rotacja prawy lewy
	avl_node* balans(avl_node *w); // balansuje drzewo po zmianach
	avl_node* dodaj(avl_node *w, int klucz); // dodaje wezel do drzewa
	avl_node* usun(avl_node *w, int klucz); // usuwa wezel o zadanej wartosci
	avl_node * minimum(avl_node *w); // znajduje minimum
	void wyswietl(avl_node *w, int klucz); // wyswietla drzewo
	void inorder(avl_node *); // przejscie przez drzewo inorder
	void preorder(avl_node *); // przejscie przez drzewo preorder
	void postorder(avl_node *); // przejscie przez drzewo postorder
	avlTree() // konstruktor drzewa
	{
		korzen = nullptr; // korzen poczatkowo jest null
	}
};