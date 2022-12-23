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
    
    ll n, m;
    cin >> n >> m;

    vector < vector <ll> > vec(n, vector <ll> (m));

    ll maxx = -INF;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cin >> vec[i][j];
            maxx = max(maxx, vec[i][j]);
        }
    }

    vector <ll> index;

    for (ll i = 0; i < n; i++) {
        bool flag = true;
        for (ll j = 0; j < m and flag; j++) {
            if (vec[i][j] == maxx) {
                index.pb(i);
                flag = false;
            }
        }
    }

    vector <ll> pref(m);

    for (ll i = 0; i < (ll)index.size(); i++) {
        for (ll j = 0; j < m; j++) {
            pref[j] += vec[index[i]][j];
        }
    }

    ll first_i = index.front();
    for (ll j = 0; j < m; j++) {
        vec[first_i][j] = pref[j];
    }

    cout << '\n';

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            cout << vec[i][j] << ' ';
        }
        cout << '\n';
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