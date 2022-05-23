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

struct cell {
    int x, y;
    int dis;
    cell() {}
    cell(int x, int y, int dis):x(x), y(y), dis(dis){}
};


/// Global variable and input, init ///

void inputAndInit(){

}

bool isInside(int x, int y, int N){
    if (x >= 1 && x <= N && y >= 1 && y <= N)
        return true;
    return false;
}

int minStepToReachTarget(int knightPos[], int targetPos[], int N){
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    queue<cell> q;

    q.push(cell(knightPos[0], knightPos[1], 0));

    cell t;
    int x, y;
    bool visit[N + 1][N + 1];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            visit[i][j] = false;

    visit[knightPos[0]][knightPos[1]] = true;

    while (!q.empty()) {
        t = q.front();
        q.pop();

        if (t.x == targetPos[0] && t.y == targetPos[1])
            return t.dis;

        for (int i = 0; i < 8; i++) {
            x = t.x + dx[i];
            y = t.y + dy[i];

            if (isInside(x, y, N) && !visit[x][y]) {
                visit[x][y] = true;
                q.push(cell(x, y, t.dis + 1));
            }
        }
    }
}

/// Process ///
void solve(int testIndex){
    int n = 8;
    string s1, s2;
    cin >> s1 >> s2;
    int k[] = {s1[0] - 'a' + 1, s1[1] - '0'};
    int t[] = {s2[0] - 'a' + 1, s2[1] - '0'};

    cout << minStepToReachTarget(k, t, n) << endl;
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
