#include<iostream>
#include<vector>
using namespace std;
vector<double>  Merge(vector<double> &left,vector<double>  &right){
    int left_num=left.size();
    int right_num=right.size();
    int total=left_num+right_num;
    int l=0,r=0;
    vector<double> result;
    for (int i=0;i<total;i++){
        if(l<left_num&&r<right_num){
            if(left[l]<=right[r]){
                result.push_back(left[l]);
                l++;
            }
            else {
                result.push_back(right[r]);
                r++;
            }
        }
        else if(l<left_num){
            for(;l<left_num;l++)
            result.push_back(left[l]);
            break;
        }    
        else if(r<right_num){
            for(;r<right_num;r++)
            result.push_back(right[r]);
            break;
        }
        else break;
    }
    return result;
}

 vector<double>  MergeSort(vector<double> & input){
    int num=input.size();
    vector<double> left,right,left_order,right_order;
    if(num>1){
        for (int i=0;i<num/2;i++)
        left.push_back(input[i]);
        for (int i=num/2;i<num;i++) //最开始i=num/2-1,错误，段错误！！！！！递归无法结束！！！！！
        right.push_back(input[i]);
        //return right;
        left_order=MergeSort(left);
        right_order=MergeSort(right);
        return Merge(left_order,right_order);
    }
        
    else {
        return input;
    }
}

int main(){
    vector<double> disorder,order,ordertest;
    double element=0;
    cout<<"Input the number:"<<endl;
    while(cin>>element){
        disorder.push_back(element);
    }
    // disorder={1,2,3,4,5,6,7,8,9,10,3.5};
    // vector<double> d2={1,2,4,6};
    // vector<double> d1={9,7,8,9};
    // ordertest=Merge(d1,d2);
    int num=disorder.size();
    cout<<num<<endl;
    cout<<"disorder:"<<endl;
    for (int i=0;i<num;i++)
        cout<<disorder[i]<<" ";
    order=MergeSort(disorder);
    cout<<"order:";
    int numl=order.size();
    for (int i=0;i<numl;i++){
        cout<<order[i]<<" ";
    }   
    cout<<endl;
    return 0;
}