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
void DestroyList(ForwardList *list){
    ForwardList *node=list,*node2;
    while(node!=nullptr){
        node2=node->next;
        delete node;
        node=node2;
    }
}