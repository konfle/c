#include <iostream>
#include <cmath>
using namespace std;

// Program oblicza rownanie kwadratowe

int main() {
	int a,b,c, delta,x,x1,x2; //deklaracja zmiennych typu integer
	
	// pobieranie danych od uzytkownika 
	cout << "Podaj a: " << endl; 
	cin >> a;
	cout << "Podaj b: " << endl;
	cin >>b;
	cout << "Podaj c: " << endl;
	cin >>c;
	delta = pow(b,2) - 4 * a * c; // liczy delte
	
	/* sprwdzanie warunkow rownania kwadratowoego dla a=0 wyswetlamy komunikat i koniec programu.
		jezeli dela wieksza od 0 liczy dwa rozwiazania x1 i x2 i wyswietla wynik.
		jezeli delta rowna 0 to liczy x i wyswietla wynik */
		
	if (a == 0){ 										
		cout << "wartosc 'a' musi byc rozna od 0";
	} else if (delta > 0){ 							
		x1 = (-b-sqrt(delta))/2*a;
		x2 = (-b+sqrt(delta))/2*a;
		cout << "Delta dodatnia, rozwiazania to " << x1 << " oraz " << x2 << endl;
	} else if (delta == 0) {
		x = -b/2*a;
		cout << "Delta rowna zero " << x << endl;
	} else {
		cout << "Brak rozwiazan" << endl;
	}
	
}
