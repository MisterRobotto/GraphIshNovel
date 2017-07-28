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

class Character {
public:
    Character();
    Character(const Character& orig);
    virtual ~Character();
    std::string Say(const std::string style, const std::string input);
private:
    std::string m_short;
    std::map<std::string,std::string> m_say_styles;
};

#endif /* CHARACTER_H */

