/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Location.h
 * Author: ConnorFlynn
 *
 * Created on July 17, 2017, 11:38 PM
 */

#ifndef LOCATION_H
#define LOCATION_H

#include <vector>
#include <string>

class Location {
public:
    Location(std::vector<std::vector<std::string>> line_args);
    Location(const Location& orig);
    virtual ~Location();
private:

};

#endif /* LOCATION_H */

