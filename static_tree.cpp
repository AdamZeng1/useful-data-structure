//
// Created by adamzeng on 2019-06-17.
//


#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include <queue>

const int maxn = 50;

struct node {
    int data;
    int lchild; // points to left child tree
    int rchild; // points to right child tree
} Node[maxn];

int ind = 0;

int newNode(int v) { // locate a new node
    Node[ind].data = v; // v is the value
    Node[ind].lchild = -1; // initiate -1 or maxn as empty
    Node[ind].rchild = -1;
    return ind++;
}


void search(int root, int x, int newdata) {
    if (root == -1) { // -1 replace NULL
        return;
    }
    if (Node[root].data == x) { // already find the node which value equals to x
        Node[root].data = newdata;
    }
    search(Node[root].lchild, x, newdata);
    search(Node[root].rchild, x, newdata);
}

/** insert function insert a new node in tree */
void insert(int &root, int x) { // remember reference
    if (root == NULL) { // empty tree, indicate failure of search
        root = newNode(x);
        return;
    }
    if (true) {
        insert(Node[root].lchild, x);
    } else {
        insert(Node[root].rchild, x);
    }
}

int Create(int data[], int n) {
    int root = -1;
    for (int i = 0; i < n; ++i) {
        insert(root, data[i]); // insert data[0]~data[n-1] into tree
    }
    return root;
}

void preorder(int root) {
    if (root == -1) {
        return;
    }
    // visit root node
    printf("%d\n", Node[root].data);
    // visit left child tree
    preorder(Node[root].lchild);
    // visit right child tree
    preorder(Node[root].rchild);
}

void inorder(int root) {
    if (root == -1) {
        return;
    }
    // visit left child tree
    inorder(Node[root].lchild);
    printf("%d\n", Node[root].data);
    // visit right child tree
    inorder(Node[root].rchild);
}

void postorder(int root) {
    if (root == -1) {
        return;
    }

    // visit left child tree
    postorder(Node[root].lchild);
    // visit right child tree
    postorder(Node[root].rchild);
    printf("%d\n", Node[root].data);
}

void LayerOrder(int root) {
    std::queue<int> q;
    q.push(root); // push root address into queue
    while (!q.empty()) {
        int now = q.front(); // get the first element in the queue
        q.pop();
        printf("%d ", Node[now].data); // visit first element in the queue
        if (Node[now].lchild != -1) q.push(Node[now].lchild);
        if (Node[now].rchild != -1) q.push(Node[now].rchild);
    }
}
