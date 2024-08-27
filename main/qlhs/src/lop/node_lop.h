#include "lop.cpp"
class Node_Lop
{
public:
    Lop lop;
    Node_Lop *next;

public:
    Node_Lop();
    Node_Lop(Lop);
    ~Node_Lop();
};