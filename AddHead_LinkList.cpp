#include<iostream>
using namespace std;
// cau truc node
struct Node{
	int data;
	Node*next;
};
typedef struct Node* node;
// tao mot Node moi

node MakeNode(int x){
	node NewNode=new Node();
	NewNode->data=x;
	NewNode->next=NULL;
	return NewNode;
}
// ktra Node co bao nhhieu phan tu;
int check(node Head ){
	int count=0;
	while(Head!=NULL){
		count++;
		Head=Head->next;
	}
	return count;
}
// AddHead: them Node vao dau danh sach lien ket
void AddHead(int x, node &Head){
	node NewNode= MakeNode(x);
	if(Head==NULL){
		Head=NewNode;
	}
	else{
		NewNode->next=Head;
		Head=NewNode;
	}
}
// Ham out
void out(node Head){
	while(Head!=NULL){
		cout<<Head->data;
		Head=Head->next;
	}
}

int main(){
	node Head=NULL;
	int a,x;
	do{
		cout<<"nhap a=1 de addHead va a=2 de thoat.....a=";
		cin>> a;
		if(a==1){
			cout<<"nhap x=";
			cin>> x;
			AddHead(x,Head);
		}
	}while(a==1);
	cout<<check(Head);
	cout<<"\n";
	out(Head);
}
