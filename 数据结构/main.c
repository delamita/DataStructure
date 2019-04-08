//
//  main.c
//  数据结构
//
//  Created by 费克翔 on 2017/11/9.
//  Copyright © 2017年 LCC. All rights reserved.
//


#include "common.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    chainLine cl = clInit();
    
    int a= 6;
    char s = 's';
    
    clAddNodeT(&cl, (void *)3, Int);
    clAddNodeT(&cl, (void *)'c', Char);
    clAddNodeT(&cl, "3", String);
    clAddNodeT(&cl, "4", String);
    clAddNodeT(&cl, &a, pInt);
    clAddNodeT(&cl, &s, pChar);
    
    ptChainLine(cl);
    
    chainLine ch = clInitByValuefor(5, (void *)6, Int);
    
    ptChainLine(ch);
    
    clconect(&ch, &cl);
    
    ptChainLine(ch);
    
    clAddNodeWithoutSame(&ch, (void *)6, Int);
    
    ptChainLine(ch);
    
    return 0;
}



// asdadsq1111111111111111111111111111

