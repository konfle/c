// Easy calc with calss for circuit and surface areas

#include <iostream>
#include <cmath>
using namespace std;

class square {
	public:
		void areaOfSquare(double aLength) {
			cout << "Area of your square is: " << aLength * aLength << "\n\n";
			system("pause");
			system("cls");
		}
		void circuitOfSquare(double aLength){
			cout << "Circuit of your rectangle is: " << 4 * aLength << "\n\n";
			system("pause");
			system("cls");
		}
};

class rectangle {
	public:
		void areaOfRectangle(double a, double b) {
			cout << "Area of your square is: " << a * b << "\n\n";
			system("pause");
			system("cls");
		}
		void circuitOfRectangle(double a, double b) {
			cout << "Circuit of your rectangle is: " << (2 * a) + (2 * b) << "\n\n";
			system("pause");
			system("cls");
		}
};

class circle {
	public:
		void areaOfCircle(double r){
			cout << "Area of your circle is: " << 2 * M_PI * r << "\n\n";
			system("pause");
			system("cls");
		}
		void circuitOfCircel(double r) {
			cout << "Circuit of your circle is: " << M_PI * (r * r) << "\n\n";
			system("pause");
			system("cls");
		}
};

int main() {
	/*
	int a;
    square sqareObject;
    cout << "Give me a side length from your suare: " << endl;
    cin >> a;
    sqareObject.areaOfSquare(a);
    sqareObject.circuitOfSquare(a);
    */
	int choice;
	double squareLength, aLengthOfRectangle, bLengthOfRectangle, radiusOfCircle;
	bool start = true;
	square sqareObject;
	rectangle rectangleObject;
	circle circleObject;
	while (start == true){
		cout << "What we will count?\n\n Square:\n 1 - surface area\n 2 - circuit\n\n Rectangle:\n 3 - surface area\n 4 - circuit \n\n Circle:\n 5 - surface area \n 6 - circuit \n\n For exit from program choice 0 or type exit" << endl;
		cin >> choice;
		if (choice == 1) {
			system("cls");
			cout << "Give me a side length from your square: " << endl;
			cin >> squareLength;
			sqareObject.areaOfSquare(squareLength);		
		} else if (choice == 2) {
			system("cls");
			cout << "Give me a side length from your square: " << endl;
			cin >> squareLength;	
			sqareObject.circuitOfSquare(squareLength);
		} else if (choice == 3) {
			system("cls");
			cout << "Give me a side length from your rectangle: " << endl;
			cin >> aLengthOfRectangle;
			cout << "Give me b side length from your rectangle: " << endl;
			cin >> bLengthOfRectangle;
			rectangleObject.areaOfRectangle(aLengthOfRectangle, bLengthOfRectangle);
		} else if (choice == 4) {
			system("cls");
			cout << "Give me a side length from your rectangle: " << endl;
			cin >> aLengthOfRectangle;
			cout << "Give me b side length from your rectangle: " << endl;
			cin >> bLengthOfRectangle;
			rectangleObject.circuitOfRectangle(aLengthOfRectangle, bLengthOfRectangle);
		} else if (choice == 5) {
			system("cls");
			cout << "Give me radius from your circle: " << endl;
			cin >> radiusOfCircle;
			circleObject.areaOfCircle(radiusOfCircle);			
		} else if (choice == 6) {
			system("cls");
			cout << "Give me radius from your circle: " << endl;
			cin >> radiusOfCircle;
			circleObject.circuitOfCircel(radiusOfCircle);
		}
		else if (choice == 0) {
			cout << "BYE!";
			start = false;
		} else {
			cout << "Sorry not ready yet. \nPlease use numbers from list.\n" << endl;
			system("pause");
			system("cls");
		}
	}
return 0;
}
