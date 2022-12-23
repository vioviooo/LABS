#include <math.h>
#include <stdio.h>
#include <stdbool.h> 

long double fi_function(long double x) {
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

long double fi_derivative(long double x) { // производная от первой функции
    return -(cos(x) * cos(x) + 2 * sqrt(1 - x))/(2 * sqrt(1 - x) * cos(x) * cos(x));
}

long double se_derivative(long double x) { // производная от второй функции
    return 1 - (13 * sin(pow(x, 0.52) + 2))/(25 * pow(x, 0.48));
}

void fi_dichotomy(long double a, long double b, long double EPS) {
    bool flag = true;
    long double mid = 0;
    int cnt = 0;
    while (abs(a - b) > EPS && flag) {
        mid = (a + b) / 2; // middle point
        if (fi_function(mid) == 0) {
            break;
        }
        else {
            if (fi_function(mid) * fi_function(a) < 0) {
                b = mid;
            }
            else if (fi_function(b) * fi_function(mid) < 0) {
                a = mid;
            }
            cnt++;
        }
        if (cnt > 100) {
            flag = false;
        }
    }
    if (!flag) {
        printf("Метод дихотомии не применим. \n");
    }
    else {
        printf("Метод дихотомии: %.20Lf; Кол-во итераций: %d \n", mid, cnt);
    }
}

void se_dichotomy(long double a, long double b, long double EPS) {
    bool flag = true;
    long double mid = 0;
    int cnt = 0;
    while (abs(a - b) > EPS && flag) {
        mid = (a + b) / 2; // middle point
        if (se_function(mid) == 0 && flag) {
            break;
        }
        else {
            if (se_function(mid) * se_function(a) < 0) {
                b = mid;
            }
            else if (se_function(b) * se_function(mid) < 0) {
                a = mid;
            }
        }
        cnt++;
        if (cnt > 100) {
            flag = false;
        }
    }
    if (!flag) {
        printf("Метод дихотомии не применим. \n");
    }
    else {
        printf("Метод дихотомии: %.20Lf; Кол-во итераций: %d \n", mid, cnt);
    }
}

void fi_iter(long double a, long double b, long double EPS) {
    bool flag = true;
    long double x = 0.6, x0 = 0.7, y;
    int cnt = 0;
    while (abs(x0 - x) > EPS && flag) {
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
        printf("Метод итераций не применим. \n");
    }
    else {
        printf("Метод итераций: %.20Lf; Кол-во итераций: %d \n", x, cnt);
    }
}

void se_iter(long double a, long double b, long double EPS) {
    bool flag = true;
    long double x = 0.4, x0 = 0.3, y;
    int cnt = 0;
    while (abs(x0 - x) > EPS && flag) {
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
        printf("Метод итераций не применим. \n");
    }
    else {
        printf("Метод итераций: %.20Lf; Кол-во итераций: %d \n", x, cnt);
    }
}

void fi_newton(long double a, long double b, long double EPS) {
    bool flag = true;
    int cnt = 0;
    long double x = 0.2, x0 = 0.1, y;
    while (abs(x0 - x) > EPS && flag) {
        y = x - (fi_function(x) / fi_derivative(x));
        x0 = x;
        x = y;
        cnt++;
        if (cnt > 100) {
            flag = false;
        }
    }
    if (!flag) {
        printf("Метод Ньютона не применим. \n");
    }
    else {
        printf("Метод Ньютона: %.20Lf; Кол-во итераций: %d \n", x, cnt);
    }
}

void se_newton(long double a, long double b, long double EPS) {
    bool flag = true;
    int cnt = 0;
    long double x = 0.6, x0 = 0.1, y;
    while (abs(x0 - x) > EPS && flag) {
        y = x - (se_function(x) / se_derivative(x));
        x0 = x;
        x = y;
        cnt++;
        if (cnt > 100) {
            flag = false;
        }
    }
    if (!flag) {
        printf("Метод Ньютона не применим. \n");
    }
    else {
        printf("Метод Ньютона: %.20Lf; Кол-во итераций: %d \n", x, cnt);
    }
}

int main(void) {

    long double EPS = 1.0;
    while (1.0 + EPS / 2.0 > 1) {
        EPS /= 2;
    }

    long double a1 = 0, b1 = 1;
    long double a2 = 0.5, b2 = 1;

    printf("Результаты вычислений для 1 функции: \n");
    fi_dichotomy(a1, b1, EPS);
    fi_newton(a1, b1, EPS);
    fi_iter(a1, b1, EPS);

    printf("\n");

    printf("Результаты вычислений для 2 функции: \n");
    se_dichotomy(a2, b2, EPS);
    se_newton(a2, b2, EPS);
    se_iter(a2, b2, EPS);
    
    return 0;
}
