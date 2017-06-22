//
// Created by Krzysiek on 09.03.2017.
//

#include "SimpleForwardList.h"
#include <iostream>
using namespace std;

struct ForwardList;

ForwardList *CreateNode(int value){
    ForwardList *node=new ForwardList;
    node->value=value;
    node->next=nullptr;
    return node;
}

ForwardList *PushFront(ForwardList *list, int value){
    if(list==nullptr){
        return nullptr;
    }
    ForwardList *new_node=CreateNode(value);
    new_node->next=list;
    return new_node;
}

void Append(ForwardList *list, ForwardList *tail){
    ForwardList *pt=list;
    if(list==nullptr){
        return;
    }
    while(pt->next!=nullptr){
        pt=pt->next;
    }
    pt->next=tail;
}


void DestroyList(ForwardList *list){
    ForwardList *node2;
    while(list!=nullptr){
        node2=list;
        list=list->next;
        delete node2;
    }
    //delete list;
}