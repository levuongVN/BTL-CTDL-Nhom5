#include<iostream>
#include<string>
using namespace std;
struct Sach{
     string Ten_Sach;
    string Ten_Tac_Gia;
    float Gia_Sach;
};
typedef Sach keys;
struct Tree{
    keys key;
    Tree *left;
    Tree *right;
};
typedef Tree *cay;
void Init(cay &T){
    T=NULL;
}
void AddElm(cay &T,keys x){// Them 1 phan tu vao cay
    if(T==NULL){
        T= new Tree;
        T->key=x;
        T->left=NULL;
        T->right=NULL;
    }
    else{
        if(x.Gia_Sach<T->key.Gia_Sach){
            AddElm(T->left,x);
        }
        else{
            AddElm(T->right,x);
        }
    }
}

void Search(cay &T, keys x){
    if(T!=NULL){
        if(x.Ten_Sach==T->key.Ten_Sach){
            cout<<T->key.Ten_Sach<<" "<<T->key.Ten_Tac_Gia<<" "<<T->key.Gia_Sach<<endl;
        }
        Search(T->left,x);
        Search(T->right,x);
    }
}
void SearchByAuthor(cay &T, keys x){
    if(T!=NULL){
        if(x.Ten_Tac_Gia==T->key.Ten_Tac_Gia){
            cout<<T->key.Ten_Sach<<" "<<T->key.Ten_Tac_Gia<<" "<<T->key.Gia_Sach<<endl;
        }
        SearchByAuthor(T->left,x);
        SearchByAuthor(T->right,x);
    }
}
void SearchByPrice(cay &T, keys x){
    if(T!=NULL){
        if(x.Gia_Sach==T->key.Gia_Sach){
            cout<<T->key.Ten_Sach<<" "<<T->key.Ten_Tac_Gia<<" "<<T->key.Gia_Sach<<endl;
        }
        SearchByPrice(T->left,x);
        SearchByPrice(T->right,x);
    }
}
void OutputMinToMax(cay T){// In tu gia thap den gia cao
    if(T!=NULL){
        OutputMinToMax(T->left);
        cout<<T->key.Ten_Sach<<" "<<T->key.Ten_Tac_Gia<<" "<<T->key.Gia_Sach<<endl;
        OutputMinToMax(T->right);
    }
}
void menu(){
    cay T;
    keys x;
    int a;
    do {
        cout<<"Nhap chuong trinh\n";
        cout<<"1. Khoi tao\n";
        cout<<"2. Them 1 phan tu\n";
        cout<<"4. Tim kiem sach bang ten sach\n";
        cout<<"5. Tim kiem sach bang ten tac gia\n";
        cout<<"6. Tim kiem sach theo menh gia\n";
        cout<<"12. In sach theo gia tu thap den cao\n";
        cin>>a;
        switch (a) {
            case 1:
                Init(T);
                cout<<"Done!\n";
                break;
            case 2:{
                cout<<"Nhap thong tin sach\n";
                cout<<"Gia sach?";
                cin>>x.Gia_Sach;
                cin.ignore();
                cout<<"Nhap ten sach:";getline(cin,x.Ten_Sach);
                cout<<"Nhap ten tac gia:";getline(cin,x.Ten_Tac_Gia);
                AddElm(T, x);
                cout<<"Da xong\n";
                break;
            }
            case 4:{
                cout<<"Nhap ten sach: ";
                cin.ignore();// Xoa dau '\n' van con ton tai tu truoc do
                getline(cin,x.Ten_Sach);
                Search(T,x);
                break;
            }
            case 5:{
                cout<<"Nhap ten tac gia: ";
                cin.ignore();
                getline(cin,x.Ten_Tac_Gia);
                SearchByAuthor(T,x);
                break;
            }
            case 12:{
                OutputMinToMax(T);
                break;
            }
        }
    } while (a!=100);
}
int main(){
    menu();
}