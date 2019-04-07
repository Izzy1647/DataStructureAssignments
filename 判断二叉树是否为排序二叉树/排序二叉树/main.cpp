//
//  main.cpp
//  排序二叉树
//
//  Created by zzy on 2019/2/28.
//  Copyright © 2019 zzy. All rights reserved.
//

#include"bitree.h"
using namespace std;

int main()
{
    BiTree<char>* bitree=new BiTree<char>();        // 创建一棵二叉树
    bitree->PreOrder();                             // 前序遍历
    cout << endl;
    bitree->InOrder();                              // 中序遍历
    cout << endl;
    bitree->PostOrder();                            // 后序遍历
    cout << endl;
    //cout<< endl;
    if(bitree->isBST()){
        cout<<"yes"<<endl;
    }
    else cout<<"no."<<endl;    
    delete bitree;
    //return 0;
}
