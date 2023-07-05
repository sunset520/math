#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<sstream>
#include<assert.h>

#define MAX_N 1000005
#define MAX_COMPUTE_N 1000005
#define MAX_PRINT_N 105
#define INF 999999999

// 打印
void print(std::string name, int(*get)(std::vector<int>, int), std::vector<int> params, int max_num);

// 计算堆垒性质
void compute(std::string name, int(*get)(std::vector<int>, int), std::vector<int> params, int max_num);

// params: {}
int getPalindrome(std::vector<int>params, int index);

// params: {power_num}
int getPowerNumber(std::vector<int>params, int index);

// params: {gonal_num}
int getPolygonalNumber(std::vector<int>params, int index);

// params: {gonal_num}
int getPyramidalNumber(std::vector<int>params, int index);

// params: {dim_num, gonal_num}
int getGenernalizedPolygonalNumber(std::vector<int>params, int index);

// params: {angle_num}
int getStarNumber(std::vector<int>params, int index);

// params: {face_num}
int getPolyhedronNumber(std::vector<int>params, int index);

// params: {}
int getStellaOctangulaNumber(std::vector<int>params, int index);

// params: {}
int getRhombicDodecahedralNumber(std::vector<int>params, int index);

// params: {}
int getTricappedPrismNumber(std::vector<int>params, int index);