#include "bangdiem.cpp"
class Node_BangDiem
{
public:
    BangDiem bd;
    Node_BangDiem *next;

public:
    Node_BangDiem();
    Node_BangDiem(BangDiem);
    void SaveAllLop(Node_BangDiem *&, const string &);
    void ThemLop(BangDiem, Node_BangDiem *&);
    //  Đọc file ( đọc dữ liệu từ database lưu vào cấu trúc dữ liệu linked-list)
    void DocFile(ifstream &, BangDiem *&);
    ~Node_BangDiem();
};