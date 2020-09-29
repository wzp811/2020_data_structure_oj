#include <list>
#include <iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n1,n2;
		cin>>n1;
		int *bef=new int [n1];
		int *on=new int [n1];
		int k=0;
		list <int> bef1;
		list <int> on1;
		for(int i=0;i<n1;i++){
			cin>>bef[i]>>on[i];
		}
		for(int i=0;i<=on[n1-1];i++){
			if(i==on[k]){
				on1.push_back(i);
				bef1.push_back(bef[k]);
				k++;
			}else{
				on1.push_back(i);
				bef1.push_back(0);
			}
		}
		delete[]bef;
		delete[]on;
		
		cin>>n2;
		bef=new int [n2];
		on=new int [n2];
		k=0;
		list <int> bef2;
		list <int> on2;
		for(int i=0;i<n2;i++){
			cin>>bef[i]>>on[i];
		}
		for(int i=0;i<=on[n2-1];i++){
			if(i==on[k]){
				on2.push_back(i);
				bef2.push_back(bef[k]);
				k++;
			}else{
				on2.push_back(i);
				bef2.push_back(0);
			}
		}
		delete []bef;
		delete []on;
		
		if(on1.back()>=on2.back()){
			int begin=on2.back();
			int times=on1.back()-on2.back();
			for(int i=0;i<times;i++){
				on2.push_back(i+begin+1);
				bef2.push_back(0);
			}
		}else{
			int begin=on1.back();
			int times=on2.back()-on1.back();
			for(int i=0;i<times;i++){
				on1.push_back(i+begin+1);
				bef1.push_back(0);
			}
		}
		
		int times=on1.back();
		list <int> ::iterator ii=on1.begin();
		list <int> ::iterator ij=on2.begin();
		list <int> ::iterator ji=bef1.begin();
		list <int> ::iterator jj=bef2.begin();
//add		
		list <int> res_add_bef;
		list <int> res_add_on;
		ii=on1.begin();
		ij=on2.begin();
		ji=bef1.begin();
		jj=bef2.begin();
		for(int i=0;i<=times;i++){
			res_add_bef.push_back(*ji+*jj);
			res_add_on.push_back(*ii);
			ii++;
			ij++;
			ji++;
			jj++;
		}
//display
		ii=res_add_bef.begin();
		ij=res_add_on.begin();
		int flag=0;//0指第一个还没输出
		int temp=0;//0指多项式为0 
		for(int i=0;i<=times;i++){
			if(*ii!=0){
				temp=1;
				break;
			}
			ii++;
		}
		ii=res_add_bef.begin();
		ij=res_add_on.begin();
		if(temp==0){
			cout<<"0"<<endl;
		}else{
			for(int i=0;i<=times;i++){
				if(flag==0&&*ii!=0){
					if(*ij==0){
						cout<<*ii;
					}else if(*ij==1){
						if(*ii==1){
							cout<<"x";
						}else if(*ii==-1){
							cout<<"-x";
						}else{
							cout<<*ii<<"x";
						}
					}else{
						if(*ii==1){
							cout<<"x^"<<*ij;
						}else if(*ii==-1){
							cout<<"-x^"<<*ij;
						}else{
							cout<<*ii<<"x^"<<*ij;
						}
					}
					flag=1;
				}else if(flag==1&&*ii!=0){
					if(*ij==1){
						if(*ii==1){
							cout<<"+x";
						}else if(*ii==-1){
							cout<<"-x";
						}else if(*ii>1){
							cout<<"+"<<*ii<<"x";
						}else if(*ii<-1){
							cout<<*ii<<"x";
						}
					}else{
						if(*ii==1){
							cout<<"+x^"<<*ij;
						}else if(*ii==-1){
							cout<<"-x^"<<*ij;
						}else if(*ii>1){
							cout<<"+"<<*ii<<"x^"<<*ij;
						}else if(*ii<-1){
							cout<<*ii<<"x^"<<*ij;
						}
					}
				}
				ii++;
				ij++;
			}
			cout<<endl;
		}
//
//min
		list <int> res_min_bef;
		list <int> res_min_on;
		ii=on1.begin();
		ij=on2.begin();
		ji=bef1.begin();
		jj=bef2.begin();
		for(int i=0;i<=times;i++){
			res_min_bef.push_back(*ji-*jj);
			res_min_on.push_back(*ii);
			ii++;
			ij++;
			ji++;
			jj++;
		}
//diaplay
		ii=res_min_bef.begin();
		ij=res_min_on.begin();
		flag=0;//0指第一个还没输出
		temp=0;//0指多项式为0 
		for(int i=0;i<=times;i++){
			if(*ii!=0){
				temp=1;
				break;
			}
			ii++;
		}
		ii=res_min_bef.begin();
		ij=res_min_on.begin();
		if(temp==0){
			cout<<"0"<<endl;
		}else{
			for(int i=0;i<=times;i++){
				if(flag==0&&*ii!=0){
					if(*ij==0){
						cout<<*ii;
					}else if(*ij==1){
						if(*ii==1){
							cout<<"x";
						}else if(*ii==-1){
							cout<<"-x";
						}else{
							cout<<*ii<<"x";
						}
					}else{
						if(*ii==1){
							cout<<"x^"<<*ij;
						}else if(*ii==-1){
							cout<<"-x^"<<*ij;
						}else{
							cout<<*ii<<"x^"<<*ij;
						}
					}
					flag=1;
				}else if(flag==1&&*ii!=0){
					if(*ij==1){
						if(*ii==1){
							cout<<"+x";
						}else if(*ii==-1){
							cout<<"-x";
						}else if(*ii>1){
							cout<<"+"<<*ii<<"x";
						}else if(*ii<-1){
							cout<<*ii<<"x";
						}
					}else{
						if(*ii==1){
							cout<<"+x^"<<*ij;
						}else if(*ii==-1){
							cout<<"-x^"<<*ij;
						}else if(*ii>1){
							cout<<"+"<<*ii<<"x^"<<*ij;
						}else if(*ii<-1){
							cout<<*ii<<"x^"<<*ij;
						}
					}
				}
				ii++;
				ij++;
			}
			cout<<endl;
		}
//	
//mul
		list <int> res_mul_bef;
		list <int> res_mul_on;
		times=on1.back()+on2.back();
		
		for(int i=0;i<=times;i++){
			res_mul_on.push_back(i);
			int sum=0;
			for(ii=on1.begin(),ji=bef1.begin();(*ii)<=i;ii++,ji++){
				for(ij=on2.begin(),jj=bef2.begin();(*ij)<=i;ij++,jj++){
					if(*ii+*ij==i)
						sum+=(*ji)*(*jj);
				}
			}
			res_mul_bef.push_back(sum);
		}
		
//diaplay
		ii=res_mul_bef.begin();
		ij=res_mul_on.begin();
		flag=0;//0指第一个还没输出
		temp=0;//0指多项式为0 
		for(int i=0;i<=times;i++){
			if(*ii!=0){
				temp=1;
				break;
			}
			ii++;
		}
		ii=res_mul_bef.begin();
		ij=res_mul_on.begin();
		if(temp==0){
			cout<<"0"<<endl;
		}else{
			for(int i=0;i<=times;i++){
				if(flag==0&&*ii!=0){
					if(*ij==0){
						cout<<*ii;
					}else if(*ij==1){
						if(*ii==1){
							cout<<"x";
						}else if(*ii==-1){
							cout<<"-x";
						}else{
							cout<<*ii<<"x";
						}
					}else{
						if(*ii==1){
							cout<<"x^"<<*ij;
						}else if(*ii==-1){
							cout<<"-x^"<<*ij;
						}else{
							cout<<*ii<<"x^"<<*ij;
						}
					}
					flag=1;
				}else if(flag==1&&*ii!=0){
					if(*ij==1){
						if(*ii==1){
							cout<<"+x";
						}else if(*ii==-1){
							cout<<"-x";
						}else if(*ii>1){
							cout<<"+"<<*ii<<"x";
						}else if(*ii<-1){
							cout<<*ii<<"x";
						}
					}else{
						if(*ii==1){
							cout<<"+x^"<<*ij;
						}else if(*ii==-1){
							cout<<"-x^"<<*ij;
						}else if(*ii>1){
							cout<<"+"<<*ii<<"x^"<<*ij;
						}else if(*ii<-1){
							cout<<*ii<<"x^"<<*ij;
						}
					}
				}
				ii++;
				ij++;
			}
			cout<<endl;
		}
	}
}

