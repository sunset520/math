#include <iostream>
#include <cmath>

// 判断一个数是否为素数
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// 验证哥德巴赫猜想
void goldbach(int n) {
    if (n <= 2 || n % 2 != 0) {
        std::cout << "输入的数必须是大于2的偶数" << std::endl;
        return;
    }

    for (int i = 2; i <= n / 2; i++) {
        if (isPrime(i) && isPrime(n - i)) {
            std::cout << n << " = " << i << " + " << n - i << std::endl;
            return;
        }
    }

    std::cout << "没有找到两个素数之和为" << n << "的组合" << std::endl;
}

int main() {
    int n;
    std::cout << "请输入一个大于2的偶数：";
    std::cin >> n;
    goldbach(n);
    return 0;
}