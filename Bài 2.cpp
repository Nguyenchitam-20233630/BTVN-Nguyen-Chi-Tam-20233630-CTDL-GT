#include <iostream>
#include <set> // S? d?ng set thay cho unordered_set
#include <cmath> // Thý vi?n tính sqrt

using namespace std;

// Hàm ki?m tra s? nguyên t?
bool Kiem_tra(int n) {
    if (n < 2) {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++) { // Ki?m tra ð?n cãn b?c hai c?a n
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Hàm ki?m tra s? nguyên t? Blum
bool is_blum_prime(int num) {
    return Kiem_tra(num) && num % 4 == 3;
}

// Sinh các s? nguyên t? Blum
int* generate_blum_primes(int n, int& size) {
    int* blum_primes = new int[n];
    size = 0;

    for (int i = 2; i < n; ++i) {
        if (is_blum_prime(i)) {
            blum_primes[size++] = i;
        }
    }
    return blum_primes; 
}

// Sinh các s? Blum
int* generate_blum_numbers(int n, int& blum_size) {
    int size;
    int* blum_primes = generate_blum_primes(n, size);
    int* blum_numbers = new int[n]; 
    blum_size = 0;

    for (int i = 0; i < size; ++i) {
        for (int j = i; j < size; ++j) {
            int blum_number = blum_primes[i] * blum_primes[j];
            if (blum_number < n) {
                blum_numbers[blum_size++] = blum_number; 
            } else {
                break;
            }
        }
    }

    delete[] blum_primes; 
    return blum_numbers; 
}

// Hàm t?m t?ng c?a các s? Blum
void Tim_tong(int* blum_numbers, int blum_size, int n) {
    set<int> blum_set(blum_numbers, blum_numbers + blum_size); // Dùng set thay cho unordered_set
    for (int i = 0; i < blum_size; ++i) {
        for (int j = i; j < blum_size; ++j) {
            int sum = blum_numbers[i] + blum_numbers[j];
            if (sum < n && blum_set.find(sum) != blum_set.end()) { // Ki?m tra ði?u ki?n sum < n
                cout << "(" << blum_numbers[i] << ", " << blum_numbers[j] << ")\n";
            }
        }
    }
}

// Hàm ki?m tra s? M có t?n t?i trong d?y không
bool Tim_So_M(int* blum_numbers, int blum_size, int M) {
    for (int i = 0; i < blum_size; ++i) {
        if (blum_numbers[i] == M) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cout << "Nhap N: ";
    cin >> n;

    int blum_size;
    int* blum_numbers = generate_blum_numbers(n, blum_size);
    
    cout << "Day cac so Blum la: ";
    for (int i = 0; i < blum_size; ++i) {
        cout << blum_numbers[i] << " ";
    }
    cout << endl;

    Tim_tong(blum_numbers, blum_size, n);
    
    int M;
    cout << "Nhap M: ";
    cin >> M;
    if (Tim_So_M(blum_numbers, blum_size, M)) {
        cout << M << " ton tai trong day" << endl;
    } else {
        cout << M << " khong ton tai trong day" << endl;
    }

    delete[] blum_numbers;
    return 0;
}

