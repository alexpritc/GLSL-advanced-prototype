#include "Model.h"

Model::Model()
{
}


void Model::loadFromFile(const char* objPath, const char* mtlPath) {

    mesh = loadOBJ(objPath, mtlPath);
    std::string path;

    // Load in all indices
    for (size_t i = 0; i < mesh.size(); ++i)
    {
        vertices.push_back(mesh[i].position);
        uvs.push_back(mesh[i].texcoord);
        normals.push_back(mesh[i].normal);

        ambients.push_back(mesh[i].material.ambientColour);
        diffuses.push_back(mesh[i].material.diffuseColour);
        speculars.push_back(mesh[i].material.specularColour);

        dissolves.push_back(mesh[i].material.dissolve);
    }

    // OBj info 
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, (vertices.size()) * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);

    glGenBuffers(1, &uvbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);

    glGenBuffers(1, &normalbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

    // MTL info
    glGenBuffers(1, &ambientbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, ambientbuffer);
    glBufferData(GL_ARRAY_BUFFER, ambients.size() * sizeof(glm::vec3), &ambients[0], GL_STATIC_DRAW);

    glGenBuffers(1, &diffusebuffer);
    glBindBuffer(GL_ARRAY_BUFFER, diffusebuffer);
    glBufferData(GL_ARRAY_BUFFER, diffuses.size() * sizeof(glm::vec3), &diffuses[0], GL_STATIC_DRAW);

    glGenBuffers(1, &specularbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, specularbuffer);
    glBufferData(GL_ARRAY_BUFFER, speculars.size() * sizeof(glm::vec3), &speculars[0], GL_STATIC_DRAW);

    glGenBuffers(1, &dissolvebuffer);
    glBindBuffer(GL_ARRAY_BUFFER, dissolvebuffer);
    glBufferData(GL_ARRAY_BUFFER, dissolves.size() * sizeof(float), &dissolves[0], GL_STATIC_DRAW);
}

void Model::draw() {

    // Enable the vertex, uv, normal buffers, and lighting buffers.
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(2);
    glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(3);
    glBindBuffer(GL_ARRAY_BUFFER, ambientbuffer);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(4);
    glBindBuffer(GL_ARRAY_BUFFER, diffusebuffer);
    glVertexAttribPointer(4, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(5);
    glBindBuffer(GL_ARRAY_BUFFER, specularbuffer);
    glVertexAttribPointer(5, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

    glEnableVertexAttribArray(6);
    glBindBuffer(GL_ARRAY_BUFFER, dissolvebuffer);
    glVertexAttribPointer(6, 1, GL_FLOAT, GL_FALSE, 0, (void*)0);

    // Pass the texture to the shader.
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturebuffer);
    glUniform1i(texturebuffer, 0);

    glDrawArraysInstanced(GL_TRIANGLES, 0, vertices.size(), 100);

    // Disable the arrays so the next draw call can be made.
    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
    glDisableVertexAttribArray(2);
    glDisableVertexAttribArray(3);
    glDisableVertexAttribArray(4);
    glDisableVertexAttribArray(5);
    glDisableVertexAttribArray(6);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Model::loadTextureFromFile(const char* filePath) {
    if (strcmp(filePath, "") != 0) {
        printf("Loading Image %s...", filePath);
        GLint programID = getProgramID();
        glGenTextures(1, &texturebuffer);
        int width, height, comp;
        unsigned char* image = stbi_load(filePath, &width, &height, &comp, STBI_rgb_alpha);
        if (image == nullptr) {
            printf("Failed. Image wasn't able to load.\n");
        }
        else {
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, texturebuffer);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
            stbi_image_free(image);
            glUniform1i(glGetUniformLocation(programID, "ourTexture"), 0);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            printf("Done\n");
        }
    }
}