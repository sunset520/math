#include <bits/stdc++.h>

using u64 = unsigned long long;

const int N = 20, M = 30;
const int EDGES[M][2] = {
    {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}, {7, 8}, {8, 9}, {9, 0},
    {10, 12}, {11, 13}, {12, 14}, {13, 15}, {14, 16}, {15, 17}, {16, 18}, {17, 19}, {18, 10}, {19, 11},
    {0, 10}, {1, 11}, {2, 12}, {3, 13}, {4, 14}, {5, 15}, {6, 16}, {7, 17}, {8, 18}, {9, 19},
};

// 枚举生成树 
int dsuFind(std::array<char, N>& dsu, int u) {
    return u == dsu[u] ? u : dsu[u] = dsuFind(dsu, dsu[u]);
}
std::unordered_set<int> set1;
void spanningTreeDFS(int depth, int n, int mask, std::array<char, N>& dsu) {
    if(n == N - 1) { set1.insert(mask); return; }
    if(depth == M) return;
    spanningTreeDFS(depth + 1, n, mask, dsu);
    int u = dsuFind(dsu, EDGES[depth][0]), v = dsuFind(dsu, EDGES[depth][1]);
    if(u == v) return;
    auto newDsu = dsu;
    newDsu[v] = u;
    spanningTreeDFS(depth + 1, n + 1, mask | (1 << depth), newDsu);
}

// 计算自同构
bool mat[N][N];
std::vector<std::array<char, M>> edgeMappings;
void automorphismDFS(int depth, int mask, std::array<char, N> vertexMapping) {
    if(depth == N) {
        std::unordered_map<int, int> mp;
        for(int i = 0; i < M; ++i) {
            int u = vertexMapping[EDGES[i][0]], v = vertexMapping[EDGES[i][1]];
            if(u > v) std::swap(u, v);
            mp[u * N + v] = i;
        }
        std::array<char, M> edgeMapping;
        for(int i = 0; i < M; ++i) {
            int u = EDGES[i][0], v = EDGES[i][1];
            if(u > v) std::swap(u, v);
            edgeMapping[i] = mp[u * N + v];
        }
        edgeMappings.push_back(edgeMapping);
        return;
    }
    for(int i = 0; i < N; ++i) {
        if(mask & (1 << i)) continue;
        bool ok = true;
        for(int j = 0; j < depth; ++j)
            if(mat[depth][j] != mat[i][int(vertexMapping[j])]) { ok = false; break; }
        if(ok) {
            vertexMapping[depth] = i;
            automorphismDFS(depth + 1, mask | (1 << i), vertexMapping);
        }
    }
}

// 计算树同构
std::unordered_set<u64> set2;
bool calcTreeHash(int mask) {
    std::unordered_set<u64> set;
    for(auto&& mapping : edgeMappings) {
        int newMask = 0;
        for(int i = 0; i < M; ++i)
            if(mask & (1 << i))
                newMask |= 1 << mapping[i];
        if(set2.count(newMask)) return false;
        set.insert(newMask);
    }
    set2.insert(set.begin(), set.end());
    return true;
}

int main() {
    std::array<char, N> dsu;
    std::iota(dsu.begin(), dsu.end(), char(0));
    spanningTreeDFS(0, 0, 0, dsu);
    int result1 = set1.size();
    std::cout << "The Number of Trees: " << result1 << std::endl;
    
    for(int i = 0; i < M; ++i) {
        int u = EDGES[i][0], v = EDGES[i][1];
        mat[u][v] = mat[v][u] = true;
    }
    automorphismDFS(0, 0, {});
    std::cout << "The Number of Automorphisms: " << edgeMappings.size() << std::endl;
    
    int result2 = 0;
    for(int mask : set1)
        result2 += calcTreeHash(mask);
    std::cout << "The Number of Non-Automorphism Trees: " << result2 << std::endl;
}