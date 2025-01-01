#include <iostream>
using namespace std;
/* HN: 0 
HB: 1 
ST: 2
TN: 3
BN: 4
HD: 5
HY: 6
PL: 7
BG: 8
UB: 9
HPP:10*/

struct node {
    int dinh;
    node* next;
};

struct graph {
    int Sodinh;
    int* Matran;
    node* Danhsach;

    graph(int vertices) {
        Sodinh = vertices;

        Matran = new int[Sodinh * Sodinh];
        for (int i = 0; i < Sodinh * Sodinh; i++) {
            Matran[i] = 0;
        }

 
        Danhsach = new node[Sodinh];
        for (int i = 0; i < Sodinh; i++) {
            Danhsach[i].dinh = i;
            Danhsach[i].next = NULL;
        }
    }

    graph() {
        delete[] Matran;
        for (int i = 0; i < Sodinh; i++) {
            node* current = Danhsach[i].next;
            while (current != NULL) {
                node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] Danhsach;
    }

    void addEdgeMatrix(int u, int v) {
        Matran[u * Sodinh + v] = 1;
        Matran[v * Sodinh + u] = 1; 
    }

    void displayMatrix() {
        cout << "Ma trận kề:" << endl;
        for (int i = 0; i < Sodinh; i++) {
            for (int j = 0; j < Sodinh; j++) {
                cout << Matran[i * Sodinh + j] << " ";
            }
            cout << endl;
        }
    }

    void addEdgeList(int u, int v) {
        node* newnode = new node{v, Danhsach[u].next};
        Danhsach[u].next = newnode;

        newnode = new node{u, Danhsach[v].next};
        Danhsach[v].next = newnode; 
    }

    void displayList() {
        cout << "Danh sách kề:" << endl;
        for (int i = 0; i < Sodinh; i++) {
            cout << i << ": ";
            node* current = Danhsach[i].next;
            while (current != NULL) {
                cout << current->dinh << " ";
                current = current->next;
            }
            cout << endl;
        }
    }
};

int main() {
    graph g(11); 
//Ma trận kề
    g.addEdgeMatrix(0, 1);
    g.addEdgeMatrix(0, 2);
    g.addEdgeMatrix(0, 3);
    g.addEdgeMatrix(0, 4);
    g.addEdgeMatrix(0, 5);
    g.addEdgeMatrix(0, 7);
    g.addEdgeMatrix(4, 8);
    g.addEdgeMatrix(4, 9);
    g.addEdgeMatrix(5, 6);
    g.addEdgeMatrix(5, 10);
    g.addEdgeMatrix(6, 7);
    g.addEdgeMatrix(8, 9);
    g.addEdgeMatrix(9, 10);
    g.displayMatrix();
//Danh sách kề
    g.addEdgeList(0, 1);
    g.addEdgeList(0, 2);
    g.addEdgeList(0, 3);
    g.addEdgeList(0, 7);
    g.addEdgeList(4, 8);
    g.addEdgeList(4, 9);
    g.addEdgeList(5, 6);
    g.addEdgeList(5, 10);
    g.addEdgeList(6, 7);
    g.addEdgeList(8, 9);
    g.addEdgeList(9, 10);
    g.displayList();

    return 0;
}