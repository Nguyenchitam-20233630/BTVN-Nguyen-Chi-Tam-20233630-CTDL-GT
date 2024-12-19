#include<iostream>
using namespace std;

struct NODE // Lưu data của 1 chap
{
    int chapter; // Thứ tự các chap của sách
    int page; // Số trang của chap đó
    int section; // Số phần của chap
    int subsection; // Số tiểu mục
    NODE* left; 
    NODE* right;

    NODE(int c, int p, int s, int subs)
    {
        chapter = c;
        page = p;
        section = s;
        subsection = subs;
        // Khởi tạo pointer trỏ đến con trái và con phải
        left = NULL;
        right = NULL;
    }
};

// Hàm kiểm tra cây rỗng
int isEmpty(NODE* root)
{
    return root == NULL;
}

// Hàm tạo 1 node
NODE* createNode(int c, int p, int s, int subs)
{
    NODE* ptr = new NODE(c, p, s, subs); // Gán địa chỉ của node mới cho pointer ptr
    return ptr;
}

// Hàm chèn một node vào cây
NODE* insertNode(NODE* root, int c, int p, int s, int subs) 
{
    if (root == NULL) return createNode(c, p, s, subs);

    if (c < root->chapter) root->left = insertNode(root->left, c, p, s, subs);
    else if (c > root->chapter) root->right = insertNode(root->right, c, p, s, subs);

    return root;
}

// Hàm đếm số lượng chương
void countChapter(NODE* root)
{
    if(isEmpty(root)) {
        cout << "0 chapters";
        return;
    }
    if(isEmpty(root->right))
    {
        if(root->chapter == 1) cout << "1 chapter";
        else cout << root->chapter << " chapters";
    }
    else countChapter(root->right);
}

// Hàm tìm chapter dài nhất dựa trên số trang của nó
int maxChapter(NODE* root, int &longestChap)
{
    if(isEmpty(root)) return 0;

    int max = 0;
    if(root->page > max) 
    {
        max = root->page;
        longestChap = root->chapter;
    }
    maxChapter(root->left, longestChap);
    maxChapter(root->right, longestChap);

    return longestChap;
}

// Hàm tìm kiếm chapter
void searchChapter(NODE* root, int chapter)
{
    if(isEmpty(root)) 
    {
        cout << "EMPTY !!!" << endl;
        return;
    }
    if(chapter == root->chapter) cout << "Found!" << endl;
    else searchChapter(root->right, chapter);
}

// Hàm cập nhật thứ tự chương sau khi xóa
void updateChapter(NODE* root, int delChapter) 
{
    if (root == NULL) return; // Điều kiện dừng: cây rỗng

    if (root->chapter > delChapter) 
    {
        root->chapter--;
    }

    updateChapter(root->left, delChapter);
    updateChapter(root->right, delChapter);
}

// Hàm xóa nếu node cần xóa không phải root
void deleteNodeNoRoot(NODE* root, int c)
{
    NODE* temp;
    int delChapter;
    if(c == root->right->chapter)
    {
        temp = root->right;
        if(!isEmpty(root->right->right)) root->right = root->right->right;
        delChapter = temp->chapter;
        delete temp;
    }
    updateChapter(root, delChapter);
}   

// Hàm xóa 1 node khỏi cây
void deleteNode(NODE* root, int c)
{
    if(c == root->chapter)
    {
        root = root->right;
        delete root->right;
    }
    deleteNodeNoRoot(root, c);
}

// Duyệt cây theo kiểu tiền tố (gốc - trái - phải)
void prefix(NODE* root)
{
    if(isEmpty(root)) return;
    cout << "Chapter: " << root->chapter << " Page: " << root->page << " Section: " << root->section << " Subsection: " << root->subsection;
    cout << endl;
    prefix(root->left);
    prefix(root->right); 
}

int main()
{
    NODE* root = NULL;

    int chapter;
    int page;
    int section;
    int subsection;

    for(int i = 0; i < 3; i++)
    {
        cout << " Chapter: ";
        cin >> chapter;
        cout << " Page: ";
        cin >> page;
        cout << " Section: ";
        cin >> section;
        cout << " subsection: ";
        cin >> subsection;

        root = insertNode(root, chapter, page, section, subsection);
    }

    prefix(root); cout << endl;

    countChapter(root); cout << endl;

    int longestChap;
    longestChap = maxChapter(root, longestChap);
    cout << longestChap << endl;
    searchChapter(root, 2); cout << endl;
    deleteNode(root, 2);

    return 0;
}
