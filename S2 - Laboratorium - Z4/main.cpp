#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#define N 2 //ilosc osob
#define M 3 //ilosc ocen

struct STUDENT
{
    std::string nazwisko;
    float oceny[N];
    float srednia;
};

void wczytaj_studenta(STUDENT persona[]);
float srednia_ocen(STUDENT persona[]);
void sprawdz_srednia(STUDENT persona[], float srednia_wszystkich);
void wyswietl_dane(STUDENT persona[]);
void wyswietl_najwyzsza_srednia(STUDENT persona[]);
void wyszukaj_studenta(STUDENT persona[]);

int main()
{
    float avg = 0;
    srand(time(0));
    STUDENT lista[N];

    std::cout << "_POBIERANIE DANYCH STUDENTOW_\n";
    wczytaj_studenta(lista);

    std::cout << "_SRENIDA OCEN WSZYSTKICH STUDENTOW_\n";
    avg = srednia_ocen(lista);
    std::cout << "Srednia ocen " << N << " studentow wynosi " << avg << "\n";
    std::cout << "\n";

    std::cout << "_LICZBA STUDENTOW ZE SREDNIA WYZSZA NIZ SREDNIA WSZYSTKICH_\n";
    sprawdz_srednia(lista, avg);

    std::cout << "_WYSWIETALM DANE STUDENTOW_\n";
    wyswietl_dane(lista);

    std::cout << "_NAJWYZSZA SREDNIA_\n";
    wyswietl_najwyzsza_srednia(lista);

    std::cout << "_WYSZUKIWANIE STUDENTA_\n";
    wyszukaj_studenta(lista);

    return 0;
}

void wczytaj_studenta(STUDENT persona[])
{
    float ocena, srednia, suma;

    for(int i = 0; i < N; i++)
    {
        srednia = 0;
        suma = 0;

        std::cout << "Podaj nazwisko studenta: ";
        std::cin >> persona[i].nazwisko;

        // losowanie ocen studenta
        for(int j = 0; j < M; j++)
        {
            ocena = 4 + (rand() % 7); // <2,5> 4, bo chcemy od 2, 7 bo chcemy miec 7 ocen od 2, 2.5, 3, 3.5, 4, 4.5, 5
            persona[i].oceny[j] = ocena;

        }

        // srednia ocen studenta
        for(int k = 0; k < M; k++)
            suma += persona[i].oceny[k];
        srednia = (suma / M) / 2.;
    }
    std::cout << "\n";
}

float srednia_ocen(STUDENT persona[])
{
    float suma = 0, ocena;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
        {
            ocena = persona[i].oceny[j] / 2;
            suma += ocena;
        }
    return suma / (N * M);
}

void sprawdz_srednia(STUDENT persona[], float srednia_wszystkich)
{
    int licznik = 0;
    float srednia, suma;

    for(int i = 0; i < N; i++)
    {
        srednia = 0;
        suma = 0;

        for(int k = 0; k < M; k++)
            suma += persona[i].oceny[k];

        srednia = (suma / M) / 2.;
        if(srednia > srednia_wszystkich)
        {
            licznik++;
            std::cout << "+------------------------+\n";
            std::cout << "Nazwisko: " << persona[i].nazwisko << "\nSrednia: " << srednia << "\n";
            std::cout << "+------------------------+\n";
        }
    }
    if(licznik == 1)
        std::cout << "Jeden student ma srednia wyzsza niz " << srednia_wszystkich <<".\n\n";
    else if(licznik == 0)
        std::cout << "Zaden student nie ma sredniej wyzszej niz " << srednia_wszystkich << " to " << licznik << ".\n\n";
    else
        std::cout << "Liczba studentow ze srednia wyzsza niz " << srednia_wszystkich << " to " << licznik << ".\n\n";
}

void wyswietl_dane(STUDENT persona[])
{
    float suma, srednia;

    std::cout << "+------------------------+\n";

    for(int i = 0; i < N; i++)
    {
        suma = 0;
        srednia = 0;
        std::cout << "Nazwisko: " << persona[i].nazwisko << "\n";

        // srednia ocen studenta
        for(int k = 0; k < M; k++)
            suma += persona[i].oceny[k];

        srednia = (suma / M) / 2.;
        std::cout << "Srednia: " << srednia << "\n";

        // oceny studenta
        std::cout << "Oceny : ";
        for(int j = 0; j < M; j++)
            std::cout << "[" << persona[i].oceny[j] / 2 << "] ";

        std::cout << "\n+------------------------+\n";
    }
    std::cout << "\n";
}

void wyswietl_najwyzsza_srednia(STUDENT persona[])
{
    float najwyzsza_srednia = 0, suma, srednia;
    std::string nazwisko;

    for(int i = 0; i < N; i++)
    {
        suma = 0;
        srednia =0;

        // srednia ocen studenta
        for(int k = 0; k < M; k++)
            suma += persona[i].oceny[k];

        srednia = (suma / M) / 2;

        if(srednia >= najwyzsza_srednia)
        {
            najwyzsza_srednia = srednia;
            nazwisko = persona[i].nazwisko;
        }
    }
    std::cout << "Nazwisko: " << nazwisko << "\nSrednia: " << najwyzsza_srednia << "\n\n";
}

void wyszukaj_studenta(STUDENT persona[])
{
    std::string nazwisko;
    float suma = 0, srednia = 0, ocena = 0;

    std::cout << "Wyszukaj: ";
    std::cin >>  nazwisko;

    for(int i = 0; i < N; i++)
        if(nazwisko == persona[i].nazwisko)
        {
            std::cout << "\nWYNIK WYSZUKIWANIA\n";
            std::cout << "Nazwisko: " << nazwisko << "\n";
            std::cout << "Oceny: ";
            for (int j = 0; j < M; j++)
            {
                ocena = persona[i].oceny[j] / 2;
                std::cout << "[" << ocena << "] ";
                suma += ocena;
            }
            srednia = suma / M;
            std::cout << "\nSrednia: " << srednia << "\n";
        }
}
