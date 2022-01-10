//
//  DigitalArche2.cpp
//  DigitalArche2
//
//  Created by 杨丰 on 2022/1/10.
//

#include <iostream>
#include "DigitalArche2.hpp"
#include "DigitalArche2Priv.hpp"

void DigitalArche2::HelloWorld(const char * s)
{
    DigitalArche2Priv *theObj = new DigitalArche2Priv;
    theObj->HelloWorldPriv(s);
    delete theObj;
};

void DigitalArche2Priv::HelloWorldPriv(const char * s) 
{
    std::cout << s << std::endl;
};

