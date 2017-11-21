//
//  stack.h
//  数据结构
//
//  Created by 费克翔 on 2017/11/13.
//  Copyright © 2017年 LCC. All rights reserved.
//

#ifndef stack_h
#define stack_h

#include <stdio.h>
#include <stdbool.h>

#include "common.h"

typedef struct stNode{
    void *data;
    struct stNode *nextStNode;
    type dataType;
} stNode;

typedef struct {
    
    int length;
    bool isSameType;
    bool isEmpty;
    
    stNode *bottom;
    stNode *top;
    
    type dataType;
    
}stack;


#endif /* stack_h */
