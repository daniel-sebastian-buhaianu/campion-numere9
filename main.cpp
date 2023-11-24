#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX_CIFRE 9
#define MAX_BUCATI 35
#define MAX_NUMERE MAX_BUCATI*MAX_BUCATI
using namespace std;
struct Numar
{
    char cifre[MAX_CIFRE+1];
    int bucati[MAX_BUCATI], nrBucati;
};
void construiesteToateBucatile(Numar &);
int main()
{
	ifstream citeste("numere9.in");
	Numar x;
	citeste >> x.cifre;
	construiesteToateBucatile(x);
	int n;
	citeste >> n;
	while (n > 0)
	{
	    char y[MAX_CIFRE+1];
		citeste >> y;
		if (esteNumarCorect(y, x))
        {
            ofstream scrie("numere9.out");
            scrie << y;
            scrie.close();
            break;
        }
		n--;
	}
	citeste.close();
	return 0;
}
bool esteNumarCorect(char nrDinLista[], Numar nrScrisPeCartonas)
{
    for (int i = 0; i < nrScrisPeCartonas.nrBucati; i++)
    {
        char bucataStanga[MAX_CIFRE+1] = "";
        strcpy(bucataStanga, )
    }
}
int pozitieNumarInVectorSortatCrescator(int numar, int vector[], int nrElemente)
{
    int stanga = -1, dreapta = nrElemente;
    while (dreapta-stanga > 1)
    {
        int mijloc = stanga + (dreapta-stanga)/2;
        if (vector[mijloc] < numar)
            stanga = mijloc;
        else
            dreapta = mijloc;
    }
    return dreapta;
}
void insereazaNumarInVectorLaPozitia(int numar, int vector[], int & nrElemente, int pozitie)
{
    for (int i = nrElemente; i > pozitie; i--)
        vector[i] = vector[i-1];
    vector[pozitie] = numar;
    nrElemente++;
}
bool existaNumarInVectorSortatCrescator(int numar, int pozitie, int vector[], int nrElemente)
{
    if (pozitie >= 0 && pozitie < nrElemente)
        if (vector[pozitie] == numar)
            return 1;
    return 0;
}
void construiesteToateBucatile(Numar & numar)
{
	numar.nrBucati = 0;
	int nrCifre = strlen(numar.cifre);
	if (nrCifre > 2)
		for (int lungime = 2; lungime < nrCifre; lungime++)
			for (int i = 0; i <= nrCifre-lungime; i++)
			{
				char bucata[MAX_CIFRE+1] = "";
				strncpy(bucata, numar.cifre + i, lungime);
				bucata[lungime] = 0;
				while (bucata[0] == '0') strcpy(bucata, bucata+1);
				int nrCifreBucata = strlen(bucata);
				if (nrCifreBucata > 0 && nrCifreBucata < 8)
                {
                    int nr = atoi(bucata);
                    int pozitie = pozitieNumarInVectorSortatCrescator(nr, numar.bucati, numar.nrBucati);
                    if (!existaNumarInVectorSortatCrescator(nr, pozitie, numar.bucati, numar.nrBucati))
                        insereazaNumarInVectorLaPozitia(nr, numar.bucati, numar.nrBucati, pozitie);
                }
			}
}
