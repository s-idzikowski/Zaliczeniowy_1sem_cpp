#pragma once

void naglowek();
void ustawienie_3tablic(int& rozmiarTablic, float*& piwo, float*& wino, float*& wodka);
void generujDane(int rozmiarTablic, float*& piwo, float*& wino, float*& wodka);
void wprowadzDane(int rozmiarTablic, float*& piwo, float*& wino, float*& wodka);
void wyswietlDane(const float* piwo, const float* wino, const float* wodka, int rozmiarTablic);
float* tabNajwyzsze(const float* tablica, int rozmiar);
void wyswietlNaj(const float* piwo, const  float* wino, const float* wodka, int rozmiarTablic);
float srednia_arytmetyczna(const float* tablica, int rozmiarTablicy);
float srednia_arytmetyczna(const float* tablica, int rozmiarTablicy, int a, int b);
float srednia_harmoniczna(const float* tablica, int rozmiarTablicy);
float srednia_harmoniczna(const float* tablica, int rozmiarTablicy, int a, int b);
void wyswietlSrednia(const float* piwo, const  float* wino, const float* wodka, int rozmiarTablic);
int* tab_indeksy(int rozmiarTablic);
float* kopia_tablicy(const float* tablica, int rozmiarTablic);
void wyswietlRosnaco(const float* piwo, const  float* wino, const float* wodka, int rozmiarTablic);
void oblicz_kwartal(float& pierwszy, float& drugi, float& trzeci, float& czwarty, const float* tablica, int rozmiarTablic);
void wyswietlHistogram(const float* piwo, const  float* wino, const float* wodka, int rozmiarTablic);
void menu_analiza(float* piwo, float* wino, float* wodka, int rozmiarTablic);