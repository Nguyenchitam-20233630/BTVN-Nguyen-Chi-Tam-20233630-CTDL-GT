#include <iostream>

using namespace std;

struct NODE 
{
    float heso;     
    int somu;        
    NODE* next;  

};

struct LIST 
{
    NODE* first;  
    NODE* last;   

};


void LIST_INIT(LIST* danhsach) 
{
    danhsach->first = danhsach->last = NULL; 

}


NODE* MAKE_NODE(float hs, int sm) 
{
    NODE* p = new NODE; 
    if (p == NULL) return NULL;
    p->heso = hs;
    p->somu = sm;
    p->next = NULL;

    return p; 
}


void ADD_NODE(LIST* ds, NODE* p)
{
    if (ds->first == NULL) 
    {   
        ds->first = ds->last = p; 
    }
    else
    {
        ds->last->next = p; 
        ds->last = p;       
    }

}


void ATTACH_NODE(LIST* lDT, float hs, int sm)
{
    if (hs == 0) return;
    NODE* pDT = MAKE_NODE(hs, sm);
    if (pDT == NULL) return; 
    ADD_NODE(lDT, pDT); 

}


void DT(LIST* lDT) 
{
    float hs;
    int sm;
    int i = 0; 
    cout << "Bat dau nhap da thuc (nhap he so 0 de ket thuc): " << endl;
    do 
    {
        i++;
        cout << "Nhap so phan tu thu " << i << endl;
        cout << "Nhap he so = ";
        cin >> hs;
        if (hs == 0) break;
        cout << "Nhap so mu = ";
        cin >> sm;
        ATTACH_NODE(lDT, hs, sm); 
    } while (hs != 0);
    cout << "Ket thuc nhap" << endl;

}


void inDT(LIST* lDT) 
{
    NODE* p = lDT->first;
    cout << endl << "f(x) = ";
    while (p != NULL)
    {
        if (p->heso != 0) 
        { 
            cout << p->heso << " * x^" << p->somu;
            if (p->next != NULL) cout << " + ";
        }
        p = p->next; 
    }
    cout << endl;

}

int main() 
{
    LIST DT1;
    LIST_INIT(&DT1); 
    DT(&DT1); 
    inDT(&DT1); 

    return 0;
}
