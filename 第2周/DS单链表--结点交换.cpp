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
	void exchange(int index1,int index2){
		if(index1>0&&index1<=len&&index2>0&&index2<=len){
			ListNode *p,*q;
			ListNode *k=head;
			for(int i=0;i<index1;i++){
				k=k->next;
			}
			p=k;
			k=head;
			for(int i=0;i<index2;i++){
				k=k->next;
			}
			q=k;
			swap(p,q);
			swap(p->data,q->data);
			LL_display();
		}else{
			cout<<"error"<<endl;
		}
	}
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

int main()
{
	int n;
	cin>>n;
	int *a=new int [n];
	LinkList per;
	for(int i=0;i<n;i++){
		cin>>a[i];
		per.LL_insert(i+1,a[i]);
	}
	per.LL_display();
	int index1,index2;
	cin>>index1>>index2;
	per.exchange(index1,index2);
	cin>>index1>>index2;
	per.exchange(index1,index2);
	
	delete[]a;
}
