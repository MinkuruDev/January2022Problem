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

/// Global variable and input, init ///
int a[MAX][MAX];
int r,c;
multiset<int> si;
void inputAndInit(){
    cin >> r >> c;
    fow(i,0,r){
        fow(j,0,c){
            cin >> a[i][j];
        }
    }
}

bool check(int i, int j){
    if(i<0 || j<0 || i>r || j>c) return false;
    return true;
}

/// Process ///
void solve(int testIndex){
    int result = 0;
    r--, c--;
    si.insert(a[r][c]);

    priority_queue<int> pq;
    red(j,c-1,0){
        int _i = r;
        int _j = j;
        while(check(_i,_j)){
            pq.push(a[_i][_j]);
            _i--; _j++;
        }

        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            result += *(lower_bound(si.begin(), si.end(), temp));
            si.insert(temp);
        }
    }

    red(i,r-1,0){
        int _i = i;
        int _j = 0;
        while(check(_i,_j)){
            pq.push(a[_i][_j]);
            _i--; _j++;
        }

        while(!pq.empty()){
            int temp = pq.top();
            pq.pop();
            result += *(lower_bound(si.begin(), si.end(), temp));
            si.insert(temp);
        }
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
