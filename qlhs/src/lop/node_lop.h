#include "lop.cpp"
class Node_Lop
{
public:
    Lop lop;
    Node_Lop *next;

public:
    Node_Lop();
    Node_Lop(Lop);
    void ShowAllLop(Node_Lop *&, const string &);
    void ThemLop(Lop, Node_Lop *&, int);
    void SuaLop(Lop);
    void XoaLop(string);
    //  Đọc file
    void DocFile(ifstream &, Node_Lop *&);
    ~Node_Lop();
};