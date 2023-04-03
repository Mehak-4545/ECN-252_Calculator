#include <iostream>
#include <fstream>
using namespace std;

int add(int a,int b){
    return a+b;
}
int subtract(int a,int b){
    return a-b;
}
int multiply(int a,int b){
    return a*b;
}
int divide(int a,int b){

    return a/b;
}
int rightshift(int a,int b){
    return (int(a)>>int(b));
}
int leftshift(int a,int b){
    return (int(a)<<int(b));
}
int OR(int a,int b){
    return (int(a) | int(b));
}
int AND(int a,int b){
    return (int(a) & int(b));
}
int main(){
    char answer;
    // cout<<"Do you want to compute again? (y/n)"<<endl;
    // cin>>answer;
    ofstream fout;
    fout.open("cppcal.txt");
    //do{
    string op;
    cout<<"Enter operator (+,-,*,/,<<,>>,&,|)"<<endl;
    cin>>op;
    int num1,num2;
    cout<<"Enter operand 1: ";
    cin>>num1;
    cout<<"Enter operand 2: ";
    cin>>num2;
    if(op=="+") fout<<add(num1,num2);
    else if(op=="-") fout<<"  "<<subtract(num1,num2);
    else if(op=="*") fout<<"  "<<multiply(num1,num2);
    else if(op=="/") {
        if(num2==0){
            cout<<"Error: division by zero";
        }else
        fout<<"  "<<divide(num1,num2);
    }
    else if(op==">>") fout<<"  "<<rightshift(num1,num2);
    else if(op=="<<") fout<<"  "<<leftshift(num1,num2);
    else if(op=="|") fout<<"  "<<OR(num1,num2);
    else if(op=="&") fout<<"  "<<AND(num1,num2);
    else{
        cout<<"Error: invalid operator";
    }
    // cout<<"Do you want to compute again? (y/n)";
    // cin>>answer;
    // }while(answer=='y' || answer=='Y');
    fout.close();
    return 0;
}