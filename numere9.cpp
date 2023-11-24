#include <fstream>
#include <cstring>
#include <cstdlib>
#define MAX_CIFRE 9
#define MAX_BUCATI 35
using namespace std;
ifstream citeste("numere9.in");
ofstream scrie("numere9.out");
struct Numar
{
    char cifre[MAX_CIFRE+1];
    int bucati[MAX_BUCATI], nrBucati;
};
void construiesteToateBucatile(Numar&);
bool esteCorectNumarul(char*, Numar);
int main()
{
	Numar nrScrisPeCartonas;
	citeste >> nrScrisPeCartonas.cifre;
	construiesteToateBucatile(nrScrisPeCartonas);
	int nrNumereDinLista;
	citeste >> nrNumereDinLista;
	while (nrNumereDinLista > 0)
	{
		char numar[MAX_CIFRE+1];
		citeste >> numar;
		if (esteCorectNumarul(numar, nrScrisPeCartonas))
		{
		    scrie << numar;
		    break;
		}
		nrNumereDinLista--;
	}
	citeste.close();
	scrie.close();
	return 0;
}
void convertesteNumarInSirDeCaractere(
	int numar,
	char sir[])
{
	int lungime = 0;
	while (numar)
	{
		sir[lungime++] = '0' + numar%10;
		numar /= 10;
	}
	int i, j;
	for (i = 0, j = lungime-1; i < j; i++, j--)
	{
		swap(sir[i], sir[j]);
	}
	sir[lungime] = 0;
}
void concateneazaDouaSiruri(
	char a[],
	char b[],
	char c[])
{
	strcpy(c, "");
	strcat(c, a);
	strcat(c, b);
}
int zeceLaPuterea(int nrPutere)
{
	int rezultat = 1;
	while (nrPutere > 0)
	{
		rezultat *= 10;
		nrPutere--;
	}
	return rezultat;
}
int pozitieNumarInVectorSortatCrescator(
	int numar,
	int vector[],
	int nrElemente)
{
    int stanga = -1, dreapta = nrElemente;
    while (dreapta-stanga > 1)
    {
        int mijloc = stanga + (dreapta-stanga)/2;
        if (vector[mijloc] < numar)
	{
            stanga = mijloc;
	}
        else
	{
            dreapta = mijloc;
	}
    }
    return dreapta;
}
int pozitieBucataLipsaDeLungime(
	int lungime,
	Numar nrScrisPeCartonas)
{
	int celMaiMicNumarEligibil = zeceLaPuterea(lungime-1);
	int pozitie = pozitieNumarInVectorSortatCrescator(
		celMaiMicNumarEligibil,
		nrScrisPeCartonas.bucati,
		nrScrisPeCartonas.nrBucati);
	if (pozitie >= 0
	    && pozitie < nrScrisPeCartonas.nrBucati)
	{
		return pozitie;
	}
	return -1;
}
bool esteCorectNumarul(
	char numar[],
	Numar nrScrisPeCartonas)
{
	int lungimeNumar = strlen(numar);
	for (int i = 0; i < nrScrisPeCartonas.nrBucati; i++)
	{
		char bucataStanga[MAX_CIFRE+1];
		convertesteNumarInSirDeCaractere(
			nrScrisPeCartonas.bucati[i],
			bucataStanga);
		int lungimeBucataStanga = strlen(bucataStanga);
		int lungimeBucataDreapta = lungimeNumar
		                           - lungimeBucataStanga;
		if (lungimeBucataDreapta < 2
		    || lungimeBucataDreapta > 8)
		{
			continue;
		}
		int j = pozitieBucataLipsaDeLungime(
			lungimeBucataDreapta,
			nrScrisPeCartonas);	
		if (j < 0)
		{
			continue;
		}
		while (j < nrScrisPeCartonas.nrBucati)
		{
			char bucataDreapta[MAX_CIFRE+1];
			convertesteNumarInSirDeCaractere(
				nrScrisPeCartonas.bucati[j],
				bucataDreapta);
			if (strlen(bucataDreapta) == lungimeBucataDreapta)
			{
				char bucata[MAX_CIFRE+1];
				concateneazaDouaSiruri(
					bucataStanga,
					bucataDreapta,
					bucata);
				if (strcmp(bucata, numar) == 0)
				{
					return 1;
				}
				j++;
			}
			else
			{
				break;
			}
		}
	}
	return 0;
}
void insereazaNumarInVectorLaPozitia(
	int numar,
	int vector[],
	int & nrElemente,
	int pozitie)
{
    for (int i = nrElemente; i > pozitie; i--)
    {
        vector[i] = vector[i-1];
    }
    vector[pozitie] = numar;
    nrElemente++;
}
bool existaNumarInVectorSortatCrescator(
	int numar,
	int pozitie,
	int vector[],
	int nrElemente)
{
    if (pozitie >= 0 && pozitie < nrElemente)
    {
        if (vector[pozitie] == numar)
	{
            return 1;
	}
    }
    return 0;
}
void construiesteToateBucatile(Numar & numar)
{
	numar.nrBucati = 0;
	int nrCifre = strlen(numar.cifre);
	if (nrCifre > 2)
	{
		for (int lungime = 2; lungime < nrCifre; lungime++)
		{
			for (int i = 0; i <= nrCifre-lungime; i++)
			{
				char bucata[MAX_CIFRE+1] = "";
				strncpy(bucata, numar.cifre + i, lungime);
				bucata[lungime] = 0;
				while (bucata[0] == '0')
				{
					strcpy(bucata, bucata+1);
				}
				int nrCifreBucata = strlen(bucata);
				if (nrCifreBucata > 0 && nrCifreBucata < 8)
				{
				    int nr = atoi(bucata);
				    int pozitie = pozitieNumarInVectorSortatCrescator(
							nr,
							numar.bucati,
							numar.nrBucati);
				    if (!existaNumarInVectorSortatCrescator(
					    nr,
					    pozitie,
					    numar.bucati,
					    numar.nrBucati))
				    {
					insereazaNumarInVectorLaPozitia(
						nr,
						numar.bucati,
						numar.nrBucati,
						pozitie);
				    }
				}
			}
		}
	}
}
