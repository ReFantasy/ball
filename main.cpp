#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <chrono>
#include "eigen3/Eigen/Dense"
#include "renderer.h"
#include <windows.h>


using namespace std;



int main()
{

	SphereWrapper sw;
	auto tp = std::chrono::high_resolution_clock::now();


	Eigen::Vector3f v{1.1,0,0} ;
	Eigen::Vector3f v_wind{ 0,0,0 };
	Eigen::Vector3f x{0,0,0} ;
	Eigen::Vector3f g{ 0,0,0 };
	float t = 0;
	float t_max = 600000000.f;
	int n = 0;
	float h = 0.001; // timestep
	float d = 0.4f; // Air Resistance
	float m = 1.f;


	while (t < t_max)
	{
		// Output appro frame
		if(n% int((1/30.0)/h)==0)
		    sw.display(x);

		// compute new state
		Eigen::Vector3f a = g + d / m * (v_wind - v);
		x = x + v * h;
		v = v + a * h;

		// update time count
		n = n + 1;
		t = n * h;

		Sleep(h*1000);
	}


	return 0;


}