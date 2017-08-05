/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scene.h
 * Author: ConnorFlynn
 *
 * Created on July 16, 2017, 7:36 PM
 */

#ifndef SCENE_H
#define SCENE_H

#include "Event.h"
#include "Location.h"

#include <vector>
#include <string>

class Scene : public Event {
public:
    Scene(std::vector<std::vector<std::string>> line_args);
    Scene(const Scene& orig);
    virtual ~Scene();
    virtual void Run();
private:
    Location * m_etting;
};

#endif /* SCENE_H */

