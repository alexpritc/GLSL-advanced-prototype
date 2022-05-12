#include "Points.h"

Points::Points()
{
}

void Points::init() 
{
    // Snowflakes
    srand((unsigned int)time(0));

    for (int i = 0; i < _numSprites; i++)
    {
        glm::vec3 p(((float)rand() / RAND_MAX * 2.0f) - 1.0f,
            ((float)rand() / RAND_MAX * 2.0f) - 1.0f,
            ((float)rand() / RAND_MAX * 2.0f) - 1.0f);

        vertices[i * 3] = p.x;
        vertices[i * 3 + 1] = p.y;
        vertices[i * 3 + 2] = p.z;
    }

    glGenBuffers(1, &spritebuffer);
    glBindBuffer(GL_ARRAY_BUFFER, spritebuffer);
    glBufferData(GL_ARRAY_BUFFER, _numSprites * 3 * sizeof(float), vertices, GL_STATIC_DRAW);

    delete[] vertices;

    glGenVertexArrays(1, &_sprites);
    glBindVertexArray(_sprites);

    glBindBuffer(GL_ARRAY_BUFFER, spritebuffer);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, ((GLubyte*)NULL + (0)));

    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

void Points::draw()
{
    glBindVertexArray(_sprites);
    glDrawArrays(GL_POINTS, 0, _numSprites);

    // Pass the texture to the shader.
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturebuffer);
    glUniform1i(texturebuffer, 0);

    glFinish();

    // Disable the arrays so the next draw call can be made.
    glDisableVertexAttribArray(0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void Points::loadTextureFromFile(const char* filePath) {
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