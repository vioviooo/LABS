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
const int N = 4000;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;

template <typename T>

using pair2 = pair <T, T>;
using pii = pair <int, int>;
using pli = pair <ll, int>;
using pll = pair <ll, ll>;

#define pop pop_back
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define fastboi ios::sync_with_stdio(false); cin.tie(0);

clock_t startTime;
double timing() {
	return (double)(clock() - startTime) / CLOCKS_PER_SEC;
}

int main() {
    
    fastboi

    ld eps = 1.0;
    while (1.0 + eps / 2.0 > 1) {
        eps /= 2;
    }

    ll N;
    cin >> N;

    ld a = 0.0, b = 0.5;

    ld step = (b - a) / N;

    ld x = a;

    for (ll i = 0; i <= N; i++) {

        ld row0 = -((4 * x * x) / 2);
        ld row_function = row0;

        ll x0 = 2, num_of_operations = 0;

        bool flag = true;

        for (ll n = 0; n < 100 and flag; n++) {

            row0 = (-1) * row0 * ((4 * x * x) / ((x0 + 1) * (x0 + 2)));

            if (abs(row0) < eps) {
                flag = false;
                num_of_operations = n;
            }

            row_function += row0;
            x0 += 2;
            
        }

        cout << num_of_operations << ' ';

        cout << fixed << setprecision(20);
        
        ld taylor_function = 2 * (cos(x) * cos(x) - 1);
        cout << taylor_function << '\n';
        
        cout << row_function << '\n';

        cout << '\n';

        x += step;
    }

    //cout << endl << timing();
    
    return 0;
}