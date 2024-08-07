#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Sach {
    string TenSach; // Tên cuốn sách
    string TenTG;   // Tên tác giả
    float GiaSach;  // Giá cuốn sách
};

typedef Sach Item;
struct TNode {
    Item Key;
    TNode *Left;
    TNode *Right;
};
typedef TNode *Tree;

// Khởi tạo cây
void Init(Tree &T) {
    T = NULL;
}

// Kiểm tra cây rỗng
bool isEmpty(Tree T) {
    return (T == NULL);
}

// Thêm 1 cuốn sách vào cây T
void AddNode(Tree &T, Item x) {
    if (T == NULL) { // Cây rỗng
        T = new TNode;
        T->Key = x;
        T->Left = NULL;
        T->Right = NULL;
    } else { // Cây không rỗng
        if (x.GiaSach<T ->Key.GiaSach) { // x nhỏ hơn key thì cho bên trái
            AddNode(T->Left, x); // Thêm vào bên trái
        } else { // x lớn hơn key thì cho bên phải
            AddNode(T->Right, x); // Thêm vào bên phải
        }
    }
}


// In cây sách
void InCaySach(Tree T) {
    if (T != NULL) {
        cout << T->Key.TenSach << "\t" << T->Key.TenTG << "\t" << T->Key.GiaSach << endl;
        InCaySach(T->Left);
        InCaySach(T->Right);
    }
}

// In từ thấp đến cao theo giá trị của sách
void InTuThapDenCao(Tree T) {
    if (T != NULL) {
        InTuThapDenCao(T->Left);
        cout << T->Key.TenSach << "\t" << T->Key.TenTG << "\t" << T->Key.GiaSach << endl;
        InTuThapDenCao(T->Right);
    }
}

// In từ cao đến thấp theo giá trị của sách
void InTuCaoDenThap(Tree T) {
    if (T != NULL) {
        InTuCaoDenThap(T->Right);
        cout << T->Key.TenSach << "\t" << T->Key.TenTG << "\t" << T->Key.GiaSach << endl;
        InTuCaoDenThap(T->Left);
    }
}

// Đọc dữ liệu từ tệp Sach.txt vào cây T
void DocTep(Tree &T) {
    ifstream f1("Sach.txt");

    if (!f1) {
        cout << "Mo tep loi!" << endl;
        return;
    }

    Item x;
    while (getline(f1, x.TenSach) && getline(f1, x.TenTG) && f1 >> x.GiaSach) {

        f1.ignore();
        AddNode(T, x);
    }
    f1.close();
    cout << "Da doc xong!" << endl;
}

// Tính và trả về tổng giá trị sách trong cây
float TongGiaTriSach(Tree T) {
    if (T != NULL) {
        return T->Key.GiaSach + TongGiaTriSach(T->Left) + TongGiaTriSach(T->Right);
    } else
        return 0;
}

// Đếm và trả về số lượng sách trong cây
int DemSoLuongSach(Tree T) {
    if (T != NULL) {
        return 1 + DemSoLuongSach(T->Left) + DemSoLuongSach(T->Right);
    } else
        return 0;
}

void DemSach(Tree T, int price  ) {
    if (T != NULL) { // Cây không rỗng
     if(T->Key.GiaSach <= price){
        cout<< T->Key.GiaSach<<"\t"<<T->Key.TenSach<<" "<<T->Key.TenTG<<'\n';
        DemSach(T->Left, price);
        DemSach(T->Right, price);
     }
     else if (T->Key.GiaSach > price)
     {
       DemSach(T->Right, price);
       DemSach(T->Left, price);
     }
    }
}

// Tìm sách theo tên tác giả
void TimSachTheoTenTG(Tree T, string TenTG) {
if (T != NULL) {
        if (T->Key.TenTG == TenTG) {
            cout << "Ten sach la: " << T->Key.TenSach << " " << "Gia sach: " << T->Key.GiaSach << endl;
        }else{
        TimSachTheoTenTG(T->Left, TenTG);
        TimSachTheoTenTG(T->Right, TenTG);
        }
    }
}

// Tìm tác giả theo tên sách
void TimTGTheoTenSach(Tree T, string TenSach) {
    if (T != NULL) {
        if (T->Key.TenSach == TenSach)
            cout << "Ten tac gia la: " << T->Key.TenTG << "\t" << "Gia sach: " << T->Key.GiaSach << endl;
        TimTGTheoTenSach(T->Left, TenSach);
        TimTGTheoTenSach(T->Right, TenSach);
    }
}

// Tìm sách theo giá trị sách
void TimSachTheoGiaTri(Tree T, Item x) {
    if (T != NULL) {
        if (T->Key.GiaSach == x.GiaSach)
            cout << "Ten sach la: " << T->Key.TenSach << "\t" << "Tac Gia: " << T->Key.TenTG << endl;
        TimSachTheoGiaTri(T->Left, x);
        TimSachTheoGiaTri(T->Right, x);
    }
}

// Tìm giá trị sách lớn nhất trong cây
TNode *TimGiaTriLonNhat(Tree T) {
    while (T->Right != NULL) {
        T = T->Right;
    }
    return T;
}

// Tìm giá trị sách nhỏ nhất trong cây
TNode *TimGiaTriNhoNhat(Tree T) {
    while (T->Left != NULL) {
        T = T->Left;
    }
    return T;
}

// Xóa một sách trong cây
void XoaSach(Tree &T, string TenSach) {
    if (T == NULL)
        return;
    if (T->Key.TenSach == TenSach) {
        if (T->Left == NULL && T->Right == NULL) {
            delete T;
            T = NULL;
        } else if (T->Left == NULL) {
            TNode *p = T;
            T = T->Right;
            delete p;
        } else if (T->Right == NULL) {
            TNode *p = T;
            T = T->Left;
            delete p;
        } else {
            TNode *p = TimGiaTriNhoNhat(T->Right);
            T->Key = p->Key;
            XoaSach(T->Right, p->Key.TenSach);
        }
    } else if (T->Key.TenSach < TenSach)
        XoaSach(T->Right, TenSach);
    else
        XoaSach(T->Left, TenSach);
}

// Xóa toàn bộ sách trong cây
void XoaToanBoSach(Tree &T) {
    if (T == NULL) {
        return;
    } else {
        XoaToanBoSach(T->Left);
        XoaToanBoSach(T->Right);
        delete T;
        T = NULL;
    }
}

// Ghi dữ liệu vào tệp
void GhiTep(Tree T, ofstream &f) {
    if (T == NULL) {
        return;
    } else {
        GhiTep(T->Left, f);
        f << T->Key.TenSach << "\n" << T->Key.TenTG << "\n" << T->Key.GiaSach << "\n";
        GhiTep(T->Right, f);
    }
}

void ChangeInformation(Tree &t,string NameBook){
    if(t == NULL){
        return;
    }else{
        if(t->Key.TenSach == NameBook){
            cout << "Nhap ten sach moi: ";
            getline(cin,t->Key.TenSach);
            cout << "Nhap ten tac gia moi: ";
            getline(cin,t->Key.TenTG);
            cout << "Nhap gia sach moi: ";
            cin >> t->Key.GiaSach;
            cin.ignore();
        }
        ChangeInformation(t->Left,NameBook);
        ChangeInformation(t->Right,NameBook);
    }
}
int DemSoLuongSachTheoTG(Tree T, string Name){
    if(T == NULL){
        return 0;
    }else{
        if(T->Key.TenTG==Name){
            return 1 + DemSoLuongSachTheoTG(T->Left,Name) + DemSoLuongSachTheoTG(T->Right,Name);
        }else{
            return DemSoLuongSachTheoTG(T->Left,Name) + DemSoLuongSachTheoTG(T->Right,Name);
        }
    }
}
// Menu
void Menu(Tree T) {
    int LuaChon;
    do {
        cout << "\nCAC CHUC NANG\n";
        cout << "1. Khoi tao \n";
        cout << "2. Dem so luong sach\n";
        cout << "3. Them 1 cuon sach\n";
        cout << "4. In sach\n";
        cout << "5. In sach theo gia tri tu thap den cao \n";
        cout << "6. In sach theo gia tri tu cao den thap \n";
        cout << "7. Doc du lieu tu tep\n";
        cout << "8. Tong gia tri sach \n";
        cout << "9. Dem so luong sach cua mot tac gia\n";
        cout << "10. Trung binh gia cua moi cuon sach\n";
        cout << "11. Loc sach co khoang gia nho hon gia nguoi dung nhap\n";
        cout << "12. Tim sach theo ten tac gia\n";
        cout << "13. Tim tac gia theo ten sach\n";
        cout << "14. Tim sach theo gia tien\n";
        cout << "15. Tim sach co gia tien lon nhat\n";
        cout << "16. Tim sach co gia tien nho nhat\n";
        cout << "17. Xoa mot cuon sach\n";
        cout << "18. Xoa toan bo sach\n";
        cout << "19. Ghi du lieu vao tep\n";
        cout << "20. Cap nhat thong tin moi cua mot quyen sach\n";
        cout << "21. Tam biet!\n";
        cout << "Moi chon chuc nang (1-21)?";
        cin >> LuaChon;
        switch (LuaChon) {
            case 1:{ // Khởi tạo
                Init(T);
                cout << "Da khoi tao!";
            }
                break;
            case 2:{ // Kiểm tra rỗng
                if (isEmpty(T))
                    cout << "Cay rong!";
                else
                    cout << "So luong sach trong cay la:" << DemSoLuongSach(T) << endl;
                break;
            }
            case 3: // Thêm một cuốn sách vào cây
                {
                    Item x;
                    cout << "Nhap thong tin sach! \n";
                    cout << "Nhap ten sach: ";
                    cin.ignore();
                    getline(cin, x.TenSach);
                    cout << "Nhap ten tac gia: ";
                    getline(cin, x.TenTG);
                    cout << "Gia cuon sach: ";
                    cin >> x.GiaSach;
                    AddNode(T, x);
                    cout << "da xong!";
                    break;
                }
              
            case 4:{ // In cây sách
                InCaySach(T);
                break;
            }
            case 5:{ // In từ thấp đến cao theo giá trị
                InTuThapDenCao(T);
                break;
            }
            case 6:{
                InTuCaoDenThap(T);
                break;
            }
            case 7:{ // Đọc từ tệp vào cây
                DocTep(T);
                break;
            }
            case 8:{ // Tổng giá trị của sách trong cây
                cout << "Tong gia tri sach trong cay la:" << TongGiaTriSach(T) << endl;
                break;
            }
            case 9:{ // Đếm số lượng sách của một tác giả
                cin.ignore();
                string ten;
                cout<<"Nhap ten tac gia: ";getline(cin,ten);
                cout << "So luong sach cua tac gia " << ten << " la: " << DemSoLuongSachTheoTG(T, ten) << endl;
                break;
            }
            case 10:{ // Trung bình giá của 1 cuốn sách
                cout << "Trung binh gia cua 1 cuon sach la:" << (float)TongGiaTriSach(T) / DemSoLuongSach(T) << endl;
                break;
            }
            case 11:{ // Đếm số sách dưới số tiền người dùng nhập
                double price ;
                cout<<"Nhap khoang gia ban muon tim kiem!\n";
                cin>>price;
                Tree p = new TNode;
                p = T;
                if(T==NULL){
                    cout << "Khong co cuon sach nao!\n";
                    break;
                }else if(p->Key.GiaSach > price){
                    cout<<"Khong co cuon sach nao trong khoang gia nay ";
                }else{DemSach(T, price);}
                break;
            }
            case 12: // Sử dụng hàm tìm sách theo tên tác giả để tìm sách
                {   
                    if(T==NULL){
                        cout << "Khong co cuon sach nao!\n";
                        break;
                    }
                    string tenTacGia;
                    cin.ignore();
                    cout << "Nhap ten tac gia: ";
                    getline(cin, tenTacGia);
                    cout << "Sach can tim voi tac gia " << tenTacGia << " la: " << endl;
                    TimSachTheoTenTG(T, tenTacGia);
                }
                break;
            case 13: // Tìm tác giả theo tên sách
                {
                    string tenSach;
                    cout << "Nhap ten sach: ";
                    cin.ignore();
                    getline(cin, tenSach);
                    cout << "Tac gia can tim voi ten sach " << tenSach << " la: " << endl;
                    TimTGTheoTenSach(T, tenSach);
                }
                break;
            case 14: // Tìm sách theo giá sách
                {
                    Item x;
                    cout << "Nhap gia sach: ";
                    cin >> x.GiaSach;
                    cout << "Ten sach can tim voi gia sach " << x.GiaSach << " la: " << endl;
                    TimSachTheoGiaTri(T, x);
                }
                break;
            case 15: // Tìm sách giá trị lớn nhất
                {
                    TNode *Max;
                    Max = TimGiaTriLonNhat(T);
                    if (Max != NULL) {
                        cout << "Gia tri sach lon nhat la:" << Max->Key.GiaSach << "\t" << "Ten sach: " << Max->Key.TenSach << endl;
                    } else {
                        cout << "Cay rong!" << endl;
                    }
                }
                break;
            case 16: // Tìm sách giá trị nhỏ nhất
                {
                    TNode *Min;
                    Min = TimGiaTriNhoNhat(T);
                    if (Min != NULL) {
                        cout << "Gia tri sach nho nhat la:" << Min->Key.GiaSach << "\t" << "Ten sach: " << Min->Key.TenSach << endl;
                    } else {
                        cout << "Cay rong!" << endl;
                    }
                }
                break;
            case 17: // Xóa một sách ra khỏi cây
                {
                    string TenSach;
                    cout << "Nhap ten sach can xoa: ";
                    cin.ignore();
                    getline(cin, TenSach);
                    cout << "Da xoa sach ten la: " << TenSach << endl;
                    XoaSach(T, TenSach);
                }
                break;
            case 18:{ // Xóa toàn bộ sách trong cây
                XoaToanBoSach(T);
                cout << "Da xoa toan bo sach!" << endl;
                break;
            }
            case 19: // Ghi tệp
                {
                    ofstream f("Ghi.txt");
                    if (f.is_open()) {
                        GhiTep(T, f);
                        f.close();
                        cout << "Da ghi tep!" << endl;
                    } else {
                        cout << "Khong the mo tep Ghi.txt de ghi!" << endl;
                    }
                }
                break;
            case 20:{
                string NameBook;
                cout << "Nhap ten sach can thay doi: ";
                cin.ignore();
                getline(cin, NameBook);
                ChangeInformation(T, NameBook);
                break;
                    break;
                }
            case 21: // Thoát
            cout << "Tam biet!";
                break;
        }
    } while (LuaChon != 21);
}

int main() {
    Tree T;
    Menu(T);
    return 0;
}
