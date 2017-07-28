/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flow.h
 * Author: ConnorFlynn
 *
 * Created on July 17, 2017, 9:19 PM
 */

#ifndef FLOW_H
#define FLOW_H

#include "Action.h"

#include <map>
#include <string>
#include <vector>

class Flow {
public:
    Flow();
    Flow(const Flow& orig);
    virtual ~Flow();
private:
    std::map<std::string,Action> m_actions;
};

#endif /* FLOW_H */

