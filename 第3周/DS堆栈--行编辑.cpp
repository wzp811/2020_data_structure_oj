#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		string str;
		cin>>str;
		int len=str.length();
		stack <char> s;
		stack <char> res;
		for(int i=len-1;i>=0;i--){
			s.push(str[i]);
		}
		while(!s.empty()){
			if(s.top()=='#'){
				if(res.empty()==0){
					res.pop();
				}
				s.pop();
			}else{
				res.push(s.top());
				s.pop();
			}
		}
		stack <char> result;
		while(!res.empty()){
			result.push(res.top());
			res.pop();
		}
		if(result.empty()){
			cout<<"NULL";
		}else{
			while(!result.empty()){
				cout<<result.top();
				result.pop();
			}
		}
		cout<<endl;
	}
}
