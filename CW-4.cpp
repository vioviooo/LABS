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

long double fi_function(ld x) {
    return sqrt(1 - x) - tan(x);
}

long double se_function(long double x) {
    return x + cos(pow(x, 0.52) + 2);
}

long double fi_iter(long double x) {
    return 1 - tan(x) * tan(x); // запись 1 функции вида: f(x) = x
}

long double se_iter(long double x) {
    return -cos(pow(x, 0.52) + 2); // запись 2 функции вида: f(x) = x
}

long double fi_derivative(long double x) { // производная от второй функции
    return -(cos(x) * cos(x) + 2 * sqrt(1 - x))/(2 * sqrt(1 - x) * cos(x) * cos(x));
}

long double se_derivative(long double x) { // производная от второй функции
    return 1 - (13 * sin(pow(x, 0.52) + 2))/(25 * pow(x, 0.48));
}

void fi_dichotomy(ld a, ld b, ld EPS) {
    bool flag = true;
    ld c;
    int cnt = 0;
    while (abs(a - b) > EPS and flag) {
        c = (a + b) / 2; // middle point
        if (fi_function(c) == 0) {
            break;
        }
        else {
            if (fi_function(c) * fi_function(a) < 0) {
                b = c;
            }
            else if (fi_function(b) * fi_function(c) < 0) {
                a = c;
            }
            cnt++;
        }
        if (cnt >100100) {
            flag = false;
        }
    }
    if (flag) cout << "Метод дихотомии: " << c << "; Кол-во итераций: " << cnt << '\n';
    else {
        cout << "Метод дихотомии не применим." << '\n';
    }
}

void se_dichotomy(ld a, ld b, ld EPS) {
    bool flag = true;
    ld c;
    int cnt = 0;
    while (abs(a - b) > EPS) {
        c = (a + b) / 2; // middle point
        if (se_function(c) == 0 and flag) {
            break;
        }
        else {
            if (se_function(c) * se_function(a) < 0) {
                b = c;
            }
            else if (se_function(b) * se_function(c) < 0) {
                a = c;
            }
        }
        cnt++;
        if (cnt > 100) {
            flag = false;
        }
    }
    if (flag) cout << "Метод дихотомии: " << c << "; Кол-во итераций: " << cnt << '\n';
    else {
        cout << "Метод дихотомии не применим." << '\n';
    }
}

void fi_iter(long double a, long double b, ld EPS) {
    bool flag = true;
    ld x = 0.6, x0 = 0.7, y;
    int cnt = 0;
    while (abs(x0 - x) > EPS and flag) {
        y = fi_iter(x0);
        x0 = x;
        x = y;
        cnt++;
        if (cnt > 100) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << "Метод итераций не применим." << '\n';
    }
    else {
        cout << "Метод итераций: " << x << "; Кол-во итераций: " << cnt << '\n';
    }
}

void se_iter(long double a, long double b, ld EPS) {
    bool flag = true;
    ld x = 0.4, x0 = 0.3, y;
    int cnt = 0;
    while (abs(x0 - x) > EPS) {
        y = se_iter(x0);
        x0 = x;
        x = y;
        cnt++;
        if (cnt > 100) {
            flag = false;
            break;
        }
    }
    if (!flag) {
        cout << "Метод итераций не применим." << '\n';
    }
    else {
        cout << "Метод итераций: " << x << "; Кол-во итераций: " << cnt << '\n';
    }
}

void fi_newton(long double a, long double b, ld EPS) {
    bool flag = true;
    int cnt = 0;
    ld x = 0.2, x0 = 0.1, y;
    while (abs(x0 - x) > EPS and flag) {
        y = x - (fi_function(x) / fi_derivative(x));
        x0 = x;
        x = y;
        cnt++;
        if (cnt > 100) {
            flag = false;
        }
    }
    if (flag) {
        cout << "Метод Ньютона: " << x << "; Кол-во итераций: " << cnt << '\n';
    }
    else {
        cout << "Метод Ньютона не применим." << '\n';
    }
}

void se_newton(long double a, long double b, ld EPS) {
    bool flag = true;
    int cnt = 0;
    ld x = 0.6, x0 = 0.1, y;
    while (abs(x0 - x) > EPS and flag) {
        y = x - (se_function(x) / se_derivative(x));
        x0 = x;
        x = y;
        cnt++;
        if (cnt > 100) {
            flag = false;
        }
    }
    if (flag) {
        cout << "Метод Ньютона: " << x << "; Кол-во итераций: " << cnt << '\n';
    }
    else {
        cout << "Метод Ньютона не применим." << '\n';
    }
}

int main() {
    
    fastboi

    long double EPS = 1.0;
    while (1.0 + EPS / 2.0 > 1) {
        EPS /= 2;
    }

    // long double EPS = pow(2, -26);

    long double a1 = 0, b1 = 1;
    long double a2 = 0.5, b2 = 1;

    cout << fixed << setprecision(20);

    cout << "Результаты вычслений для 1 функции: " << '\n';
    fi_dichotomy(a1, b1, EPS);
    fi_newton(a1, b1, EPS);
    fi_iter(a1, b1, EPS);

    cout << '\n';

    cout << "Результаты вычислений для 2 функции: " << '\n';
    se_dichotomy(a2, b2, EPS);
    se_newton(a2, b2, EPS);
    se_iter(a2, b2, EPS);

// g++ 4-CW.cpp
    
    return 0;
}