#pragma once

// STL
#include <functional>

// GLM
#include <glm/glm.hpp>

/**
 * Implements a camera, that can fly around the world freely.
 * It cannot rotate more than 90 degrees up / down (so it's not sutiable for space flight simulators).
 */
class Camera
{
public:

    Camera();

    Camera(const glm::vec3& position, const glm::vec3& upVector);

    /**
     * Sets movement speed of camera (how fast camera moves forward / backward and strafes left / right).
     *
     * @param moveSpeed  Movement speed (distance travelled per second)
     */
    void setMoveSpeed(float moveSpeed);

    void setYaw(float yaw);

    void setPitch(float pitch);

    void setFOV(float fov);

    /**
     * Gets the current view matrix calculated from position and viewpoint of camera.
     */
    glm::mat4 getViewMatrix() const;

    glm::mat4 getProjectionMatrix() const;
    /**
     * Gets the current eye position (camera's position).
     */
    glm::vec3 getPosition() const;

    /**
     * Gets the up vector of the camera.
     */
    glm::vec3 getUpVector() const;

    /**
    * Gets the front vector of the camera.
     */
    glm::vec3 getFrontVector() const;
    ;

    float getFOV() const;

    void processInput(GLFWwindow* window, float deltaTime);

private:

    glm::vec3 _position = glm::vec3(0.0f, 0.0f, 0.0f); // Camera's position (eye position)
    glm::vec3 _upVector = glm::vec3(0.0f, 1.0f, 0.0f); // Up vector of the camera
    glm::vec3 _frontVector = glm::vec3(0.0f, 0.0f, -1.0f); // Front vector of the camera

    float _moveSpeed = 15.0f; // Speed of camera (both for going forward / backward and for strafing left / right)

    float _yaw = -90.0f; // Yaw is initialized to -90.0 degrees since a yaw of 0.0 results in a direction vector pointing to the right so we initially rotate a bit to the left.
    float _pitch;
    float _fov = 45.0f;
};