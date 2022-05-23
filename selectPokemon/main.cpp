/***************************************************\
*                                                   *
*   000   000       111        00000       11111    *
*   0000 0000      11 11       00  00     11        *
*   00 000 00     11   11      00000       11111    *
*   00     00    111111111     00  00          11   *
*   00     00   11       11    00   00     11111    *
*                                                   *
\***************************************************/

#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define fow(i,a,b) for(auto i = a; i<b; i++)
#define rep(i,a,b) for(auto i = a; i<=b; i++)
#define red(i,a,b) for(auto i = a; i>=b; i--)
#define repa(i,a) for(auto i: a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define mod 1000000007
#define MAX 1000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct Pokemon{
    unsigned int index, atk, def, hp;
};

/// Global variable and input, init ///
Pokemon pokemons[MAX];
int n,k;
void inputAndInit(){
    cin >> n >> k;
    fow(i,0,n){
        pokemons[i].index = i;
        cin >> pokemons[i].atk >> pokemons[i].def >> pokemons[i].hp;
    }
}

/// Process ///
void solve(int testIndex){
    set<int> si;
    sort(pokemons, pokemons+n, [](Pokemon a, Pokemon b){
            return a.atk > b.atk;
         });
    fow(i,0,k){
        si.insert(pokemons[i].index);
    }

    sort(pokemons, pokemons+n, [](Pokemon a, Pokemon b){
            return a.def > b.def;
         });
    fow(i,0,k){
        si.insert(pokemons[i].index);
    }

    sort(pokemons, pokemons+n, [](Pokemon a, Pokemon b){
            return a.hp > b.hp;
         });
    fow(i,0,k){
        si.insert(pokemons[i].index);
    }

    cout << si.size() << endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 1;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}
