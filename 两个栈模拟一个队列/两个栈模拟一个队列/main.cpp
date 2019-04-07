//
//  main.cpp
//  两个栈模拟一个队列
//
//  Created by zzy on 2018/10/26.
//  Copyright © 2018 zzy. All rights reserved.
//
#define SIZE 5
#include <iostream>
#include "TSTQ.h"
#include "SeqStack.h"
using namespace std;

int main()
{
    TSTQ a;
    int e;
    int numbers[SIZE];
    cout<<"Input "<<SIZE<<" integars:"<<endl;
    int c=0;
    while(c<SIZE){
        cin>>numbers[c];
        a.EnterQueue(numbers[c]);
        c++;
    }
    while (!a.isEmpty()){
        a.QuitQueue(e);
        cout<<"The deleted element from the queue is: "<<e<<endl;
    }
    //a.QuitQueue(e);
    //cout<<e<<endl;
    cout<<a.isEmpty()<<endl;
    return 0;
}
