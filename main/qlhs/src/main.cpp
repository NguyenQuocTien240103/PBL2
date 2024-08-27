//#include "qlhs.cpp"
#include "lop/quanli_lop.cpp"
#include "bangdiem/quanli_bangdiem.cpp"
#include <fstream> // Thư viện để làm việc với file
using namespace std;
void init()
{
    cout << "\t\t\t....................................................................\n";
    cout << "\t\t\t.                                                                  .\n";
    cout << "\t\t\t.               PBL2: QUAN LI DIEM HOC SINH THPT                   .\n";
    cout << "\t\t\t.                                                                  .\n";
    cout << "\t\t\t....................................................................\n";
    cout << "\t\t\t.                                                                  .\n";
    cout << "\t\t\t.               NGUYEN QUOC TIEN    MSSV:102220043                 .\n";
    cout << "\t\t\t.               PHAM QUOC VU        MSSV:102220050                 .\n";
    cout << "\t\t\t.               GVHD: TS. TRUONG NGOC CHAU                         .\n";
    cout << "\t\t\t....................................................................\n";
    cout << endl;
}

bool CheckLop(HocSinh hs, Node_Lop *Head)
{
    Node_Lop *temp = Head;
    while (temp != nullptr)
    {
        if (temp->lop.GetMaLop() == hs.GetMaLop())
        {
            return true;
        }
        temp = temp->next; // Move to the next node
    }
    return false;
}

bool CheckIdHocSinh(HocSinh hs, Node_HocSinh *Head)
{
    Node_HocSinh *temp = Head;
    while (temp != nullptr)
    {
        if (temp->hs.GetId() == hs.GetId())
        {
            return false;
        }
        temp = temp->next; // Move to the next node
    }
    return true;
}

int main()
{
    // Lop
    QuanLiLop quanli_lop;
    string fileNameLop = "../data/data_lop/data.txt";
    ifstream fileInputLop(fileNameLop);
    quanli_lop.DocFile(fileInputLop);
    // HocSinh
    QuanLiHocSinh quanli_hocsinh;
    string fileNameHocSinh = "../data/data_hocsinh/data.txt";
    ifstream fileInputHocSinh(fileNameHocSinh);
    quanli_hocsinh.DocFile(fileInputHocSinh);
    // BangDiem
    QuanLiBangDiem quanli_bangdiem;
    string fileNameBangDiem = "../data/data_BangDiem/data.txt";
    ifstream fileInputBangDiem(fileNameBangDiem);
    quanli_bangdiem.DocFile(fileInputBangDiem);

    init();
    int n;
    do
    {
        cout << "------Quan Li Diem Hoc Sinh------" << endl;
        cout << "1. Quan Li Lop" << endl;
        cout << "2. Quan Li Diem Hoc Sinh" << endl;
        cout << "3. Quan Li Hoc Sinh" << endl;
        cout << "4. Thoat" << endl;
        cout << "Nhap TH : ";
        cin >> n;
        if (n == 1)
        {
            system("cls");
            init();
            cout << "1. Xem Danh Sach Lop" << endl;
            cout << "2. Them Lop Moi" << endl;
            cout << "Nhap TH : ";
            int option;
            cin >> option;
            if (option == 1)
            {
                quanli_lop.HienThiDanhSachLop();
            }
            else if (option == 2)
            {
                Lop lop;
                lop.DauVao();
                quanli_lop.ThemLop(lop);
                quanli_lop.SaveAllLop(fileNameLop);
            }
        }
        else if (n == 2)
        {
            system("cls");
            init();
            cout << "1. Xem Danh Sach Bang Diem" << endl;
            cout << "2. Them Bang Diem Moi" << endl;
            cout << "3. Xoa Bang Diem" << endl;
            cout << "4. Tim Kiem Bang Diem Hoc Sinh" << endl;
            cout << "5. Sap Xep Theo Diem" << endl;
            cout << "6. Sua Diem" << endl;
            cout << "Nhap TH : ";
            int option;
            cin >> option;
            if (option == 1)
            {

                quanli_bangdiem.HienThiDanhSachBangDiem();
            }
            else if (option == 2)
            {

                // bangdiem
                BangDiem bd;
                bd.DauVao();
                HocSinh NewHocSinh = bd.GetHocSinh();
                // option
                cout << " ---Vi Tri Ma Ban Muon Them Vao ?---" << endl;
                cout << "1. Them Vao Dau" << endl;
                cout << "2. Them Vao Cuoi" << endl;
                cout << "3. Them Vao Vi Tri Bat Ki" << endl;
                cout << "Nhap TH : ";
                int option;
                cin >> option;
                if (CheckIdHocSinh(NewHocSinh, quanli_hocsinh.getHead()))
                {
                    if (CheckLop(NewHocSinh, quanli_lop.getHead()))
                    {
                        if (option == 1)
                        {

                            quanli_bangdiem.ThemBangDiemVaoDau(bd);
                        }
                        else if (option == 2)
                        {

                            quanli_bangdiem.ThemBangDiemVaoCuoi(bd);
                        }
                        else if (option == 3)
                        {
                            int pos;
                            cout << "Vi tri Muon Them Vao : ";
                            cin >> pos;
                            quanli_bangdiem.ThemVaoViTriBatKi(bd, pos);
                        }
                        quanli_hocsinh.ThemHocSinh(NewHocSinh);
                        quanli_bangdiem.SaveBangDiem(fileNameBangDiem);
                        quanli_hocsinh.SaveAllHocSinh(fileNameHocSinh);
                    }
                    else
                    {
                        cout << "Ma Lop khong ton tai" << endl;
                    }
                }
                else
                {
                    cout << "Id Hoc Sinh Da Trung" << endl;
                }
            }
            else if (option == 3)
            {
                system("cls");
                cout << "1. Xoa Tai Dau" << endl;
                cout << "2. Xoa Tai Cuoi" << endl;
                cout << "3. Xoa Tai Vi Tri Bat Ki" << endl;
                cout << "Nhap TH : ";
                int option;
                cin >> option;
                if (option == 1)
                {

                    quanli_bangdiem.XoaBangDiemVaoDau(quanli_hocsinh);
                }
                else if (option == 2)
                {
                    quanli_bangdiem.XoaBangDiemVaoCuoi(quanli_hocsinh);
                }
                else if (option == 3)
                {

                    int pos;
                    cout << "Vi Tri Muon Xoa : ";
                    cin >> pos;

                    quanli_bangdiem.XoaVaoViTriBatKi(pos, quanli_hocsinh);
                }
                quanli_bangdiem.SaveBangDiem(fileNameBangDiem);
                quanli_hocsinh.SaveAllHocSinh(fileNameHocSinh);
            }

            else if (option == 4)
            {

                int Id;
                cout << "Nhap Id Cua Hoc Sinh Can Tim Kiem : ";
                cin >> Id;
                quanli_bangdiem.TimKiemBangDiemHocSinh(Id);
            }
            else if (option == 5)
            {

                quanli_bangdiem.SapXepDiem();
            }
            else if (option == 6)
            {
                int Id;
                cout << "Nhap Id Cua Hoc Sinh : ";
                cin >> Id;
                quanli_bangdiem.SuaDiem(Id);
                quanli_bangdiem.SaveBangDiem(fileNameBangDiem);
                quanli_hocsinh.SaveAllHocSinh(fileNameHocSinh);
            }
        }
        else if (n == 3)
        {
            system("cls");
            init();
            cout << "1. Xem Danh Sach Hoc Sinh" << endl;
            cout << "Nhap TH : ";
            int option;
            cin >> option;
            if (option == 1)
            {
                quanli_hocsinh.HienThiDanhSachHocSinh();
            }
        }
        else if (n == 4)
        {
            break;
        }
        else if (n > 4)
        {
            system("cls");
            init();
        }

    } while (true);
    return 0;
}