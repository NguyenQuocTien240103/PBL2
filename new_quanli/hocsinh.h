#include<iostream>
using namespace std;

class HocSinh{
	private:
	string ten,ngaysinh;
    int id;
	public:
		HocSinh();
		HocSinh(string,string,int);
		string get_ten();
		string get_ngaysinh();
		int get_id();
		void nhapthongtin();
		void set_ten(string);
		void set_ngaysinh(string);
		void set_id(int);
		void xuat_thong_tin();
		~HocSinh();
		void docFile_hocsinh(ifstream&);
};
