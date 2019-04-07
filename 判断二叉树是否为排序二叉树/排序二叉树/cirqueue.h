//
//  cirqueue.h
//  排序二叉树
//
//  Created by zzy on 2019/2/28.
//  Copyright © 2019 zzy. All rights reserved.
//

#pragma once
#include <iostream>
const int queueSize = 100;
template<class T>
class queue
{
public:
    //....
    T data[queueSize];
    int front, rear;
    //....
};
