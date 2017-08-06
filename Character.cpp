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
    m_name = "";
    m_prefer = "";
    m_short = "";
    m_color = "";
    
    int c = 0;
    std::string prefix;
    // Go through all the lines
    for(std::vector<std::vector<std::string>>::iterator it = line_args.begin();
            it != line_args.end(); ++it)
    {
        // Iterate the counter
        c++;
        
        std::vector<std::string> line = *it;
        prefix = line.at(0);
        
        // If prefix is "name"
        if(prefix == "name")
        {
            // If m_short isn't set, set it
            if(m_name == "")
            {
                m_name = line.at(1);
            }
            // Otherwise, pass up a DoubleDef_Error
            else
            {
                throw std::pair<std::string, int>(std::string("Name"),c);
            }
        }
        
        // If prefix is "prefer"
        else if(prefix == "prefer")
        {
            // If m_prefer isn't set, set it
            if(m_prefer == "")
            {
                m_prefer = line.at(1);
            }
            // Otherwise, pass up a DoubleDef_Error
            else
            {
                throw std::pair<std::string, int>(std::string("Preferred name"),
                        c);
            }
        }
        
        // If prefix is "short"
        else if (prefix == "short")
        {            
            // If m_short isn't set, set it
            if (m_short == "")
            {
                m_short = line.at(1);
            }
            // Otherwise, pass up a DoubleDef_Error
            else
            {
                throw std::pair<std::string, int>(std::string("Short name"), c);
            }
        }
        
        // If prefix is "color"
        else if (prefix == "color")
        {
            // If m_color isn't set...
            if (m_color == "")
            {
                // If color is valid 
                if(IsHex(line.at(1)))
                {
                    m_color = line.at(1);
                }
                // Otherwise, throw an error [TODO] make the error
                else
                {
                    throw std::string("NOT A HEXADECIMAL");
                }
            }
        }
        
        // If prefix is "say"
        else if (prefix == "say")
        {
            // If m_say_styles doesn't contain a style with that ID, add it
            if(m_say_styles.count(line.at(1)) == 0)
            {
                m_say_styles[line.at(1)] = line.at(2);
            }
            // Otherwise, pass up a DoubleDef_Error
            else
            {
                throw std::pair<std::string, int>(std::string("Say style \""
                        + line.at(1) + "\""),c);
            }
        }
        
        // If prefix is "image"
        else if (prefix == "image")
        {
            // If m_say_styles doesn't contain a style with that ID, add it
            if(m_images.count(line.at(1)) == 0)
            {
                // [TODO] Check if image is valid
                m_images[line.at(1)] = line.at(2);
            }
            // Otherwise, pass up a DoubleDef_Error
            else
            {
                throw std::pair<std::string, int>(std::string("Image \""
                        + line.at(1) + "\""),c);
            }
        }
    }
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


/*
 * Name: IsHex
 * Desc: Returns whether a string is hexadecimal
 * Prec: A string
 * Post: Outputs true if string is hexadecimal, false otherwise
 */
bool Character::IsHex(std::string input)
{
    std::regex hex_rgx(std::string("[A-Fa-f0-9]"));
    bool output = true;
    // For every character
    for(std::string::iterator it = input.begin(); it != input.end(); ++it)
    {
        // If the character doesn't match the hexadecimal regex, set output to
        //      false
        std::string currChar(1,*it);
        if(!std::regex_match(currChar,hex_rgx))
            output = false;
    }
    // If any wasn't hexadecimal, output was changed to false
    //      otherwise, it stayed true
    return output;
}