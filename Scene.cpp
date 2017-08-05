/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Scene.cpp
 * Author: ConnorFlynn
 * 
 * Created on July 16, 2017, 7:36 PM
 */

#include <vector>

#include "Scene.h"

Scene::Scene(std::vector<std::vector<std::string>> line_args) {
}

Scene::Scene(const Scene& orig) {
}

Scene::~Scene() {
    Clear_Flows();
}

/*
 * Name: Run()
 * Desc: Overloaded run method, to load location before beginning running event
 * Prec: Loaded Scene object
 * Post: Loads location m_setting and calls Run_Main()
 */
void Scene::Run()
{
    // TODO: Change background and generally load location m_setting
    Run_Main();
}