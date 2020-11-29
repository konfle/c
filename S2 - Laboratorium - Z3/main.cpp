#include <iostream>
#include <cstdlib>
#include <ctime>

void losuj(float tab[][8], int N);
void wypisz(float tab[][8], int N);
float srednia(float tab[][8], int N);
void wypelnij_C(float dawca[][8], float biorca[8], int N);
void wypisz_C(float tab[], int N);
void wypelnij_D(float dawca[][8], float biorca[5], int N);
void wypisz_D(float tab[], int N);
void sort_A(float tab[][8], int N);

int main()
{
    const int N = 8;
    const int M = 5;
    srand(time(0));
    float A[8][8];
    float B[5][8];
    float wynik_sr;
    float C[N];
    float D[M];

    std::cout << "_TABLICA A_\n";
    losuj(A, N);
    wypisz(A, N);
    std::cout << "\n";

    std::cout << "_TABLICA B_\n";
    losuj(B, M);
    wypisz(B, M);
    std::cout << "\n";

    std::cout << "_SREDNIA POD PRZEKATNA TABLICY A_\n";
    wynik_sr = srednia(A, N);
    std::cout << "Srednia = " << wynik_sr << "\n\n";

    std::cout << "_TABLICA C_\n";
    wypelnij_C(B, C, N);
    wypisz_C(C, N);
    std::cout << "\n";

    std::cout << "_TABLICA D_\n";
    wypelnij_D(B, D, N);
    wypisz_D(D, N);
    std::cout << "\n";

    std::cout << "_TABLICA A Z UPORZADKOWANA PRZEKONTNA_\n";
    sort_A(A, N);
    wypisz(A, N);

    return 0;
}

void losuj(float tab[][8],int N)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 8 ;j++)
            tab[i][j] = (float)(std::rand() % 51) / 10;
}

void wypisz(float tab[][8], int N)
{
    for(int i = 0; i  < N; i++)
        {
            for(int j = 0; j < 8; j++)
                std::cout << tab[i][j] << "\t";
                std::cout << "\n";
        }
}

float srednia(float tab[][8], int N)
{
    float suma = 0, ilosc = 0, wynik;

        for(int i = 0; i  < N; i++)
        {
            for(int j = 0; j < 8; j++)
                if(i > j)
            {
                suma += tab[i][j];
                ilosc++;
            }
        }

    wynik = suma / ilosc;

    return wynik;
}

void wypelnij_C(float dawca[][8], float biorca[8], int N)
{
    float s = 0;

    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < 5; j++)
            s += dawca[j][i];

        biorca[i] = s;
        s = 0;
    }
}

void wypisz_C(float tab[], int N)
{
    for(int i = 0; i < N; i++)
        std::cout << tab[i] << "\t";
    std::cout << "\n";
}

void wypelnij_D(float dawca[][8], float biorca[8], int N)
{
    float najmniejszy;

    for(int i = 0; i < N; i++)
    {
        najmniejszy = dawca[i][0];
        for(int j = 0; j < 5; j++)
        {
            if(najmniejszy >= dawca[i][j])
            {
                najmniejszy = dawca[i][j];
                biorca[i] = najmniejszy;
            }
        }
    }
}

void wypisz_D(float tab[], int N)
{
    for(int i = 0; i < N; i++)
        std::cout << tab[i] << "\t";
    std::cout << "\n";
}

void sort_A(float tab[][8], int N)
{

    float sort_tab[8];

    /* Do tablicy sort_tab zapisujemy liczby przekatnej tablicy */
    for(int i = 0; i  < N; i++)
            sort_tab[i] = tab[i][i];

    /* Sortujemy malejaco wartosci przechowywane w tablicy sort_tab */
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N - 1; j++)
        {
            if(sort_tab[j] < sort_tab[j + 1])
                std::swap(sort_tab[j], sort_tab[j + 1]);

        }
    }

    /* Wstawiamy posortowane wartosci do tablicy 2 wymiarowej */
    for(int i = 0; i < N; i++)
        tab[i][i] = sort_tab[i];
}
