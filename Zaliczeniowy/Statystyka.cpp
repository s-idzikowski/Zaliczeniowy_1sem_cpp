#include "Operacje.h"
#include <iostream>

using namespace std;

int main() {

	int rozmiarTablic;
	float* piwo;
	float* wino;
	float* wodka;
	bool czyLosowo;

	char wybor;
	do
	{
		naglowek();
		cout << "Podaj sposob wprowadzania danych:\n";
		cout << "(l)osowo, (r)ecznie\n";
		cout << "lub (z)akmnij program\n";
		cin >> wybor;
	} while (wybor != 'l' && wybor != 'r' && wybor != 'z');

	if (wybor == 'l' || wybor == 'r')
	{
		wybor == 'l' ? czyLosowo = true : czyLosowo = false;
		ustawienie_3tablic(rozmiarTablic, piwo, wino, wodka);
		
	}
	if (wybor == 'z') {
	cout << "Program zostal zakonczony";
	return 1;
	}
	if (czyLosowo == true) {
		generujDane(rozmiarTablic, piwo, wino, wodka);
	}
	else {
		wprowadzDane(rozmiarTablic, piwo, wino, wodka);
	}

	menu_analiza(piwo, wino, wodka, rozmiarTablic);
	
}