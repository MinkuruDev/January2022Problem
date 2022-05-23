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
#define MAX 10000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/// Global variable and input, init ///
string a,b;
void inputAndInit(){

}

int lcs(string a, string b, int m, int n){
    int L[m+1][n+1];

    rep(i,0,m){
        rep(j,0,n){
            if(i==0 || j==0)
                L[i][j] = 0;
            else if(a[i-1] == b[j-1])
                 L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max(L[i-1][j], L[i][j-1]);
        }
    }

    return L[m][n];
}

/// Process ///
bool solve(int testIndex){
    cin >> a;
    if(a=="#") return false;
    cin >> b;

    int len = lcs(a,b,a.size(),b.size());
    int total = 15*(a.size() - len);
    total += 30*(b.size() - len);

    cout << total << endl;

    return true;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 1;
    if(testCase == 0) cin >> testCase;
    while(true)
        if(!solve(0)) break;
    return 0;
}
