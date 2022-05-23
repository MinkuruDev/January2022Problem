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

struct card{
    int r,s;

    card() = default;

    card(int _r, int _s){
        r = _r;
        s = _s;
    }

    card(int _r, char _s){
        r = _r;

        switch(_s){
            case 'C':
                s = 0;
                break;
            case 'D':
                s = 1;
                break;
            case 'H':
                s = 2;
                break;
            case 'S':
                s = 3;
                break;
        }
    }
};

bool operator<(const card &c1, const card &c2){
    if(c1.r == c2.r){
        return c1.s < c2.r;
    }

    return c1.r < c2.r;
}

bool operator==(const card &c1, const card &c2){
    return c1.r == c2.r && c1.s == c2.s;
}

struct hand{
    multiset<int> suit[4];

    void ins(card _card){
        if(_card.r == 0) return;
        suit[_card.s].insert(_card.r);
    }
};

/// Global variable and input, init ///
void inputAndInit(){

}

/// Process ///
void solve(int p, int m, int n){
    vector<hand> playerHand;
    queue<card> stock;

    int r;
    char s;
    while(n--){
        cin >> r >> s;
        stock.push(card(r,s));
    }

    card currentCard = stock.front();
    stock.pop();

    hand h;
    fow(i,1,m){
        card c = stock.front();
        stock.pop();
        h.suit[c.s].insert(c.r);
    }
    playerHand.push_back(h);

    fow(i,1,p){
        hand h;
        fow(j,0,m){
            card c = stock.front();
            stock.pop();
            h.suit[c.s].insert(c.r);
        }
        playerHand.push_back(h);
    }
    /*
    repa(i, playerHand){
        fow(j,0,4){
            cout << j << ". ";
            repa(k, i.suit[j]){
                cout << k << " ";
            }
            el;
        }
    }
    */
    /// play here
    int turn = p * 1000;
    int dt = 1;
    while(true){
        turn += dt;
        db(stock.size());
        bool played = false;
        bool flag = true;
        if(!playerHand[turn%p].suit[currentCard.s].empty()){
            if(*(prev(playerHand[turn%p].suit[currentCard.s].end())) > currentCard.r){
                currentCard.r = *(prev(playerHand[turn%p].suit[currentCard.s].end()));
                playerHand[turn%p].suit[currentCard.s].erase(prev(playerHand[turn%p].suit[currentCard.s].end()));
                played = true;
                flag = false;

            }
        }
        if(flag){

            red(i,3,currentCard.s){
                auto it = playerHand[turn%p].suit[i].find(currentCard.r);
                cout << "i'm here" << endl;
                if (it != playerHand[turn%p].suit[i].end()){
                    currentCard.s = i;
                    playerHand[turn%p].suit[i].erase(it);
                    played = true;
                    break;
                }
            }


            if(!played){
                card c = stock.front();
                stock.pop();
                if(c.r == currentCard.r || c.s == currentCard.s){
                    currentCard.r = c.r;
                    currentCard.s = c.s;
                    played = true;
                }else
                    playerHand[turn%p].ins(c);
            }
        }

        bool win = true;
        fow(i,0,4){
            if(playerHand[turn%p].suit[i].size() > 0){
                win = false;
            }

        }

        if(win){
            cout << (turn%p) + 1<< endl;
            return;
        }

        if(played){
            if(currentCard.r == 1){
                card c = stock.front();
                stock.pop();
                playerHand[(turn+dt)%p].ins(c);
                turn += dt;
            }
            if(currentCard.r == 7){
                card c = stock.front();
                stock.pop();
                playerHand[(turn+dt)%p].ins(c);
                c = stock.front();
                stock.pop();
                playerHand[(turn+dt)%p].ins(c);
                turn += dt;
            }
            if(currentCard.r == 11){
                turn += dt;
            }
            if(currentCard.r == 12){
                dt = -dt;
            }

        }


    }
}

void test(){

}

int main(){
    fast_io;
    inputAndInit();
    //test();
    while(true){
        int p,m,n;
        cin >> p >> m >> n;
        if(p==0 && m==0 && n==0) break;
        solve(p,m,n);
    }

    return 0;
}
