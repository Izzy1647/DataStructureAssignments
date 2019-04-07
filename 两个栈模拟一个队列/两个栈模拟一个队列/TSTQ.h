//
//  TSTQ.h
//  两个栈模拟一个队列
//
//  Created by zzy on 2018/10/26.
//  Copyright © 2018 zzy. All rights reserved.
//
#include "SeqStack.h"
#ifndef TSTQ_h
#define TSTQ_h
using namespace std;
SeqStack s1(10);
SeqStack s2(10);
//int numbers[10];
class TSTQ{
protected:
    int queue_size;
public:
    TSTQ(int size=SIZE);
    int EnterQueue(const int e);//入队操作
    int QuitQueue(int &e);//出队操作
    bool isEmpty();//判断非空
    //void GetInput();//获取数据
};
//构造函数
TSTQ::TSTQ(int size){
    queue_size=size;
}
/*void TSTQ::GetInput(){
    cout<<"Input 10 integars"<<endl;
    
    for (int y=0;y++;y<10){
        cin>>numbers[y];
        EnterQueue(numbers[y]);
    }
}*/
//入队列相当于进s1栈
int TSTQ::EnterQueue(const int a){
    return s1.Push(a);//==1
}

//出队操作先把s1倒进s2，再把s2栈顶取出，再把其余的倒回去
int TSTQ::QuitQueue(int &e){
    int e1;
    if(s1.isEmpty()!=1){
        while(s1.isEmpty()!=1){
            s1.Pop(e1);
            s2.Push(e1);  //s1不空就从s1倒进s2
        }
        s2.Pop(e);//把栈顶元素弹出
        while(s2.isEmpty()!=1){
            s2.Pop(e1);
            s1.Push(e1);//s2不空把s2中剩余的倒回s1
        }
        return SUCCESS;
    }
    else{
        return UNDER_FLOW;
    }
}

//队列空不空就相当于栈s1空不空
bool TSTQ::isEmpty(){
    return s1.isEmpty();
}

#endif /* TSTQ_h */
