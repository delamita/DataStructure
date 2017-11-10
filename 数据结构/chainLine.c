//
//  chainLine.c
//  数据结构
//
//  Created by 费克翔 on 2017/11/9.
//  Copyright © 2017年 LCC. All rights reserved.
//

#include "chainLine.h"

extern Error error;



Error addError(int errorCode, char *errorDescription){
    
    error.errorCode = errorCode;
    error.errorDescription = errorDescription;
    
    return error;
}





/**
 0.0.1 chainLineInit
 初始化并返回一个为空的链表
 
 @return 空链表
 */
chainLine clInit(){
    
    chainLine cl;
    cl.length = 0;
    cl.head = NULL;
    cl.lastNode = NULL;
    cl.isSameType = true;
    cl.dataTpye = Void;

    return cl;
}




/**
 0.0.2 chainLine Add newNode
 向目标链表添加节点
 
 @param chainline 添加的目标链表
 @param data 新添加节点的数据
 @param dataType 新添加节点数据的类型
 @return 修改后的链表
 */
chainLine clAddNodeTo(chainLine *chainline,void *data,type dataType){
    
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->dataType = dataType;
    
    if (chainline->length==0) {
        chainline->head = newNode;
    }
    else{
        chainline->lastNode->nextNode = newNode;
    }
    
    if (chainline->dataTpye!=newNode->dataType) {
        chainline->dataTpye = Multiple;
        chainline->isSameType = false;
    }
    
    chainline->lastNode = newNode;
    chainline->length += 1;
    
    return *chainline;
}




/**
 0.0.3 chainline is Same type check
 检查链表的数据类型是否相同，并更新

 @param chainline 需要检查的链表
 @return 返回更新后的值
 */
bool clisSameTypeCheck(chainLine *chainline){
    
    if (chainline->length == 0) {
        return chainline->isSameType;
    }
    
    bool isSame = true;
    
    for (node *arm=chainline->head; arm->nextNode!=NULL; arm=arm->nextNode) {
        if (arm->dataType != arm->nextNode->dataType) {
            isSame = false;
            break;
        }
    }

    
    if (isSame) {
        chainline->dataTpye = chainline->head->dataType;
        chainline->isSameType = true;
    }
    else{
        chainline->dataTpye = Multiple;
        chainline->isSameType = false;
    }

    return chainline->isSameType;
}





/**
 0.1.0 chainLinePrint
 打印一个链表

 @param chainline 需要打印的链表
 @return 返回打印是否成功
 */
int ptChainLine(const chainLine chainline){
    

    printf("[ {length: %d, dataType: %u} :",chainline.length,(type)chainline.dataTpye);
;
    
    if (chainline.length == 0) {
        printf("链表为空 ]\n");
        return FINE;
    }
    else{
        
        for (node *arm=chainline.head; arm!=NULL; arm=arm->nextNode) {
            
            char *head = ",  ";
            
            if (arm == chainline.head){
                head = " ";
            }
            
            switch (arm->dataType) {
                case Int:
                    printf("%s%d",head,*(int *)(arm->data));
                    break;
                case String:
                    printf("%s%s",head,(char *)(arm->data));
                    break;
                case Char:
                    printf("%s%c",head,(char)(arm->data));
                    break;
                default:
                    break;
            }
        }
        
    }
    
    printf(" ]\n");
    
    
    return FINE;
}




/**
 0.1.1 chainLineInitByValueForLength
 初始化并返回一个固定长度和默认值的链表

 @param lenght 默认长度
 @param data 默认值
 @return 初始化完成的链表
 */
chainLine clInitByValuefor(int lenght, void *data, type dataType){
    
    chainLine cl = clInit();
    
    for (int i=0; i<lenght; i++) {
        clAddNodeTo(&cl, data, dataType);
    }

    return cl;
}



/**
 0.2.1 chainline RemoveAll Node
 删除链表的所有节点

 @param chainline 删除的目标链表
 @return 返回删除后的链表
 */
chainLine clRemoveAll(chainLine *chainline){

    chainline->head = NULL;
    chainline->dataTpye = Void;
    chainline->isSameType = true;
    chainline->lastNode = NULL;
    chainline->length = 0;
    
    return *chainline;
    
}


/**
 0.2.2 chainLine remove index node
 删除指定位置的节点

 @param chainline 需要操作的链表
 @param index 指定的位置
 @return 返回删除后的链表
 */
chainLine clReomoveIndex(chainLine *chainline,int index){
    
    if (index>=chainline->length) {
        addError(0, "范围超出链表");
        return *chainline;
    }
    else{
        
        if (index==0) {
            chainline->head = chainline->head->nextNode;
        }
        else{
            node *arm = chainline->head;
            for (int i=0; i<index-1; i++) {
                arm = arm->nextNode;
            }
            arm->nextNode = arm->nextNode->nextNode;
        }
        
        chainline->length -= 1;
    }
    
    if (chainline->isSameType) {
    }
    else{
        clisSameTypeCheck(chainline);
    }
    
    return *chainline;
}


/**
 <#Description#>

 @param chainline <#chainline description#>
 @param data <#data description#>
 @return <#return value description#>
 */
node *chRemoveByValue(chainLine *chainline, void *data){
    
    node *newNode = NULL;
    
    node *bfNode = clScNodeBeforeValue(*chainline, data);
    
    if (bfNode!=NULL) {
        
        bfNode->nextNode = bfNode->nextNode->nextNode;
        chainline->length -= 1;
        
        if (chainline->isSameType!=true){
            clisSameTypeCheck(chainline);
        }
        
    }
 
    return newNode;
    
}




/**
 0.3.0 chainline search node by Value
 在链表中查找并返回指定值的节点
 
 @param chainline 查找的链表
 @param data 查找的数据
 @return 返回查找到的节点，未找到返回NULL
 */
node *clSearchNodeByValue(const chainLine chainline, void *data){
    
    node *newNode = NULL;
    
    for (node *arm=chainline.head;arm!=NULL; arm=arm->nextNode) {
        if (arm->data==data) {
            newNode = arm;
            break;
        }
    }
    
    if (newNode==NULL) {
        addError(0, "未找到节点");
    }
    
    return newNode;
}


/**
 0.3.1 chainline search before node by Value
 在链表中查找并返回指定值之前的节点

 @param chainline 查找的链表
 @param data 查找的数据
 @return 返回查找到的节点，未找到或数据在头结点中时返回NULL
 */
node *clScNodeBeforeValue(const chainLine chainline, void *data){
    
    node *newNode = NULL;
    
    if (chainline.length==0) {
        return NULL;
    }
    
    for (node *arm=chainline.head; arm->nextNode!=NULL;arm = arm->nextNode) {
        if (arm->nextNode->data==data) {
            newNode = arm;
            break;
        }
    }
    
    return newNode;
}



