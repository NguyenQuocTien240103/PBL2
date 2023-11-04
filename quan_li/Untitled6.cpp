#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
class HocSinh{
	private:
	string ten,ngaysinh,lop;
	public:
		HocSinh();
		HocSinh(string,string,string);
		string get_ten();
		string get_ngaysinh();
		string get_lop();
		void nhapthongtin();
		void set_lop(string);
		void set_ngaysinh(string);
		void set_ten(string);
		void xuat_thong_tin();
		void docFile_hocsinh(ifstream&);
		~HocSinh();
};
HocSinh::HocSinh(){}

HocSinh::HocSinh(string ten,string ngaysinh,string lop){
	this->ten=ten;
	this->ngaysinh=ngaysinh;
	this->lop=lop;
}

string HocSinh::get_ten(){
	return this->ten;
}

string HocSinh::get_ngaysinh(){
	return this->ngaysinh;
}

string HocSinh::get_lop(){
	return this->lop;
}

void HocSinh::nhapthongtin(){
	cin.ignore();
	cout<<"nhap ten hoc sinh: "; getline(cin,this->ten);
	cout<<"nhap ngay sinh cua hoc sinh: "; cin>>this->ngaysinh;
	cout<<"nhap lop cua hoc sinh do: ";cin>>this->lop;
}

void HocSinh::set_lop(string lop){
	this->lop=lop;
}

void HocSinh::set_ngaysinh(string ngaysinh){
	this->ngaysinh=ngaysinh;
}

void HocSinh::set_ten(string ten){
	this->ten=ten;
}

void HocSinh::xuat_thong_tin(){
	cout<<"ten:"<<this->ten<<endl;
	cout<<"ngaysinh:"<<this->ngaysinh<<endl;
	cout<<"lop:"<<this->lop<<endl;
}
void HocSinh::docFile_hocsinh(ifstream& filein){
	getline(filein,this->ten);
	filein>>this->ngaysinh;
	filein>>this->lop;
	filein.ignore();
}

HocSinh::~HocSinh(){}

class MonHoc{
	private:
		double toan,li,hoa,van,anh,tin;
		double diemtrungbinh;
		string hocluc;
	public:
		MonHoc();
		MonHoc(double,double,double,double,double,double);
		void nhapdiem();
		double get_toan();
		double get_li();
		double get_hoa();
		double get_van();
		double get_anh();
		double get_tin();
		string get_hoc_luc();
		void set_toan(double);
		void set_li(double);
		void set_hoa(double);
		void set_van(double);
		void set_anh(double);
		void set_tin(double);
		double get_diem_trung_binh();
		void set_diem_trung_binh(double);
		void set_hoc_luc(string);
		void xuatdiem();
		void docFile_MonHoc(ifstream&);
		~MonHoc();
};

MonHoc::MonHoc(){}

MonHoc::MonHoc(double toan,double li,double hoa,double van,double anh,double tin){
	this->toan=toan;
	this->li=li;
	this->hoa=hoa;
	this->van=van;
	this->anh=anh;
	this->tin=tin;
}

void MonHoc::nhapdiem(){ 
	cout<<"nhap diem toan: "; cin>>this->toan;
	cout<<"nhap diem li: "; cin>>this->li;
	cout<<"nhap diem hoa: "; cin>>this->hoa;
	cout<<"nhap diem van: "; cin>>this->van;
	cout<<"nhap diem anh: "; cin>>this->anh;
	cout<<"nhap diem tin: "; cin>>this->tin;
}

double MonHoc::get_toan(){
	return this->toan;
}

double MonHoc::get_li(){
	return this->li;
}

double MonHoc::get_hoa(){
	return this->hoa;
}

double MonHoc::get_van(){
	return this->van;
}

double MonHoc::get_anh(){
	return this->anh;
}

double MonHoc::get_tin(){
	return this->tin;
}

double MonHoc::get_diem_trung_binh(){
	return this->diemtrungbinh=(toan+li+hoa+van+anh+tin)/6;
}

string MonHoc::get_hoc_luc(){
	if(this->diemtrungbinh>=8)
		this->hocluc="Gioi";
	else if(this->diemtrungbinh>=6.5 && this->diemtrungbinh<8)
		this->hocluc="Kha";
	else if(this->diemtrungbinh>=5 && this->diemtrungbinh<6.5)
		this->hocluc="Trung Binh";
	else{
		this->hocluc="Yeu";
	}
	return this->hocluc;
}

void MonHoc::set_toan(double toan){
	this->toan=toan;
}

void MonHoc::set_li(double li){
	this->li=li;
}

void MonHoc::set_hoa(double hoa){
	this->hoa=hoa;
}

void MonHoc::set_van(double van){
	this->van=van;
}

void MonHoc::set_anh(double anh){
	this->anh=anh;
}

void MonHoc::set_tin(double tin){
	this->tin=tin;
}

void MonHoc::set_diem_trung_binh(double diemtrungbinh){
	this->diemtrungbinh=diemtrungbinh;
}

void MonHoc::set_hoc_luc(string hocluc){
	this->hocluc=hocluc;
}

void MonHoc::xuatdiem(){
	cout<<"toan:"<<this->toan<<endl;
	cout<<"li:"<<this->li<<endl;
	cout<<"hoa:"<<this->hoa<<endl;
	cout<<"van:"<<this->van<<endl;
	cout<<"anh:"<<this->anh<<endl;
	cout<<"tin:"<<this->tin<<endl;
	double tb=get_diem_trung_binh();
	set_diem_trung_binh(tb);
	cout<<"diem trung binh:"<<this->diemtrungbinh<<endl;
	string hl =get_hoc_luc();
	set_hoc_luc(hl);
	cout<<"hoc luc:"<<this->hocluc<<endl;
}

void MonHoc::docFile_MonHoc(ifstream& filein){
	filein>>this->toan;
	filein>>this->li;
	filein>>this->hoa;
	filein>>this->van;
	filein>>this->anh;
	filein>>this->tin;
}

MonHoc::~MonHoc(){}

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
Node::Node(){}

Node::Node(HocSinh student, MonHoc subject){
	this->student=student;
	this->subject=subject;
	this->next=NULL;
}

Node::~Node(){}

class QuanLi{
	private:
		Node *Head;
	public:
		QuanLi();
		int dem_so_luong_hoc_sinh();
		void them_hoc_sinh_vao_dau(HocSinh,MonHoc);
		void them_hoc_sinh_vao_cuoi(HocSinh,MonHoc);
		void them_hoc_sinh_vao_vi_tri_bat_ki(HocSinh,MonHoc,int);
		void xoa_hoc_sinh_o_vi_tri_dau_tien();
		void xoa_hoc_sinh_o_vi_tri_cuoi_cung();
		void xoa_hoc_sinh_o_vi_tri_bat_ki(int);
		void sua_diem_cho_hoc_sinh(int);
		void tim_kiem_hoc_sinh(string);
		void HienThiDanhSach();
		void sap_xep_diem();
//		void docFile();
		~QuanLi();
};

QuanLi::QuanLi(){
	this->Head=NULL;
}

int QuanLi::dem_so_luong_hoc_sinh(){
	Node*temp=Head;
	int count=0;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	return count;
}

void QuanLi::them_hoc_sinh_vao_dau(HocSinh student,MonHoc subject){
	Node * new_student=new Node(student,subject);
	if(Head==NULL)
		Head=new_student;
	else{
		new_student->next=Head;
		Head=new_student;
	}
}

void QuanLi::them_hoc_sinh_vao_cuoi(HocSinh student,MonHoc subject){
	Node*new_student=new Node(student,subject);
	if(Head==NULL)
		Head=new_student;
	else{
		Node*temp=Head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_student;
	}
}

void QuanLi::them_hoc_sinh_vao_vi_tri_bat_ki(HocSinh student,MonHoc subject,int pos){
	int k=dem_so_luong_hoc_sinh();
	if(pos<1 || pos>k+1)
		cout<<"vi tri chen khong hop le";
	else if(pos==1){
		them_hoc_sinh_vao_dau(student,subject);
	}
	else{
		Node* temp=Head;
		Node* new_student=new Node(student,subject);
		for(int i=1;i<pos-1;i++){
			temp=temp->next;
		}
		new_student->next=temp->next;
		temp->next=new_student;
	}
}

void QuanLi::xoa_hoc_sinh_o_vi_tri_dau_tien(){
	if(Head==NULL)
		cout<<"danh sach rong";
	else{
		Node*temp=Head;
		Head=Head->next;
		delete temp;
	}
}

void QuanLi::xoa_hoc_sinh_o_vi_tri_cuoi_cung(){
	if(Head==NULL)
		cout<<"danh sach rong";
	Node*temp=Head;
	Node*current=NULL;
	while(temp->next!=NULL){
		current=temp;
		temp=temp->next;
	}
	current->next=NULL;
	delete temp;
}

void QuanLi::xoa_hoc_sinh_o_vi_tri_bat_ki(int pos){
	int k=dem_so_luong_hoc_sinh();
	if(pos<1||pos>k){
		cout<<"vi tri xoa khong hop le";
	}
	else if(pos==1){
		xoa_hoc_sinh_o_vi_tri_dau_tien();
	}
	else{
		Node*temp=Head;
		Node*current=NULL;
		for(int i=1;i<pos;i++){
			current=temp;
			temp=temp->next;
		}
		current->next=temp->next;
		delete temp;
	}
}

void QuanLi::sua_diem_cho_hoc_sinh(int pos){
	int k=dem_so_luong_hoc_sinh();
	if(pos<1||pos>k){
		cout<<"vi tri can sua diem khong ton tai"<<endl;
	}
	else{
		Node*temp=Head;
		for(int i=1;i<pos;i++){
			temp=temp->next;
		}
		int n;
		cout<<"1.sua diem toan"<<endl;
		cout<<"2.sua diem li"<<endl;
		cout<<"3.sua diem hoa"<<endl;
		cout<<"4.sua diem van"<<endl;
		cout<<"5.sua diem anh"<<endl;
		cout<<"6.sua diem tin"<<endl;
		cout<<"nhap TH can sua:"; cin>>n;
		if(n==1){
			double a;
			cout<<"so diem toan can sua la:"; cin>>a;
			temp->subject.set_toan(a);
		}
		if(n==2){
			double a;
			cout<<"so diem li can sua la:"; cin>>a;
			temp->subject.set_li(a);
		}
		if(n==3){
			double a;
			cout<<"so diem hoa can sua la:"; cin>>a;
			temp->subject.set_hoa(a);
		}
		if(n==4){
			double a;
			cout<<"so diem van can sua la:"; cin>>a;
			temp->subject.set_van(a);
		}
		if(n==5){
			double a;
			cout<<"so diem anh can sua la:"; cin>>a;
			temp->subject.set_anh(a);
		}
		if(n==6){
			double a;
			cout<<"so diem tin can sua la:"; cin>>a;
			temp->subject.set_tin(a);
		}
	}
}

void QuanLi::tim_kiem_hoc_sinh(string ten){
	int count=0;
	Node*temp=Head;
	while(temp!=NULL){
		if(temp->student.get_ten().compare(ten) == 0){
			count++; // danh dau 
			temp->student.xuat_thong_tin();
			temp->subject.xuatdiem();
		}
		temp=temp->next;

	}
	if(count==0){
		cout<<"khong co hoc sinh nao giong ten ban da nhap!!!"<<endl;
		return;
	}
}

void QuanLi::HienThiDanhSach(){
	Node *temp=Head;
	if(temp==NULL)
		cout<<"danh sach rong"<<endl;
	else{
		cout<<"danh sach hoc sinh"<<endl;
		while(temp!=NULL){
			temp->student.xuat_thong_tin();
			temp->subject.xuatdiem();
			temp=temp->next;
		}
	}
}
//void QuanLi::docFile(ifstream& filein){
//	student.docFile_hocsinh(filein);
//	subject.docFile_MonHoc(filein);
//	a.them_hoc_sinh_vao_cuoi(student,subject);
//}
void QuanLi::sap_xep_diem(){
	Node *temp=Head;
	Node *current=NULL;
	while(temp!=NULL){
		current=temp;
		while(current!=NULL){
			if(temp->subject.get_diem_trung_binh() >= current->subject.get_diem_trung_binh()){
				HocSinh a= temp->student;
				temp->student=current->student;
				current->student=a;
				MonHoc b= temp->subject;
				temp->subject=current->subject;
				current->subject=b;
			}
			current=current->next;
		}
		temp=temp->next;	
	}
}
QuanLi::~QuanLi(){
	Node *temp=Head;
	while(temp!=NULL){
		Node*current=temp->next;
		delete temp;
		temp=current;
	}
	Head=NULL;
}
int main(){
	QuanLi a;
	HocSinh student;
	MonHoc subject;
	int n;
	do{
		cout<<"0.them file vao danh sach"<<endl;
		cout<<"1.them hoc sinh vao dau danh sach"<<endl;
		cout<<"2.them hoc sinh vao cuoi danh sach"<<endl;
		cout<<"3.them hoc sinh vao vi tri bat ki"<<endl;
		cout<<"4.xoa hoc sinh o dau danh sach"<<endl;
		cout<<"5.xoa hoc sinh o cuoi danh sach"<<endl;
		cout<<"6.xoa hoc sinh o vi tri bat ki"<<endl;
		cout<<"7.sua diem cho hoc sinh"<<endl;
		cout<<"8.tim kiem hoc sinh"<<endl;
		cout<<"9.hien thi danh sach hoc sinh"<<endl;
		cout<<"10.sap xep diem"<<endl;
		cout<<"nhap TH:";cin>>n;
		if(n==0){
			int so_luong;
			ifstream filein1,filein2,filein3;
			filein1.open("thongtinhocsinh.txt");
			filein2.open("diemmonhoc.txt");
			filein3.open("so_luong.txt");
			filein3>>so_luong;
			for(int i=0;i<so_luong;i++){
			student.docFile_hocsinh(filein1);
			subject.docFile_MonHoc(filein2);
			a.them_hoc_sinh_vao_cuoi(student,subject);
			}
		}
		else if(n==1){
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_dau(student,subject);
		}
		else if(n==2){
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_cuoi(student,subject);
		}
		else if(n==3){
			int pos;
			cout<<"nhap vi tri can them hoc sinh:"; cin>>pos;
			cout<<"nhap thong tin va` diem cua hoc sinh do:"<<endl;
			student.nhapthongtin();
			subject.nhapdiem();
			a.them_hoc_sinh_vao_vi_tri_bat_ki(student,subject,pos);
		}
		else if(n==4){
			a.xoa_hoc_sinh_o_vi_tri_dau_tien();
		}
		else if(n==5){
			a.xoa_hoc_sinh_o_vi_tri_cuoi_cung();
		}
		else if(n==6){
			int pos;
			cout<<"nhap vi tri can xoa:"; cin>>pos;
			a.xoa_hoc_sinh_o_vi_tri_bat_ki(pos);
		}
		else if(n==7){
			int pos;
			cout<<"nhap vi tri can sua diem cho hoc sinh:";cin>>pos;
			a.sua_diem_cho_hoc_sinh(pos);
		}
		else if(n==8){
			string name;
			cout<<"tim kiem hoc sinh bang cach loc ten"<<endl;
			cout<<"nhap ten hoc sinh ma` ban muon tim` kiem:";
			cin.ignore();
			getline(cin,name);
			cout<<"thong tin hoc sinh ma` ban tim kiem la:"<<endl;
			a.tim_kiem_hoc_sinh(name);
		}
		else if(n==9){
			a.HienThiDanhSach();
		}
		else if(n==10){
			a.sap_xep_diem();
		}
	}while(n==0||n==1||n==2||n==3||n==4||n==5||n==6||n==7||n==8||n==9 || n==10);
}
