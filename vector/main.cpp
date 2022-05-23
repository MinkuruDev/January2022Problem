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
#define MAX 100000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct Vector{
    int x,y,index;
    double ag;

    double angle(Vector other){
        int dot = x*other.x + y*other.y;
        int det = x*other.y - y*other.x;
        return atan2(det, dot);
    }

    bool operator<(Vector other){
        return ag < other.ag;
    }
};

/// Global variable and input, init ///
vector<Vector> vt;
int n;
pair<int, int> pii;
void inputAndInit(){
    cin >> n;
    Vector Ox;
    Ox.x = 1; Ox.y = 0;
    pii = make_pair(1,2);
    Vector v;
    fow(i,0,n){
        cin >> v.x >> v.y;
        v.index = i;
        v.ag = v.angle(Ox);
        vt.push_back(v);

        if(v.ag < 0){
            v.ag += 2*M_PI;
            vt.push_back(v);
        }
    }

    sort(vt.begin(), vt.end());
}

/// Process ///
void solve(int testIndex){
    int sz = vt.size();
    double minAngle = M_PI;
    fow(i,1,sz){
        if(vt[i].ag - vt[i-1].ag < minAngle){
            minAngle = vt[i].ag - vt[i-1].ag;
            pii.first = vt[i-1].index + 1;
            pii.second = vt[i].index + 1;
        }
    }

    cout << pii.first << " " << pii.second << endl;
}

void test(){
    Vector a,b;
    a.x = 231231; a.y = 0;
    b.x = 0; b.y = -1;
    auto ag = a.angle(b);
    if(ag < 0) ag += M_PI;
    cout << ag;
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
