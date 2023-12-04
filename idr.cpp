// Solutie 100p
// Iulian-Daniel Rusu
#include <fstream>
#include <cstring>
 
using namespace std;
 
ifstream fin("numere9.in");
ofstream fout("numere9.out");
 
char v[12], r[12], sir1[15002][12], sir2[15002][12];
int i, n, j, l, lg;
char *p1, *p2;
 
int main() {
    fin >> v;
 
    fin >> n;
 
    if(strlen(v) == 2) {
        for(i = 1;i <= n;i++) {
            fin >> r;
 
            if(r[0] == v[0] && r[2] == v[0] && r[1] == v[1] && r[3] == v[1] && strlen(r) == 4) break;
        }
    }
    else {
        for(i = 1;i <= n;i++) {
            fin >> r;
 
            lg = strlen(r);
 
            for(j = 1;j < lg - 2;j++) {
                for(l = 0;l <= j;l++) {
                    sir1[i][l] = r[l];
                }
 
                for(l = j + 1;l < lg;l++) {
                    sir2[i][l - j - 1] = r[l];
                }
 
                sir2[i][lg - j - 1] = '\0';
 
                p1 = strstr(v, sir1[i]);
                p2 = strstr(v, sir2[i]);
 
                if(p1 != NULL && p2 != NULL) break;
            }
 
            if(p1 != NULL && p2 != NULL) break;
        }
    }
 
    fout << r << '\n';
 
    fin.close();
    fout.close();
 
    return 0;
}
