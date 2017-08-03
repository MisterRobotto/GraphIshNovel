/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: ConnorFlynn
 *
 * Created on July 28, 2017, 2:09 PM
 */

#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>

class Menu {
public:
    Menu(std::vector<std::string> lines);
    Menu(const Menu& orig);
    virtual ~Menu();
private:

};

#endif /* MENU_H */

