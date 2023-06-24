#include <iostream>
#include <cmath>

#define pi 3.14159265358979
#define e 2.718281828459045
#define varpi 2.62205755429211

// 定义一些测试函数

double func1(double x) {
    double a = 1;
    double b = 2;
    return 2 / (pi * sqrt(a * a * cos(x) * cos(x) + b * b * sin(x) * sin(x)));
}

double func2(double x) {
    double a = 1;
    double b = 3;
    return 2 / (pi * sqrt(a * a * cos(x) * cos(x) + b * b * sin(x) * sin(x)));
}

double func3(double x) {
    double a = 2;
    double b = 3;
    return 2 / (pi * sqrt(a * a * cos(x) * cos(x) + b * b * sin(x) * sin(x)));
}

double func4(double x, double y) {
    double a = 1.4567910;
    double b = 1.8636168;
    double c = 2.1817521;
    return 4 / (pi * pi * sqrt(a * a * cos(x) * cos(x) * cos(y) * cos(y) + b * b * sin(x) * sin(x) * cos(y) * cos(y) + c * c * sin(y) * sin(y)));
}


// 积分
double integral(double (*fun)(double), double L, double H, long n = 10000) {
    double x, dx, sum;
    dx = (H - L) / n;
    x = L + 0.5 * dx;
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += fun(x) * dx;
        x += dx;
    }
    return sum;
}

// 二重积分
double integral(double (*fun)(double, double), double xL, double xH, double yL, double yH, long n = 1000) {
    double x, y, dx, dy, sum;
    dx = (xH - xL) / n;
    dy = (yH - yL) / n;
    x = xL + 0.5 * dx;
    sum = 0;
    for (int i = 0; i < n; i++) {
        y = yL + 0.5 * dy;
        for (int j = 0; j < n; j++) {
            sum += dx * dy * fun(x, y);
            y += dy;
        }
        x += dx;
    }
    return sum;
}

int main() {
    using namespace std;
    std::cout.precision(8);
    std::cout.setf(ios_base::showpoint);
    double result1 = integral(func1, 0, pi / 2);
    std::cout << 1 / result1 << std::endl;
    double result2 = integral(func2, 0, pi / 2);
    std::cout << 1 / result2 << std::endl;
    double result3 = integral(func3, 0, pi / 2);
    std::cout << 1 / result3 << std::endl;
    double result4 = integral(func4, 0, pi / 2, 0, pi / 2);
    std::cout << 1 / result4 << std::endl;
    return 0;
}

