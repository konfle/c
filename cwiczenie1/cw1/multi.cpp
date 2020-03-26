#include <iostream>
#include <cmath>
using namespace std;

/*Program wyswietla imie i nazwosko studenta, konwetuje mile morskie na metry,
	oblicza objetosc stozka, wypisuje najwieksza liczbe*/
int main() {
	int mile,h,r,l,pierwszaLiczba, drugaLiczba, trzeciaLiczba;
	double jednaTrzecia = 0.33;
	float objetosc, poleBoczne;
	
	// Przedstawienie
	cout << "Konrad Flejter" << endl;
	
	// Konwertowanie
	cout << "Podaj odlegosc w milach morskich" << endl;
	cin >>mile;
	cout << mile << " mile morskie to " << mile * 1852 << " metrow" << endl;
	
	// Stozek
	cout << "Podaj wysokosc stozka" << endl;
	cin >> h;
	cout << "Podaj promien podstawy kola" << endl;
	cin >> r;
	cout << "Podaj tworzaca stozka" << endl;
	cin >>l;
	objetosc = jednaTrzecia * M_PI * float(r * r) * float(h);
	poleBoczne = M_PI * r * l;
	cout << "Objetosc twojego stozka to " << objetosc << ", a pole boczne to " << poleBoczne << endl;
	
	// Ktora wieksza
	cout << "Podaj pierwsza liczbe" << endl;
	cin >> pierwszaLiczba;
	cout << "Podaj druga liczbe" << endl;
	cin >> drugaLiczba;
	cout << "Podaj trzecia liczbe" << endl;
	cin >> trzeciaLiczba;
	if (pierwszaLiczba > drugaLiczba && pierwszaLiczba > trzeciaLiczba) {
		cout << "Najwieszka liczba to " << pierwszaLiczba;
	} else if (drugaLiczba > pierwszaLiczba && drugaLiczba > trzeciaLiczba) {
		cout << "Najwieksza liczba to " << drugaLiczba;
	} else {
		cout << "Najwieszka liczba to " << trzeciaLiczba;
	}
	return 0;
}
