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
#define MAX 1000000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

/// Global variable and input, init ///
vector<int> a;
int n;
void inputAndInit(){
    cin >> n;
    int temp;
    fow(i,0,n){
        cin >> temp;
        a.push_back(temp);
    }
    a[0] = -abs(a[0]);
}

int CeilIndex(std::vector<int>& v, int l, int r, int key)
{
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (v[m] >= key)
            r = m;
        else
            l = m;
    }
    return r;
}

int lis(std::vector<int>& v)
{
    if (v.size() == 0)
        return 0;

    std::vector<int> tail(v.size(), 0);
    int length = 1;
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0]){
            tail[0] = v[i];
            continue;
        }
        else if (v[i] > tail[length - 1]){
            tail[length++] = v[i];
            continue;
        }

        v[i] = -v[i];

        if (v[i] < tail[0])
            tail[0] = v[i];
        else if (v[i] > tail[length - 1])
            tail[length++] = v[i];
        else{
            v[i] = -abs(v[i]);
             tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
        }
    }

    return length;
}

/// Process ///
void solve(int testIndex){
    int len = lis(a);

    cout << len << endl;
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
