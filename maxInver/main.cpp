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
bool b1[MAX], b2[MAX];
int n,p;
void inputAndInit(){
    fow(i,0,MAX){
        b1[i] = i%2==0;
        b2[i] = 1 ^ b1[i];
    }
}

/// Process ///
void solve(string s){
    int sz = s.size();
    bool bs[sz];
    fow(i,0,sz){
        if(s[i]>='a'&s[i]<='z')
            bs[i] = false;
        else
            bs[i] = true;
    }

    int cnt1 = 0, cnt2 = 0;
    fow(i,0,sz){
        if(bs[i] ^ b1[i])
            cnt1++;
        else
            cnt2++;
    }

    cout << min(cnt1, cnt2) << endl;
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    while(true){
        string s = "#";
        cin >> s;
        if(s=="#") break;

        solve(s);
    }
    return 0;
}
