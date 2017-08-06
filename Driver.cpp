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

/*
 * Name: Driver
 * Desc: Default constructor
 * Prec: None
 * Post: Creates a default empty Driver object
 */
Driver::Driver()
{
    m_main_driver = false;
    m_start = "";
}

Driver::Driver(const Driver& orig) {
}

Driver::~Driver() {
}

/*
 * Name: AddDriver
 * Desc: Adds a new driver from a file
 * Prec: Bugswept vector of lines (vector of arguments) from a driver
 *      .GNF file
 * Post: Adds the driver file to the driver
 */
void Driver::AddDriver(std::vector<std::vector<std::string>> line_args)
{
    int c = 0;
    
    // Go through all the lines
    for(std::vector<std::vector<std::string>>::iterator it = line_args.begin();
            it != line_args.end(); ++it)
    {
        // Set the current driver as not the main driver, unless it's the
        //      first driver
        bool curr_main_driver = (m_driver_count == 0);
        
        // Iterate the counter
        c++;
        
        std::vector<std::string> line = *it;
        std::string prefix = line.at(0);
        
        // If prefix is "MAIN_DRIVER"
        if (prefix == "MAIN_DRIVER")
        {
            // If main driver is already set, throw error
            if(m_main_driver)
            {
                throw std::pair<std::string,int>(std::string("Main driver"),c);
            }
            else
            {
                // Clear previous settings
                m_include.clear();
                m_start = "";
                // Set m_main_driver and curr_main_driver to true
                m_main_driver = true;
                curr_main_driver = true;
            }
        }
        
        // If prefix is "start" and current driver is the main driver
        else if(prefix == "start" && curr_main_driver)
        {
            // If start is not set, set it
            if(m_start == "")
            {
                m_start = line.at(1);
            }
            // Otherwise, pass up a DoubleDef_Error
            else
            {
                throw std::pair<std::string,int>(std::string("Start node"),c);
            }
        }
        
        // [TODO] "include" and "vars", once collections are figured out
    }
}