#include "Points.h"

Points::Points()
{
}

void Points::init() 
{
    srand((unsigned int)time(0));

    // Flower positions

    //numPoints = 100;
    //points = new float[numPoints * 3];

    //for (int i = 0; i < numPoints; i++) {

    //    glm::vec2 p(((float)rand() / RAND_MAX * 10.0f) - 1.0f,
    //        ((float)rand() / RAND_MAX * 10.0f) - 1.0f);

    //    points[i * 3] = p.x;
    //    points[i * 3 + 1] = p.y;
    //    points[i * 3 + 2] = 0.0f;
    //}

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
   float points[] = {
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
                GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
            GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                GetRandomNumber(), 0.0f, GetRandomNumber(),
                        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
        GetRandomNumber(),  0.0f, GetRandomNumber(),
    };

    //unsigned int VBO, VAO;
    glGenBuffers(1, &VBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(points), &points, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    glBindVertexArray(0);
}

float Points::GetRandomNumber() {

    return -100.0f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (100.0f - -100.0f)));
}

void Points::draw()
{
    //glGenBuffers(1, &VBO);
    //glGenVertexArrays(1, &VAO);
    //glBindVertexArray(VAO);
    //glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //glBufferData(GL_ARRAY_BUFFER, sizeof(points), &points, GL_STATIC_DRAW);
    //// Points
    //glEnableVertexAttribArray(0);
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    //// Colours
    //glEnableVertexAttribArray(1);
    //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(2 * sizeof(float)));
    //glBindVertexArray(0);

    // Pass the texture to the shader.
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texturebuffer);
    glUniform1i(texturebuffer, 0);

    glBindVertexArray(VAO);
    glEnable(GL_PROGRAM_POINT_SIZE);
    glPointSize(10);
    glDrawArrays(GL_POINTS, 0, numPoints);
}

void Points::loadTextureFromFile(const char* filePath) {
    if (strcmp(filePath, "") != 0) {
        stbi_set_flip_vertically_on_load(1);
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