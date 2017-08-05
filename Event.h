/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.h
 * Author: ConnorFlynn
 *
 * Created on July 16, 2017, 7:25 PM
 */

#ifndef EVENT_H
#define EVENT_H

#include "Flow.h"

#include <map>
#include <string>
#include <vector>

class Event {
public:
    Event();
    Event(std::vector<std::vector<std::string>> line_args);
    Event(const Event& orig);
    virtual ~Event();
    virtual void Run();
protected:
    void Clear_Flows();
    void Run_Main();
    std::map<std::string,std::string> m_vars;
private:
    std::map<std::string,Flow*> m_flows;
    std::string m_start_flow;
};

#endif /* EVENT_H */

