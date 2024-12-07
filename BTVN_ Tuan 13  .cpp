#include <iostream>
#include <string>

using namespace std;

struct Node {
    string name;
    int so_tien;
    int so_san_pham_A;
    Node* next ;
};

struct Queue {
    Node* F = NULL;
    Node* R = NULL;

    bool isEmpty() const {
        return F == NULL;
    }

    void enqueue(const string& name, int amount, int productA) {
        Node* newNode = new Node{name, amount, productA, NULL};
        if (isEmpty()) {
            F = R = newNode;
        } else {
            R->next = newNode;
            R = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Hang doi trong" << endl;
            return;
        }
        Node* temp = F;
        F = F->next;
        if (!F) R = NULL;
        cout << temp->name << " thanh toan xong" << endl;
        delete temp;
    }

    int totalProductA() const {
        int count = 0;
        for (Node* p = F; p; p = p->next) {
            count += p->so_san_pham_A;
        }
        return count;
    }

    float totalAmount() const {
        float sum = 0;
        for (Node* p = F; p; p = p->next) {
            sum += p->so_tien;
        }
        return sum;
    }

    void clear() {
        while (!isEmpty()) dequeue();
    }
};

int main() {
    Queue queue;
    int n;

    cout << "Nhap so khach hang: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string name;
        int amount, productA;

        cout << "Nhap ten khach hang thu " << i + 1 << ": ";
        getline(cin, name);
        cout << "So tien cua khach hang: ";
        cin >> amount;
        cout << "So luong san pham A: ";
        cin >> productA;
        cin.ignore();

        queue.enqueue(name, amount, productA);
    }

    if (!queue.isEmpty()) {
        cout << "So san pham A la: " << queue.totalProductA() << endl;
        cout << "Tong so tien thu duoc la: " << queue.totalAmount() << endl;
    }

    queue.clear(); 
    return 0;
}
