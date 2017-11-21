//
//  chainLine.h
//  数据结构
//
//  Created by 费克翔 on 2017/11/9.
//  Copyright © 2017年 LCC. All rights reserved.
//

#define print(VAR) printf(#VAR)

#ifndef chainLine_h

#define chainLine_h

#include <stdlib.h>
#include <stdbool.h>

#include "mainHead.h"

typedef struct node{
    
    void *data;
    struct node *nextNode;
    type dataType;

} node;

typedef struct{
    
    int length;
    node *head;
    node *lastNode;
    bool isSameType;
    type dataType;
    
} chainLine;



/**
 0.0.1 chainLineInit
 初始化并返回一个为空的链表
 
 @return 空链表
 */
chainLine clInit(void);



/**
 0.0.2 chainLine Add newNode
 向目标链表添加节点
 
 @param data 新添加节点的数据
 @param chainline 新添加节点数据的类型
 @return 修改后的链表
 */
chainLine clAddNodeT(chainLine *chainline,void *data, type dataType);




/**
 0.0.3 chainline is Same type check
 检查链表的数据类型是否相同，并更新
 
 @param chainline 需要检查的链表
 @return 返回更新后的值
 */
bool clisSameTypeCheck(chainLine *chainline);



/**
 0.0.4 chainline Add newNode without same value
 向目标链表添加节点，如果新节点的值已经存在就不再添加
 
 @param chainline 添加的目标链表
 @param data 新添加的数据
 @param dataType 新添加的数据类型
 @return 返回添加后的链表
 */
chainLine clAddNodeWithoutSame(chainLine *chainline, void *data, type dataType);



/**
 0.1.0 chainLinePrint
 打印一个链表
 
 @param chainline 需要打印的链表
 @return 返回打印是否成功
 */
int ptChainLine(const chainLine chainline);




/**
 0.1.1 chainLineInitByValueForLength
 初始化并返回一个固定长度和默认值的链表
 
 @param lenght 默认长度
 @param data 默认值
 @return 初始化完成的链表
 */
chainLine clInitByValuefor(int lenght,void *data, type dataType);


/**
 0.2.1 chainline RemoveAll Node
 删除链表的所有节点
 
 @param chainline 删除的目标链表
 @return 返回删除后的链表
 */
chainLine clRemoveAll(chainLine *chainline);




/**
 0.2.2 chainLine remove index node
 删除指定位置的节点
 
 @param chainline 需要操作的链表
 @param index 指定的位置
 @return 返回删除后的链表
 */
chainLine clReomoveIndex(chainLine *chainline,int index);





/**
 0.2.3 chainLine RemoveByValue
 删除指定值的节点，如有多个删除第一个找到的
 
 @param chainline 需要操作的链表
 @param data 删除的数据
 @return 返回被删除的节点指针
 */
node *clRemoveByValue(chainLine *chainline, void *data);



/**
 0.3.0 chainline search node by Value
 在链表中查找并返回指定值的节点
 注意:当指定值在头节点中时返回为NULL，所以使用时一定要对是否在头结点中进行单独检验。
 
 @param chainline 查找的链表
 @param data 查找的数据
 @return 返回查找到的节点，未找到返回NULL；
 */
node *clSearchNodeByValue(const chainLine chainline, void *data);





/**
 0.3.0.1 chainline search node by value and dataType
 再链表中查找并返回指定值和值类型的节点
 
 @param chainline 查找的链表
 @param data 查找的数据
 @param dataType 查找的数据类型
 @return 返回查找到的节点，未找到返回NULL
 */
node *clSearchNodeByValueAndType(const chainLine chainline, void *data, type dataType);










/**
 0.3.1 chainline search before node by Value
 在链表中查找并返回指定值之前的节点
 
 @param chainline 查找的链表
 @param data 查找的数据
 @return 返回查找到的节点，未找到或数据在头结点中时返回NULL
 */
node *clScNodeBeforeValue(const chainLine chainline, void *data);



/**
 0.4.0 chainline conect
 直接连接两个链表，并把尾链表初始化
 
 @param headchainline 连接的头链表
 @param taicChainline 连接的尾链表
 @return 连接后的链表
 */
chainLine clconect(chainLine *headchainline, chainLine *taicChainline);



#endif /* chainLine_h */
