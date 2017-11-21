//
//  stack.c
//  数据结构
//
//  Created by 费克翔 on 2017/11/13.
//  Copyright © 2017年 LCC. All rights reserved.
//

#include "stack.h"
#include <stdlib.h>

extern Error error;

/** st.0.1
 初始化一个堆栈

 @return   返回初始化后的堆栈
 */
stack stInit(){
    
    stack st;
    
    st.bottom = NULL;
    st.top = NULL;
    st.dataType = Void;
    st.isSameType = true;
    st.length = 0;
    st.isEmpty = true;
    
    return st;
}


/** st.0.2 init stack with dataType
 初始化一个指定数据类型的堆栈，但堆栈长度为空.

 @param dataType 指定的数据类型
 @return 返回初始化后的堆栈
 */
stack stInitT(type dataType){
    
    stack st = stInit();
    
    st.dataType = dataType;
    
    return st;
}



/**
 st.0.3 stack push without data type.
 向目标堆栈中压栈,数据类型为堆栈的类型.
 Error(0, "无法压栈，堆栈的数据类型为多种");
 Error(1, " 无法压栈，堆栈数据类型为空，需要先指定堆栈的数据类型");
 
 @param stack 压栈的目标
 @param data 压入栈的内容
 @return 返回压栈后的栈
 */
stack stPush( stack *stack, void *data){
    
    if (stack->isSameType != true) {
        //addError(0, "无法压栈，堆栈的数据类型为多种");
        return *stack;
    }
    
    if (stack->isEmpty == true) {
        //addError(1, " 无法压栈，堆栈数据类型为空，需要先指定堆栈的数据类型");
    }
    
    
    stNode *newStNode;
    newStNode = (stNode *)malloc(sizeof(stNode));
    
    newStNode->data = data;
    newStNode->dataType = stack->dataType;
    newStNode->nextStNode = NULL;
    
    if (stack->length==0) {
        stack->bottom = newStNode;
        stack->isEmpty = false;
    }
    else{
        stack->top->nextStNode = newStNode;
    }
    
    stack->top = newStNode;
    stack->length += 1;
    
    return *stack;
}

/** st.0.4 add newnode to stack with dataType.
 先目标链表中添加指定数据和数据类型的链表

 @param stack 添加的目标链表
 @param data 添加数据
 @param dataType 添加数据的数据类型
 @return 返回添加后的数据类需求
 */
stack stPushT( stack *stack, void *data, type dataType){
    
    stNode *newStNode = (stNode *)malloc(sizeof(stNode));
    
    newStNode->data = data;
    newStNode->dataType = stack->dataType;
    newStNode->nextStNode = NULL;
    
    if (stack->length==0) {
        stack->bottom = newStNode;
        stack->isEmpty = false;
    }
    else{
        stack->top->nextStNode = newStNode;
    }
    
    if (stack->dataType==Void) {
        stack->dataType = newStNode->dataType;
    }
    else if (stack->dataType!=newStNode->dataType) {
        stack->dataType = Multiple;
        stack->isSameType = false;
    }
    
    stack->top = newStNode;
    stack->length += 1;
   
    return *stack;
}


int stPrint(const stack stack){
    
    char *type = "Void";
    
    switch (stack.dataType) {
        case Int:
            type = "Int";
            break;
            
        case String:
            type = "String";
            break;
            
        case Char:
            type = "Char";
            break;
            
        case p:
            type = "p";
            break;
            
        case pInt:
            type = "pInt";
            break;
            
        case pChar:
            type = "pChar";
            break;
            
        case Multiple:
            type = "Multiple";
            
        case Array:
            type = "Array";
            
        default:
            break;
    }
    
    printf("[ {length: %d, dataType: %s} :",stack.length,type);
    
    if (stack.isEmpty == true) {
        printf("堆栈为空 ]\n");
        return FINE;
    }
    else{
        
        for (stNode *arm=stack.bottom; arm!=NULL; arm=arm->nextStNode) {
            
            char *head = ",  ";
            if (arm == stack.bottom) {
                head = " ";
            }
            
            switch (arm->dataType) {
                case Int:
                    printf("%s%d",head,(int)(arm->data));
                    break;
                    
                case String:
                    printf("%s%s",head,(char *)(arm->data));
                    break;
                    
                case Char:
                    printf("%s%c",head,(char)(arm->data));
                    break;
                    
                case p:
                    printf("%s%d",head,(int)(arm->data));
                    break;
                    
                case pInt:
                    printf("%s%d",head,*(int *)(arm->data));
                    break;
                    
                case pChar:
                    printf("%s%c",head,*(char *)(arm->data));
                    break;
                    
                default:
                    break;
            }
            
        }
        
        
    }
    
    
    return FINE;
}



