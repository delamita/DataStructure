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

    int a = 3;
    
    clAddNodeTo(&cl, &a, Int);
    clAddNodeTo(&cl, (void *)'c', Char);
    clAddNodeTo(&cl, "3", String);
    clAddNodeTo(&cl, "4", String);
    
    ptChainLine(cl);
    
    node *arm;
    
    arm =  clScNodeBeforeValue( cl, "4");
    
    return 0;
}
