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

struct Date{
    int day, month, year;

    Date(int dd, int mm, int yyyy){
        day = dd;
        month = mm;
        year = yyyy;
    }

    bool isValidDate(){
        if(year < 2000 || month > 12 || day > 31) return false;
        if(day == 0 || month == 0) return false;

        switch(month){
            case 4:
            case 6:
            case 9:
            case 11:
                if(day > 30) return false;
                break;
            case 2:
                if(day > 29) return false;
                if(day == 29){
                    if(year % 400 == 0) return true;
                    if(year % 100 == 0) return false;
                    if(year % 4 == 0) return true;
                    return false;
                }
        }

        return true;
    }
};

bool operator<(const Date &a, const Date &b){
    if(a.year == b.year){
        if(a.month == b.month){
            return a.day < b.day;
        }
        return a.month < b.month;
    }

    return a.year < b.year;
}

bool operator==(const Date &a, const Date &b){
    return a.year == b.year && a.month == b.month && a.day == b.day;
}

/// Global variable and input, init ///

void inputAndInit(){

}

/// Process ///
void solve(int testIndex){
    set<Date> dates;
    string dd, mm, yyyy;
    cin >> dd >> mm >> yyyy;
    string d = dd+mm+yyyy;
    sort(d.begin(), d.end());

    do{
        dd = d.substr(0,2);
        mm = d.substr(2,2);
        yyyy = d.substr(4,4);
        int day = stoi(dd),
            month = stoi(mm),
            year = stoi(yyyy);

        Date date(day, month, year);
        if(date.isValidDate()){
            dates.insert(date);
        }
    }while(next_permutation(d.begin(), d.end()));

    cout << dates.size();
    if(dates.size() == 0){
        cout << endl;
    }else{
        auto minDate = *(dates.begin());
        cout << " " << setfill('0') << setw(2) << minDate.day;
        cout << " " << setfill('0') << setw(2) << minDate.month;
        cout << " " << minDate.year << endl;
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
