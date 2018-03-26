#include "AVLTree.h"
#include <ctime>
#include <cstdio>
#include <Windows.h>

#define RAND_MAX 0x7fff

using namespace std;

// funkcje potrzebne do mierzenia czasu tworzenia losowego drzewa, 
// funkcje z biblioteki Windows.h
// znalezione na stronie http://jaroslaw.mierzwa.staff.iiar.pwr.wroc.pl/pamsi/debug_and_time.pdf

LARGE_INTEGER startTimer()
{
	LARGE_INTEGER start;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&start);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return start;
}
LARGE_INTEGER endTimer()
{
	LARGE_INTEGER stop;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&stop);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return stop;
}
void utworz_drzewo(avlTree &avl, int wielkosc) 
{
	srand(time(NULL)); 

	for (int i = 0; i < wielkosc; i++) // wielkosc to zmienna okreslajaca ile elementow ma drzewo
	{
		avl.dodaj(avl.korzen, rand() % 100000); // losujemy z przedzialu od 0 do 256 i wstawiamy do drzewa
	}
}

int main()
{
	LARGE_INTEGER performanceCountStart, performanceCountEnd;
	__int64 freq;
	QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
	double tm;

	int wybor, wartosc; // zmienna potrzebna do menu i zmienna do wrowadzania elementow 
	avlTree avl; // utowrzenie obiektu typu avlTree o nazwie avl
	while (1)
	{
		cout << "\n-------------------------------------------------" << endl;
		cout << "            Implementacja drzewa AVL   " << endl;
		cout << "\n-------------------------------------------------" << endl;
		cout << "1. Dodaj element do drzewa" << endl;
		cout << "2. Wyswietl zbalansowane drzewo" << endl;
		cout << "3. Usun element o zadanym kluczu" << endl;
		cout << "4. Wyswietl wysokoœæ drzewa" << endl;
		cout << "5. Wyswietl korzen drzewa" << endl;
		cout << "6. Przejscie preorder" << endl;
		cout << "7. Przejscie postorder" << endl;
		cout << "8. Przejscie inorder" << endl;
		cout << "9. Utworz losowe drzewo o wskazanej ilosci elementow" << endl;
		cout << "10. Wyjdz " << endl;
		cout << "\n---------------------------------------------------" << endl;
		cout << "Wybierz opcje: ";
		cin >> wybor;
		switch (wybor)
		{
		case 1:
			cout << "Podaj wartosc do dodania : ";
			cin >> wartosc;
			performanceCountStart = startTimer();
			avl.dodaj(avl.korzen, wartosc);
			performanceCountEnd = endTimer();
			tm = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;
			cout << endl << "czas tworzenia drzewa:" << tm << " s" << endl;
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
			performanceCountStart = startTimer();
			utworz_drzewo(avl, wartosc);
			performanceCountEnd = endTimer();
			tm = (double)(performanceCountEnd.QuadPart - performanceCountStart.QuadPart) / freq;
			cout << endl << "czas tworzenia drzewa:" << tm << " s" << endl;
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