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


class SphereWrapper
{
public:
	SphereWrapper()
	{
		Init();
	}

	void display(Eigen::Vector3f x)
	{
		if (!glfwWindowShouldClose(window))
		{
			::display(window, glfwGetTime(),x);
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
	}
	~SphereWrapper()
	{
		glfwDestroyWindow(window);
		glfwTerminate();
		//exit(EXIT_SUCCESS);
	}

private:
	void Init()
	{
		if (!glfwInit()) { exit(EXIT_FAILURE); }
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		window = glfwCreateWindow(600, 600, "Chapter6 - program1", NULL, NULL);
		glfwMakeContextCurrent(window);
		if (glewInit() != GLEW_OK) { exit(EXIT_FAILURE); }
		glfwSwapInterval(1);

		glfwSetWindowSizeCallback(window, window_size_callback);

		init(window);
	}

	GLFWwindow* window;
};
#endif

