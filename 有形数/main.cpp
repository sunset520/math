#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <sstream>
#include <assert.h>
#include "main.h"

// 打印
void print(std::string name, int(*get)(std::vector<int>, int), std::vector<int> params, int max_num) {
    assert(max_num <= MAX_COMPUTE_N);
    for(int i = 1;i <= max_num;i++) {
        std::cout<<get(params, i) <<' ';
    }
    std::cout<< name << " ";
    std::cout <<"{ ";
    for(std::vector<int>::const_iterator i = params.begin();i != params.end();i++) {
        std::cout<< *i <<' ';
    }
    std::cout << "}\n";
    return;
}

// 计算堆垒性质
void compute(std::string name, int(*get)(std::vector<int>, int), std::vector<int> params, int max_num) {
    assert(max_num <= MAX_COMPUTE_N);
    int* dp = new int[max_num+2] {INF}; // 动态规划结果储存
    int* pd = new int[max_num+2] {INF}; // 动态规划结果储存
    int ans_num = 1; // 问题的解 ans_num
    int ans_max = 0; // 至少需要 ans_num 个数相加的最大数
    dp[0] = 0;
    pd[0] = 0;
    for (int i = 1;i <= max_num;i++) {
        int minn = INF;
        int currj;
        for (int j = 1;get(params, j) <= i;j++) {
            minn = minn < dp[i - get(params, j)] ? minn : dp[i - get(params, j)];
            currj = minn < dp[i - get(params, j)] ? currj : j;
        }
        dp[i] = minn + 1;
        pd[i] = currj;
    }
    for (int i = 1;i <= max_num;i++) {
        int result = dp[i];
        if (result >= ans_num) {
            ans_num = result;
            ans_max = i;
        }
    }
    std::cout <<max_num << "\t" << ans_num << "\t" << ans_max << "\t" << name << " ";
    std::cout <<"{ ";
    for(std::vector<int>::const_iterator i = params.begin();i != params.end();i++) {
        std::cout<< *i <<' ';
    }
    std::cout << "}\n";
    return;
}

// 回文数
// params: {}
int getPalindrome(std::vector<int>params, int index) {
    int temp = index - 1;
    int count = 0;
    int number = 9;
    int width = 0;
    int half;
    int high = 1;
    int res;
    while (true) {
        if (width > 0 && width % 2 == 0) {
            number *= 10;
        }
        width++;
        if (count + number > temp) {
            break;
        }
        count += number;
    }
    temp -= count;
    for (int i = 0;i < (width - 1) / 2;i++) {
        high *= 10;
    }
    half = high + temp;
    res = half;
    if (width % 2 != 0) {
        half /= 10;
    }
    while (half != 0) {
        res = res * 10 + half % 10;
        half /= 10;
    }
    return res;
}

// 幂
// params: {power_num}
int getPowerNumber(std::vector<int>params, int index) {
    return (int)pow(index, params[0]);
}

// 多边形数
// params: {gonal_num}
int getPolygonalNumber(std::vector<int>params, int index) {
    std::vector<int> new_params = {2};
    new_params.insert(new_params.end(),params.begin(), params.end());
    return getGenernalizedPolygonalNumber(new_params, index);
}

// 角锥数
// params: {gonal_num}
int getPyramidalNumber(std::vector<int>params, int index) {
    std::vector<int> new_params = {3};
    new_params.insert(new_params.end(),params.begin(), params.end());
    return getGenernalizedPolygonalNumber(new_params, index);
}

// 广义多边形数
// params: {dim_num, gonal_num}
int getGenernalizedPolygonalNumber(std::vector<int>params, int index) {
    int ans = 1;
    for (int i = 0;i <= params[0] - 2;i++) {
        ans = ans * (index + i) / (i + 1);
    }
    ans = ans * ((params[1] - 2) * index - (params[1] - params[0] - 2)) / params[0];
    return ans;
}

// 星数
// params: {angle_num}
int getStarNumber(std::vector<int>params, int index) {
    return params[0] * index * index - params[0] * index + 1;
}

// 正多面体数
// params: {face_num}
int getPolyhedronNumber(std::vector<int>params, int index) {
    int ans = 0;
    switch (params[0]) {
    case 4:
        ans = index * (index + 1) * (index + 2) / 6;
        break;
    case 6:
        ans = index * index * index;
        break;
    case 8:
        ans = index * (2 * index * index + 1) / 3;
        break;
    case 12:
        ans = index * (3 * index - 1) * (3 * index - 2) / 2;
        break;
    case 20:
        ans = index * (5 * index * index - 5 * index + 2) / 2;
        break;
    default:
        break;
    }
    return ans;
}

// 斯特拉八角星数
// params: {}
int getStellaOctangulaNumber(std::vector<int>params, int index) {
    return index * (2 * index * index - 1);
}

// 菱形十二面体数
// params: {}
int getRhombicDodecahedralNumber(std::vector<int>params, int index) {
    return 4 * index * index * index - 6 * index * index + 4 * index - 1;
}

// 三帽三棱柱数
// params: {}
int getTricappedPrismNumber(std::vector<int>params, int index) {
    return index * (3 * index * index - 2 * index + 1) / 2;
}

void testPrint() {
    print("Palindrome", getPalindrome, {}, 10);
    print("PowerNumber", getPowerNumber, { 3 }, 10);
    print("PolygonalNumber", getPolygonalNumber, { 5 }, 10);
    print("PyramidalNumber", getPyramidalNumber, { 5 }, 10);
    print("GenernalizedPolygonalNumber", getGenernalizedPolygonalNumber, { 3,3 }, 10);
    print("StarNumber", getStarNumber, { 5 }, 10);
    print("PolyhedronNumber", getPolyhedronNumber, { 12 }, 10);
    print("StellaOctangulaNumber", getStellaOctangulaNumber, {}, 10);
    print("RhombicDodecahedralNumber", getRhombicDodecahedralNumber, {}, 10);
    print("TricappedPrismNumber", getTricappedPrismNumber, {}, 10);
    return;
}

void testCompute() {
    compute("Palindrome", getPalindrome, {}, 10000);
    compute("PowerNumber", getPowerNumber, { 3 }, 10000);
    compute("PolygonalNumber", getPolygonalNumber, { 5 }, 10000);
    compute("PyramidalNumber", getPyramidalNumber, { 5 }, 10000);
    compute("GenernalizedPolygonalNumber", getGenernalizedPolygonalNumber, { 3,3 }, 10000);
    compute("StarNumber", getStarNumber, { 5 }, 10000);
    compute("PolyhedronNumber", getPolyhedronNumber, { 12 }, 10000);
    compute("StellaOctangulaNumber", getStellaOctangulaNumber, {}, 10000);
    compute("RhombicDodecahedralNumber", getRhombicDodecahedralNumber, {}, 10000);
    compute("TricappedPrismNumber", getTricappedPrismNumber, {}, 10000);
    return;
}

int main() {
    testPrint();
    // testCompute();
    return 0;
}