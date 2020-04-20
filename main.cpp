#include <iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;

/* Program do cwiczenia 2 */

int main() {
	int N, LW, rozmiar, a, b, x, y, wynik = 1, wybor, powtorzenie;
	double sum;
	string s = "*";
do {
	cout<<" ======\n |MENU|\n ======\n Wybierz numer zadania:\n\n 1 - Suma \n 2 - Polowa piramidy \n 3 - Tabliczka mnozenia \n 4 - Potegowanie \n\n Aby potwierdzic wybor nacisnij ENTER\n";
	cin>>wybor;
	system("CLS");
	switch (wybor){
		case 1:
		// SUMA
			cout<<"Podaj ostatni element sumy: ";
			cin>>N;
			while (N < 1){
			cout<<"Ostatni element musi byc wiekszy badz rowny 1!\n Podaj ponownie ostatni element:";
			cin>>N;
			}
			if (N >= 1){
				for (float i = 1; i <= N; i++){
					sum = (i+1)/(2 * i * i + 1);
					}
				cout<<"Wynik sumowania "<<N<<" elementow wedlug wzoru z zadania pierwszego to "<<sum<<"\n";
			} else {
				cout<<"ups, cos poszlo nie tak!"<<endl;
				}
		break;
		case 2:
		// POLOWA PIRAMIDY
			cout<<"Podaj liczbe wierszy: ";
			cin>>LW;
			for (int i = 0; i <= LW-1; i++){
				for (int j=0; j <= i; j++){
					cout<<s;
				}
				cout<<"\n";
			}
		break;
		case 3:
		// TABLICZKA MNOZENIA
			cout<<"Podaj liczbe w przedziele od 1 do 10: ";
			cin>>rozmiar;
			while (rozmiar < 1 || rozmiar > 10){
			cout<<"Liczba musi byc w przedziale od 1 do 10!\n Podaj liczbe w przedziale: ";
			cin>>rozmiar;
			}	
			for(int i = 1; i <= rozmiar; i++){
    			for(int j = 1; j <= rozmiar; j++){
        			cout<<"\t"<<i*j;
   				}
   				cout<<"\n";
   			}
   		break;
		case 4:
   		// POTEGOWANIE
   			cout<<"Podaj liczbe ktora chcesz potegowac: ";
   			cin>>x;
   			cout<<"Podaj do ktorej potegi podniesc Twoja liczbe: ";
   			cin>>y;
   			while (y < 0){
   				cout<<"Potega musi byc wieksza badz rowna zera\n Podaj liczbe: ";
   				cin>>y;
   			}
   			for (int i = 0; i < y; i++){
   				wynik*=x;
   			}
   			cout<<"Wynik potegowania to: "<<wynik<<endl;
   		break;
   }
   	cout<<"czy powtorzyc (0-nie, 1-tak)?\n";
   	cin>>powtorzenie;
   	system("CLS");
}
while (powtorzenie == 1);
cout<<"DO ZOBACZENIA!";
}
