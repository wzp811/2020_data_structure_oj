#include <iostream>
#include <cmath>
using namespace std;

class point{
	double x,y;
public:
	point(){
		
	}
	point(double xval,double yval){
		x=xval;
		y=yval;
	}
	void setXY(double xval,double yval){
		x=xval;
		y=yval;
	}
	double getx(){return x;}
	double gety(){return y;}
	~point(){
		x=0;
		y=0;
		cout<<"point clear"<<endl;
	}
};

class circle{
	double x,y;
	double r;
public:
	circle(double xval,double yval,double rval){
		x=xval;
		y=yval;
		r=rval;
	}
	bool contain(point &p){
		double len=sqrt((x-p.getx())*(x-p.getx())+(y-p.gety())*(y-p.gety()));
		return len<r;
	}
	~circle(){
		x=0;
		y=0;
		r=0;
		cout<<"circle clear"<<endl;
	}
};

int main()
{
	int x,y;
	cin>>x>>y;
	point p(x,y);
	int n;
	cin>>n;
	point *k=new point [n];
	for(int i=0;i<n;i++){
		cin>>x>>y;
		k[i].setXY(x,y);
	}
	int r;
	cin>>x>>y>>r;
	circle cir(x,y,r);
	cout<<(cir.contain(p)?"in":"out")<<endl;
	for(int i=0;i<n;i++){
		cout<<(cir.contain(k[i])?"in":"out")<<endl;
	}
//	delete[]k;
}
