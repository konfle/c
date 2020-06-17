#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <iomanip>

/* Poprawa cwiczenie 2 */

int main() {
	int lastElement, numbersOfRows, size, root, fractional, result = 1, wybor, repeat, keyPress;
	double summary = 0;
do {
	std::cout << "\t|Menu Glowne| \n\n\t1 - Suma \n\t2 - Polowa choinki \n\t3 - Tabliczka mnozenia \n\t4 - Potegowanie \n\nENTER, aby potwierdzic wybor.\n";
	std::cin >> keyPress;
	system("CLS");
	switch (keyPress){
		case 1:
// SUMA
			std::cout << "Podaj ostatni element sumy: ";
			std::cin >> lastElement;
			system("CLS");
			while (lastElement < 1){
			std::cout << "Ostatni element musi byc >= 1!\n Wprowadz ponownie ostatni element: ";
			std::cin >> lastElement;
			system("CLS");
			}
			for (float i = 1; i <= lastElement; i++){
				summary = (i + 1) / (2 * i * i + 1);
				}
			std::cout << "Wynik sumowania to " << lastElement << " elementow to: " << summary << "\n\n";
		break;
		case 2:
// POLOWA CHOINKI
			std::cout << "Wprowadz liczbe wierszy: ";
			std::cin >> numbersOfRows;
			system("CLS");
			while (numbersOfRows < 1){
				std::cout << "Liczba musi byc (>= 1)! \n Wprowadz ponownie: ";
				std::cin >> numbersOfRows;	
				system("CLS");
			}
			std::cout << "Oto Twoja polowka :) \n\n";
			for (int i = 0; i <= numbersOfRows-1; i++){
				for (int j=0; j <= i; j++){
					std::cout << "*";
				}
				std::cout << "\n";
			}
			std::cout << "\n";
		break;
		case 3:
// TABLICZKA MNOZENIA
			std::cout << "Do ilu liczb chcesz wyswietlic tabliczke? \n Wprowadz wartosc od 1 do 10: ";
			std::cin >> size;
			std::cout << "\n";
			system("CLS");
			while (size < 1 or size > 10){
			std::cout << "Podana liczba jest poza przedzialem <1,10>\n Wprowadz ponownie: ";
			std::cin >> size;
			system("CLS");
			}	
			std::cout << "Ponizej Twoja tabliczka mnozenia.\n\n";
			for(int i = 1; i <= size; i++){
    			for(int j = 1; j <= size; j++){
        			std::cout << std::setw(4) << i * j;
   				}
   				std::cout << "\n";
   			}
   			std::cout << "\n";
   		break;
		case 4:
// POTEGOWANIE
   			std::cout << "Podaj liczbe ktora chcesz potegowac: ";
   			std::cin >> root;
   			std::cout << "Podaj do ktorej potegi podniesc Twoja liczbe: ";
   			std::cin >> fractional;
   			std::cout << "\n";
   			
   			while (fractional < 0){
   				std::cout << "Potega musi byc wieksza badz rowna zera\n Podaj liczbe: ";
   				std::cin >> fractional;
   			}
   			
   			for (int i = 0; i < fractional; i++){
   				result *= root;
   			}
   			std::cout << "Wynik potegowania to: " << result << "\n\n";
   		break;
   		default:
   			std::cout << "Oops, ";
   }
   	std::cout << "czy chcesz powtorzyc (0-nie | 1-tak)?\n";
   	std::cin >> repeat;
   	system("CLS");
}
while (repeat == 1);
	std::cout << "Dzieki, do zobaczenia!";
}
