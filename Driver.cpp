/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Driver.cpp
 * Author: ConnorFlynn
 * 
 * Created on July 31, 2017, 1:20 PM
 */

#include "Driver.h"

Driver::Driver() {
}

Driver::Driver(const Driver& orig) {
}

Driver::~Driver() {
}


/*
 * Name: IsMainDriver
 * Desc: Returns whether or not the driver object is declared as the main driver
 * Prec: None
 * Post: Returns m_main_driver
 */
bool Driver::IsMainDriver()
{
    return m_main_driver;
}