#include <iostream>
#include <string>
using namespace std;

struct File {
    string name;       // Tên file
    long long size;    // Kích thước file
    string date;       // Thời gian tạo file 
    File* next;        // Con trỏ tới file tiếp theo trong danh sách
};

struct FileList {
    File* head;        // Con trỏ tới file đầu tiên trong danh sách

    // Khởi tạo danh sách trống
    FileList() : head(nullptr) {}
    
    // Hàm thêm file vào danh sách theo trật tự thời gian
    void addFile(const string& name, long long size, const string& date) {
        File* newFile = new File{name, size, date, nullptr};
        
        if (!head || date < head->date) { // Nếu danh sách trống hoặc ngày của file mới sớm hơn
            newFile->next = head;
            head = newFile;
        } else {
            File* current = head;
            while (current->next && current->next->date < date) {
                current = current->next;
            }
            newFile->next = current->next;
            current->next = newFile;
        }
    }
    
    // Hàm tính tổng kích thước các file trong danh sách
    long long calculateTotalSize() const {
        long long totalSize = 0;
        File* current = head;
        while (current) {
            totalSize += current->size;
            current = current->next;
        }
        return totalSize;
    }
    
    // Hàm xóa file có kích thước nhỏ nhất
    void removeSmallestFile() {
        if (!head) return; // Danh sách trống
        
        File *prev = nullptr, *smallestPrev = nullptr;
        File *current = head, *smallest = head;
        
        // Tìm file có kích thước nhỏ nhất
        while (current) {
            if (current->size < smallest->size) {
                smallest = current;
                smallestPrev = prev;
            }
            prev = current;
            current = current->next;
        }
        
        // Xóa file nhỏ nhất
        if (smallestPrev) {
            smallestPrev->next = smallest->next;
        } else {
            head = head->next;
        }
        delete smallest;
    }

    // Hàm sao lưu các file vào USB có dung lượng 32GB
    void backupToUSB() {
        const long long USB_CAPACITY = 32LL * 1024 * 1024 * 1024; // 32GB
        while (calculateTotalSize() > USB_CAPACITY) {
            removeSmallestFile();
        }
    }

    // Hàm hiển thị danh sách file
    void displayFiles() const {
        File* current = head;
        while (current) {
            cout << "File: " << current->name << ", Size: " << current->size << " bytes, Date: " << current->date << endl;
            current = current->next;
        }
    }
};