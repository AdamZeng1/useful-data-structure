//
// Created by adamzeng on 2019-06-17.
//

#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>

using namespace std;


const int maxn = 50;

struct node {
    int data;
    node *lchild;
    node *rchild;
};

int pre[maxn], in[maxn], post[maxn]; // pre,in,post
int n; // node number

/** current tree's post is [postL,postR], in is [inL,inR]
 * create function return root address of tree */

node *create(int postL, int postR, int inL, int inR) {
    if (postL > postR) {
        return NULL;
    }

    node *root = new node(); // new node as root
    root->data = post[postR]; // new node data field equals to post[postR]
    int k;
    // find the root value in [inL,inR]
    for (k = 0; k <= inR; ++k) {
        if (in[k] == post[postR]) { // post[postR] equals to root value
            break; // k is the index of root in [inL,inR]
        }
    }

    int numLeft = k - inL; // left child tree's node number

    root->lchild = create(postL, postL + numLeft - 1, inL, k - 1);
    root->rchild = create(postL + numLeft, postR - 1, k + 1, inR);

    return root;
}

int num = 0; // already outputting nodes
void BFS(node *root) {
    queue<node *> q;
    q.push(root); // push root node into queue
    while (!q.empty()) {
        node *now = q.front(); // get first element in queue
        q.pop();
        printf("%d", now->data); // visit first node in queue
        num++;
        if (num < n) printf(" ");
        if (now->lchild != NULL) q.push(now->lchild);
        if (now->rchild != NULL) q.push(now->rchild);
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }
    node *root = create(0, n - 1, 0, n - 1);
    BFS(root);
    return 0;
}