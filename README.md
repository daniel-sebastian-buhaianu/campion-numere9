# campion-numere9
#include <fstream>
#include <cstring>
#define MAX_CIFRE 9
using namespace std;
int rezultat;
void citesteDateleDeIntrare();
void afiseazaDateleDeIesire();
int main()
{
	citesteDateleDeIntrare();
	afiseazaDateleDeIesire();
	return 0;
}
void convertesteNumarInSirDeCaractere(int numar, char sir[])
{
	int lg = 0;
	while (numar)
	{
		sir[lg++] = '0' + numar%10;
		numar /= 10;
	}
	int i, j;
	for (i = 0, j = lg-1; i < j; i++, j--)
		swap(sir[i], sir[j]);
	sir[lg] = 0;
}
bool esteCorect(int numar, int numarScrisPeCartonas)
{
	char sirNumar[MAX_CIFRE+1], sirNumarCartonas[MAX_CIFRE+1];
	convertesteNumarInSirDeCaractere(numarScrisPeCartonas, sirNumarCartonas);
	convertesteNumarInSirDeCaractere(numar, sirNumar);
	int n = strlen(sirNumar);
	int m = strlen(sirNumarCartonas);
	if (n > m) return 0;
	if (n < 4) return 0;
	int nrPerechi, i;
	for (nrPerechi = i = 0; i < n-1; i++)
	{
		char pereche[3];
		pereche[0] = sirNumar[i];
		pereche[1] = sirNumar[i+1];
		pereche[2] = 0;
		if (strstr(sirNumarCartonas, pereche))
			nrPerechi++;
		else if (i == 0 || i == n-2) return 0;
	}
	if (nrPerechi != n-2) return 0;
	return 1;
}
void citesteDateleDeIntrare()
{
	ifstream citeste("numere9.in");
	int numarScrisPeCartonas, nrNumere;
	citeste >> numarScrisPeCartonas;
	citeste >> nrNumere;
	while (nrNumere > 0 && !rezultat)
	{
		int numar;
		citeste >> numar;
		if (esteCorect(numar, numarScrisPeCartonas))
			rezultat = numar;
		nrNumere--;
	}
	citeste.close();
}
void afiseazaDateleDeIesire()
{
	ofstream scrie("numere9.out");
	scrie << rezultat;
	scrie.close();
}
