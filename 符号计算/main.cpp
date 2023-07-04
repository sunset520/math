#include<iostream>
using namespace std;

double func(int p, int k) {
    double ans = 1.0;
    ans = ans * (p + k);
    for (int i = 1;i <= k + 1;i++) {
        ans = ans / (p + i);
    }
    return ans;
}

int main() {
    double sum = 0.0;
    for (int k = 0;k < 100;k++) {
        sum+= func(1000, k);
    }
    cout<<sum;
    return 0;
}