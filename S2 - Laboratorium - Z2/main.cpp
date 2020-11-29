#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

void draw(int table[], int beginning, int ends);
void write(int table[]);
float average(int table[]);
void sorting(int table[]);
void how_many_gave_the_grade(int table_1[], int table_2[]);
void write_sorted_grade(int table[], int M);
void grade_frequency(int table[], int M);
void histogram(int table[], int M);
void mediana(int table[]);

#define N 100
int main()
{
    srand(time(0));
    const int M = 11;
    int student[N], beginning = 0, ends = 10, assessment[M];
    float average_value = 0.;

    std::cout<< "<--- OCENY STUDENTOW -->\n";
    draw(student, beginning, ends);
    write(student);
    average_value = average(student);

    std::cout<< "\n<--- SREDNIA OCEN -->";
    std::cout << "\nSrednia ocen studentow to: "<< average_value << "\n";

    std::cout<< "\n<--- POSORTOWANE OCENY -->\n";
    sorting(student);
    write(student);

    std::cout << "\n<--- MEDIANA -->\n";
    mediana(student);


    how_many_gave_the_grade(student, assessment);
    std::cout << "\n<--- ILOSC OCEN -->\n";
    write_sorted_grade(assessment, M);

    std::cout << "\n<--- NAJWYZSZA CZESTOTLIWOSC OCEN -->\n";
    grade_frequency(assessment, M);

    std::cout << "\n<--- HISTOGRAM OCEN -->\n";
    histogram(assessment, M);

return 0;
}

void draw(int table[], int beginning, int ends)
{
    /* losujemy wartosci do tablicy N elementowej.
       Z zakresu ustalonego zmiennymi p i k */
    for (int i = 0; i < N; i++)
    {
        table[i] = beginning + rand() % (ends - beginning + 1);
    }
}

void write(int table[])
{
    int counter = 0;

    /* iterujemy po tablicy i wypisujemy jej elementy.
       Zmienna licznik odpowaida za wyswietlanie 10 elementow w linii */
    for (int i = 0; i < N; i++)
    {
        std::cout << table[i] << "\t";
        counter++;

        if (counter % 10 == 0)
        {
             std::cout << "\n";
        }
    }
}

float average(int table[])
{
	float  sum = 0., result;

	// iterujemy po tablicy sumujac elementy
	for (int i = 0.; i < N; i++)
    {
        sum += table[i];
    }

    // obliczamy srednia
    result = sum / N;

    // zwracamy wynik
	return result;
}

void sorting(int table[])
{

    /* iterujemy po tablicy sprawdzajac czy wartosc jest wieksza
       od kolejnej jesli tak to zamieniemy miejscami.
       Petla zagniezdzona, bo chcemy sprawdzic wszystkie elementy tablicy.
       Sortujemy tablice korzystajac z algorytmu sortowania babelkowego*/
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - 1; j++)
        {
            if(table[j] > table[j + 1])
            {
               std::swap(table[j], table[j + 1]);
        }
            }

    }
}

void how_many_gave_the_grade(int table_1[], int table_2[])
{
    int i = 0, zero = 0, one = 0, two = 0,
    three = 0, four = 0, five = 0, six = 0,
    seven = 0, eight = 0, nine = 0,
    ten = 0;

    /* iterujemy po tablicy aby sprawdzic jej wartosci i
       przypisujemy do odpowiedniej smiennej zmiennej */
    for (i; i < N; i++)
    {
        if (table_1[i] == 0)
        {
            zero++;
        }
        else if (table_1[i] == 1)
        {
            one++;
        }
        else if (table_1[i] == 2)
        {
            two++;
        }
        else if (table_1[i] == 3)
        {
            three++;
        }
        else if (table_1[i] == 4)
        {
            four++;
        }
        else if (table_1[i] == 5)
        {
            five++;
        }
        else if (table_1[i] == 6)
        {
            six++;
        }
        else if (table_1[i] == 7)
        {
            seven++;
        }
        else if (table_1[i] == 8)
        {
            eight++;
        }
        else if (table_1[i] == 9)
        {
            nine++;
        }
        else if (table_1[i] == 10)
        {
            ten++;
        }
    }

    // do odpowiedniego elementu przypisujemy wartosc zmiennej
    table_2[0] = zero;
    table_2[1] = one;
    table_2[2] = two;
    table_2[3] = three;
    table_2[4] = four;
    table_2[5] = five;
    table_2[6] = six;
    table_2[7] = seven;
    table_2[8] = eight;
    table_2[9] = nine;
    table_2[10] = ten;
}

void write_sorted_grade(int table[], int M)
{
    // wypisujemy ilosc ocen dla danej oceny
    for(int i = 0; i < M; i++)
    {
        std::cout <<"Ocena: "<< i << "\tilosc: " << table[i] << "\n";
    }
}

void grade_frequency(int table[], int M)
{
    int highest = 0, amount = 0;

    // ustalamy najwyzsza ilosc glosow
    for(int i=0; i < M; i++)
    {
        if (table[i] >= highest)
        {
            highest = table[i];
        }
    }

    /* sprawdzamy czy wartosc w tablicy rowna sie najwyzszej
       jesli tak to wypisujemy */
    for(int i = 0; i < M; i++)
    {
        if(table[i] == highest)
        {
            std::cout << "Ocena: " << i << "\tilosc: " << highest << "\n";
        }
    }
}

void histogram(int table[], int M)
{
    /* iterujemy po elementach wypisujac element tablicy jako ocene,
       dzieki petli zagniezdzonej wyswietalamy "*"
       w iloœci odpowiadaj¹cej dla danej oceny */
    for(int i = 0; i < M; i++)
    {
        std::cout << "Ocena " << i << ": ";

        for(int j = 0; j < table[i]; j++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}


void mediana(int table[])
{
    int median_value = 0;

    /* sprawdzamy czy rozmiar tablicy jest
       nieparzysty czy parzysty i obliczamy mediane */
    if (N % 2 == 1)
    {
        median_value = N/2;
        std::cout << "Mediana: " << table[median_value] << "\n";
    }
    else
    {
        median_value = N/2;
        std::cout << "Mediana: " << (table[median_value - 1] + table[median_value]) / 2. << "\n";
    }
}
