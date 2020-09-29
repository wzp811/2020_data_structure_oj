#include <iostream>
#include <cstdio>
using namespace std;

class node{
public:
	int number;
	node *next;
	node(){
		number=-1;
		next=NULL;
	}
	node(int val){
		number=val;
		next=NULL;
	}
};

class list{
public:
	node *head;
	int len;
	list(int val){
		len=val;
		head = new node();
		node *p=head;
		for(int i=0;i<val;i++){
			node *per = new node(i+1);
			p->next=per;
			p=p->next;
		}
		p->next=head;
	}
	~list(){
	}
	void del(int index){
	}
	void operation(int nval,int sval){
		node *p=head;
		for(int i=0;i<sval;i++){
			p=p->next;
			if(p->number==-1){
				p=p->next;
			}
		}
		cout<<p->number<<endl;
		while(len){
			for(int i=0;i<nval-2;i++){
				p=p->next;
				if(p->number==-1){
					p=p->next;
				}
			}
			node *q=p;
			q=q->next;
			if(q->number==-1){
				q=q->next;
			}
			p->next=q->next;
			cout<<q->number<<" ";
			delete q;
			len--;
			p=p->next;
			if(p->number==-1){
				p=p->next;
			}
		}
		cout<<endl;
	}
	void display(){
		node *p=head;
		int t=60;
		while(t--){
			cout<<p->number<<" ";
			p=p->next;
		}
		cout<<endl;
	}
};

int main()
{
	int N;
	int t=2;
	while(scanf("%d",&N)!=EOF){
		int K,S;
		cin>>K>>S;
		list ex(N);
//		ex.display();
		ex.operation(K,S);
	}
}
