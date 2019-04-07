//
//  SeqStack.h
//  两个栈模拟一个队列
//
//  Created by zzy on 2018/10/26.
//  Copyright © 2018 zzy. All rights reserved.
//

#ifndef SeqStack_h
#define SeqStack_h
//#define SIZE 10
#define OVER_FLOW 0
#define SUCCESS 1
#define UNDER_FLOW 0
class SeqStack{
protected:
    int top;
    int maxsize;
    int *elems;
public:
    SeqStack(int size=SIZE);
    virtual ~SeqStack();
    bool isEmpty() const;
    int Push(const int e);
    int Pop(int &e);
};

SeqStack::SeqStack(int size){
    maxsize=size;
    if (elems != NULL){
        delete []elems;
    }
    elems=new int[maxsize];
}

SeqStack::~SeqStack(){
    delete []elems;
}

bool SeqStack::isEmpty()const{
    if(top!=0) return 0;
    else return 1;
}

int SeqStack::Push(const int e){
    if (top==maxsize){
        return OVER_FLOW;
    }
    else{
        elems[++top]=e;
        return SUCCESS;
    }
}
int SeqStack::Pop(int &e){
    if(isEmpty()){
        return UNDER_FLOW;
    }
    else{
        e=elems[top--];
        return SUCCESS;
    }
}



#endif /* SeqStack_h */
