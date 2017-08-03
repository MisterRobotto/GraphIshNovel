/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.h
 * Author: ConnorFlynn
 *
 * Created on July 28, 2017, 2:04 PM
 */

#ifndef INODE_H
#define INODE_H

#include <string>

class INode {
public:
    virtual ~INode(){};
    virtual void Run() = 0;
protected:
    std::string m_id;
};

#endif /* INODE_H */

