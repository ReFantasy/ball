#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <chrono>
#include "eigen3/Eigen/Dense"
#include "renderer.h"

using namespace std;

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



int main()
{

	SphereWrapper sw;
	auto tp = std::chrono::high_resolution_clock::now();


	Eigen::Vector3f v{1.1,0,0} ;
	Eigen::Vector3f v_wind{ 0,0,0 };
	Eigen::Vector3f x{0,0,0} ;
	Eigen::Vector3f g{ 0,0,0 };
	float t = 0;
	float t_max = 600000000;
	int n = 0;
	float h = 0.1; // timestep
	float d = 0.4f; // Air Resistance
	float m = 1.f;


	while (t < t_max)
	{
		// Output appro frame
		//cout << fixed << setprecision(1) << x.transpose() << endl;
		sw.display(x);

		// compute new state
		Eigen::Vector3f a = g + d / m * (v_wind - v);
		x = x + v * h;
		v = v + a * h;

		// update time count
		n = n + 1;
		t = n * h;

		auto tp2 = std::chrono::high_resolution_clock::now();
		while(std::chrono::duration_cast<std::chrono::milliseconds>(tp2-tp).count()<(h*1000))
		{
			tp2 = std::chrono::high_resolution_clock::now();
		}
		tp = tp2;
	}


	return 0;


}