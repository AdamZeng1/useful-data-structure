//
// Created by adamzeng on 2019-06-25.
//


#include <cstdio>
#include <vector>

using namespace std;

struct node {
    int data; // 数据域
    node *left, *right; // 指针域
};

void insert(node *&root, int data) {
    if (root == NULL) { // 到达空结点时,即为需要插入的位置
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }

    if (data < root->data) insert(root->left, data); // 插在左子树
    else insert(root->right, data); // 插在右子树
}

void preOrder(node *root, vector<int> &vi) { // 先序遍历,结果存在vi
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrder(root->left, vi);
    preOrder(root->right, vi);
}

void preOrderMirror(node *root, vector<int> &vi) {
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->right, vi);
    preOrderMirror(root->left, vi);
}

void postOrder(node *root, vector<int> &vi) {
    if (root == NULL) return;
    vi.push_back(root->data);
    preOrderMirror(root->left, vi);
    preOrderMirror(root->right, vi);
    vi.push_back(root->data);
}

void postOrderMirror(node *root, vector<int> &vi) {
    if (root == NULL) return;
    postOrderMirror(root->right, vi);
    postOrderMirror(root->left, vi);
    vi.push_back(root->data);
}

// origin 存放初始序列
// pre、post先序、后序,preM、postM为镜像树先序、后序
vector<int> origin, pre, preM, post, postM;

int main() {
    int n, data;
    node *root = NULL; // 定义头结点
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preOrder(root, pre);
    preOrderMirror(root, preM);
    postOrder(root, post);
    postOrderMirror(root, postM);
    if (origin == pre) {
        printf("YES\n");
        for (int i = 0; i < post.size(); ++i) {
            printf("%d", post[i]);
            if (i < post.size() - 1) printf(" ");
        }
    } else if (origin == preM) {
        printf("YES\n");
        for (int i = 0; i < postM.size(); ++i) {
            printf("%d", postM[i]);
            if (i < postM.size() - 1) printf(" ");
        }
    } else {
        printf("NO\n");
    }
    return 0;
}


