#include <math.h>
#include <stdio.h>
#include <stdbool.h> 

long double fi_function(long double a) {
    return sqrt(1 - a) - tan(a);
}

long double se_function(long double a) {
    return a + cos(pow(a, 0.52) + 2);
}

long double fi_iter_func(long double a) {
    return 1 - tan(a) * tan(a); // запись 1 функции вида: f(a) = a
}

long double se_iter_func(long double a) {
    return -cos(pow(a, 0.52) + 2); // запись 2 функции вида: f(a) = a
}

long double fi_derivative(long double a) { // производная от первой функции
    return -(cos(a) * cos(a) + 2 * sqrt(1 - a))/(2 * sqrt(1 - a) * cos(a) * cos(a));
}

long double se_derivative(long double a) { // производная от второй функции
    return 1 - (13 * sin(pow(a, 0.52) + 2))/(25 * pow(a, 0.48));
}

void fi_dichotomy(long double a, long double b, long double EPS) {
    bool flag = true;
    long double c = 0;
    int cnt = 0;
    while (fabs(a - b) > EPS && flag) {
        c = (a + b) / 2; // cdle point
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
        if (cnt > 100) {
            flag = false;
        }
    }
    if (!flag) {
        printf("Метод дихотомии не применим. \n");
    }
    else {
        printf("Метод дихотомии: %.20Lf; Кол-во итераций: %d \n", c, cnt);
    }
}

void se_dichotomy(long double a, long double b, long double EPS) {
    bool flag = true;
    long double c = 0;
    int cnt = 0;
    while (fabs(a - b) > EPS && flag) {
        c = (a + b) / 2; // cdle point
        if (se_function(c) == 0 && flag) {
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
    if (!flag) {
        printf("Метод дихотомии не применим. \n");
    }
    else {
        printf("Метод дихотомии: %.20Lf; Кол-во итераций: %d \n", c, cnt);
    }
}

void fi_iter(long double a, long double b, long double EPS) {
    bool flag = true;
    long double c;
    int cnt = 0;
    while (fabs(b - a) > EPS && flag) {
        c = fi_iter_func(b);
        b = a;
        a = c;
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
        printf("Метод итераций: %.20Lf; Кол-во итераций: %d \n", a, cnt);
    }
}

void se_iter(long double a, long double b, long double EPS) {
    bool flag = true;
    long double c;
    int cnt = 0;
    while (fabs(b - a) > EPS && flag) {
        c = se_iter_func(b);
        b = a;
        a = c;
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
        printf("Метод итераций: %.20Lf; Кол-во итераций: %d \n", a, cnt);
    }
}

void fi_newton(long double a, long double b, long double EPS) {
    bool flag = true;
    int cnt = 0;
    long double c;
    while (fabs(b - a) > EPS && flag) {
        c = a - (fi_function(a) / fi_derivative(a));
        b = a;
        a = c; 
        cnt++;
        if (cnt > 100) {
            flag = false;
        }
    }
    if (!flag) {
        printf("Метод Ньютона не применим. \n");
    }
    else {
        printf("Метод Ньютона: %.20Lf; Кол-во итераций: %d \n", a, cnt);
    }
}

void se_newton(long double a, long double b, long double EPS) {
    bool flag = true;
    int cnt = 0;
    long double c;
    while (fabs(b - a) > EPS && flag) {
        c = b - (se_function(b) / se_derivative(b));
        b = a;
        a = c; 
        cnt++;
        if (cnt > 100) {
            flag = false;
        }
    }
    if (!flag) {
        printf("Метод Ньютона не применим. \n");
    }
    else {
        printf("Метод Ньютона: %.20Lf; Кол-во итераций: %d \n", a, cnt);
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
