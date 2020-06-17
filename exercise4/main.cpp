#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <bits/stdc++.h>

/* Program do tematu 4  */

int numberDraw(int startValue, int endValue, int & randNumberSummary); 
void losuj (int t[], int N);
void wypisz(int t[], int N); 
float srednia(int t[], int N); 
int ile_razy(int t[], int N, int szukana); 
int maks_element(int t[], int N, int & howManyTimes); 

int main() {
	srand(time(0)); 
	const int N = 10; 
	int startValue, endValue, sumOfNumbers = 0, amountOfOdd, searched, searchResult, A[N], B[N], maxValue, howManyTimes = 0;
	float average;
	
// Losowanie 100 liczb
	std::cout << "|-- LOSOWANIE 100 LICZB --|\n";
	std::cout << "Podaj poczatek przedzialu: ";
	std::cin >> startValue;
	std::cout << "Podaj koniec przedzialu: ";
	std::cin >> endValue;
	amountOfOdd = numberDraw(startValue, endValue, sumOfNumbers);
	std::cout << "Ilosc liczb nieparzystych " << amountOfOdd << ", a ich suma wynosi: " << sumOfNumbers << "\n\n";	
	
// Losowanie i wypisanie liczb dla tablic A, B
	std::cout << "|-- WYLOSOWANE LICZBY W TABLICACH A & B --|\n";
    std::cout << "Wylosowane liczby dla tablicy A: ";
    losuj(A, N); 	
    wypisz(A, N); 	
    std::cout << "\n";
    std::cout << "Wylosowane liczby dla tablicy B: ";
    losuj(B, N); 
    wypisz(B, N);	
    std::cout << "\n\n";
    
// Srednia arytmetyczna dla tablicy A
	std::cout << "|-- SREDNIA ARYTMETYCZNA --|\n";
    average = srednia(A, N);
    std::cout << "Srednia arytmetyczna liczb dodatnich w tablicy A to:  " << average << "\n\n";
	    
// Ile razy wystapi³a dana liczba w tablicy A
	std::cout << "|-- SPRAWDZANIE LICZB --|\n";
    std::cout << "Jaka liczbe z przedzialu <-9,29> chcesz srpawdzic w tablicy A: ";
    std::cin >> searched;
    searchResult = ile_razy(A, N, searched);
    std::cout << "Szukana liczba " << searched << " wystepuje " << searchResult << " raz/y w tablicy A" << "\n\n";
    
// Ile razy wystapi³a dana liczba w tablicy B
    std::cout << "Jaka liczbe z przedzialu <-9,29> chcesz srpawdzic w tablicy B: ";
    std::cin >> searched;
    searchResult = ile_razy(B, N, searched); 
    std::cout << "Szukana liczba " << searched << " wystepuje " << searchResult << " raz/y w tablicy B" << "\n\n";
    
// Najwieksza liczba i ile razy sie pojawila w tablicy
	std::cout << "|-- NAJWIEKSZY ELEMENT --|\n";
    maxValue = maks_element(B, N, howManyTimes);
    std::cout << "Najwieksza liczba w tablicy B to " << maxValue << " pojawila sie "<< howManyTimes << " raz/y.";
	return 0;
}
// Funkcja losowanie 100
int numberDraw(int startValue, int endValue, int & randNumberSummary){
	int randNumber, sumOfNumbers, amountOfOddNumbers;
	randNumberSummary, sumOfNumbers, amountOfOddNumbers = 0;
	for (int i = 0; i <= 99; i++){ 
		randNumber = (startValue + rand() % (endValue - startValue + 1));
		if (randNumber % 2 != 0){
			amountOfOddNumbers++;
			randNumberSummary += randNumber;
		}
	}
	sumOfNumbers = randNumberSummary;
	return amountOfOddNumbers;
}
// losowanie elementow tablicy
void losuj (int t[], int N){
	int p = -9, k = 29; 
	for (int i = 0; i < 9; i++){
		t[i] = p + rand() % (k - p + 1);
	}
}
// Wypisanie elementow tablicy
void wypisz(int t[], int N){
	for (int i = 0; i < N; i++) 
    std::cout << t[i] << std::setw(4);
}
// Srednia arytmetyczna dodatnich elementow tablicy
float srednia(int t[], int N){
	float suma = 0.0, ileDodatnich = 0.0, summary = 0.0;	
	for (int i = 0.; i < N; i++){
		if (t[i] > 0){
			suma += t[i];
			ileDodatnich++;	
		}
	}
	summary = suma / ileDodatnich;
	return summary;
}
// Ile razy w tablicy pojawia sie wczytana liczba
int ile_razy(int t[], int N, int szukana){
	int howManyTimesSearched;
	for (int i = 0; i < N; i++){
    	if (t[i] == szukana){
    		howManyTimesSearched++;
		}
	}
	return howManyTimesSearched;
}
// Jaka jest njwieszka liczba i ile razy wystapila
int maks_element(int t[], int N, int & howManyTimes){
	int maximalValue;
	maximalValue = * std::max_element(t, t + N);
	for (int i = 0; i < N; i++){
		if (t[i] == maximalValue){
			howManyTimes++;
		}
	}
	return maximalValue;
}
