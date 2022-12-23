#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iomanip> 
#include <string>
#include <queue>
#include <set>
#include <fstream>
#include <ctime>
#include <random>
#include <bitset>
#include <array>

using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

template <typename T>

using pair2 = pair <T, T>;
using pii = pair <int, int>;
using pli = pair <ll, int>;
using pll = pair <ll, ll>;

#define lb lower_bound
#define ub upper_bound
#define pop pop_back
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define fastboi ios::sync_with_stdio(false); cin.tie(0);

clock_t startTime;
double timing() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

ll down(ll a, ll b) {
    return (a + b - 1) / b;
}

const ll MOD = 1e9 + 7;
const ll INF = 1e18;
//const ld PI = acos(-1);

int main() {

    fastboi
    
    ll n;
    cin >> n;

    vector < vector <ll> > vec(n, vector <ll> (n));

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            cin >> vec[i][j];
        }
    }

    ll num = 1, tmp = 1, last_i = n - 1, last_j = 0, ii, jj;
    bool isUp = false;
    for (ll t = 0; t < n - 1; t++) {
    
        if (!isUp) {
            for (ll k = 0; k < tmp; k++) {
                cout << vec[last_i][last_j] << ' ';
                last_i++;
                last_j++;
            }
            last_i--;
        }
        else {
            for (ll k = tmp - 1; k >= 0; k--) {
                cout << vec[last_i][last_j] << ' ';
                last_i--;
                last_j--;
            }
            last_j++;
        }

        isUp = !isUp;
        
        tmp++;
    }

    if (n & 1) {
        for (ll i = 0; i < n; i++) {
            cout << vec[i][i] << ' ';
            last_i++;
            last_j++;
        }
    }
    else {
        for (ll i = n - 1; i >= 0; i--) {
            last_i--;
            last_j--;
            cout << vec[i][i] << ' ';
        }
    }

    bool endPoint = true;
    if (last_i < 0 and last_j < 0) {
        last_i++;
        last_j += 2;
    }
    else {
        last_i -= 2;
        last_j--;
        endPoint = false;
    }
    
    tmp = n - 1;
    for (ll t = 0; t < n - 1; t++) {

        if (endPoint) {
            for (ll k = 0; k < tmp; k++) {
                cout << vec[last_i][last_j] << ' ';
                last_i++;
                last_j++;
            }
            last_j--;
            last_i -= 2;
        }
        else {
            for (ll k = tmp - 1; k >= 0; k--) {
                cout << vec[last_i][last_j] << ' ';
                last_i--;
                last_j--;
            }
            last_i++;
            last_j += 2;
        }
        
        // cout << last_i << ' ' << last_j << '\n';

        endPoint = !endPoint;

        tmp--;
    }
    
    //cout << endl << timing();
    
    return 0;
}

/*
    * 0-1 Индексация?
    * Границы массива? Выход за границы?
    * Если много вложенных циклов: использование i, ... , j несколько раз?
    * Focus on DIFFERENT approaches
    * Дают маленькие значения Н => O(n ^ 3) or O(n ^ 2) ?
    * Don't get stuck on 1 problem

*/