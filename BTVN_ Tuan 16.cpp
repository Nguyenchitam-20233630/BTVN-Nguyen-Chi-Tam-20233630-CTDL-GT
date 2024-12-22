#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};
//Cài đặt hàm nhập node mới
Node* createNode(int key) {
    Node* node = new Node();
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getHeight(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}
//Cài đặt hàm xoay đơn/kép
Node* rightRotate(Node* z) {
    Node* y = z->left;
    Node* T3 = y->right;

    y->right = z;
    z->left = T3;

    z->height = 1 + ((getHeight(z->left) > getHeight(z->right)) ? getHeight(z->left) : getHeight(z->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));

    return y;
}

Node* leftRotate(Node* z) {
    Node* y = z->right;
    Node* T2 = y->left;

    y->left = z;
    z->right = T2;

    z->height = 1 + ((getHeight(z->left) > getHeight(z->right)) ? getHeight(z->left) : getHeight(z->right));
    y->height = 1 + ((getHeight(y->left) > getHeight(y->right)) ? getHeight(y->left) : getHeight(y->right));

    return y;
}
//Cài đặt hàm kiểm tra cân bằng
int getBalance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = (node->left == NULL) ? 0 : node->left->height;
    int rightHeight = (node->right == NULL) ? 0 : node->right->height;
    return leftHeight - rightHeight;
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        return createNode(key);
    }

    if (key < root->key) {
        root->left = insert(root->left, key);
    } else {
        root->right = insert(root->right, key);
    }

    root->height = 1 + ((getHeight(root->left) > getHeight(root->right)) ? getHeight(root->left) : getHeight(root->right));

    int balance = getBalance(root);

    // trường hợp trái - trái
    if (balance > 1 && key < root->left->key) {
        return rightRotate(root);
    }

    // trường hợp phải - phải
    if (balance < -1 && key > root->right->key) {
        return leftRotate(root);
    }

    // trường hợp trái phải
    if (balance > 1 && key > root->left->key) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // trường hợp phải trái
    if (balance < -1 && key < root->right->key) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
//Cài đặt hàm in cây AVL (theo thứ tự duyệt)
void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->key << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    int data[] = {17, 23, 201, 98, 67, 83, 13, 23, 10, 191, 84, 58};
    int n = sizeof(data) / sizeof(data[0]);

    Node* root = NULL;
    for (int i = 0; i < n; ++i) {
        root = insert(root, data[i]);
    }

    cout << "in cây AVL theo thứ tự duyệt:" << endl;
    preOrder(root);

    return 0;
}
