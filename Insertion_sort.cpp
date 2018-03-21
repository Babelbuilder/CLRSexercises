/*
Insertion sort algorithm
*/

#include<iostream>
#include<vector>
using namespace std;
vector<double> & insertion_sort(vector<double> &input){
    int length=input.size();
    for (int i=1;i<length;i++){
        double key=input[i];
        int j=i-1;
        while (j>=0&&input[j]>key){
            input[j+1]=input[j];
            j--;
        }
        input[j+1]=key;
    }
    return input;
}

int main(){
    vector<double> disorder,order;
    double element=0;
    cout<<"Input the number:"<<endl;
    while(cin>>element){
        disorder.push_back(element);
    }
    int num=disorder.size();
    cout<<"disorder:";
    for (auto i : disorder)
        cout<<i<<" ";
    cout<<endl;
    order=insertion_sort(disorder);
    cout<<"order:";
    for (auto i : order)
        cout<<i<<" ";
    cout<<endl;
    return 0;
}