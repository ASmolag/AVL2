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
avl_node *avlTree::rl(avl_node *rodzic)
{
	avl_node *x;
	x = rodzic->right;
	rodzic->right = ll(x);
	return rr(rodzic);
}

/*
* balansowanie drzewa
*/
avl_node *avlTree::balans(avl_node *w)
{
	int balans = wsp_balansu(w); // zmienna przechowujaca roznice
	if (balans > 1) // jezeli ta zmienna wieksza od 1 to przewaza lewe poddrzewo
	{
		if (wsp_balansu(w->left) == 1) // jezeli wspolczynnik lewego poddrzewa rowny 1
			w = ll(w);			// to rotacja lewy lewy
		              
		else if(wsp_balansu(w->left) == -1) // jezeli równy -1
			w = lr(w);                      // to rotacja lewy prawy
	}
	else if (balans < -1) // jezeli zmienna mniejsza od -1 to przewaza prawe poddrzewo 
	{
		if (wsp_balansu(w->right) == -1) // jezeli wspolczynnik prawego rowny -1 
			w = rr(w); // to rotacja prawy prawy
		  
		else if(wsp_balansu(w->right)== 1) // jezeli rowny 1
			w = rl(w);					   // to prawy lewy
	}
	return w;
}

/*
* Dodawanie elementu do drzewa
*/


avl_node *avlTree::dodaj(avl_node *korzen, int klucz)
{
	if (korzen == nullptr) // jezli nie ma korzenia
	{
		korzen = new avl_node(klucz); // to korzeniem staje sie nowy wezelo
		//root->data = value;
		//root->left = NULL;
		//root->right = NULL;
		this->korzen = korzen;
		return korzen;
	}
	else if (klucz < korzen->data) // jezeli wpisany klucz jest mniejszy od obecnego w wezle
	{
		korzen->left = dodaj(korzen->left, klucz); // to przechodzimy do lewego poddrzewa i tam dodajemy
		korzen = balans(korzen); // wykonujemy balans drzewa
	}
	else if (klucz > korzen->data) // jezeli wpisany klucz jest wiekszy od obecnego w wezle
	{
		korzen->right = dodaj(korzen->right, klucz); // to przechodzimy do lewego poddrzewa i tam dodajemy
		korzen = balans(korzen); // wykonujemy balans 
	}
	else if (klucz == korzen->data) // jezli juz istnieje element
	{
		cout << "istnieje juz taki element" << endl;
		//return korzen;
	}
	this->korzen = korzen;
	return korzen;
}

/*
* Wyswietlanie drzewa - gotowa funkcja z internetu 
*/
void avlTree::wyswietl(avl_node *w, int poziom)
{
	int i;
	if (w != nullptr)
	{
		wyswietl(w->right, poziom + 1);
		printf("\n");
		if (w == korzen)
			cout << "Root -> ";
		for (i = 0; i < poziom && w != korzen; i++)
			cout << "        ";
		cout << w->data;
		wyswietl(w->left, poziom + 1);
	}
}
/*
* Przejscie inorder
*/
void avlTree::inorder(avl_node *drzewo)
{
	if (drzewo == nullptr) // jezeli drzewo nie istniej
		return;				// zwroc puste
	inorder(drzewo->left); // wywo³aj dla lewego poddrzewa
	cout << drzewo->data << "  "; // wyswietl klucz danego elementu
	inorder(drzewo->right); // wywo³aj dla prawego poddrzewa 
}


/*
* Przejscie preorder
*/
void avlTree::preorder(avl_node *drzewo)
{
	if (drzewo == nullptr)
		return;
	cout << drzewo->data << "  "; // wyswietl klucz danego elementu
	preorder(drzewo->left); // wywo³aj dla lewego poddrzewa
	preorder(drzewo->right); // wywo³aj dla prawego poddrzewa 

}

/*
* Przejscie postorder
*/
void avlTree::postorder(avl_node *drzewo)
{
	if (drzewo == nullptr)
		return;
	postorder(drzewo->left); // wywo³aj dla lewego poddrzewa
	postorder(drzewo->right); // wywo³aj dla prawego poddrzewa 
	cout << drzewo->data << "  "; // wyswietl klucz danego elementu
}

avl_node* avlTree::minimum(avl_node* x) // funkcja potrzebna do usuwania 
{
	while (x->left != nullptr) x = x->left; // tak d³ugo jak lewy istnieje przechodz na lewo
	this->korzen = x;
	return x;
}

avl_node *avlTree::usun(avl_node *x, int klucz)
{
	if (x == nullptr) //jezeli x jest pusty
	{
		this->korzen = x; // korzen staje sie pusty 
		return x; 
	}
	else if (klucz < x->data) x->left = usun(x->left, klucz); // jezeli klucz jest mniejszy to wywolujemy rekurencyjnie dla lewego
	else if (klucz > x->data) x->right = usun(x->right, klucz);// jezeli  jest wiekszy to dla prawego 

	else {

		if (x->left == nullptr && x->right == nullptr) { // jezeli  jest lisciem to usuwamy
			delete x;
			x = nullptr;
		}

		else if (x->left == nullptr) { // jezeli lewy jest pusty 
			avl_node *temp = x; // zmienna pomocnicza
			x = x->right; // przechodzimy do prawego i usuwamy zmienna tymczasowa
			delete temp;
		}
		else if (x->right == nullptr) { //jezeli  prawy jest pusty 
			avl_node *temp = x;
			x = x->left; // przechodzimy do lewego i usuwamy zmienna 
			delete temp;
		}

		else {
			avl_node *temp = minimum(x->right); // wywolanie funkcji minimum dla prawego poddrzewa
			x->data = temp->data; // kluczem x staje sie klucz z minimum 
			x->right = usun(x->right, temp->data); // wywow³anie funkcji usun dla prawego poddrzewa i klucza z minimum 
		}
	}
	this->korzen = x; // korzeniem drzewa staje sie x 
	return x;
}




