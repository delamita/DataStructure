//
//  mainHead.h
//  数据结构
//
//  Created by 费克翔 on 2017/11/9.
//  Copyright © 2017年 LCC. All rights reserved.
//

#ifndef mainHead_h
#define mainHead_h

#include <stdio.h>

#include "chainLine.h"

#include "stack.h"


#define FINE 0
#define ERROR 1
#define true 1
#define false 0

typedef struct{
    int errorCode;
    char *errorDescription;
}Error;

Error error;

typedef enum{
    
    Void,       //0
    Multiple,   //1
    Int,        //2
    Char,       //3
    String,     //4
    p,          //5
    pInt,       //6
    pChar,      //7
    Array       //8
    
}type;


#endif /* mainHead_h */
