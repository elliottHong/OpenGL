/* Start Header -------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior written
consent of DigiPen Institute of Technology is prohibited.
File Name: scene.cpp
Purpose: This file is parent class for scenes.
Language: c++
Platform: VS2019 / Window
Project:  HGraphics
Author: Elliott Hong <s.hong@digipen.edu>
Creation date: Sep 29, 2021
End Header ---------------------------------------------------------*/
#include "scene.h"

#include "OBJManager.h"

Scene::Scene()
{
    window_width_ = 1280;
    window_height_ = 720;
}

Scene::Scene(int windowWidth, int windowHeight)
{
    window_height_ = windowHeight;
    window_width_ = windowWidth;
}

Scene::~Scene()
{
    CleanUp();
}

void Scene::LoadAllModels()
{
    OBJ_MANAGER->loadOBJFile("../assets/models/quad.obj", "quad", false, Mesh::UVType::PLANAR_UV);
    OBJ_MANAGER->loadOBJFile("../assets/models/sponza.obj", "sponza", true, Mesh::UVType::PLANAR_UV);

    //OBJ_MANAGER->ReadSectionFile("models/Power_Plant_Files/Section1.txt");

    /*OBJ_MANAGER->loadOBJFile("models/bunny_high_poly.obj", "bunny_high_poly", false, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/cube.obj", "cube", true, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/4Sphere.obj", "4Sphere", false, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/bunny.obj", "bunny", false, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/cup.obj", "cup", false, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/cube2.obj", "cube2", false, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/rhino.obj", "rhino", false, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/starwars1.obj", "starwars1", false, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/sphere.obj", "sphere", false, Mesh::UVType::CUBE_MAPPED_UV);
    OBJ_MANAGER->loadOBJFile("models/sphere_modified.obj", "sphere_modified", false, Mesh::UVType::CUBE_MAPPED_UV);*/
    OBJ_MANAGER->setupSphere("orbitSphere");
    OBJ_MANAGER->setupPlane("plane");
    OBJ_MANAGER->setupOrbitLine("orbitLine", 2.5f);
    OBJ_MANAGER->loadTexture("../assets/textures/SilkMedieval_512_albedo.png", "albedoTexture");
    //OBJ_MANAGER->loadTexture("textures/SilkMedieval_512_ao.png", "ambTexture");
    OBJ_MANAGER->loadTexture("../assets/textures/SilkMedieval_512_normal.png", "normTexture");
    OBJ_MANAGER->loadTexture("../assets/textures/grid.png", "gridTexture");
}

int Scene::Init(GLFWwindow* pWwindow)
{
    return -1;
}

void Scene::LoadAllShaders()
{
}

int Scene::Display()
{
    preRender();

    Render();

    RenderImGUI();

    postRender();

    return -1;
}

int Scene::preRender()
{
    return 0;
}

int Scene::Render()
{
    return 0;
}

int Scene::postRender()
{
    return 0;
}

void Scene::CleanUp()
{
}

void Scene::SetupImGUI(GLFWwindow* pWwindow)
{
}

int Scene::RenderImGUI()
{
    

    return -1;
}

void Scene::ProcessInput(GLFWwindow* pWwindow, double dt)
{
}

void Scene::ProcessMouseInput(GLFWwindow* pWwindow)
{
}
