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

// Utility files
#include "Exceptions.cpp"
#include "TypeEnums.cpp"

// Object classes
#include "Character.h"
#include "Driver.h"
#include "Event.h"
#include "Location.h"
#include "Menu.h"
#include "Scene.h"


// Standard library
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <regex>
#include <tuple>

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
    // Location Prefixes
    std::vector<std::string> m_loc_prefixes;
    std::regex m_loc_prefixes_regex;
    // Scene Prefixes
    std::vector<std::string> m_scne_prefixes;
    std::regex m_scne_prefixes_regex;
    // Menu Prefixes
    std::vector<std::string> m_menu_prefixes;
    std::regex m_menu_prefixes_regex;
    // Driver Prefixes
    std::vector<std::string> m_drvr_prefixes;
    std::regex m_drvr_prefixes_regex;
    
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
    
    // "Collection" types
    std::vector<std::string> m_collections;
    std::regex m_collections_regex;
    
    // Validate number of arguments
    std::map<std::string,int> m_arg_count;
    
    // Check for colons at the end
    std::vector<std::string> m_colon_check;
    std::regex m_colon_check_regex;
private:
    // Functions
    void LoadSettings();
    void LoadFile(const std::string file) throw();
    void LoadDirectory(const std::string path);
    bool HasArgs(std::string line, int arg_num);
    std::vector<std::string> GetArgs(std::string line);
    std::regex MakeRegex(std::vector<std::string> vec);
    
    // The driver
    Driver m_driver;
    
    // Catalog of all objects and their types, mapped <id, type>
    std::map<std::string,ObjectType> m_objects;
    
    // Catalogs of each type of objects, mapped <id, object>
    std::map<std::string,Character*> m_characters;
    std::map<std::string,Event*> m_events;
    std::map<std::string, Location*> m_locations;
    std::map<std::string, Menu*> m_menus;
    std::map<std::string, Scene*> m_scenes;
};

#endif /* GINMANAGER_H */

