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
    void insert(int loc,int val){
        if(loc<=len+1&&loc>0){
            for(int i=len;i>=loc;i--){
                a[i]=a[i-1];
            }
            a[loc-1]=val;
            len++;
            cout<<len<<" ";
            for(int i=0;i<len;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }else{
            cout<<"error"<<endl;
        }
    }
    void del(int loc){
        if(loc<=len&&loc>0){
            for(int i=loc-1;i<len-1;i++){
                a[i]=a[i+1];
            }
            len--;
            cout<<len<<" ";
            for(int i=0;i<len;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }else{
            cout<<"error"<<endl;
        }
    }
    void find(int loc){
        int val;
        if(loc<=len&&loc>0){
            cout<<a[loc-1]<<endl;
        }else{
            cout<<"error"<<endl;
        }
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
    int loc,val;
    cin>>loc>>val;
    p.insert(loc,val);
    cin>>loc>>val;
    p.insert(loc,val);
    cin>>loc;
    p.del(loc);
    cin>>loc;
    p.del(loc);
    cin>>loc;
    p.find(loc);
    cin>>loc;
    p.find(loc);
}
