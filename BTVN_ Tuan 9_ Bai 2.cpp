#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    char word[50];
    int count;     
    Node* next;    
    Node(const char* w) {
        strcpy(word, w);
        count = 1;
        next = NULL;
    }
};

void addWord(Node*& head, const char* word) {
    Node* current = head;

    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            current->count++; 
            return;
        }
        current = current->next;
    }

    Node* newNode = new Node(word);
    newNode->next = head;
    head = newNode;
}

void findMostFrequent(Node* head) {
    Node* current = head;
    char mostFrequentWord[50] = "";
    int maxCount = 0;

    while (current != NULL) {
        if (current->count > maxCount) {
            maxCount = current->count;
            strcpy(mostFrequentWord, current->word);
        }
        current = current->next;
    }

    cout << "Từ xuất hiện nhiều nhất: " << mostFrequentWord 
         << " (" << maxCount << " lần)" << endl;
}

void Loai_Bo_Tu_lay(Node*& head) {
    Node* current = head;
    Node* prev = NULL;

    while (current != NULL) {
        char part1[25], part2[25];
        if (sscanf(current->word, "%s %s", part1, part2) == 2) {
            if (strcmp(part1, part2) == 0) { // Nếu từ là từ láy
                if (prev == NULL) {
                    head = current->next;
                } else {
                    prev->next = current->next;
                }
                Node* temp = current;
                current = current->next;
                delete temp;
                continue;
            }
        }
        prev = current;
        current = current->next;
    }
}

int countWords(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

void displayList(Node* head) {
    Node* current = head;

    while (current != NULL) {
        cout << current->word << " (" << current->count << ")" << endl;
        current = current->next;
    }
}

void freeList(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;
    
    int n;
    cout << "Nhập độ dài mảng: ";
    cin >> n;
    
    char* Sentence = new char[n + 1];  
    cout << "Nhập chuỗi ký tự: ";
    cin.ignore(); 
    cin.getline(Sentence, n + 1);  
    
    cout << "Chuỗi bạn đã nhập: " << Sentence << endl;
    
    char* word = strtok(Sentence, " ");
    while (word != NULL) {
        addWord(head, word);
        word = strtok(NULL, " ");
    }
    
    cout << "Danh sách từ và số lần xuất hiện:\n";
    displayList(head);

    findMostFrequent(head);

    Loai_Bo_Tu_lay(head);
    cout << "Danh sách sau khi loại bỏ từ láy:\n";
    displayList(head);

    int totalWords = countWords(head);
    cout << "\nTổng số từ: " << totalWords << endl;

    freeList(head); 
    delete[] Sentence;
    return 0;
}
