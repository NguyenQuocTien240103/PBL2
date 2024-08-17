#include "node_lop.h"
Node_Lop::Node_Lop(Lop lop)
{
    this->lop = lop;
    this->next = nullptr;
}
//#
void Node_Lop::ShowAllLop(Node_Lop *&Head, const string &file_name)
{
    ofstream fileOutput(file_name); // Mở file output để ghi dữ liệu

    if (!fileOutput.is_open())
    {
        cerr << "Không thể mở file: " << file_name << endl;
        return;
    }

    Node_Lop *temp = Head;
    int count = 0; // Đếm số thứ tự

    if (temp == NULL)
    {
    }
    else
    {
        //fileOutput << "\t\t\t\t\t\t*****DANH SACH HOC SINH*****" << endl;
        while (temp != NULL)
        {
            temp->lop.GhiVaoFile(fileOutput);
            temp = temp->next;
            fileOutput << endl;
        }
    }

    fileOutput.close(); // Đóng file sau khi hoàn thành ghi dữ liệu
}
void Node_Lop::ThemLop(Lop lop, Node_Lop *&Head, int ViTri)
{
    if (ViTri == 0) // đầu
    {
        Node_Lop *new_lop = new Node_Lop(lop);
        if (Head == NULL)
            Head = new_lop;
        else
        {
            new_lop->next = Head;
            Head = new_lop;
        }
    }
    else if (ViTri == 1) // cuối
    {
        Node_Lop *new_lop = new Node_Lop(lop);
        if (Head == NULL)
            Head = new_lop;
        else
        {
            Node_Lop *temp = Head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = new_lop;
        }
    }
}

void Node_Lop::SuaLop(Lop)
{
}

void Node_Lop::XoaLop(string)
{
}

void Node_Lop::DocFile(ifstream &filein, Node_Lop *&Head)
{
    string MaLop, TenLop;
    while (getline(filein, MaLop, ',') && getline(filein, TenLop))
    {
        // Kiểm tra xem tệp có mở thành công không
        if (!filein.is_open())
        {
            cerr << "Không thể mở tệp để đọc" << endl;
            return;
        }
        // Xóa khoảng trắng thừa nếu cần
        MaLop.erase(0, MaLop.find_first_not_of(" \t\n\r\f\v"));
        TenLop.erase(0, TenLop.find_first_not_of(" \t\n\r\f\v"));

        // Nếu dữ liệu không rỗng, thêm vào danh sách liên kết
        if (!MaLop.empty() && !TenLop.empty())
        {
            Lop newLop;
            newLop.SetMaLop(MaLop);
            newLop.SetTenLop(TenLop);
            ThemLop(newLop, Head, 0); // Thêm vào đầu danh sách
        }
    }
}