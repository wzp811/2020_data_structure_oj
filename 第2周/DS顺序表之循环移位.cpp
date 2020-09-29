#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int *a=new int [n];
	int *b=new int [n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	int dir,num;
	cin>>dir>>num;
	if(dir==0){
		for(int i=0;i<n;i++){
			if(i+num<n){
				b[i]=a[i+num];
			}else{
				b[i]=a[i+num-n];
			}
		}
	}else{
		for(int i=n-1;i>=0;i--){
			if(i-num>=0){
				b[i]=a[i-num];
			}else{
				b[i]=a[i-num+n];
			}
		}
	}
	for(int i=0;i<n;i++){
		a[i]=b[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cin>>dir>>num;
	if(dir==0){
		for(int i=0;i<n;i++){
			if(i+num<n){
				b[i]=a[i+num];
			}else{
				b[i]=a[i+num-n];
			}
		}
	}else{
		for(int i=n-1;i>=0;i--){
			if(i-num>=0){
				b[i]=a[i-num];
			}else{
				b[i]=a[i-num+n];
			}
		}
	}
	for(int i=0;i<n;i++){
		a[i]=b[i];
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	delete []a;
	delete []b;
}
