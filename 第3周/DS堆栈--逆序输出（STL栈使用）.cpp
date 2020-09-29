#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		string str;
		int len;
		cin>>str;
		len=str.length();
		stack <char> s;
		for(int i=0;i<len;i++){
			s.push(str[i]);
		}
		while(!s.empty()){
			cout<<s.top();
			s.pop();
		}
		cout<<endl;
	}
}
