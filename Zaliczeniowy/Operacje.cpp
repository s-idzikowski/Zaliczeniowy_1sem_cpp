#include <iostream>
#include <ctype.h>
#include <random>
#include <ctime>
#include <iomanip>
#include <string>

using namespace std;

string ktory_rok_miesiac(int miesiac) {
	string tekst;
	int rok = miesiac / 12 + 1;
	tekst = "Rok: ";
	tekst += to_string(rok);
	tekst += " Miesiac: ";

	if (miesiac % 12 == 0)
		tekst += "Styczen ";
	if (miesiac % 12 == 1)
		tekst += "Luty ";
	if (miesiac % 12 == 2)
		tekst += "Marzec ";
	if (miesiac % 12 == 3)
		tekst += "Kwiecien ";
	if (miesiac % 12 == 4)
		tekst += "Maj ";
	if (miesiac % 12 == 5)
		tekst += "Czerwiec ";
	if (miesiac % 12 == 6)
		tekst += "Lipiec ";
	if (miesiac % 12 == 7)
		tekst += "Sierpien ";
	if (miesiac % 12 == 8)
		tekst += "Wrzesien ";
	if (miesiac % 12 == 9)
		tekst += "Pazdziernik ";
	if (miesiac % 12 == 10)
		tekst += "Listopad ";
	if (miesiac % 12 == 11)
		tekst += "Grudzien ";

	return tekst;
}

void naglowek()
{
	system("CLS");
	cout << "Analiza sprzedazy napojow alkoholowych w poszczegolnych miesiacach\n";
	cout << "---------------------------------------------------------------------\n";
}

void ustawienie_3tablic(int& rozmiarTablic, float*& piwo, float*& wino, float*& wodka)
{
	do
	{
		cout << "Dla ilu lat chcesz dokonac analizy?: ";
		cin >> rozmiarTablic;
		if (cin.fail()) {
			cout << "\nPodaj ilosc lat za pomoca liczby!\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		if (rozmiarTablic <= 0) {
			cout << "Nie mozna dokonac analizy dla " << rozmiarTablic << " lat\n\n";
		}
	} while (rozmiarTablic <= 0);
	rozmiarTablic = rozmiarTablic * 12;
	piwo = new float[rozmiarTablic];
	wino = new float[rozmiarTablic];
	wodka = new float[rozmiarTablic];
}

void generujDane(int rozmiarTablic, float*& piwo, float*& wino, float*& wodka) {
	default_random_engine generator(time(0));
	uniform_real_distribution<> losowa(0, 1000);

	for (int i = 0; i < rozmiarTablic; i++)
	{
		piwo[i] = static_cast<float>(round(losowa(generator) / 0.01) * 0.01);
		wino[i] = static_cast<float>(round(losowa(generator) / 0.01) * 0.01);
		wodka[i] = static_cast<float>(round(losowa(generator) / 0.01) * 0.01);
	}
}

void wprowadzDane(int rozmiarTablic, float*& piwo, float*& wino, float*& wodka) {
	cout << "Podaj " << rozmiarTablic << " wartosci dla sprzedazy piwa: ";
	for (int i = 0; i < rozmiarTablic; i++)
	{
		cin >> piwo[i];
	}
	cout << "Podaj " << rozmiarTablic << " wartosci dla sprzedazy wino: ";
	for (int i = 0; i < rozmiarTablic; i++)
	{
		cin >> wino[i];
	}
	cout << "Podaj " << rozmiarTablic << " wartosci dla sprzedazy wodka: ";
	for (int i = 0; i < rozmiarTablic; i++)
	{
		cin >> wodka[i];
	}
}
void wyswietlDane(const float* piwo, const float* wino, const float* wodka, int rozmiarTablic) {
	naglowek();

	for (int i = 0; i < rozmiarTablic; i++)
	{
		if (i % 12 == 0) {
			cout << "Rok " << i / 12 + 1 << endl;
			cout << "Styczen: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 1) {
			cout << "Luty: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 2) {
			cout << "Marzec: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 3) {
			cout << "Kwiecien: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 4) {
			cout << "Maj: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 5) {
			cout << "Czerwiec: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 6) {
			cout << "Lipiec: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 7) {
			cout << "Sierpien: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 8) {
			cout << "Wrzesien: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 9) {
			cout << "Pazdziernik: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 10) {
			cout << "Listopad: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
		if (i % 12 == 11) {
			cout << "Grudzien: " << "piwo: " << piwo[i] << " wino: " << wino[i] << " wodka: " << wodka[i] << endl;
		}
	}
}

float* tabNajwyzsze(const float* tablica, int rozmiar) {
	float* tab = new float[2];
	tab[0] = 0; //indeks
	tab[1] = tablica[0]; //wartosc

	for (int i = 1; i < rozmiar; i++)
	{
		if (tablica[i] > tab[1])
		{
			tab[1] = tablica[i]; //ustawiamy nowy maks
			tab[0] = i; //ustawiamy indeks na ktorym jest maks
		}
	}
	return tab;
}

void wyswietlNaj(const float* piwo, const  float* wino, const float* wodka, int rozmiarTablic) {
	naglowek();
	float* najPiwo = tabNajwyzsze(piwo, rozmiarTablic);
	float* najWino = tabNajwyzsze(wino, rozmiarTablic);
	float* najWodka = tabNajwyzsze(wodka, rozmiarTablic);
	cout << "Najwyzsza wartosc dla Piwa wyniosla: " << najPiwo[1] << " i bylo to w: " << ktory_rok_miesiac(najPiwo[0]) << endl;
	cout << "Najwyzsza wartosc dla Wina wyniosla: " << najWino[1] << " i bylo to w: " << ktory_rok_miesiac(najWino[0]) << endl;
	cout << "Najwyzsza wartosc dla Wodki wyniosla: " << najWodka[1] << " i bylo to w: " << ktory_rok_miesiac(najWodka[0]) << endl;
}

float srednia_arytmetyczna(const float* tablica, int rozmiarTablicy) {
	float wynik = tablica[0];
	for (int i = 1; i < rozmiarTablicy; i++)
	{
		wynik += tablica[i];
	}
	return wynik / rozmiarTablicy;
}

float srednia_arytmetyczna(const float* tablica, int rozmiarTablicy, int a, int b) {
	//wybrany zakres - funkcja przeciazona
	if (a > b) {
		int tmp = b;
		b = a;
		a = tmp;
	}
	float wynik = tablica[a];
	for (int i = a + 1; i <= b; i++)
	{
		wynik += tablica[i];
	}
	return wynik / (b - a + 1);
}

float srednia_harmoniczna(const float* tablica, int rozmiarTablicy) {
	float wynik = 0.0;
	for (int i = 0; i < rozmiarTablicy; i++)
	{
		wynik += (1.0 / tablica[i]);
	}
	return (float)rozmiarTablicy / wynik;

}

float srednia_harmoniczna(const float* tablica, int rozmiarTablicy, int a, int b) {
	//z wybrana wartoscia - funkcja przeciazona
	if (a > b) {
		int tmp = b;
		b = a;
		a = tmp;
	}
	float wynik = 0.0;
	for (int i = a; i <= b; i++)
	{
		wynik += (1.0 / tablica[i]);
	}
	return (float)(b - a) / wynik;

}

void wyswietlSrednia(const float* piwo, const  float* wino, const float* wodka, int rozmiarTablic) {
	naglowek();
	char wybor;
	bool flaga = 1;
	int a, b;

	float sredniaPiwo;
	float sredniaWino;
	float sredniaWodka;

	cout << "Jaka srednia obliczyc?";
	cout << "\n\ta - arytmetyczna z calego okresu\n\th - harmoniczna z calego okresu\n";
	cout << "\n\tb - arytmetyczna z wybranego okresu\n\tj - harmoniczna z wybranego okresu\n";
	cin >> wybor;
	if (wybor != 'a' && wybor != 'h') {
		do
		{
			cout << "\tPodaj miesiace dla ktorych policzyc srednia (liczby z zakresu od 1 do " << rozmiarTablic << " miesiaca): ";
			cin >> a >> b;
			if (cin.fail()) {
				cout << "\nDozwolone tylko liczby z zakresu od 1 do " << rozmiarTablic << endl;
				cin.clear();
				cin.ignore(100, '\n');
			}
		} while (a <= 0 || a > rozmiarTablic&& b <= 0 || b > rozmiarTablic);
	}

	switch (wybor)
	{
	case 'a':
		sredniaPiwo = srednia_arytmetyczna(piwo, rozmiarTablic);
		sredniaWino = srednia_arytmetyczna(wino, rozmiarTablic);
		sredniaWodka = srednia_arytmetyczna(wodka, rozmiarTablic);
		cout << "Srednia arytmetyczna piwo: " << sredniaPiwo << " wino: " << sredniaWino << " wodka: " << sredniaWodka << endl;
		break;
	case 'h':
		sredniaPiwo = srednia_harmoniczna(piwo, rozmiarTablic);
		sredniaWino = srednia_harmoniczna(wino, rozmiarTablic);
		sredniaWodka = srednia_harmoniczna(wodka, rozmiarTablic);
		cout << "Srednia harmoniczna piwo: " << sredniaPiwo << " wino: " << sredniaWino << " wodka: " << sredniaWodka << endl;
		break;
	case 'b':
		sredniaPiwo = srednia_arytmetyczna(piwo, rozmiarTablic, a, b);
		sredniaWino = srednia_arytmetyczna(wino, rozmiarTablic, a, b);
		sredniaWodka = srednia_arytmetyczna(wodka, rozmiarTablic, a, b);
		cout << "Srednia arytmetyczna piwo: " << sredniaPiwo << " wino: " << sredniaWino << " wodka: " << sredniaWodka << endl;
		break;
	case 'j':
		sredniaPiwo = srednia_harmoniczna(piwo, rozmiarTablic, a, b);
		sredniaWino = srednia_harmoniczna(wino, rozmiarTablic, a, b);
		sredniaWodka = srednia_harmoniczna(wodka, rozmiarTablic, a, b);
		cout << "Srednia harmoniczna piwo: " << sredniaPiwo << " wino: " << sredniaWino << " wodka: " << sredniaWodka << endl;
		break;
	default:
		flaga = 0;
	}
	if (!flaga)
	{
		cout << "Blad - nieokreslona srednia\n";
	}
}
int* tab_indeksy(int rozmiarTablic) {
	//tworzymy tablice i przypisujemy jej wartosci - kazda wartosc odpowiada numerowi indeksu
	int* indeksy = new int[rozmiarTablic];
	for (int i = 0; i < rozmiarTablic; i++)
	{
		indeksy[i] = i;
	}
	return indeksy;
}

float* kopia_tablicy(const float* tablica, int rozmiarTablic) {
	float* kopia = new float[rozmiarTablic];
	for (int i = 0; i < rozmiarTablic; i++)
	{
		kopia[i] = tablica[i];
	}
	return kopia;
}

void wyswietlRosnaco(const float* piwo, const  float* wino, const float* wodka, int rozmiarTablic) {
	naglowek();
	int* iPiwo = tab_indeksy(rozmiarTablic);
	int* iWino = tab_indeksy(rozmiarTablic);
	int* iWodka = tab_indeksy(rozmiarTablic);
	float* kopiaPiwo = kopia_tablicy(piwo, rozmiarTablic);
	float* kopiaWino = kopia_tablicy(piwo, rozmiarTablic);
	float* kopiaWodka = kopia_tablicy(piwo, rozmiarTablic);


	//sortujemy babelkowo
	for (int i = 0; i < rozmiarTablic; i++)
		for (int j = 1; j < rozmiarTablic - i; j++) {
			if (kopiaPiwo[j - 1] > kopiaPiwo[j]) {
				swap(kopiaPiwo[j - 1], kopiaPiwo[j]);
				swap(iPiwo[j - 1], iPiwo[j]);
			}
			if (kopiaWino[j - 1] > kopiaWino[j]) {
				swap(kopiaWino[j - 1], kopiaWino[j]);
				swap(iWino[j - 1], iWino[j]);
			}
			if (kopiaWodka[j - 1] > kopiaWodka[j]) {
				swap(kopiaWodka[j - 1], kopiaWodka[j]);
				swap(iWodka[j - 1], iWodka[j]);
			}
		}

	//wyswietlamy wynik
	cout << "---------------- PIWO ----------------" << endl;
	for (int i = 0; i < rozmiarTablic; i++)
	{
		cout << ktory_rok_miesiac(iPiwo[i]) << "===> " << kopiaPiwo[i] << endl;
	}
	cout << "---------------- WINO ----------------" << endl;
	for (int i = 0; i < rozmiarTablic; i++)
	{
		cout << ktory_rok_miesiac(iWino[i]) << "===> " << kopiaWino[i] << endl;
	}
	cout << "---------------- WODKA ----------------" << endl;
	for (int i = 0; i < rozmiarTablic; i++)
	{
		cout << ktory_rok_miesiac(iWodka[i]) << "===> " << kopiaWodka[i] << endl;
	}

	//zwolnienie pamieci - tablice juz nie sa potrzebne
	delete[] iPiwo;
	delete[] iWino;
	delete[] iWodka;
	delete[] kopiaPiwo;
	delete[] kopiaWino;
	delete[] kopiaWodka;
}

void oblicz_kwartal(float& pierwszy, float& drugi, float& trzeci, float& czwarty, const float* tablica, int rozmiarTablic) {
	pierwszy = 0.0;
	drugi = 0.0;
	trzeci = 0.0;
	czwarty = 0.0;
	for (int i = 0; i < rozmiarTablic; i++)
	{
		if (i % 12 == 0 || i % 12 == 1 || i % 12 == 2)
			pierwszy += tablica[i];
		if (i % 12 == 3 || i % 12 == 4 || i % 12 == 5)
			drugi += tablica[i];
		if (i % 12 == 6 || i % 12 == 7 || i % 12 == 8)
			trzeci += tablica[i];
		if (i % 12 == 9 || i % 12 == 10 || i % 12 == 11)
			czwarty += tablica[i];
	}
}

void wyswietlHistogram(const float* piwo, const  float* wino, const float* wodka, int rozmiarTablic) {
	naglowek();
	cout << "KWARTAL ----- I ------ II ------III ------ IV -------" << endl;
	float pierwszy;
	float drugi;
	float trzeci;
	float czwarty;

	oblicz_kwartal(pierwszy, drugi, trzeci, czwarty, piwo, rozmiarTablic);
	cout << "PIWO -----" << pierwszy << "----" << drugi << "----" << trzeci << "----" << czwarty << "-" << endl;
	oblicz_kwartal(pierwszy, drugi, trzeci, czwarty, wino, rozmiarTablic);
	cout << "WINO -----" << pierwszy << "----" << drugi << "----" << trzeci << "----" << czwarty << "-" << endl;
	oblicz_kwartal(pierwszy, drugi, trzeci, czwarty, wodka, rozmiarTablic);
	cout << "WODKA ----" << pierwszy << "----" << drugi << "----" << trzeci << "----" << czwarty << "-" << endl;
}

void menu_analiza(float* piwo, float* wino, float* wodka, int rozmiarTablic) {
	naglowek();
poczatek:
	cout << "-----------------------------------------------------\n";
	cout << "Co chcesz uczynic z wprowadzonymi danymi:\n";
	cout << "1 - Wyswietl wszystkie dane\n";
	cout << "2 - Wyswietl rok i miesiac w ktorym sprzedaz byla najwyzsza\n";
	cout << "3 - Wyswietl srednia arytmetyczna/harmoniczna dla podanego okresu\n";
	cout << "4 - Wyswietl okres w porzadku rosnacym na podstawie wielkosci sprzedazy\n";
	cout << "5 - Sprzedaz w poszczegolnych kwartalach przedstawiona w histogramie\n";
	cout << "6 - Wyjscie z programu";

	int wybor;
	do
	{
		cout << "\nPodaj liczbe od 1 do 6\n";
		cin >> wybor;
		if (cin.fail()) {
			cout << "Dozwolone tylko liczby!\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
	} while (wybor <= 0 || wybor > 6);

	switch (wybor)
	{
	case 1:
		wyswietlDane(piwo, wino, wodka, rozmiarTablic);
		goto poczatek;
		break;
	case 2:
		wyswietlNaj(piwo, wino, wodka, rozmiarTablic);
		goto poczatek;
		break;
	case 3:
		wyswietlSrednia(piwo, wino, wodka, rozmiarTablic);
		goto poczatek;
		break;
	case 4:
		wyswietlRosnaco(piwo, wino, wodka, rozmiarTablic);
		goto poczatek;
		break;
	case 5:
		wyswietlHistogram(piwo, wino, wodka, rozmiarTablic);
		goto poczatek;
		break;
	case 6:
		cout << "\nZakonczenie programu";
		return;
		break;
	}
}