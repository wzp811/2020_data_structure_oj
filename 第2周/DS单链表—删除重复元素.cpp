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
	void check(){
		ListNode *pi=head;
		while(pi->next){
			pi=pi->next;
			ListNode *pj=head->next;
			int k=0;
			while(pj){
				if(pi->data==pj->data&&pi!=pj){
					ListNode *temp=pj->next;
					LL_del(k+1);
					pj=temp;
				}else{
					pj=pj->next;
					k++;
				}
			} 
		}
		cout<<len<<": ";
		LL_display();
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
	int k=0;
	while(p)
	{
		cout<<p->data;
		k++;
		if(k<len){
			cout<<" ";
		}
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
	int t;
	cin>>t;
	while(t--){
		LinkList per;
		int n;
		cin>>n;
		int *a=new int [n];
		for(int i=0;i<n;i++){
			cin>>a[i];
			per.LL_insert(i+1,a[i]);
		}
		per.check();
	}
}
