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
    std::vector<std::string> m_object_types;
private:
    void LoadSettings();
    std::string LoadFile(const std::string file);
    void LoadDirectory(const std::string path);
    std::string m_driver;
    bool HasArgs(std::string line, int arg_num);
};

#endif /* GINMANAGER_H */

