/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GinObject.h
 * Author: ConnorFlynn
 *
 * Created on August 3, 2017, 3:29 PM
 */

#ifndef GINOBJECT_H
#define GINOBJECT_H

#include <string>

class IGinObject {
public:
    virtual ~IGinObject();
    std::string GetType();
protected:
    std::string m_id;
    std::string m_type;
};

#endif /* GINOBJECT_H */