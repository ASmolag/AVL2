#include "AVLTree.h"
#include <ctime>
#include <cstdio>
using namespace std;

void utworz_drzewo(avlTree &avl, int wielkosc) 
{
	srand(time(NULL)); 

	for (int i = 0; i < wielkosc; i++) // wielkosc to zmienna okreslajaca ile elementow ma drzewo
	{
		avl.dodaj(avl.korzen, rand() % 1000); // losujemy z przedzialu od 0 do 256 i wstawiamy do drzewa
	}
}

int main()
{
	int wybor, wartosc; // zmienna potrzebna do menu i zmienna do wrowadzania elementow 
	avlTree avl; // utowrzenie obiektu typu avlTree o nazwie avl
	while (1)
	{
		cout << "\n---------------------" << endl;
		cout << "  Implementacja drzewa AVL   " << endl;
		cout << "\n---------------------" << endl;
		cout << "1. Dodaj element do drzewa" << endl;
		cout << "2. Wyswietl zbalansowane drzewo" << endl;
		cout << "3. Usuñ element o zadanym kluczu" << endl;
		cout << "4. Wyœwietl wysokoœæ drzewa" << endl;
		cout << "5. Wyœwietl korzen drzewa" << endl;
		cout << "6. Przejscie preorder" << endl;
		cout << "7. Przejscie postorder" << endl;
		cout << "8. Przejscie inorder" << endl;
		cout << "9. Utworz losowe drzewo o wskazanej ilosci elementow" << endl;
		cout << "10. Wyjdz " << endl;
		cout << "\n-----------------------" << endl;
		cout << "Wybierz opcje: ";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "Podaj wartosc do dodania : ";
			cin >> wartosc;
			avl.dodaj(avl.korzen, wartosc);
			break;
		case 2:
			if (avl.korzen == nullptr)
			{
				cout << "Drzewo jest puste" << endl;
				continue;
			}
			cout << "Zabalansowane drzewo:" << endl;
			avl.wyswietl(avl.korzen, 1);
			break;
		case 3:
			cout << "Wprowadz element, ktory chcesz usunac : ";
			cin >> wartosc;
			avl.usun(avl.korzen, wartosc);
			break;
		case 4:
			cout << "Wysokosc drzewa wynosi : " << avl.wysokosc(avl.korzen) << endl;
			break;
		case 5:
			cout << "Korzen:" << avl.korzen->data<<endl;
			break;
		case 6:
			cout << "Preorder Traversal:" << endl;
			avl.preorder(avl.korzen);
			cout << endl;
			break;
		case 7:
			cout << "Postorder Traversal:" << endl;
			avl.postorder(avl.korzen);
			cout << endl;
			break;
		case 8:
			cout << "Inorder Traversal:" << endl;
			avl.inorder(avl.korzen);
			cout << endl;
			break;
		case 9:
			cout << "Wprowadz ilosc elementow: ";
			cin >> wartosc;
			utworz_drzewo(avl, wartosc);
			break;
		case 10:
			exit(1);
			break;
		default:
			cout << "Nie ma takiej opcji" << endl;
		}
	}
	return 0;
}