#include <iostream>
#include <cstdlib>
#include <ctime>

void draw(int table[], int N, int beginning, int ends);
void write(int table[], int N);
int max_value(int table_1, int table_2, int table_3);
int max_element_in_table(int table[], int N, int &how_many_times_appers);
float average_higher_than_average(int table[], int N, float &average);


int main(int argc, char** argv)
{

	srand(time(0));
	const int N = 10;
	float average = 0.0;
	int tab_X[N], tab_Y[N], tab_Z[N], tab_Q[N], beginning,
	ends, how_many_times_appers = 0, max_for_X,
    max_for_Y, reset_variable, higher_than_average;


	// Wczytywanie poczatku i konca przedzialu
	std::cout << "<--- USTALANIE PRZEDZIALU --->\n";
    std::cout << "Poczatek przedzialu: ";
    std::cin >> beginning;
    std::cout << "Koniec przedzialu: ";
    std::cin >> ends;
    std::cout << "\n";

    // Tablica X
    std::cout << "<--- ZESTAW TABLIC --->\n";
    std::cout << "Tablica X: ";
    draw(tab_X, N, beginning, ends);
    write(tab_X, N);
    std::cout << "\n";

    // Tablica Y
    std::cout << "Tablica Y: ";
    draw(tab_Y, N, beginning, ends);
    write(tab_Y, N);
    std::cout << "\n";

    // Tablica Z
    std::cout << "Tablica Z: ";
    draw(tab_Z, N, beginning, ends);
    write(tab_Z, N);
    std::cout << "\n";
    std::cout << "-------------------------------------------------\n";

    // Tablica Q
    std::cout << "Tablica Q: ";
    int i = 0;
    for(i; i < N; i++)
    {
        tab_Q[i] = max_value(tab_X[i], tab_Y[i], tab_Z[i]);
    }
    write(tab_Q, N);
    std::cout << "\n\n";

    std::cout << "<--- MAKSYMALNY ELEMENT I ILE RAZY WYSTAPIL --->\n";
    max_for_X = max_element_in_table(tab_X, N, how_many_times_appers);
    std::cout << "Najwieksza liczba w tablicy X to " << max_for_X <<
    " pojawila sie w niej "<< how_many_times_appers << " raz/y." << "\n";

    reset_variable = 0;
    how_many_times_appers = reset_variable;
    max_for_Y = max_element_in_table(tab_Y, N, how_many_times_appers);
    std::cout << "Najwieksza liczba w tablicy Y to " << max_for_Y <<
    " pojawila sie w niej "<< how_many_times_appers << " raz/y." << "\n\n";

    std::cout << "<--- SREDNIA I ILOSC LICZ WIEKSZYCH OD SREDNIEJ --->\n";
    higher_than_average = average_higher_than_average(tab_X, N, average);
    std::cout << "Srednia tablicy X jest rowna: " << average <<
    ", a ilosc liczb wiekszych od sredniej to: " << higher_than_average << "." << "\n\n";

    std::cout << "<--- TABLICA DYNAMICZNA --->\n";
    int *dynamiczna_tablica = new int[higher_than_average];
    std::cout << "Tablica o dynamicznym rozmiarze rowna ilosci liczb wiekszych od sredniej z tablicy X." << "\n";
    draw(dynamiczna_tablica, higher_than_average, beginning, ends);
    std::cout << "Tablica D: ";
    write(dynamiczna_tablica, higher_than_average);
    std::cout << "\n";
    delete [] dynamiczna_tablica;

	return 0;
}
void draw(int table[], int N, int beginning, int ends)
{
    int i;

    for (i = 0; i < N; i++)
        table[i] = beginning + rand() % (ends - beginning + 1);
}

void write(int table[], int N)
{
    for (int i = 0; i < N; i++)
        std::cout << table[i] << "  ";
}

int max_value(int table_1, int table_2, int table_3)
{
    if (table_1 > table_2 and table_1 > table_3)
        return table_1;
    else if (table_2 > table_1 and table_2 > table_3)
        return table_2;
    else
        return table_3;
}

int max_element_in_table(int table[], int N, int &how_many_times_appers)
{
	int maximal_value = table[0];

	for (int i = 0; i < N; i++)
    {
        if (maximal_value < table[i])
            maximal_value = table[i];
	}

	for (int i = 0; i < N; i++)
    {
		if (table[i] == maximal_value)
			how_many_times_appers++;
	}

	return maximal_value;
}

float average_higher_than_average(int table[], int N, float &average)
{
	float  sum = 0.;
	int how_much_larger_than_average = 0;

	for (int i=0.; i < N; i++)
    {
        sum += table[i];
    }
	average = sum / N;

	for (int i = 0; i < N; i++)
    {
        if (table[i] > average)
            how_much_larger_than_average++;
    }

	return how_much_larger_than_average;
}
