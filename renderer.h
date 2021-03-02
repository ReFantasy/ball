#ifndef _RENDERER_H__
#define _RENDERER_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include "Utils.h"
#include "eigen3/Eigen/Dense"

#define numVAOs 1
#define numVBOs 3

void init(GLFWwindow* window);
void display(GLFWwindow* window, double currentTime, Eigen::Vector3f x);
void window_size_callback(GLFWwindow* win, int newWidth, int newHeight);

#endif

