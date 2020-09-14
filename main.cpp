//
// Created by 陈肯 on 2020/8/31.
//
#include<iostream>

void copyArray(int * a,int * b);

int main(){
    using namespace std;
    int rawarray[10]={2,3,4,5,6,11,23,45,7,1};
    int coppyarray[10]={};
    copyArray(rawarray,coppyarray);
    for(int i=0;i<10;i++){
        cout<<coppyarray[i]<<endl;
    }
}

void copyArray(int *a,int *b){
    for(int i=0;i<10;i++){
        b[i]=a[i];
    }




};