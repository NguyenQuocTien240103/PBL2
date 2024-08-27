#include "quanli_bangdiem.h"
QuanLiBangDiem::QuanLiBangDiem()
{
    this->Head = nullptr;
}

void QuanLiBangDiem::SaveBangDiem(const string &file_name)
{
    ofstream fileOutput(file_name); // Mở file output để ghi dữ liệu

    if (!fileOutput.is_open())
    {
        cerr << "Không thể mở file: " << file_name << endl;
        return;
    }
    Node_BangDiem *temp = this->Head;
    while (temp != nullptr)
    {
        temp->bd.GhiVaoFile(fileOutput);
        temp = temp->next;
        fileOutput << endl;
    }
    fileOutput.close(); // Đóng file sau khi hoàn thành ghi dữ liệu
}

int QuanLiBangDiem::DemSoLuong()
{
    Node_BangDiem *temp = this->Head;
    int count = 0;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void QuanLiBangDiem::ThemBangDiemVaoDau(BangDiem bd)
{
    Node_BangDiem *new_bangdiem = new Node_BangDiem(bd);
    if (this->Head == nullptr)
        this->Head = new_bangdiem;
    else
    {
        new_bangdiem->next = this->Head;
        this->Head = new_bangdiem;
    }
}

void QuanLiBangDiem::ThemBangDiemVaoCuoi(BangDiem bd)
{
    // luôn luôn thêm vào cuối
    Node_BangDiem *new_bangdiem = new Node_BangDiem(bd);
    if (this->Head == nullptr)
        this->Head = new_bangdiem;
    else
    {
        Node_BangDiem *temp = this->Head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = new_bangdiem;
    }
}

void QuanLiBangDiem::ThemVaoViTriBatKi(BangDiem bd, int pos)
{
    int k = DemSoLuong();
    if (pos < 1 || pos > k + 1)
        cout << "vi tri chen khong hop le";
    else if (pos == 1)
    {
        ThemBangDiemVaoDau(bd);
    }
    else
    {
        Node_BangDiem *temp = this->Head;
        Node_BangDiem *NewBangDiem = new Node_BangDiem(bd);
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        NewBangDiem->next = temp->next;
        temp->next = NewBangDiem;
    }
}
void QuanLiBangDiem::SuaDiem(int id)
{
    Node_BangDiem *temp = this->Head;
    while (temp != NULL)
    {
        if (temp->bd.GetHocSinh().GetId() == id)
        {
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {
        cout << "ID cua hoc sinh khong ton tai" << endl;
    }
    else
    {
        int n;
        cout << "1.Sua diem toan" << endl;
        cout << "2.Sua diem li" << endl;
        cout << "3.Sua diem hoa" << endl;
        cout << "Nhap TH can sua : ";
        cin >> n;
        if (n == 1)
        {
            double a;
            cout << "So diem toan can sua la:";
            cin >> a;
            temp->bd.SetToan(a);
        }
        if (n == 2)
        {
            double a;
            cout << "So diem li can sua la:";
            cin >> a;
            temp->bd.SetLi(a);
        }
        if (n == 3)
        {
            double a;
            cout << "So diem hoa can sua la:";
            cin >> a;
            temp->bd.SetHoa(a);
        }
        temp->bd.SetDTB(temp->bd.GetToan(), temp->bd.GetLi(), temp->bd.GetHoa());
        temp->bd.SetHocLuc(temp->bd.GetDTB());
    }
}
void QuanLiBangDiem::XoaBangDiemVaoDau(QuanLiHocSinh &qlhs)
{
    if (this->Head == nullptr)
        cout << "Danh sach rong" << endl;
    else
    {
        Node_BangDiem *temp = this->Head;
        this->Head = Head->next;
        //
        Node_HocSinh *temp_hocsinh = qlhs.getHead();
        int count = 0;
        while (temp_hocsinh != nullptr && temp_hocsinh->hs.GetId() != temp->bd.GetHocSinh().GetId())
        {
            temp_hocsinh = temp_hocsinh->next;
            count++;
        }
        qlhs.XoaVaoViTriBatKi(count);
        delete temp; // Giải phóng bộ nhớ của Node_BangDiem
    }
}

void QuanLiBangDiem::XoaBangDiemVaoCuoi(QuanLiHocSinh &qlhs)
{
    if (this->Head == nullptr)
    {
        cout << "danh sach rong";
    }
    Node_BangDiem *temp = this->Head;
    Node_BangDiem *current = nullptr;
    while (temp->next != nullptr)
    {
        current = temp;
        temp = temp->next;
    }

    Node_HocSinh *temp_hocsinh = qlhs.getHead();
    int count = 0;
    while (temp_hocsinh != nullptr && temp_hocsinh->hs.GetId() != temp->bd.GetHocSinh().GetId())
    {
        temp_hocsinh = temp_hocsinh->next;
        count++;
    }
    qlhs.XoaVaoViTriBatKi(count);
    current->next = nullptr;
    delete temp;
}

void QuanLiBangDiem::XoaVaoViTriBatKi(int pos, QuanLiHocSinh &qlhs)
{
    if (this->Head == nullptr)
    {
        return;
    }
    Node_BangDiem *temp = this->Head;
    if (pos == 0)
    {
        this->Head = temp->next;
        Node_HocSinh *temp_hocsinh = qlhs.getHead();

        int count = 0;
        while (temp_hocsinh != nullptr && temp_hocsinh->hs.GetId() != temp->next->bd.GetHocSinh().GetId())
        {
            temp_hocsinh = temp_hocsinh->next;
            count++;
        }

        qlhs.XoaVaoViTriBatKi(count);
        delete temp; // Giải phóng bộ nhớ
        return;
    }
    for (int i = 0; temp != nullptr && i < pos - 1; i++)
    {
        temp = temp->next;
    }
    if (temp == nullptr || temp->next == nullptr)
    {

        return;
    }
    Node_HocSinh *temp_hocsinh = qlhs.getHead();
    int count = 0;
    while (temp_hocsinh != nullptr && temp_hocsinh->hs.GetId() != temp->next->bd.GetHocSinh().GetId())
    {
        temp_hocsinh = temp_hocsinh->next;
        count++;
    }

    qlhs.XoaVaoViTriBatKi(count);

    Node_BangDiem *next = temp->next->next;
    delete temp->next;
    temp->next = next;
}

void QuanLiBangDiem::TimKiemBangDiemHocSinh(int Id)
{
    int count = 0;
    Node_BangDiem *temp = this->Head;
    while (temp != nullptr)
    {
        if (temp->bd.GetHocSinh().GetId() == Id)
        {
            count++; // danh dau
            temp->bd.DauRa();
        }
        temp = temp->next;
    }
    if (count == 0)
    {
        cout << "Khong co hoc sinh nao giong ID ban da nhap!!!" << endl;
        return;
    }
    cout << endl;
}
void QuanLiBangDiem::SapXepDiem()
{
    Node_BangDiem *temp = this->Head;
    Node_BangDiem *current = nullptr;
    while (temp != nullptr)
    {
        current = temp;
        while (current != nullptr)
        {
            if (temp->bd.GetToan() >= current->bd.GetToan())
            {
                BangDiem a = temp->bd;
                temp->bd = current->bd;
                current->bd = a;
            }
            current = current->next;
        }
        temp = temp->next;
    }
    // xuất
    HienThiDanhSachBangDiem();
}

void QuanLiBangDiem::HienThiDanhSachBangDiem()
{

    Node_BangDiem *temp = this->Head;
    while (temp != nullptr)
    {
        temp->bd.DauRa();
        temp = temp->next;
    }
}

void QuanLiBangDiem::DocFile(ifstream &filein)
{
    // Kiểm tra xem tệp có mở thành công không
    if (!filein.is_open())
    {
        return;
    }
    string IdHocSinh, MaLop, TenHocSinh, NgaySinh, Toan, Li, Hoa, DTB, HocLuc;
    while (getline(filein, IdHocSinh, ',') &&
           getline(filein, MaLop, ',') && getline(filein, TenHocSinh, ',') &&
           getline(filein, NgaySinh, ',') && getline(filein, Toan, ',') && getline(filein, Li, ',') && getline(filein, Hoa, ',') &&
           getline(filein, DTB, ',') && getline(filein, HocLuc))
    {
        // Xóa khoảng trắng thừa nếu cần
        IdHocSinh.erase(0, IdHocSinh.find_first_not_of(" \t\n\r\f\v"));
        MaLop.erase(0, MaLop.find_first_not_of(" \t\n\r\f\v"));
        TenHocSinh.erase(0, TenHocSinh.find_first_not_of(" \t\n\r\f\v"));
        NgaySinh.erase(0, NgaySinh.find_first_not_of(" \t\n\r\f\v"));
        Toan.erase(0, Toan.find_first_not_of(" \t\n\r\f\v"));
        Li.erase(0, Li.find_first_not_of(" \t\n\r\f\v"));
        Hoa.erase(0, Hoa.find_first_not_of(" \t\n\r\f\v"));
        DTB.erase(0, DTB.find_first_not_of(" \t\n\r\f\v"));
        HocLuc.erase(0, HocLuc.find_first_not_of(" \t\n\r\f\v"));
        // Nếu dữ liệu không rỗng, thêm vào danh sách liên kết
        if (!MaLop.empty() && !TenHocSinh.empty() && !NgaySinh.empty() &&
            !IdHocSinh.empty() && !Toan.empty() && !Li.empty() && !Hoa.empty() && !DTB.empty() && !HocLuc.empty())
        {
            float toan = stof(Toan);
            float li = stof(Li);
            float hoa = stof(Hoa);
            float dtb = stof(DTB);
            int IdHS = stoi(IdHocSinh);
            // lưu HocSinh
            HocSinh newHocSinh;
            newHocSinh.SetId(IdHS);
            newHocSinh.SetMaLop(MaLop);
            newHocSinh.SetTenHocSinh(TenHocSinh);
            newHocSinh.SetNgaySinh(NgaySinh);
            // lưu bảng điểm HocSinh
            BangDiem newBangDiem;
            // newBangDiem.SetId(Id);
            newBangDiem.SetToan(toan);
            newBangDiem.SetLi(li);
            newBangDiem.SetHoa(hoa);
            newBangDiem.SetDTB(toan, li, hoa);
            newBangDiem.SetHocLuc(dtb);
            newBangDiem.SetHocSinh(newHocSinh);
            // Thêm vào cuối danh sách
            ThemBangDiemVaoCuoi(newBangDiem);
        }
    }
}

QuanLiBangDiem::~QuanLiBangDiem()
{
    Node_BangDiem *temp = this->Head;
    while (temp != nullptr)
    {
        Node_BangDiem *current = temp->next;
        delete temp;
        temp = current;
    }
    this->Head = nullptr;
}