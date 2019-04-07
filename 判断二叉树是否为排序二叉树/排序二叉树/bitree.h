//
//  bitree.h
//  排序二叉树
//
//  Created by zzy on 2019/2/28.
//  Copyright © 2019 zzy. All rights reserved.
using namespace std;
#pragma once
#include <iostream>

// 二叉链表的节点
template<class T>
struct BiNode
{
    T data;    // 数据域
    BiNode<T>*lchild, *rchild;    // 左右指针域
};

// 二叉链表类实现
template<class T>
class BiTree
{
public:
    BiTree() { root = Creat(root); }        // 构造函数，建立一颗二叉树
    ~BiTree() { Release(root); }            // 析构函数，释放各节点的存储空间
    void PreOrder() { PreOrder(root); }      // 递归前序遍历二叉树
    void InOrder() { InOrder(root); }        // 递归中序遍历二叉树
    void PostOrder() { PostOrder(root); }    // 递归后序遍历二叉树
    bool isBST();
private:
    BiNode<T>* root;                        // 指向根节点的头节点
    BiNode<T>* Creat(BiNode<T>* bt);        // 构造函数调用
    void Release(BiNode<T>* bt);            // 析构函数调用
    void PreOrder(BiNode<T>* bt);           // 前序遍历函数调用
    void InOrder(BiNode<T>* bt);            // 中序遍历函数调用
    void PostOrder(BiNode<T>* bt);          // 后序遍历函数调用
};

template<class T>
inline BiNode<T>* BiTree<T>::Creat(BiNode<T>* bt)
{
    T ch;
    cin >> ch;　　　　　　　　　　　　　　　　　　// 输入结点的数据信息，假设为字符
    if (ch == '#')　　　　　　　　　　　　　　　　// 建立一棵空树
        bt = NULL;
    else
    {
        bt = new BiNode<T>;　　　　　　　　　　// 生成一个结点，数据域为ch
        bt->data = ch;
        bt->lchild = Creat(bt->lchild);　　　// 递归建立左子树
        bt->rchild = Creat(bt->rchild);　　　// 递归建立右子树
    }
    return bt;
}

template<class T>
inline void BiTree<T>::Release(BiNode<T>* bt)
{
    if (bt != NULL)
    {
        Release(bt->lchild);　　　　　　　　　　// 释放左子树
        Release(bt->rchild);　　　　　　　　　　// 释放右子树
        delete bt;　　　　　　　　　　　　　　　　// 释放根节点
    }
}

template<class T>
inline void BiTree<T>::PreOrder(BiNode<T>* bt)
{
    if (bt == NULL)　　　　　　　　　　　　　　// 递归调用的结束条件
        return;
    cout << bt->data;　　　　　　　　　　　　　// 访问根节点bt的数据域
    PreOrder(bt->lchild);　　　　　　　　　　 // 前序递归遍历bt的左子树
    PreOrder(bt->rchild);　　　　　　　　　　 // 前序递归遍历bt的右子树
}

template<class T>
inline void BiTree<T>::InOrder(BiNode<T>* bt)
{
    if (bt == NULL)
        return;
    InOrder(bt->lchild);
    cout << bt->data;
    InOrder(bt->rchild);
}

template<class T>
inline void BiTree<T>::PostOrder(BiNode<T>* bt)
{
    if (bt == NULL)
        return;
    PostOrder(bt->lchild);
    PostOrder(bt->rchild);
    cout << bt->data;
}
int temp;
bool judge;

template<class T>
inline void inOrderHelp(BiNode<T> *r) {
    if (r != nullptr) {
        inOrderHelp(r->lchild);
        if (r->data >= temp) {
            temp = r->data;
        } else {
            judge = false;
        }
        inOrderHelp(r->rchild);
    }
}

template<class T>
inline bool BiTree<T>::isBST() {
    if (root != nullptr) {
        BiNode<T> *node = root;
        while (node->lchild != nullptr) {
            node = node->lchild;
        }
        temp = node->data;
        judge = true;
        inOrderHelp(root);
        //return judge;
    }
    return judge;
}
