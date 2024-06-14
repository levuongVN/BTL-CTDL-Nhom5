#include<iostream>
<<<<<<< Updated upstream
#include<string>
using namespace std;
struct Sach{
     string Ten_Sach;
    string Ten_Tac_Gia;
    float Gia_Sach;
=======
#include<fstream>
using namespace std;
struct Sach
{
	string Ten_Sach;
	string Ten_Tac_Gia;
	float Gia_Sach;
>>>>>>> Stashed changes
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
    while(T!=NULL){
        if(x.Ten_Sach==T->key.Ten_Sach){
            cout<<T->key.Ten_Sach<<" "<<T->key.Ten_Tac_Gia<<" "<<T->key.Gia_Sach<<endl;
        }
        Search(T->left,x);
        Search(T->right,x);
    }
}
void OutputMinToMax(cay T){// In tu gia thap den gia cao
    if(T!=NULL){
        OutputMinToMax(T->left);
        cout<<T->key.Ten_Sach<<" "<<T->key.Ten_Tac_Gia<<" "<<T->key.Gia_Sach<<endl;
        OutputMinToMax(T->right);
    }
}
<<<<<<< Updated upstream
void menu(){
    cay T;
    keys x;
    int a;
    do {
        cout<<"Nhap chuong trinhn";
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
                cout<<"Gia sach?\t";cin>>x.Gia_Sach;
                cin.ignore();
                cout<<"Nhap ten sach:\t";getline(cin,x.Ten_Sach);
                cout<<"Nhap ten tac gia:\t";getline(cin,x.Ten_Tac_Gia);
                AddElm(T, x);
                cout<<"Da xong\n";
                break;
            }
            case 3:{
                OutputMinToMax(T);
                break;
            }
            case 4:{
                cout<<"Nhap ten sach: "; getline(cin,x.Ten_Sach);
                Search(T,x);
                break;
            }
        }
    } while (a!=100);
}
int main(){
    menu();
=======

   		// cout<<"10. In sach theo gia tien tu cao den thap\n";
        // cout<<"11. Doc du lieu tu file\n";
        // cout<<"10. In danh sach\n";
void ReadFileToTree(Tree &T){ // case 11;
	ifstream f1;
	f1.open("Sach.txt");
	if(!f1){
		cout<<"Mo tep loi";
		return;
	}
	Item x;
	while (!f1.eof())///Đọc đến khi kết thúc file tệp
	{
		f1>>x.Ten_Sach;
		f1.ignore();
		getline(f1,x.Ten_Sach);
		f1>>x.Ten_Tac_Gia;
		f1.ignore();
		f1>>x.Gia_Sach;
		AddNode(T,x);
	}
	f1.close();
	cout<<"Da doc xong";
}
//Menu
void Menu(Tree T)
{
	int LuaChon;
	
	do
	{
		cout<<"\nCAC CHUC NANG\n";
		cout<<"1. Khoi tao\n";
		cout<<"2. Kiem tra cay rong\n";
		cout<<"3. Them 1 quyen sach vao danh sach \n";
        cout<<"4. Tim kiem sach bang ten sach\n";
        cout<<"5. Tim kiem sach bang ten tac gia\n";
        cout<<"6. Tim kiem sach theo menh gia\n";
        cout<<"7. Tim kiem sach theo menh gia cao nhat\n";
        cout<<"8. Tim kiem sach theo menh gia thap nhat\n";
        cout<<"9. In sach theo gia tien tu thap den cao\n";
        cout<<"10. In sach theo gia tien tu cao den thap\n";
        cout<<"11. Doc du lieu tu file\n";
        cout<<"12. In danh sach\n";		
		cout<<"Moi chon chuc nang (1-9)?";
		cin>>LuaChon;
		switch(LuaChon)
		{
			case 1:// Khởi tạo
			{
				Init(T);
				cout<<"Da khoi tao!";
				break;
			}
			case 2:// Kiểm tra rỗng
			{
				if (isEmpty(T))
					cout<<"Cay rong!";
				else
					cout<<"Cay khong trong!";
				break;
			}
			case 3: // Thêm 1 nút vào cây
			{
				Item x;
				cout<<"Nhap thong tin Sach\n";
				cout<<"Gia Sach: ";
				cin>>x.Gia_Sach;
				cout<<"Ten sach: ";
				getline(cin,x.Ten_Sach);
				cin.ignore();
				cout<<"Ho ten Tac Gia: ";
				getline(cin,x.Ten_Tac_Gia);
				cin.ignore();
			
				AddNode(T,x);
				cout<<"Da xong!\n";
				break;
			}
			
			case 11:
			{
				ReadFileToTree(T);
				break;
			}		
		}
	}while(LuaChon!=13);
>>>>>>> Stashed changes
}
