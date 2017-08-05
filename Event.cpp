/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Event.cpp
 * Author: ConnorFlynn
 * 
 * Created on July 16, 2017, 7:25 PM
 */

#include "Event.h"

Event::Event()
{
    
}

/*
 * Name: Event()
 * Desc: Default constructor
 * Prec: None
 * Post: Creates Event object
 */
Event::Event(std::vector<std::vector<std::string>> line_args)
{
    
}

Event::Event(const Event& orig)
{
    
}

/*
 * Name: Clear_Flows()
 * Desc: Frees all memory in use by the contents of m_flows
 * Prec: Existing Event object
 * Post: m_flows is empty and all memory has been freed
 */
void Event::Clear_Flows()
{
    // Delete all flows whose pointers are stored in m_flows vector
    for(std::map<std::string,Flow*>::iterator it = m_flows.begin(); it != m_flows.end(); ++it)
    {
        delete((*it).second);
    }
    
    // Clear m_flows just to be careful
    m_flows.clear();
}

Event::~Event()
{
    Clear_Flows();
}

/*
 * Name: Run()
 * Desc: Virtual method for running the event's contents
 *       In this case, runs Run_Main() as only subclasses have other pre-actions
 * Prec: Loaded Event object
 * Post: Calls Run_Main()
 */
void Event::Run()
{
    Run_Main();
}

/*
 * Name: Run_Main()
 * Desc: Main thrust of running an event, shared by all subclasses
 * Prec: Loaded Event object or subclass, called from Run()
 * Post: start_flow is begun
 */
void Event::Run_Main()
{
    
}