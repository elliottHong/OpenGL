/* Start Header -------------------------------------------------------
Copyright (C) 2021 DigiPen Institute of Technology.
Reproduction or disclosure of this file or its contents without the prior written
consent of DigiPen Institute of Technology is prohibited.
File Name: mesh.h
Purpose: This file is header for mesh.
Language: c++
Platform: VS2019 / Window
Project:  s.hong_CS300_1
Author: Elliott Hong <s.hong@digipen.edu>
Creation date: Sep 29, 2021
End Header ---------------------------------------------------------*/
#ifndef MESH_H
#define MESH_H
#include <memory>
#include <string>
#include <glad/glad.h>

#include <vector>
#include <glm/glm.hpp>

class Mesh
{
public:
    friend class OBJManager;
    Mesh();
    ~Mesh();

    // Get attribute values buffer
    GLfloat* getVertexBuffer(); // attribute 0
    GLfloat* getVertexNormals(); // attribute 1
    GLfloat* getVertexUVs(); // attribute 2

    GLfloat* getVertexNormalsForDisplay(); // attribute 0

    unsigned int getVertexBufferSize();
    unsigned int getVertexCount();
    unsigned int getVertexNormalCount();

    // Get vertex index buffer
    GLuint* getIndexBuffer();
    unsigned int getIndexBufferSize();
    unsigned int getTriangleCount();

    glm::vec3 getModelScale();
    glm::vec3 getModelCentroid();
    glm::vec3 getCentroidVector(glm::vec3 vVertex);
    float getModelScaleRatio();
    glm::vec3 getMinBound();
    glm::vec3 getMaxBound();

    virtual void render(int Flag = 0) const;
    void setupMesh();
    void setupVNormalMesh();
    void setupFNormalMesh();

    GLfloat& getNormalLength();
    void setNormalLength(GLfloat nLength);

    void clearVertexUVs();

    // initialize the data members
    void initData();

    // calculate vertex normals
    int calcVertexNormals(GLboolean bFlipNormals = false);

    // calculate the "display" normals
    void calcVertexNormalsForDisplay();

    // calculate texture coordinates
    enum class UVType
    {
        PLANAR_UV = 0,
        CYLINDRICAL_UV,
        SPHERICAL_UV,
        CUBE_MAPPED_UV
    };

    int calcUVs(UVType uvType = UVType::PLANAR_UV, bool posEntity = true);
    glm::vec2 calcCubeMap(glm::vec3 vEntity);

private:
    GLuint VAO;
    GLuint vnormalVAO;
    GLuint fnormalVAO;

    GLuint vertexCount;
    GLuint faceCount;

    GLuint VBO_pos;
    GLuint VBO_norm;
    GLuint VBO_uv;


    GLuint EBO;

    std::vector<glm::vec3> faceCentroid;

    std::vector<GLuint> vertexIndices;
    std::vector<glm::vec3> vertexBuffer;
    std::vector<glm::vec2> vertexUVs;
    std::vector<glm::vec3> vertexNormals, vertexNormalDisplay;

    glm::vec3 boundingBox[2];
    GLfloat normalLength;
};

#endif
