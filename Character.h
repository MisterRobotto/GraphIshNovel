/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: ConnorFlynn
 *
 * Created on July 21, 2017, 9:55 PM
 */

#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>
#include <string>
#include <vector>
#include <regex>

#include "Exceptions.cpp"

class Character {
public:
    Character(std::vector<std::vector<std::string>> line_args);
    Character(const Character& orig);
    virtual ~Character();
    std::string Say(const std::string style, const std::string input);
private:
    std::string m_name;
    std::string m_prefer;
    std::string m_short;
    std::string m_color;
    std::map<std::string,std::string> m_images;
    std::map<std::string,std::string> m_say_styles;
    
    bool IsHex(std::string input);
};

#endif /* CHARACTER_H */

