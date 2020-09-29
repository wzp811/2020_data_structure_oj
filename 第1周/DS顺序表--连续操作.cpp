#include <iostream>
using namespace std;

class ds{
	int *a;
	int len;
	int max;
public:
	ds(int val){
		max=1000;
		a=new int [max];
		len=val;
		for(int i=0;i<len;i++){
			cin>>a[i];
		}
		cout<<len<<" ";
		for(int i=0;i<len;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	void multiinsert(int ival,int n,int item[]){
		for(int i=len+n-1;i>=ival+n-1;i--){
			a[i]=a[i-n];
		}
		for(int i=0;i<n;i++){
			a[ival+i-1]=item[i];
		}
		len+=n;
		cout<<len<<" ";
		for(int i=0;i<len;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	void multidel(int ival,int n){
		for(int i=0;i<n;i++){
			a[ival-1+i]=a[ival-1+i+n];
		}
		len-=n;
		cout<<len<<" ";
		for(int i=0;i<len;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	~ds(){
		delete[]a;
	}
};

int main()
{
	int n;
	cin>>n;
	ds p(n);
	int ival;
	cin>>ival;
	int k;
	cin>>k;
	int *val=new int [k];
	for(int i=0;i<k;i++){
		cin>>val[i];
	}
	p.multiinsert(ival,k,val);
	cin>>ival;
	cin>>k;
	p.multidel(ival,k);
}
