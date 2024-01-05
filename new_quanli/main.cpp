#include<iostream>
#include<windows.h>
#include"quanli.cpp"
#include<vector>
#include<fstream>
using namespace std;
void gioi_thieu(){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole,FOREGROUND_RED | FOREGROUND_INTENSITY);
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
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
}
int main(){
	QuanLi quanli;
	vector<HocSinh> list_hoc_sinh;
	vector<MonHoc> list_mon_hoc;
	gioi_thieu();
	cout<<endl;
	cout<<endl;
	int n;
	int x;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do{
		SetConsoleTextAttribute(hConsole,FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		cout<<"----------LUA CHON---------"<<endl;
		cout<<"-  1.THEM CAC TINH NANG   -"<<endl;
		cout<<"-  2.HIEN THI DANH SACH   -"<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Nhap lua chon:";cin>>x;
		SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
		if(x==1){
			SetConsoleTextAttribute(hConsole,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			cout<<"\t\t\t\t\t0.Lay tu thong tin va diem hoc sinh tu file"<<endl;
			cout<<"\t\t\t\t\t1.Nhap thong tin hoc sinh"<<endl;
			cout<<"\t\t\t\t\t2.Nhap diem cua hoc sinh"<<endl;
			cout<<"\t\t\t\t\t3.Hien thi thong tin cua hoc sinh"<<endl;
			cout<<"\t\t\t\t\t4.Hien thi diem cua hoc sinh"<<endl;
			cout<<"\t\t\t\t\t5.Hien thi ID da nhap"<<endl;
			cout<<"\t\t\t\t\t6.Them hoc sinh vao dau danh sach lop hoc"<<endl;
			cout<<"\t\t\t\t\t7.Them hoc sinh vao cuoi danh sach lop hoc"<<endl;
			cout<<"\t\t\t\t\t8.Them hoc sinh vao vi tri bat ki trong danh sach lop hoc"<<endl;
			cout<<"\t\t\t\t\t9.Xoa hoc sinh o dau danh sach lop hoc"<<endl;
			cout<<"\t\t\t\t\t10.Xoa hoc sinh o cuoi danh sach lop hoc"<<endl;
			cout<<"\t\t\t\t\t11.Xoa hoc sinh o vi tri bat ki "<<endl;
			cout<<"\t\t\t\t\t12.Sua diem cho hoc sinh"<<endl;
			cout<<"\t\t\t\t\t13.Tim kiem hoc sinh"<<endl;
			cout<<"\t\t\t\t\t14.Sap xep diem"<<endl;
			cout<<"\t\t\t\t\tNhap TH:"; cin>>n;
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY);
			if(n==0){
				ifstream filein1,filein2,filein3;
				filein1.open("../new_data/thongtinhocsinh.txt");
				filein2.open("../new_data/diemmonhoc.txt");
				filein3.open("../new_data/so_luong.txt");
				int soluong;
				filein3>>soluong;
				HocSinh student_file;
				MonHoc subject_file;
                vector<HocSinh> list_file_hoc_sinh;
	            vector<MonHoc> list_file_mon_hoc;
            
				for(int i=0;i<soluong;i++){
					student_file.docFile_hocsinh(filein1);
					list_file_hoc_sinh.push_back(student_file);
					subject_file.docFile_MonHoc(filein2);
					list_file_mon_hoc.push_back(subject_file);
					// quanli.them_hoc_sinh_vao_cuoi(list_hoc_sinh[i],list_mon_hoc[i]);
				}
				for(int i=0;i<soluong;i++){
					for(int j=0;j<soluong;j++){
						if(list_file_hoc_sinh[i].get_id()==list_file_mon_hoc[j].get_id()){
							quanli.them_hoc_sinh_vao_cuoi(list_file_hoc_sinh[i],list_file_mon_hoc[j]);
						}
					}
				
				}
                for(int i=0;i<soluong;i++){
					list_hoc_sinh.push_back(list_file_hoc_sinh[i]);
					list_mon_hoc.push_back(list_file_mon_hoc[i]);
					
				}
				system("cls");
			}
			else if(n==1){
				system("cls");
				HocSinh student;
				int x;
				cout<<"Nhap ID cua hoc sinh do:";cin>>x;
				for(HocSinh a: list_hoc_sinh){
					if(a.get_id()==x){
						student=a;
						break;
					}
				}
				if(student.get_id()==x){
					cout<<"ID da bi trung"<<endl;
				}
				else{
					student.nhapthongtin(x);
					list_hoc_sinh.push_back(student);
				}
				
			}
			else if(n==2){
				system("cls");
				MonHoc subject;
				int x;
				cout<<"Nhap ID cua hoc sinh do:";cin>>x;
				for(MonHoc a: list_mon_hoc){
					if(a.get_id()==x){
						subject=a;
						break;
					}
				}
				if(subject.get_id()==x){
					cout<<"ID da bi trung"<<endl;
				}
				else{
					subject.nhapdiem(x);
					list_mon_hoc.push_back(subject);
				}

			}
			else if(n==3){
				system("cls");
				int x;
				cout<<"Nhap ID cua hoc sinh ma ban muon hien thi : "; cin>>x;
				
				for(HocSinh a: list_hoc_sinh){
					if(a.get_id()==x){
						a.xuat_thong_tin();
					}
				}
			}
			else if(n==4){
				system("cls");
				int x;
				cout<<"Nhap ID cua hoc sinh ma ban muon hien thi : ";cin>>x;
				for(MonHoc a: list_mon_hoc){
					if(a.get_id()==x){
						a.xuatdiem();
					}
				}
			}
			else if(n==5){
				system("cls");
				cout<<"cac id da nhap thong tin:"<<endl;
				for(int i=0;i<list_hoc_sinh.size();i++){
					cout<<list_hoc_sinh[i].get_id()<<" ";
				}
				cout<<endl;
				cout<<"cac id da nhap diem:"<<endl;
				for(int i=0;i<list_mon_hoc.size();i++){
					cout<<list_mon_hoc[i].get_id()<<" ";
				}
				cout<<endl;
			}
			else if(n==6){
				system("cls");
				int x;
				cout<<"Nhap ID cua hoc sinh ma ban muon them vao dau : "; cin>>x;
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
				if(student.get_id()!=x || subject.get_id()!=x){
					cout<<"ID nay da bi thieu du lieu"<<endl;
				}
				else{
					quanli.them_hoc_sinh_vao_dau(student,subject);
				}
				
			}
			else if(n==7){
				system("cls");
					int x;
				cout<<"Nhap ID cua hoc sinh ma ban muon them vao cuoi : "; cin>>x;
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
				if(student.get_id()!=x || subject.get_id()!=x){
					cout<<"ID nay da bi thieu du lieu"<<endl;
				}
				else{
					quanli.them_hoc_sinh_vao_cuoi(student,subject);
				}
				
			}
			else if(n==8){
				system("cls");
				int x,pos;
				cout<<"Nhap ID cua hoc sinh ma ban muon them vao vi tri bat ki : "; cin>>x;
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
				cout<<"Nhap vi tri ma ban muon them vao:";cin>>pos;
				if(student.get_id()!=x || subject.get_id()!=x){
					cout<<"ID nay da bi thieu du lieu"<<endl;
				}
				else{
					quanli.them_hoc_sinh_vao_vi_tri_bat_ki(student,subject,pos);
				}
				
				
			}
			else if(n==9){
				system("cls");
				quanli.xoa_hoc_sinh_o_vi_tri_dau_tien();
				
			}
			else if(n==10){		
				system("cls");
				quanli.xoa_hoc_sinh_o_vi_tri_cuoi_cung();
				
			}
			else if(n==11){
				system("cls");
				int x;
				cout<<"Nhap ID cua hoc sinh ma ban muon xoa:";cin>>x;
				quanli.xoa_hoc_sinh_o_vi_tri_bat_ki(x);
				
			}
			else if(n==12){
				system("cls");
				int x;
				cout<<"Nhap ID cua hoc sinh can sua diem:"; cin>>x;
				quanli.sua_diem_cho_hoc_sinh(x);
				
			}
			else if(n==13){		
				system("cls");	
				int ID;
				cout<<"Nhap ID cua hoc sinh ma` ban muon tim` kiem:";
				cin>>ID;
				cout<<"\t\t\t\t\t\t*****THONG TIN HOC SINH BAN VUA TIM KIEM LA*****"<<endl;
				quanli.tim_kiem_hoc_sinh(ID);
			}
			else if(n==14){
				system("cls");
				quanli.sap_xep_diem();
				
			}
			else{
				
				cout<<"TH ban vua nhap nam ngoai cac lua chon tren!!!"<<endl;
			}
		}
		else if(x==2){
			system("cls");
			quanli.HienThiDanhSach();
		}
	}while(x==1 || x==2);
}