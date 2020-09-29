#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	stack <string> web;
	stack <string> cpy;
	string command;
	string url;
	web.push("http://www.acm.org/");
	while(cin>>command&&command!="QUIT"){
		if(command=="VISIT"){
			while(!cpy.empty()){
				cpy.pop();
			}
			cin>>url;
			web.push(url);
			cout<<web.top()<<endl;
		}else if(command=="BACK"){
			cpy.push(web.top());
			web.pop();
			if(web.empty()){
				cout<<"Ignored"<<endl;
				web.push(cpy.top());
				cpy.pop();
			}else{
				cout<<web.top()<<endl;
			}
		}else if(command=="FORWARD"){
			if(cpy.empty()){
				cout<<"Ignored"<<endl;
			}else{
				web.push(cpy.top());
				cpy.pop();
				cout<<web.top()<<endl;
			}
		}
	}
}
