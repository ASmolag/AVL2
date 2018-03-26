#include "AVLTree.h"

using namespace std;

int avlTree::wysokosc(avl_node *w)
{
	int h = 0; // poczatkowo wysokosc zerowa
	if (w != nullptr)
	{
		int l_wysokosc = wysokosc(w->left); // wysokosc lewego poddrzewa 
		int r_wysokosc = wysokosc(w->right); // wyokosc prawego poddrzewa
		int max_wysokosc = max(l_wysokosc, r_wysokosc); // wybor które poddrzewo jest wy¿sze 
		h = max_wysokosc + 1; // dodajemy jedn zeby liczylo pelna wysokosc od korzenia
	}
	return h;
}

/*
* wspolczynnik balansu 
*/
int avlTree::wsp_balansu(avl_node *w)
{
	int l_wysokosc = wysokosc(w->left);
	int r_wysokosc = wysokosc(w->right);
	int roznica = l_wysokosc - r_wysokosc; // roznica wysokosc jest naszym wpsolczynnikiem
	return roznica;
}

/*
* rotacja prawy prawy 
*/
avl_node *avlTree::rr(avl_node *rodzic)
{
	avl_node *x; // zmienna pomocnicza do zamiany wezlow 
	x = rodzic->right;
	rodzic->right = x->left;
	x->left = rodzic;
	return x;
}
/*
* rotacja lewy lewy 
*/
avl_node *avlTree::ll(avl_node *rodzic)
{
	avl_node *x;
	x = rodzic->left;
	rodzic->left = x->right;
	x->right = rodzic;
	return x;
}

/*
* rotacja lewy prawy
*/
avl_node *avlTree::lr(avl_node *rodzic) // rotacja wykonujaca rotacje w lewe i w prawo 
{
	avl_node *x;
	x = rodzic->left;
	rodzic->left = rr(x); // wywolanie rotacji prawy 
	return ll(rodzic); // zwrocenie rotacji w lewo
}

/*
* rotacja prawy lewy
*/
avl_node *avlTree::rl_rotation(avl_node *rodzic)
{
	avl_node *x;
	x = rodzic->right;
	rodzic->right = ll(x);
	return rr(rodzic);
}
