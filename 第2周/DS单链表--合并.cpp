#include <iostream>
using namespace std;
#define ok 0
#define error -1

class ListNode{
public:
	int data;
	ListNode *next;
	ListNode(){
		next=NULL;
	}
};

class LinkList{
public:
	ListNode *head;
	int len;
	LinkList();
	~LinkList();
	ListNode *LL_index(int i);
	int LL_get(int i);
	int LL_insert(int i,int item);
	int LL_del(int i);
	void LL_display();
};


LinkList::LinkList()
{
	head=new ListNode();
	len=0;
}
LinkList::~LinkList()
{
	ListNode *p,*q;
	p=head;
	while(p!=NULL){
		q=p;
		p=p->next;
		delete q;
	} 
	len=0;
	head=NULL;
}
void LinkList::LL_display()
{
	ListNode *p;
	p=head->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
//	cout<<len<<endl;
}


//
ListNode* LinkList::LL_index(int i){
	ListNode *p=head;
	for(int j=0;j<=i;j++){
		p=p->next;
	}
	return p;
}
int LinkList::LL_get(int i){
	if(i<=len&&i>0){
		ListNode *p=head;
		for(int j=0;j<i;j++){
			p=p->next;
		}
		return p->data;
	}else{
		return error;
	}
	
}
int LinkList::LL_insert(int i,int item){
	if(i<=len+1&&len>0&&i>0){
		ListNode *q=new ListNode();
		q->data=item;
		ListNode *p=head;
		for(int j=0;j<i-1;j++){
			p=p->next;
		}
		q->next=p->next;
		p->next=q;
		len++;
		return ok;
	}else if(i<=len+1&&len==0&&i>0){
		ListNode *q=head;
		ListNode *p=new ListNode();
		p->data=item;
		q->next=p;
		len++;
	}else{
		return error;
	}
	
}
int LinkList::LL_del(int i){
	if(i<=len&&i>0){
		ListNode *p=head;
		for(int j=0;j<i-1;j++){
			p=p->next;
		} 
		ListNode *q=p;
		q=q->next;
		p->next=q->next;
		delete q;
		len--;
		return ok;
	}else{
		return error;
	}
} 

int LL_merge(ListNode *La,ListNode *Lb){
	ListNode *p=La;
	ListNode *q=Lb;
	p=p->next;
	q=q->next;
	LinkList res;
	int k=1;
	while(p||q){
		if(q&&p){
			if(p->data>q->data){
				res.LL_insert(k,q->data);
				q=q->next;
				k++;
			}else{
				res.LL_insert(k,p->data);
				p=p->next;
				k++;
			}
		}else if(p){
			res.LL_insert(k,p->data);
			p=p->next;
			k++;
		}else if(q){
			res.LL_insert(k,q->data);
			q=q->next;
			k++;
		}
		
	}
	res.LL_display();
}

int main()
{
	LinkList p1,p2;
	int n,m;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		p1.LL_insert(i+1,a[i]);
	}
	cin>>m;
	int *b=new int[m];
	for(int i=0;i<m;i++){
		cin>>b[i];
		p2.LL_insert(i+1,b[i]);
	}
	LL_merge(p1.head,p2.head);
	delete []a;
	delete []b;
}
