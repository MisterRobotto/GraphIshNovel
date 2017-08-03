/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Driver.h
 * Author: ConnorFlynn
 *
 * Created on July 31, 2017, 1:20 PM
 */

#ifndef DRIVER_H
#define DRIVER_H

// [TODO]: Most of this ish

class Driver {
public:
    Driver();
    Driver(const Driver& orig);
    virtual ~Driver();
    
    bool IsMainDriver();
private:
    bool m_main_driver;

};

#endif /* DRIVER_H */

