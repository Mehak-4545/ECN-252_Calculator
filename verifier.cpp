#include<iostream>
#include<vector>
#include <fstream>
//#include <boost/algorithm/string.hpp>
//using namespace boost::algorithm;
using namespace std;

string trim(string str){
    string ans="";
    if(str[0]=='-'){
        ans+='-';
        for(int i=1;i<str.length();i++){
            if(str[i]!=' '){
                ans+=str[i];
            }
        }
    }else{
        for(int i=0;i<str.length();i++){
            if(str[i]!=' '){
                ans+=str[i];
            }
        }
    }
    return ans;
}

int main()
{
    ifstream fin1;
    ifstream fin2;
    fin1.open("cppcal.txt");
    fin2.open("vercal.txt");
    string ans1,ans2,ans3;
    while(getline(fin1,ans1)){
        ans1=trim(ans1);
        cout<<"Answer through cpp calculator:"<<ans1<<endl;
    }
    while(getline(fin2,ans2)){
        ans2=trim(ans2);
        cout<<"Answer through verilog calculator:"<<ans2<<endl;
    }
    if(ans1==ans2) cout<<"The answers match."<<endl;
    else cout<<"The answers dont match."<<endl;
    fin1.close();
    fin2.close();
    return 0;
}