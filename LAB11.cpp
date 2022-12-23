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

    vector <string> res;

    ifstream fin;
    fin.open("test11-10.txt");
    
    string st;
    ll cnt = 0;
    while (fin >> st) {
        bool flag = true;
        for (ll i = 0; i < st.size() - 1; i++) {
            if ((st.size() < 2) || (tolower(st[i]) >= tolower(st[i + 1]))) flag = false;
        }
        if (flag == true) {
            cnt++;
            res.push_back(st);
        }
    }

    fin.close();

    if (cnt == 0) {
        cout << "No such words found." << '\n';
        return 0;
    }
    else {
        if (cnt == 1) {
            cout << "There is 1 such word." <<'\n';
            for (auto x : res) {
                cout << x << '\n';
            }
            return 0;
        }
    }

    cout << "There are " << cnt << " such words." << '\n';

    for (auto x : res) {
        cout << x << '\n';
    }
        
    //cout << endl << timing();
    
    return 0;
}