#include "lop.cpp"
class Node_Lop
{
public:
    Lop lop;
    Node_Lop *next;

public:
    Node_Lop();
    Node_Lop(Lop);
    void SaveAllLop(Node_Lop *&, const string &);
    void ThemLop(Lop, Node_Lop *&);
    //  Đọc file ( đọc dữ liệu từ database lưu vào cấu trúc dữ liệu linked-list)
    void DocFile(ifstream &, Node_Lop *&);
    ~Node_Lop();
};