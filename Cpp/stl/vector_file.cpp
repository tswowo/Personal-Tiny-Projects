#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> v;
    v.push_back(1);
    cout<<v[0]<<endl;
    cout<<&v[0]<<endl;
    cout<<&v<<endl;
    cout<<&v+1<<endl;
    return 0;
}