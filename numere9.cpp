#include <fstream>
#include <cstring>
#include <cstdlib>
#define MAX_CIFRE 9
#define MAX_BUCATI 35
#define MAX_NUMERE MAX_BUCATI*MAX_BUCATI
using namespace std;
char bucati[MAX_BUCATI][MAX_CIFRE+1];
int numere[MAX_NUMERE], nrBucati, nrNumere;
void construiesteToateBucatile(char *);
void construiesteToateNumerele();
int pozitieInSirCrescator(int numar, int vector[], int nrElemente);
int main()
{
	char numarScrisPeCartonase[MAX_CIFRE+1];
	int numarulDeNumereDinLista;
	ifstream citeste("numere9.in");
	citeste >> numarScrisPeCartonase;
	construiesteToateBucatile(numarScrisPeCartonase);
	construiesteToateNumerele();
	citeste >> numarulDeNumereDinLista;
	while (numarulDeNumereDinLista > 0)
	{
		int numar;
		citeste >> numar;
		int pozitie = pozitieInSirCrescator(numar, numere, nrNumere);
		if (pozitie < nrNumere && numere[pozitie] == numar)
		{
			ofstream scrie("numere9.out");
			scrie << numar;
			scrie.close();
			break;
		}
		numarulDeNumereDinLista--;
	}
	citeste.close();
	return 0;
}
void lipesteBucati(char bucataStanga[], char bucataDreapta[], char bucata[])
{
	strcpy(bucata, "");
	strcat(bucata, bucataStanga);
	strcat(bucata, bucataDreapta);
}
int pozitieInSirCrescator(int numar, int vector[], int nrElemente)
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
	for (int i = nrElemente; i > pozitie; i--) vector[i] = vector[i-1];
	vector[pozitie] = numar;
	nrElemente++;
}
void construiesteToateNumerele()
{
	for (int i = 0; i < nrBucati; i++)
		for (int j = 0; j < nrBucati; j++)
		{
			if (strlen(bucati[i]) + strlen(bucati[j]) <= MAX_CIFRE)
			{
				char bucata[MAX_CIFRE+1];
				lipesteBucati(bucati[i], bucati[j], bucata);
				int nr = atoi(bucata); // converteste sir in numar intreg
				int poz = pozitieInSirCrescator(nr, numere, nrNumere);
				insereazaNumarInVectorLaPozitia(nr, numere, nrNumere, poz);
			}
		}
}
void construiesteToateBucatile(char numar[])
{
	nrBucati = 0;
	int nrCifre = strlen(numar);
	if (nrCifre > 2)
		for (int lungime = 2; lungime < nrCifre; lungime++)
			for (int i = 0; i <= nrCifre-lungime; i++)
			{
				char bucata[MAX_CIFRE+1] = "";
				strncpy(bucata, numar + i, lungime);
				bucata[lungime] = 0;
				strcpy(bucati[nrBucati++], bucata);
			}
}
