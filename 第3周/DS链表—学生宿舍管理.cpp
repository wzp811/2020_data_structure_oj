#include <iostream>
#include <list>
#include <cstdlib>
#include <iomanip>
using namespace std;
typedef list<int> LISTINT;
typedef list<string> LISTCHAR;

int main()
{
	
	LISTINT list_free;
	LISTCHAR list_used_name;
	LISTINT list_used_num;
	LISTINT::iterator i_i;
	LISTCHAR::iterator i_c;
	LISTINT::iterator ii;
	LISTCHAR::iterator ic;
	for(int i=0;i<20;i++){
		list_free.push_back(100+i+1);
	}
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string name;
		int num;
		cin>>name>>num;
		for(i_i=list_free.begin();i_i!=list_free.end();i_i++){
			if(*i_i==num){
					list_free.erase(i_i);
					break;
			}
		}
		list_used_name.push_back(name);
		list_used_num.push_back(num);
	}/*
//////	
	i_i=list_free.begin();
	cout<<*i_i;
	i_i++;
	for(i_i;i_i!=list_free.end();i_i++){
		cout<<"-"<<*i_i;
	}
	cout<<endl;
//////
	i_c=list_used_name.begin();
	i_i=list_used_num.begin();
	cout<<*i_c<<"("<<*i_i<<")";
	i_i++;
	i_c++;
	for(i_c,i_i;i_c!=list_used_name.end(),i_i!=list_used_num.end();i_i++,i_c++){
		cout<<"-"<<*i_c<<"("<<*i_i<<")";
	}
	cout<<endl;
//////	*/		
	int m;
	cin>>m;
	while(m--){
		string command;
		cin>>command;
		if(command=="assign"){
			string name;
			cin>>name;
			list_used_num.push_back(list_free.front());
			list_used_name.push_back(name);
			list_free.pop_front();
/*			//////	
			i_i=list_free.begin();
			cout<<*i_i;
			i_i++;
			for(i_i;i_i!=list_free.end();i_i++){
				cout<<"-"<<*i_i;
			}
			cout<<endl;
			//////
			i_c=list_used_name.begin();
			i_i=list_used_num.begin();
			cout<<*i_c<<"("<<*i_i<<")";
			i_i++;
			i_c++;
			for(i_c,i_i;i_c!=list_used_name.end(),i_i!=list_used_num.end();i_i++,i_c++){
				cout<<"-"<<*i_c<<"("<<*i_i<<")";
			}
			cout<<endl;
*/			//////			
		}else if(command=="return"){
			int num_ret;
			cin>>num_ret;
			list_free.push_back(num_ret);
			for(i_c=list_used_name.begin(),i_i=list_used_num.begin();i_c!=list_used_name.end(),i_i!=list_used_num.end();i_i++,i_c++){
				if(*i_i==num_ret){
					list_used_name.erase(i_c);
					list_used_num.erase(i_i);
					break;
				}
			}
/*			//////	
			i_i=list_free.begin();
			cout<<*i_i;
			i_i++;
			for(i_i;i_i!=list_free.end();i_i++){
				cout<<"-"<<*i_i;
			}
			cout<<endl;
			//////
			i_c=list_used_name.begin();
			i_i=list_used_num.begin();
			cout<<*i_c<<"("<<*i_i<<")";
			i_i++;
			i_c++;
			for(i_c,i_i;i_c!=list_used_name.end(),i_i!=list_used_num.end();i_i++,i_c++){
				cout<<"-"<<*i_c<<"("<<*i_i<<")";
			}
			cout<<endl;
*/			//////			
		}else if(command=="display_free"){
			i_i=list_free.begin();
			cout<<*i_i;
			i_i++;
			for(i_i;i_i!=list_free.end();i_i++){
				cout<<"-"<<*i_i;
			}
			cout<<endl;
		}else if(command=="display_used"){
			for(i_i=list_used_num.begin(),i_c=list_used_name.begin();i_i!=list_used_num.end(),i_c!=list_used_name.end();i_i++,i_c++){
				for(ii=i_i,ic=i_c;ii!=list_used_num.end(),ic!=list_used_name.end();ii++,ic++){
					if(*ii<*i_i){
						swap(*ii,*i_i);
						swap(*ic,*i_c);
					}
				}
			}
			i_c=list_used_name.begin();
			i_i=list_used_num.begin();
			cout<<*i_c<<"("<<*i_i<<")";
			i_i++;
			i_c++;
			for(i_c,i_i;i_c!=list_used_name.end(),i_i!=list_used_num.end();i_i++,i_c++){
				cout<<"-"<<*i_c<<"("<<*i_i<<")";
			}
			cout<<endl;
		}
	}
}
