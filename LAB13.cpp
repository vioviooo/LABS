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
#include <clocale>

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

vector <string> setIntersection(set <string> first, set <string> second) {
    ll flag = true;

    vector <string> vec(1e5);

    auto f1 = first.begin();
    auto l1 = first.end();

    auto f2 = second.begin();
    auto l2 = second.end();

    auto iter = set_intersection(f1, l1, f2, l2, vec.begin());

    vec.resize(iter - vec.begin());

    return vec;
}

int main() {

    fastboi

    setlocale(LC_ALL,"Russian");

    vector <string> my_strings;
    
    string st;
    while (cin >> st) {
        my_strings.pb(st);
    }

    for (ll i = 0; i < (ll)my_strings.size(); i++) {

        string s1 = my_strings[i];
        string s2 = my_strings[i + 1];

        set <string> word1;
        set <string> word2;

        for (ll j = 0; j < (ll)s1.size(); j++) {
            string tmp;
            tmp += tolower(s1[j]);
            word1.insert(tmp);
        }

        for (ll j = 0; j < (ll)s2.size(); j++) {
            string tmp;
            tmp += tolower(s2[j]);
            word2.insert(tmp);
        }

        vector <string> vec;

        vec = setIntersection(word1, word2);

        if ((ll)vec.size() == (ll)word1.size() and (ll)vec.size() == word2.size()) {
            cout << "Same set of letters: " << s1 << ' ' << s2 << '\n';
        }
        else if ((ll)vec.size() == 0) {
            cout << "All letters are different: " << s1 << ' ' << s2 << '\n';
        }
        else if ((ll)vec.size() != (ll)word1.size()) {
            cout << "Only " << (ll)vec.size() << " letters are the same: " << s1 << ' ' << s2 << '\n';
        }
        else if ((ll)vec.size() != (ll)word2.size()) {
            cout << "Only " << (ll)vec.size() << " letters are the same: " << s1 << ' ' << s2 << '\n';
        }
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