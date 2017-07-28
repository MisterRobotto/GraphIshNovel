/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: ConnorFlynn
 *
 * Created on July 16, 2017, 4:23 PM
 */

#include "GinManager.h"

#include <cstdlib>
#include <iostream>
#include <string>

std::string VERSION = "0.1.1";
std::string PATH = "C:\\Users\\ConnorFlynn\\Documents\\NetBeansProjects\\GraphIshNovel\\FileTests\\tst_Directory.gnd";

/*
 * 
 */
int main(int argc, char** argv)
{
    // Opening thingy
    std::cout << "GIN Development Version " << VERSION
            << "\n----------\n\n" << std::endl;
    
    // Load stuff
    std::cout << "Loading..." << std::endl;
    GinManager manager(PATH);
    
    return 0;
}

