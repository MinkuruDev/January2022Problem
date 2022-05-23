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
string s;
void inputAndInit(){
    cin >> s;
}

/// Process ///
void solve(int testIndex){
    int chrCnt[26];
    fow(i,0,26){
        chrCnt[i] = 0;
    }

    repa(c, s){
        chrCnt[c-'a']++;
    }

    int i = 0, j = 25;

    while(i<j){
        while(chrCnt[i]%2==0 && i<26) i++;
        while(chrCnt[j]%2==0 && j>0) j--;
        if(i<j){
            chrCnt[i]++;
            chrCnt[j]--;
        }
    }
    string frt = "";
    fow(i,0,26){
        int _i = chrCnt[i] / 2;
        while(_i--){
            frt += (char)(i+'a');
        }
    }
    string lst = frt;
    reverse(lst.begin(), lst.end());

    string result = "";

    if(i==j){
        result = frt + (char)(i+'a') + lst;
    }else{
        result = frt + lst;
    }


    cout << result << endl;
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
