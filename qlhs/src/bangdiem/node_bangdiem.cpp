#include "node_bangdiem.h"
Node_BangDiem::Node_BangDiem(BangDiem bd)
{
    this->bd = bd;
    this->next = nullptr;
}
void Node_BangDiem::SaveBangDiem(Node_BangDiem *&Head, const string &file_name)
{
    ofstream fileOutput(file_name); // Mở file output để ghi dữ liệu

    if (!fileOutput.is_open())
    {
        cerr << "Không thể mở file: " << file_name << endl;
        return;
    }

    Node_BangDiem *temp = Head;
    //    int count = 0; // Đếm số thứ tự

    if (temp == NULL)
    {
    }
    else
    {
        //fileOutput << "\t\t\t\t\t\t*****DANH SACH HOC SINH*****" << endl;
        while (temp != NULL)
        {
            temp->bd.GhiVaoFile(fileOutput);
            temp = temp->next;
            fileOutput << endl;
        }
    }

    fileOutput.close(); // Đóng file sau khi hoàn thành ghi dữ liệu
}
void Node_BangDiem::ThemBangDiem(BangDiem bd, Node_BangDiem *&Head)
{
    // luôn luôn thêm vào cuối
    Node_BangDiem *new_bangdiem = new Node_BangDiem(bd);
    if (Head == NULL)
        Head = new_bangdiem;
    else
    {
        Node_BangDiem *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_bangdiem;
    }
}

void Node_BangDiem::DocFile(ifstream &filein, Node_BangDiem *&Head)
{
    // Kiểm tra xem tệp có mở thành công không
    if (!filein.is_open())
    {
        return;
    }

    string IdStr, IdHocSinh, MaLop, TenHocSinh, NgaySinh, Toan;
    while (getline(filein, IdStr, ',') && getline(filein, IdHocSinh, ',') &&
           getline(filein, MaLop, ',') && getline(filein, TenHocSinh, ',') &&
           getline(filein, NgaySinh, ',') && getline(filein, Toan))
    {
        // Xóa khoảng trắng thừa nếu cần
        IdStr.erase(0, IdStr.find_first_not_of(" \t\n\r\f\v"));
        IdHocSinh.erase(0, IdHocSinh.find_first_not_of(" \t\n\r\f\v"));
        MaLop.erase(0, MaLop.find_first_not_of(" \t\n\r\f\v"));
        TenHocSinh.erase(0, TenHocSinh.find_first_not_of(" \t\n\r\f\v"));
        NgaySinh.erase(0, NgaySinh.find_first_not_of(" \t\n\r\f\v"));
        Toan.erase(0, Toan.find_first_not_of(" \t\n\r\f\v"));

        // Nếu dữ liệu không rỗng, thêm vào danh sách liên kết
        if (!IdStr.empty() && !MaLop.empty() && !TenHocSinh.empty() && !NgaySinh.empty() &&
            !IdHocSinh.empty() && !Toan.empty())
        {
            int Id = stoi(IdStr);
            float toan = stof(Toan);
            int IdHS = stoi(IdHocSinh);
            // lưu HocSinh
            HocSinh newHocSinh;
            newHocSinh.SetId(IdHS);
            newHocSinh.SetMaLop(MaLop);
            newHocSinh.SetTenHocSinh(TenHocSinh);
            newHocSinh.SetNgaySinh(NgaySinh);
            // lưu bảng điểm HocSinh
            BangDiem newBangDiem;
            newBangDiem.SetId(Id);
            newBangDiem.SetToan(toan);
            newBangDiem.SetHocSinh(newHocSinh);
            // Thêm vào cuối danh sách
            ThemBangDiem(newBangDiem, Head);
        }
    }
}
