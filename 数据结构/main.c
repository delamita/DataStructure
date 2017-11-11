//
//  main.c
//  数据结构
//
//  Created by 费克翔 on 2017/11/9.
//  Copyright © 2017年 LCC. All rights reserved.
//


#include "mainHead.h"

Error error;

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    chainLine cl = clInit();
    
    int a= 6;
    char s = 's';
    
    clAddNodeTo(&cl, (void *)3, Int);
    clAddNodeTo(&cl, (void *)'c', Char);
    clAddNodeTo(&cl, "3", String);
    clAddNodeTo(&cl, "4", String);
    clAddNodeTo(&cl, &a, pInt);
    clAddNodeTo(&cl, &a, p);
    clAddNodeTo(&cl, &s, pChar);
    
    ptChainLine(cl);
    
    node *arm;
    
    arm =  clScNodeBeforeValue( cl, "4");
    
    clRemoveByValue(&cl, &a);
    clRemoveByValue(&cl, &a);
    
    ptChainLine(cl);
    
    return 0;
}
