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

struct Point{
    int x,y;

    Point() = default;

    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
};

bool operator<(const Point &p1, const Point &p2){
    if(p1.x == p2.x){
        return p1.y < p2.y;
    }

    return p1.x < p2.x;
}

bool operator==(const Point &p1, const Point &p2){
    return p1.x == p2.x && p1.y == p2.y;
}

/// Global variable and input, init ///
int m,n,k;
bool m1[MAX][MAX], m2[MAX][MAX];
map<Point, int> mpi;
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
void inputAndInit(){
    cin >> n >> m >> k;
    string s;
    fow(i,0,n){
        cin >> s;
        fow(j,0,m){
            if(s[j] == '.'){
                m1[i][j] = true;
                m2[i][j] = true;
            }else{
                m1[i][j] = false;
                m2[i][j] = false;
            }
        }
    }

}

/// Process ///
void solve(int testIndex){
    int x,y;
    cin >> x >> y;
    x--; y--;
    Point p(x,y);
    if(mpi[p] > 0){
        cout << mpi[p] << endl;
        return;
    }else{
        queue<Point> q;
        vector<Point> vtp;
        int cnt = 0;
        q.push(p);
        vtp.push_back(p);
        m2[x][y] = false;
        while(!q.empty()){
            Point point = q.front();
            q.pop();
            fow(i,0,4){
                x = point.x + dx[i];
                y = point.y + dy[i];
                if(m2[x][y]){
                    Point _p(x,y);
                    q.push(_p);
                    vtp.push_back(_p);
                    m2[x][y] = false;
                }else{
                    if(!m1[x][y]){
                        cnt++;
                    }
                }
            }
        }

        repa(pt, vtp){
            mpi[pt] = cnt;
        }

        cout << cnt << endl;
    }
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    int testCase = k;
    if(testCase == 0) cin >> testCase;
    fow(i,0,testCase)
        solve(i);
    return 0;
}
