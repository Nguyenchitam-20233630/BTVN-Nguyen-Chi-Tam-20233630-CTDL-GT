#include <iostream>
#include <string.h>

using namespace std;

struct Node{
    string data;
    Node* Left;
    Node* Right;
};
Node* Tao_node(string x){
    Node* newnode = new Node;
    newnode->data = x;
    newnode->Left = NULL;
    newnode->Right = NULL;
    return newnode;
}
bool isEmty(Node* root){
    return root == NULL;
}
Node* Tao_cay(string Cay[], int& p, int n) {
    if (p >= n) return NULL;
    Node* node = Tao_node(Cay[p]);
    p++;
    if (node->data == "+" || node->data == "-" || node->data == "*" || node->data == "/" || node->data == "^") {
        node->Left = Tao_cay(Cay, p, n);
        node->Right = Tao_cay(Cay, p, n);
    }

    return node;
}
void LNR(Node* root) {
    if (root == NULL) return;
    if (root->Left) cout << "(";
    LNR(root->Left);
    cout << root->data << " ";
    LNR(root->Right);
    if (root->Right) cout << ")";
}
void LRN(Node* root) {
    if (root == NULL) return; 
    LRN(root->Left);
    LRN(root->Right);
    cout << root->data << " ";
}
void NLR(Node* root) {
    if (root == NULL) return; 
    cout << root->data << " ";
    NLR(root->Left);
    NLR(root->Right);
}
int main(){
    Node* root = NULL;
    int n;
    string Phan_tu[] = {"+", "-", "*", "a", "5", "/", "*", "b", "^", "c", "6", "d", "*", "-", "h", "f", "^", "e", "1/2"};
    n = sizeof(Phan_tu) / sizeof(Phan_tu[0]);
    int x = 0;
    root = Tao_cay(Phan_tu,x,n);
    LNR(root);
    cout<<endl;
    LRN(root);
    cout<<endl;
    NLR(root);
    cout<<endl;
    return 0;
}