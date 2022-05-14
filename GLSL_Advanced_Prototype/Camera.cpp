// GLFW
#include <GLFW/glfw3.h>

// GLM
#include <glm/gtc/matrix_transform.hpp>

// Project
#include "Camera.h"

Camera::Camera() {};

Camera::Camera(const glm::vec3& position, const glm::vec3& upVector)
{
    _position = position;
    _upVector = upVector;
}

// Setters
void Camera::setMoveSpeed(float moveSpeed)
{
    _moveSpeed = moveSpeed;
}

void Camera::setYaw(float yaw)
{
    _yaw = yaw;
}

void Camera::setPitch(float pitch)
{
    _pitch = pitch;
}

void Camera::setFOV(float fov)
{
    _fov = fov;
}

// Getters
glm::mat4 Camera::getViewMatrix() const
{
    return glm::lookAt(getPosition(), getPosition() + getFrontVector(), getUpVector());
}

glm::mat4 Camera::getProjectionMatrix() const
{
    return  glm::perspective(glm::radians(getFOV()), 800.0f / 600.0f, 0.1f, 1000.0f);
}

glm::vec3 Camera::getPosition() const
{
    return _position;
}

glm::vec3 Camera::getUpVector() const
{
    return _upVector;
}

glm::vec3 Camera::getFrontVector() const
{
    return _frontVector;
}

float Camera::getFOV() const
{
    return _fov;
}

void Camera::processInput(GLFWwindow* window, float deltaTime)
{
    float cameraSpeed = _moveSpeed * deltaTime;

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
        _position += cameraSpeed * _frontVector;
    }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
        _position -= cameraSpeed * _frontVector;
    }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
        _position -= glm::normalize(glm::cross(_frontVector, _upVector)) *
            cameraSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
        _position += glm::normalize(glm::cross(_frontVector, _upVector)) *
            cameraSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
        _position += glm::vec3(0.0f, 1.0f, 0.0f) *
            cameraSpeed;
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
        _position -= glm::vec3(0.0f, 1.0f, 0.0f) *
            cameraSpeed;
    }


    // Limit the player's position to the island
    if (_position.x > 115.0f) {
        _position.x = 115.0f;
    }
    else if (_position.x < -115.0f) {
        _position.x = -115.0f;
    }

    if (_position.z > 115.0f) {
        _position.z = 115.0f;
    }
    else if (_position.z < -115.0f) {
        _position.z = -115.0f;
    }

    // Limit the player's y so they're always on the floor
   _position.y = 4.5f;

    glm::vec3 direction;

    direction.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
    direction.y = sin(glm::radians(_pitch));
    direction.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));

    _frontVector = glm::normalize(direction);
}
