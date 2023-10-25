class Node{
	public:
		HocSinh student;
		MonHoc	subject;
		Node *next;
	public:
		Node();
		Node(HocSinh,MonHoc);
		~Node();
};

