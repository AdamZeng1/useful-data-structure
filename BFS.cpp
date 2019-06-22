//
// Created by adamzeng on 2019-06-22.
//

#include <cstdio>
#include <queue>

using namespace
std;
const int maxn = 100;

struct node {
    int x, y; // 位置(x,y)
} Node;


int n, m; // 矩阵大小为n*m
int matrix[maxn][maxn];
bool inq[maxn][maxn] = {false}; // 记录位置(x,y)是否入过队
int X[4] = {0, 0, 1, -1}; // 增量数组
int Y[4] = {1, -1, 0, 0};


bool judge(int x, int y) { // 判断坐标(x,y)是否需要访问
    // 越界返回false
    if (x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }
    // 当前位置为0,或(x,y)已入过队,返回false
    if (matrix[x][y] == 0 || inq[x][y] == true) {
        return false;
    }
    // 以上都不满足,返回true
    return true;
}

// BFS函数访问位置(x,y)所在的块,将该块中所有的"1"的inq都设置为true
void BFS(int x, int y) {
    queue<node> Q; // 定义队列
    Node.x = x, Node.y = y; // 当前结点的坐标为(x,y)
    Q.push(Node);
    inq[x][y] = true; // 设置(x,y)已入过队
    while (!Q.empty()) {
        node top = Q.front();
        Q.pop();
        for (int i = 0; i < 4; ++i) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (judge(newX, newY)) { // 如果新位置(newX,newY)需要访问
                // 设置Node的坐标为(newX,newY)
                Node.x = newX;
                Node.y = newY;
                Q.push(Node); // 将结点加入队列,值传递
                inq[newX][newY] = true; // 设置位置(newX,newY)已入过队
            }
        }
    }
}

// 思考dfs的停止条件是: 无法继续往下扩展下去(四周都是已标记位)
void DFS(int x, int y) {
    if (judge(x, y)) { // (x,y)本身是否是越界点,走过的点
        inq[x][y] = true; // 设置(x,y)入队
    }
    int flag = false; // 用于标记四周各点是否被标记
    for (int i = 0; i < 4; ++i) { // 遍历该点四周四种情况
        int newX = x + X[i];
        int newY = y + Y[i];
        if (judge(newX, newY)) {
            flag = true; // 若有新点标记flag为true,否则则是递归尽头
        }
    }

    if (!flag) { // 如果没有再继续递归的可能则返回
        return;
    }

    for (int i = 0; i < 4; ++i) { // 能够执行到这里说明是具有递归可能
        int newX = x + X[i];
        int newY = y + Y[i];
        if (judge(newX, newY)) { //如果符合条件进入新一轮遍历
            DFS(newX, newY);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            scanf("%d", &matrix[x][y]); // 读入01矩阵
        }
    }

    int ans = 0; // 存放块数
//    for (int x = 0; x < n; ++x) {
//        for (int y = 0; y < m; ++y) {
//            // 如果元素为1,且未入过队
//            if (matrix[x][y] == 1 && inq[x][y] == false) {
//                ans++; // 块数加一
//                BFS(x, y); // 访问整个块,将该块所有"1"的inq都标记为true
//            }
//        }
//    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < m; ++y) {
            if (matrix[x][y] == 1 && inq[x][y] == false) {
                ans++;
                DFS(x,y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}

//6 7
//0 1 1 1 0 0 1
//0 0 1 0 0 0 0
//0 0 0 0 1 0 0
//0 0 0 1 1 1 0
//1 1 1 0 1 0 0
//1 1 1 1 0 0 0