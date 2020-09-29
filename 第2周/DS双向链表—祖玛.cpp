#include <iostream>
#include <cstring>
using namespace std;
class listnode{
public:
	char color;
	listnode *next;
	listnode *last;
	listnode(){
		next=NULL;
		last=NULL;
	}
};

class linklist{
public:
	listnode *head;
	int len;
	linklist(){
		head=new listnode();
		len=0;
	}
	~linklist(){
		listnode *p,*q;
		p=head;
		while(p!=NULL){
			q=p;
			p=p->next;
			delete q;
		} 
		len=0;
		head=NULL;
	}
	void judge(){
		int flag;
		while(flag){
			flag=0;
			for(listnode *p=head->next->next;p;p=p->next){
				if(p->last->color==p->color&&p->next->color==p->color){
					flag=1;
				}
				listnode *temp=p->last;
				listnode *q=p->next;
				p=p->last->last;
				p->next=q->next;
				q=temp;
				temp=temp->next;
				delete q;
				q=temp;
				temp=temp->next;
				delete q;
				q=temp;
				temp=temp->next;
				delete q;
			}
		} 
	} 
	void LL_insert(int loc,char col){
		listnode *q=new listnode();
		q->color=col;
		listnode *p=head;
		for(int i=0;i<loc;i++){
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
		len++;
	}
	void display(){
		if(len==0){
			cout<<"-"<<endl;
		}else{
			listnode *p=head;
			while(p){
				cout<<p->color;
			}
			cout<<endl;
		}
	} 
};

int main()
{
	char ch[1000];
	cin>>ch;
	linklist per;
	int len=strlen(ch);
	for(int i=0;i<len;i++){
		per.LL_insert(i,ch[i]);
	}
	per.display();
	int t;
	cin>>t;
	while(t--){
		int loc;
		char col;
		cin>>loc>>col;
		per.LL_insert(loc,col);
		per.judge();
		per.display();
	}
}
