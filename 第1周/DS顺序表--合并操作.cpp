#include <iostream>
using namespace std;

class ds{
	int *a;
	int len;
	int max;
public:
	ds(int val){
		len=val;
		max=1000;
		a=new int [max];
		for(int i=0;i<len;i++){
			cin>>a[i];
		}
	}
	void add(ds &p){
		for(int i=len;i<len+p.len;i++){
			a[i]=p.a[i-len];
		}
		len+=p.len;
		for(int i=0;i<len;i++){
			for(int j=i;j<len-1;j++){
				if(a[j]>a[j+1]){
					int temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
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
	ds p1(n);
	int m;
	cin>>m;
	ds p2(m);
	p1.add(p2);
}
