/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.cpp
 * Author: ConnorFlynn
 * 
 * Created on July 21, 2017, 9:55 PM
 */

#include "Character.h"

/*
 * Name: Character( vector < string > )
 * Desc: Loads Character object from state defined by a file
 * Prec: Bugswept vector of lines (vector of arguments) from a character
 *      .GNF file
 * Post: Creates the Character object
 */
Character::Character(std::vector<std::vector<std::string>> line_args)
{
    // Preset data to empty
    m_short = "";
    m_prefer = "";
    m_short = "";
    m_color = "";
}

Character::Character(const Character& orig) {
}

Character::~Character() {
}

/*
 * Name: Say
 * Desc: Formats a given string into a defined output style
 * Prec: A string to format and the name of the style to put it in
 * Post: The formatted string
 */
std::string Character::Say(const std::string style, const std::string input)
{
    std::string outString = m_say_styles[style];
    outString.replace(outString.find("{...}"),5,input);
    return outString;
}