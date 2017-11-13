//
//  Header.h
//  数据结构
//
//  Created by 费克翔 on 2017/11/13.
//  Copyright © 2017年 LCC. All rights reserved.
//

#ifndef Header_h
#define Header_h

#define FINE 0
#define ERROR 1
#define true 1
#define false 0

typedef struct{
    int errorCode;
    char *errorDescription;
}Error;

Error error;


#endif /* Header_h */
