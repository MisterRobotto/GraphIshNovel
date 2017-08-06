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

#include <string>
#include <vector>
#include <map>

#include "TypeEnums.cpp"

class Driver {
public:
    Driver();
    Driver(const Driver& orig);
    virtual ~Driver();
    
    void AddDriver(std::vector<std::vector<std::string>> line_args);
private:
    bool m_main_driver;
    std::vector<std::string> m_include;
    // [TODO] second value in map should be variable type, once that's made
    std::map<std::string,std::string> m_vars;
    int m_driver_count;
    std::string m_start;
};

#endif /* DRIVER_H */

