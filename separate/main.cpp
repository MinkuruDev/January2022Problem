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
#define repi(i,a) for((a)::iterator i : a)
#define db(x) cout << #x << " = " << x << endl
#define el cout << endl
#define getBit(n,i) ((n>>i)&1)
#define mod 1000000007
#define MAX 10000

typedef long long ll;
typedef unsigned long long ull;
using namespace std;

struct Point{
    int x,y;

    Point() = default;

    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
};

struct Reactangle{
    Point first, last;
    int index;

    Reactangle(int _i, Point _f, Point _l){
        index = _i;
        first = _f;
        last = _l;
    }
};

bool pointInReact(Point p, Reactangle r){
    return p.x > r.first.x && p.y > r.first.y && p.x < r.last.x && p.y < r.last.y;
}

/// Global variable and input, init ///
vector<Reactangle> vtr;
void inputAndInit(){

}

/// Process ///
void solve(int testIndex){
    int t; cin >> t;
    if(t == 2){
        int j; cin >> j;
        fow(it,vtr.begin(),vtr.end()){
            if(it->index == j){
                vtr.erase(it);
                break;
            }
        }

        return;
    }

    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(t==1){
        vtr.push_back(Reactangle(testIndex+1, Point(x1,y1), Point(x2,y2)));
    }else{
        Point bash(x1, y1);
        Point pikachu(x2, y2);
        bool flag = true;
        repa(react, vtr){
            if(pointInReact(bash, react) ^ pointInReact(pikachu, react)){
                flag = false;
                break;
            }
        }

        cout << (flag? "Y" : "N");
    }

}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = 0;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}
