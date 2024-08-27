#include "bangdiem.cpp"
class Node_BangDiem
{
public:
    BangDiem bd;
    Node_BangDiem *next;

public:
    Node_BangDiem();
    Node_BangDiem(BangDiem);
    ~Node_BangDiem();
};