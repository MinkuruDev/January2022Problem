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
void inputAndInit(){
    cin >> r >> c;
    fow(i,0,r){
        fow(j,0,c){
            cin >> a[i][j];
        }
    }
}

ll merge(int arr[], int temp[], int left, int mid, int right){
    int i, j, k;
    ll inv_count = 0;

    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

ll _mergeSort(int arr[], int temp[], int left, int right){
    int mid;
    ll inv_count = 0;
    if (right > left) {
        mid = (right + left) / 2;

        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

ll mergeSort(int arr[], int array_size){
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1);
}

/// Process ///
void solve(int testIndex){
    ll result = 0;
    int temp[MAX];

    fow(i,0,r){
        fow(j,0,c){
            temp[j] = a[i][j];
        }

        result += mergeSort(temp, c);
    }

    fow(j,0,c){
        fow(i,0,r){
            temp[i] = a[i][j];
        }

        result += mergeSort(temp, r);
    }

    fow(i,0,r){
        int l = 0;
        int j = 0;
        int _i = i;
        while(_i < r && j < c){
            temp[l] = a[_i][j];
            l++; _i++; j++;
        }

        result += mergeSort(temp, l);
    }

    fow(j,1,c){
        int l = 0;
        int _j = j;
        int i = 0;
        while(i<r && _j<c){
            temp[l] = a[i][_j];
            l++; i++; _j++;
        }

        result += mergeSort(temp, l);
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
