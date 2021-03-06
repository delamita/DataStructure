//
//  chainLine.c
//  数据结构
//
//  Created by 费克翔 on 2017/11/9.
//  Copyright © 2017年 LCC. All rights reserved.
//

#include "chainLine.h"




/**     0.0.1
 chainLineInit
 初始化并返回一个为空的链表
 
 @return 空链表
 */
chainLine clInit(){
    
    chainLine cl;
    cl.length = 0;
    cl.head = NULL;
    cl.lastNode = NULL;
    cl.isSameType = true;
    cl.dataType = Void;

    return cl;
}




/**     0.0.2
 chainLine Add newNode
 向目标链表添加节点
 
 @param chainline 添加的目标链表
 @param data 新添加节点的数据
 @param dataType 新添加节点数据的类型
 @return 修改后的链表
 */
chainLine clAddNodeT(chainLine *chainline,void *data,type dataType){
    
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
    
    if (chainline->dataType==Void) {
        chainline->dataType=newNode->dataType;
    }
    else if (chainline->dataType!=newNode->dataType) {
        chainline->dataType = Multiple;
        chainline->isSameType = false;
    }
    
    chainline->lastNode = newNode;
    chainline->length += 1;
    
    return *chainline;
}




/**     0.0.3
 chainline is Same type check
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
        chainline->dataType = chainline->head->dataType;
        chainline->isSameType = true;
    }
    else{
        chainline->dataType = Multiple;
        chainline->isSameType = false;
    }
    
    return chainline->isSameType;
}




/**     0.0.4)
 chainline Add newNode without same value.
 向目标链表添加节点，如果新节点的值已经存在就不再添加

 @param chainline 添加的目标链表
 @param data 新添加的数据
 @param dataType 新添加的数据类型
 @return 返回添加后的链表
 */
chainLine clAddNodeWithoutSame(chainLine *chainline, void *data, type dataType) {
    
    if (clSearchNodeByValueAndType(*chainline, data, dataType)==NULL) {
        clAddNodeT(chainline, data, dataType);
    }
    
    return *chainline;
}




/** cl.0.0.5)
 chainline Add newNode without dataType
 向目标链表添加没有数据类型的节点，新节点的数据类型与链表的数据类型相同
 
 @param chainline 添加的目标链表
 @param data 新添加数据
 @return 返回添加后的链表
 */
chainLine clAddNod(chainLine *chainline, void *data){
    
    if (chainline->isSameType != true) {
        //addError(0, "无法添加，目标链表的数据类型为多种");
        return *chainline;
    }
    
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    
    newNode->data = data;
    newNode->nextNode = NULL;
    newNode->dataType = chainline->dataType;
    
    if (chainline->length==0) {
        chainline->head = newNode;
    }
    else{
        chainline->lastNode->nextNode = newNode;
    }
    
    chainline->lastNode = newNode;
    chainline->length += 1;
    
    return *chainline;
}





/**     0.1.0
 chainLinePrint
 打印一个链表

 @param chainline 需要打印的链表
 @return 返回打印是否成功
 */
int ptChainLine(const chainLine chainline){
    
    char *type = "Void";
    
    switch (chainline.dataType) {
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
    

    printf("[ {length: %d, dataType: %s} :",chainline.length,type);
    
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
    
    printf(" ]\n");
    
    
    return FINE;
}




/**     0.1.1
 chainLineInitByValueForLength
 初始化并返回一个固定长度和默认值的链表

 @param lenght 默认长度
 @param data 默认值
 @return 初始化完成的链表
 */
chainLine clInitByValuefor(int lenght, void *data, type dataType){
    
    chainLine cl = clInit();
    
    for (int i=0; i<lenght; i++) {
        clAddNodeT(&cl, data, dataType);
    }

    return cl;
}




/** 0.2.1
 chainline RemoveAll Node
 删除链表的所有节点

 @param chainline 删除的目标链表
 @return 返回删除后的链表
 */
chainLine clRemoveAll(chainLine *chainline){

    chainline->head = NULL;
    chainline->dataType = Void;
    chainline->isSameType = true;
    chainline->lastNode = NULL;
    chainline->length = 0;
    
    return *chainline;
    
}




/**     0.2.2
 chainLine remove index node
 删除指定位置的节点

 @param chainline 需要操作的链表
 @param index 指定的位置
 @return 返回删除后的链表
 */
chainLine clReomoveIndex(chainLine *chainline,int index){
    
    if (index>=chainline->length) {
        //addError(0, "范围超出链表");
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




/**     0.2.3
 chainLine RemoveByValue
 删除指定值的节点，如有多个删除第一个找到的

 @param chainline 需要操作的链表
 @param data 删除的数据
 @return 返回被删除的节点指针
 */
node *clRemoveByValue(chainLine *chainline, void *data){
    
    node *newNode = NULL;
    
    node *bfNode = clScNodeBeforeValue(*chainline, data);
    
    if (bfNode!=NULL) {
        
        bfNode->nextNode = bfNode->nextNode->nextNode;
        chainline->length -= 1;
        
        if (chainline->isSameType!=true){
            clisSameTypeCheck(chainline);
        }
        
    }
    else{
        if (chainline->head!=NULL) {
            if (chainline->head->data==data) {
                clReomoveIndex(chainline, 0);
            }
        }
    }
 
    return newNode;
    
}




/**     0.3.0
 chainline search node by Value
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
        //addError(0, "未找到节点");
    }
    
    return newNode;
}



/**     0.3.0.1
 chainline search node by value and dataType
 再链表中查找并返回指定值和值类型的节点

 @param chainline 查找的链表
 @param data 查找的数据
 @param dataType 查找的数据类型
 @return 返回查找到的节点，未找到返回NULL
 */
node *clSearchNodeByValueAndType(const chainLine chainline, void *data, type dataType){
    
    node *newNode = NULL;
    
    for (node *arm=chainline.head;arm!=NULL; arm=arm->nextNode) {
        if (arm->data==data) {
            
            if (arm->dataType==dataType) {
                newNode = arm;
                break;
            }
        }
    }
    
    if (newNode==NULL) {
        //addError(0, "未找到节点");
    }
    
    return newNode;
}




/**     0.3.1
 chainline search before node by Value
 在链表中查找并返回指定值之前的节点
 注意:当指定值在头节点中时返回为NULL，所以使用时一定要对是否在头结点中进行单独检验。

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




/**     0.4.0
 chainline conect
 直接连接两个链表，并把尾链表初始化

 @param headchainline 连接的头链表
 @param taicChainline 连接的尾链表
 @return 连接后的链表
 */
chainLine clconect(chainLine *headchainline, chainLine *taicChainline) {
    
    headchainline->lastNode->nextNode = taicChainline->head;
    headchainline->lastNode = taicChainline->lastNode;
    headchainline->length += taicChainline->length;
    
    clisSameTypeCheck(headchainline);
    
    clRemoveAll(taicChainline);
    
    return *headchainline;
}

