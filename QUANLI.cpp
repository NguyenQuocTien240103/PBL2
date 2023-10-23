#include<iostream>
#include<string>
#include<fstream>
using namespace std;
// tao Class Student
class Student{
	private:
		string ten,lop,ngaysinh,hanhkiem;
		double toan,li,hoa,anh,tin;
	public:
		/*double toan,li,hoa,anh,tin,diemtrungbinh;
		string hanhkiem,hocluc;*/
		float diemtrungbinh();
		void hocluc();
		void nhap();
		void xuat();
		
};
// tao Node
struct Node{
	Student data;
	Node*next;
};
typedef struct Node* node;
void Student::nhap(){
	cout<<"nhap ten:";
	cin.ignore();
	getline(cin,this->ten);
	cout<<"nhap lop:"; cin>>this->lop;
	cout<<"nhap ngay sinh:"; cin>>this->ngaysinh;
	cout<<"nhap diem toan:"; cin>>this->toan;
	cout<<"nhap diem li:"; cin>>this->li;
	cout<<"nhap diem hoa:"; cin>>this->hoa;
}
void Student::xuat(){
	cout<<"ten:"<<this->ten<<endl;
	cout<<"lop:"<<this->lop<<endl;
	cout<<"ngaysinh:"<<this->ngaysinh<<endl;
	cout<<"toan:"<<this->toan<<endl;
	cout<<"li:"<<this->li<<endl;
	cout<<"hoa:"<<this->hoa<<endl;
}
void in(Student a){
	a.xuat();
}
// tao Node moi
node MakeNode(){
	Student a;
	a.nhap();
	node NewNode=new Node();
	NewNode->data=a;
	NewNode->next=NULL;
	return NewNode;	
}
// dem so Node
int dem(node Head){
	int count=0;
	while(Head!=NULL){
		count++;
		Head=Head->next;
	}
	return count;
}
// liet ke danh sach HocSinh
void DuyetHead(node Head){
	if(Head==NULL){
		cout<<"khong co hoc sinh nao dc nhap thong tin"<<endl;
		return;
	}
	while(Head!=NULL){
		in(Head->data);
		Head=Head->next;
	}
}
// them vao dau
void AddHead(node &Head){
	node NewNode=MakeNode();
	if(Head==NULL){
		Head=NewNode;
		return;
	}
	else{
		NewNode->next=Head;
		Head=NewNode;
	}
}
// them vao cuoi
void AddLast(node &Head){
	node NewNode=MakeNode();
	if(Head==NULL){
		Head=NewNode;
		return;
	}
	else{
		node temp=Head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=NewNode;
	}
}
// them vao giua 
void AddMid(node &Head,int pos){
	int k=dem(Head);
	if(pos<1 || pos>k+1){
		cout<<"vi tri them HocSinh vao khong hop le!"<<endl;
		return;
	}
	else if(pos==1){
		AddHead(Head);
		return;
	}
	else{
		node temp=Head;
		for(int i=1;i<pos-1;i++){
			temp=temp->next;
		}
		node NewNode=MakeNode();
		NewNode->next=temp->next;
		temp->next=NewNode;
	}
}
// xoa phan tu o dau`
void DeleteHead(node &Head){
	if(Head==NULL){
		cout<<"Khong co thong tin cua hoc sinh de xoa"<<endl;
		return;
	}
	node temp=Head;
	Head=Head->next;
	delete temp;
}
// xoa phan tu o cuoi
void DeleteLast(node &Head){
	if(Head==NULL){
		cout<<"Khong co thong tin cua hoc sinh de xoa"<<endl;
		return;
	}
	node temp=Head;
	node fnt=NULL;
	while(temp->next!=NULL){
		fnt=temp;
		temp=temp->next;
	}
	fnt->next=NULL;
	delete temp;
}
// xoa phan tu bat ki
void DeleteMid(node &Head,int pos){
	int k=dem(Head);
	if(pos<1||pos>k){
		cout<<"vi tri can xoa khong hop le"<<endl;
	}
	else if(pos==1){
		DeleteHead(Head);
	}
	else{
		node temp=Head;
		node fnt=NULL;
		for(int i=1;i<pos;i++){
			fnt=temp;
			temp=temp->next;
		}
		fnt->next=temp->next;
		delete temp;
	}
}

int main(){
	node Head=NULL;
	int n,a;
	do{
		cout<<"1.them vao dau danh sach"<<endl;
		cout<<"2.them vao cuoi danh sach"<<endl;
		cout<<"3.them vao giua danh sach"<<endl;
		cout<<"4.xoa phan tu o dau danh sach"<<endl;
		cout<<"5.xoa phan tu o cuoi danh sach"<<endl;
		cout<<"6.xoa phan tu o vi tri bat ki"<<endl;
		cout<<"7.duyet danh sach"<<endl;
		cout<<"nhap TH:";cin>>n;
		if(n==1){
			AddHead(Head);
		}
		else if(n==2){
			AddLast(Head);
		}
		else if(n==3){
			int pos;
			cout<<"nhap vi tri can chen vao danh sach:"; cin>>pos;
			AddMid(Head,pos);
		}
		else if(n==4){
			DeleteHead(Head);
		}
		else if(n==5){
			DeleteLast(Head);
		}
		else if(n==6){
			int pos;
			cout<<"nhap vi tri can xoa:"; cin>>pos;
			DeleteMid(Head,pos);
		}
		else if(n==7){
			DuyetHead(Head);
		}
	}while(n==1||n==2|| n==3|| n==4|| n==5|| n==6|| n==7);	
}
