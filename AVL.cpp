//
// Created by adamzeng on 2019-06-26.
//

#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct node {
    int v, height; // v为结点权值,height为当前子树高度
    node *lchild, *rchild; // 左右孩子结点地址
};

// 生产一个新结点,v为结点权值
node *newNode(int v) {
    node *Node = new node; // 申请一个node型变量的地址空间
    Node->v = v; // 结点权值为v
    Node->height = 1;
    Node->lchild = Node->rchild = NULL; // 初始状态下没有左右孩子
    return Node; // 返回新建结点的地址
}

// 获取以root为根结点的子树的当前height
int getHeight(node *root) {
    if (root == NULL) return 0; // 空结点高度为0
    return root->height;
}

// 计算结点root的平衡因子
int getBalanceFactor(node *root) {
    // 左子树高度减右子树高度
    return getHeight(root->lchild) - getHeight(root->rchild);
}

// 更新结点root的height
void updateHeight(node *root) {
    // max(左孩子的height,右孩子的height) + 1
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

// search函数查找AVL树中的数据域为x的结点
void search(node *root, int x) {
    if (root == NULL) {
        printf("search failed\n");
        return;
    }
    if (x == root->v) {
        printf("%d\n", root->v);
    } else if (x < root->v) {
        search(root->lchild, x);
    } else {
        search(root->rchild, x); // 往右子树搜索x
    }
}


// 左旋(Left Rotation)
void L(node *&root) {
    node *temp = root->rchild; // root指向结点A,temp指向结点B
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

// 右旋(Right Rotation)
void R(node *&root) {
    node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(node *&root, int v) {
    if (root == NULL) {
        root = newNode(v);
        return;
    }
    if (v < root->v) { // v比根结点的权值小
        insert(root->lchild, v); // 往左子树插入
        updateHeight(root); // 更新树高
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) { // LL型
                R(root);
            } else if (getBalanceFactor(root->lchild) == -1) { // LR型
                L(root->lchild);
                R(root);
            }
        }
    } else { // v比根结点的权值小
        insert(root->rchild, v); // 往右子树插入
        updateHeight(root); // 更新树高
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) { // RR型
                R(root);
            } else if (getBalanceFactor(root->lchild) == 1) { // RL型
                R(root->rchild);
                L(root);
            }
        }
    }
}

// AVL树的建立
node *Create(int data[], int n) {
    node *root = NULL; // 新建空根结点root
    for (int i = 0; i < n; ++i) {
        insert(root, data[i]); // 将data[0]~data[n-1]插入到AVL树中
    }
    return root; // 返回根结点
}

