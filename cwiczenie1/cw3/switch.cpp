#include <iostream>
#include <cmath>
using namespace std;

// Program oblicza objetosci kuli, stozka i prostopadloscianu wykorzystujac instrukcje switch

int main() {
	int wybor,r,h,a,b,c; // deklaracja zmiennych typu integer
	const float czteryTrzecie = 1.33; // deklaracja wartosci stalych typu zmiennoprzecinkowego float
	
	cout << "Witaj!\n\nCzego objetosc chcesz obliczyc?\n\n 1 - Kula\n 2 - Stozek\n 3 - Prostopadloscian" << endl; // pobieranie wartosci od uzytkownika
	cin >> wybor; // przypisanie wartosci podanej przez uzytkownia do zmiennej wybor
	
	/* instrukcja switch w nawiasie nalezy podac nazwe zmiennej do, ktorej przypisujemy wartosc wprowadzona przez uzytkownika
		je¿eli zmienna rowna 1 to realizowany jest przypadek 1, zmienna rowna 2 realizowany przypadek 2,
		zmienna rowna 3 realizowany jest przypadek 3, jezeli zostanie wprowadzony inny znak to jest 
		realizowany przypadek domyslny i wyswietla komunikat nie rozumiem */
	switch(wybor) {
		case 1:
			cout << "Podaj promien kuli: " << endl;
			cin >> r;
			cout << "Objetosc tej kuli to " << czteryTrzecie * M_PI * pow(r,3) << " cm." << endl;
			break;
		case 2:
			cout << "Podaj promien podstawy stozka" << endl;
			cin >> r;
			cout << "Podaj wysokosc stozka" << endl;
			cin >> h;
			cout << "Objetosc takiego stozka to " << (M_PI * pow(r,2) * h)/3 << " cm." << endl;
			break;
		case 3:
			cout << "Podaj bok a" << endl;
			cin >> a;
			cout << "Podaj bok b" << endl;
			cin >> b;
			cout << "Podaj bok c" << endl;
			cin >> c;
			cout << "Objetosc tego prostopadloscianu to " << a * b * c << " cm." << endl;
			break;
		default:
			cout << "nie rozumiem";
		
	}
}
