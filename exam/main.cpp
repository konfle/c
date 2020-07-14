#include <iostream>

/* Egzamin */

float srednia(int t[], int dlugosc);
float suma(int ostatniElement);

int main(int argc, char** argv) {
	const int N = 4;
	const int M = 6;
	int A[N] = {-2, 11, -5, 6}, B[M] = {-2, 8, 5, 56, 88, 106}, sumaTablicy = 0, ostatniElementSumy = 5;
	float wynikSumy = 0;
// Funkcja dla tablicy A	
	sumaTablicy = srednia(A,N);
	std::cout << "Suma kwadratow liczb z reszta 2 przy dzieleniu przez 3 to: " << sumaTablicy << "\n";	
// Funkcja dla tablicy B
	sumaTablicy = srednia(B,M);
	std::cout << "Suma kwadratow liczb z reszta 2 przy dzieleniu przez 3 to: " << sumaTablicy << "\n\n";
// Funkcja sumy wedlug wzoru
	wynikSumy = suma(ostatniElementSumy);
	std::cout << "Wynik sumy wedlug wzoru to " << wynikSumy << "\n";	
	return 0;
}

float srednia(int t[], int dlugosc){
	int kwadrat = 0, suma = 0;
	for (int i = 0; i < dlugosc; i++){
		if (t[i] % 3 == 2){
			kwadrat = t[i] * t[i];
			suma = suma + kwadrat;
		}
	} 
	return suma;
}

float suma(int ostatniElement){
	float wynik = 0;
	for (int i = 2; ostatniElement < 5; i+2){
		wynik = wynik + (i / (i + 2.5));
	}
	return wynik;
}
