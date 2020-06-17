#include <iostream>
#include <math.h>
using namespace std;
/* Program Cwiczenie 3 - Funkcje */
void myNameIs();
float surfaceAreaOfTrapezium(float firstBaseOfTrapezium, float secondBaseOfTrapezium, float heightOfTrapezium);
float functionValue(float xCoordinate);
float surfaceAreaOfTriangle(float firstSideOfTriangle, float secondSideOfTriangle, float angleDegrees);

int main(){
	float firstTrapezium, secondTrapezium, yCoordinate, firstTriangle, secondTriangle, xCoordinate;
	
	myNameIs();
	
	firstTrapezium = surfaceAreaOfTrapezium(4.5, 9.5, 3.3); // surfaceArea = 23.1
	secondTrapezium = surfaceAreaOfTrapezium(9, 5.5, 2.3); // surfaceArea = 16.675
	if ( firstTrapezium > secondTrapezium ){
		cout << "Pole wiekszego trapezu jest rowne " << firstTrapezium << endl;
	}
	else{
		cout << "Pole wiekszego trapezu jest rowne " << secondTrapezium << endl;
	}
	/*
		Test values: 
					x= -2, x coordinate -2 out of domain use function pattern 2/x, result y= -1
					x= 21, x coordinate 21 out of domain use function pattern 2/x, result y= 0.0952381
					x= -1, x coordinate -1 inside of domain use function pattern 2*x+1, result y= -1
					x= 20, x coordinate 20 inside of domain use function pattern 2*x+1, result y= 41
	*/
	cout << "Podaj dla jakiego argumentu chcesz policzyc wartosc: ";
	cin >> xCoordinate;
	yCoordinate = functionValue(xCoordinate);
	cout << "x=" << xCoordinate << " " << "y=" << yCoordinate << endl;
	
	firstTriangle = surfaceAreaOfTriangle(2, 4.5, 30); // surfaceArea = 2.25
	secondTriangle = surfaceAreaOfTriangle(4.5, 2, 45); // surfaceArea = 3.18198
	/*
		For test conditions else if please comment out line 38 and uncomment line 42
	*/
	//secondTriangle = surfaceAreaOfTriangle(2, 4.5, 30);
	if (firstTriangle > secondTriangle){
		cout << "Pole mniejszego trojkata jest rowne " << secondTriangle << endl;
	}
	else if (firstTriangle == secondTriangle){
		cout << "Pole obu trojkatow jest takie samo i wynosi  " << secondTriangle << endl;
	}
	else{
		cout << "Pole mniejszego trojkata jest rowne " << firstTriangle << endl;
	}
}

void myNameIs (){
	cout << "konfle\n";
	cout << "Numer indeksu = 123456\n";
}

float surfaceAreaOfTrapezium(float firstBaseOfTrapezium, float secondBaseOfTrapezium, float heightOfTrapezium){
	float surfaceArea;
	surfaceArea = ((firstBaseOfTrapezium + secondBaseOfTrapezium) * heightOfTrapezium) / 2;
	return surfaceArea;
}

float functionValue(float xCoordinate){
	if ((xCoordinate >= -1) and (xCoordinate <= 20)){
		return 2 * xCoordinate + 1;
	}
	else {
		return 2 / xCoordinate;
	}
}

float surfaceAreaOfTriangle(float firstSideOfTriangle, float secondSideOfTriangle, float angleDegrees){
	float surfaceArea, degreesToRadians;
	degreesToRadians = (angleDegrees * M_PI) / 180;
	surfaceArea = (firstSideOfTriangle * secondSideOfTriangle * sin(degreesToRadians)) / 2;
	return surfaceArea;
}
