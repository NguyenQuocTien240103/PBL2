#include<iostream>
#include<vector>
#include<fstream>
#include<cmath>
#include<iomanip>
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

HocSinh::HocSinh(){}

HocSinh::HocSinh(string ten,string ngaysinh,int id){
	this->ten=ten;
	this->ngaysinh=ngaysinh;
	this->id=id;
}

string HocSinh::get_ten(){
	return this->ten;
}

string HocSinh::get_ngaysinh(){
	return this->ngaysinh;
}

int HocSinh::get_id(){
	return this->id;
}
void HocSinh::nhapthongtin(){
	cout<<"nhap id cua hoc sinh do: ";cin>>this->id;
	cin.ignore();
	cout<<"nhap ten hoc sinh: "; getline(cin,this->ten);
	cout<<"nhap ngay sinh cua hoc sinh: "; cin>>this->ngaysinh;
	
}
void HocSinh::set_id(int id){
	this->id=id;
}
void HocSinh::set_ngaysinh(string ngaysinh){
	this->ngaysinh=ngaysinh;
}
void HocSinh::set_ten(string ten){
	this->ten=ten;
}
void HocSinh::xuat_thong_tin(){
	cout<<"id:"<<this->id<<endl;
	cout<<"ten:"<<this->ten<<endl;
	cout<<"ngaysinh:"<<this->ngaysinh<<endl;
}

void HocSinh::docFile_hocsinh(ifstream& filein){
    filein>>this->id;
	filein.ignore();
	getline(filein,this->ten);
	filein>>this->ngaysinh;
	
}
HocSinh::~HocSinh(){}

class MonHoc{
	private:
		double toan,li,hoa,van,anh,tin;
		double diemtrungbinh;
		string hocluc;
        int id;
	public:
		MonHoc();
		MonHoc(double,double,double,double,double,double,int);
		void nhapdiem();
		double get_toan();
		double get_li();
		double get_hoa();
		double get_van();
		double get_anh();
		double get_tin();
		double get_diem_trung_binh();
		string get_hoc_luc();
        int get_id();
		void set_toan(double);
		void set_li(double);
		void set_hoa(double);
		void set_van(double);
		void set_anh(double);
		void set_tin(double);
		void set_diem_trung_binh(double);
		void set_hoc_luc(string);
        void set_id(int);
		void xuatdiem();
		~MonHoc();
		void docFile_MonHoc(ifstream&);
};


MonHoc::MonHoc(){}

MonHoc::MonHoc(double toan,double li,double hoa,double van,double anh,double tin,int id){
	this->toan=toan;
	this->li=li;
	this->hoa=hoa;
	this->van=van;
	this->anh=anh;
	this->tin=tin;
    this->id=id;
}

void MonHoc::nhapdiem(){ 
    cout<<"nhap id cua hoc sinh do: "; cin>>this->id;
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
int MonHoc::get_id(){
	return this->id;
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
void MonHoc::set_id(int id){
	this->id=id;
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
	cout<<"diem trung binh:"<<setprecision(1) << fixed<<this->diemtrungbinh<<endl;
	string hl =get_hoc_luc();
	set_hoc_luc(hl);
	cout<<"hoc luc:"<<this->hocluc<<endl;
}
void MonHoc::docFile_MonHoc(ifstream& filein){
    filein>>this->id;
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
		void tim_kiem_hoc_sinh(int);
		void HienThiDanhSach();
		void sap_xep_diem();
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

void QuanLi::xoa_hoc_sinh_o_vi_tri_bat_ki(int id){
	int count=1;
	Node*temp=Head;
	Node*current=NULL;
	while(1){
		if(temp->student.get_id()==id){
			break;
		}
		else{
			current=temp;
			temp=temp->next;
			count++;
		}
	}
	if(count==1){
		Head=Head->next;
	}
	else{
		current->next=temp->next;
	}
	delete temp;
}

void QuanLi::sua_diem_cho_hoc_sinh(int id){
		Node*temp=Head;
		while(1){
			if(temp->student.get_id()==id){
				break;
			}
			else{
				temp=temp->next;
			}
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


void QuanLi::tim_kiem_hoc_sinh(int  id){
	int count=0;
	Node*temp=Head;
	while(temp!=NULL){
		if(temp->student.get_id() == id){
			count++; // danh dau 
			temp->student.xuat_thong_tin();
			temp->subject.xuatdiem();
		}
		temp=temp->next;

	}
	if(count==0){
		cout<<"khong co hoc sinh nao giong id ban da nhap!!!"<<endl;
		return;
	}
}

void QuanLi::HienThiDanhSach(){
	int count=0;
	Node *temp=Head;
	if(temp==NULL)
		cout<<"DANH SACH RONG"<<endl;
	else{
		cout<<"\t\t\t\t\t\t*****DANH SACH HOC SINH*****"<<endl;
		while(temp!=NULL){
			cout<<"STT:"<<++count<<endl;
			temp->student.xuat_thong_tin();
			temp->subject.xuatdiem();
			temp=temp->next;
			cout<<endl;
		}
	}
}
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

void gioi_thieu(){
	cout<<"\t\t\t....................................................................\n";
	cout<<"\t\t\t.                                                                  .\n";
	cout<<"\t\t\t.               PBL2: QUAN LI DIEM HOC SINH THPT                   .\n";
	cout<<"\t\t\t.                                                                  .\n";
	cout<<"\t\t\t....................................................................\n";
	cout<<"\t\t\t.                                                                  .\n";
	cout<<"\t\t\t.               NGUYEN QUOC TIEN    MSSV:102220043                 .\n";
	cout<<"\t\t\t.               PHAM QUOC VU        MSSV:102220050                 .\n";
	cout<<"\t\t\t.               GVHD: TS. TRUONG NGOC CHAU                         .\n";
	cout<<"\t\t\t....................................................................\n";
	cout<<endl;

}
int main(){
	QuanLi quanli;
	vector<HocSinh> list_hoc_sinh;
	vector<MonHoc> list_mon_hoc;
	int n;
	do{
		gioi_thieu();
		cout<<"------------------------------------------------CAC LUA CHON DE QUAN LI-------------------------------------------------\n\n";
		cout<<"\t\t\t\t\t0.lay tu thong tin va diem hoc sinh tu file"<<endl;
		cout<<"\t\t\t\t\t1.nhap thong tin hoc sinh"<<endl;
		cout<<"\t\t\t\t\t2.nhap diem cua hoc sinh"<<endl;
		cout<<"\t\t\t\t\t3.hien thi thong tin cua hoc sinh"<<endl;
		cout<<"\t\t\t\t\t4.hien thi diem cua hoc sinh"<<endl;
		cout<<"\t\t\t\t\t5.hien thi thong tin va diem cua hoc sinh"<<endl;
		cout<<"\t\t\t\t\t6.them hoc sinh vao dau danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t7.them hoc sinh vao cuoi danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t8.them hoc sinh vao vi tri bat ki trong danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t9.xoa hoc sinh o dau danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t10.xoa hoc sinh o cuoi danh sach lop hoc"<<endl;
		cout<<"\t\t\t\t\t11.xoa hoc sinh o vi tri bat ki "<<endl;
		cout<<"\t\t\t\t\t12.sua diem cho hoc sinh"<<endl;
		cout<<"\t\t\t\t\t13.tim kiem hoc sinh"<<endl;
		cout<<"\t\t\t\t\t14.sap xep diem"<<endl;
		cout<<"\t\t\t\t\t15.hien thi thong tin va diem cua hoc sinh toan lop"<<endl;
		cout<<"\t\t\t\t\nhap TH:"; cin>>n;
		if(n==0){
			ifstream filein1,filein2,filein3;
			filein1.open("thongtinhocsinh.txt");
			filein2.open("diemmonhoc.txt");
			filein3.open("so_luong.txt");
			int soluong;
			filein3>>soluong;
			HocSinh student;
			MonHoc subject;
			for(int i=0;i<soluong;i++){
				student.docFile_hocsinh(filein1);
				list_hoc_sinh.push_back(student);
				subject.docFile_MonHoc(filein2);
				list_mon_hoc.push_back(subject);
			}
		}
		else if(n==1){
			HocSinh student;
			student.nhapthongtin();
			list_hoc_sinh.push_back(student);
			system("cls");
		}
		else if(n==2){
			MonHoc subject;
			subject.nhapdiem();
			list_mon_hoc.push_back(subject);
			system("cls");
		}
		else if(n==3){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon hien thi : "; cin>>x;
			system("cls");
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					a.xuat_thong_tin();
				}
			}
		}
		else if(n==4){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon hien thi : ";cin>>x;
			system("cls");
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					a.xuatdiem();
				}
			}
		}
		else if(n==5){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon hien thi : "; cin>>x;
			system("cls");
			HocSinh student;
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					student=a;
					break;
				}
			}
			MonHoc subject;
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					subject=a;
					break;
				}
			}
			student.xuat_thong_tin();
			subject.xuatdiem();
		}
		else if(n==6){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon them vao dau : "; cin>>x;
			HocSinh student;
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					student=a;
					break;
				}
			}
			MonHoc subject;
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					subject=a;
					break;
				}
			}
			quanli.them_hoc_sinh_vao_dau(student,subject);
			system("cls");
		}
		else if(n==7){
				int x;
			cout<<"nhap id cua hoc sinh ma ban muon them vao cuoi : "; cin>>x;
			HocSinh student;
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					student=a;
					break;
				}
			}
			MonHoc subject;
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					subject=a;
					break;
				}
			}
			quanli.them_hoc_sinh_vao_cuoi(student,subject);
			system("cls");
		}
		else if(n==8){
			int x,pos;
			cout<<"nhap id cua hoc sinh ma ban muon them vao vi tri bat ki : "; cin>>x;
			HocSinh student;
			for(HocSinh a: list_hoc_sinh){
				if(a.get_id()==x){
					student=a;
					break;
				}
			}
			MonHoc subject;
			for(MonHoc a: list_mon_hoc){
				if(a.get_id()==x){
					subject=a;
					break;
				}
			}
			cout<<"nhap vi tri ma ban muon them vao:";cin>>pos;
			quanli.them_hoc_sinh_vao_vi_tri_bat_ki(student,subject,pos);
			system("cls");
		}
		else if(n==9){
			quanli.xoa_hoc_sinh_o_vi_tri_dau_tien();
			system("cls");
		}
		else if(n==10){		
			quanli.xoa_hoc_sinh_o_vi_tri_cuoi_cung();
			system("cls");
		}
		else if(n==11){
			int x;
			cout<<"nhap id cua hoc sinh ma ban muon xoa:";cin>>x;
			quanli.xoa_hoc_sinh_o_vi_tri_bat_ki(x);
			system("cls");
		}
		else if(n==12){
			int x;
			cout<<"nhap id cua hoc sinh can sua diem:"; cin>>x;
			quanli.sua_diem_cho_hoc_sinh(x);
			system("cls");
		}
		else if(n==13){
			system("cls");
			int ID;
			cout<<"tim kiem hoc sinh ban cach tim id "<<endl;
			cout<<"nhap id cua hoc sinh ma` ban muon tim` kiem:";
			cin>>ID;
			cout<<"thong tin hoc sinh ma` ban tim kiem la:"<<endl;
			quanli.tim_kiem_hoc_sinh(ID);
		}
		else if(n==14){
			quanli.sap_xep_diem();
			system("cls");
		}
		else if(n==15){
			system("cls");
			quanli.HienThiDanhSach();
		}
		else{
			system("cls");
			cout<<"TH ban vua nhap nam ngoai cac lua chon tren!!!"<<endl;
		}

	}while(n==0||n==1||n==2||n==3 ||n==4 ||n==5 || n==6 || n==7 ||n==8||n==9||n==10||n==11|n==12||n==13||n==14||n==15);
	
}

