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

const long long MOD = 1e9 + 7;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

template <typename T>

using pair2 = pair <T, T>;
using pii = pair <int, int>;
using pli = pair <ll, int>;
using pll = pair <ll, ll>;

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

int main() {
    
    fastboi

    vector <ll> vec;

    ll n;
    while (cin >> n) {
        vec.push_back(n);
    }
    
    vector <pii> p1;

    for (ll i = 2; i < vec.size(); i++) {
        if (vec[i] >= -9 && vec[i] <= 9 && vec[i - 1] >= -9 && vec[i - 1] <= 9 && vec[i - 2] >= -9 && vec[i - 2] <= 9) {
            if (vec[i] == abs(vec[i - 1] - vec[i - 2]))
                p1.push_back(mp(vec[i], (i + 1)));
        }
    }

    if (p1.size() == 0) {
        cout << "No such numbers." << '\n';
        return 0;
    }

    if (p1.size() == 1) cout << "There is " << p1.size() << " such number." << '\n';
    else    
        cout << "There are " << p1.size() << " such numbers." << '\n';
    cout << "Number | Index" << '\n';

    for (ll i = 0; i < p1.size(); i++) {
        cout << p1[i].first << "        " << p1[i].second << '\n';
    }
        
    //cout << endl << timing();
    
    return 0;
}