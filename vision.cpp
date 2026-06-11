#include<iostream>
using namespace std;
void display (char c='*',int count =3){
    for(int i=1;i<=count;++i){
        count<<c;
    }
    cout<<endl;
}
int main(){
    int count =5;
    cout <<"No argument passed:";
    display();
    cout <<"First argument passed:";
    display("#");
    cout <<"Both argument passed:";
    display('$',count);
    return 0;
}