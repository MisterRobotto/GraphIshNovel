/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GinManager.h
 * Author: ConnorFlynn
 *
 * Created on July 16, 2017, 10:09 PM
 */

#ifndef GINMANAGER_H
#define GINMANAGER_H

#include "Exceptions.cpp"

#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <regex>

class GinManager {
public:
    GinManager(const std::string input);
    GinManager(const GinManager& orig);
    virtual ~GinManager();
protected:
    // Object Types
    std::vector<std::string> m_object_types;
    std::regex m_object_types_regex;
    // Character Prefixes
    std::vector<std::string> m_char_prefixes;
    std::regex m_char_prefixes_regex;
    
    /*
     * TODO: See issue #1
     * 
    // Variable Types
    std::vector<std::string> m_var_types;
    std::regex m_var_types_regex;
    // Global Variables -- from driver
    // TODO: be able to differentiate variable types in m_global_vars
    std::map<std::string,std::string> m_global_vars;
    std::regex m_global_vars_regex;
     */
    
    // All Valid Prefixes
    std::regex m_all_prefixes_regex;
private:
    void LoadSettings();
    std::string LoadFile(const std::string file) throw();
    void LoadDirectory(const std::string path);
    std::string m_driver;
    bool HasArgs(std::string line, int arg_num);
    std::regex MakeRegex(std::vector<std::string> vec);
};

#endif /* GINMANAGER_H */

