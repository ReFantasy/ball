#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include "eigen3/Eigen/Dense"

using namespace std;

int main()
{
	Eigen::Vector3f v{10,0,30} ;
	Eigen::Vector3f x{0,100,0} ;
	Eigen::Vector3f g{ 0,-10,0 };
	float t = 0;
	float t_max = 6;
	int n = 0;
	float h = 1; // timestep
	float d = 0.4; // Air Resistance 
	float m = 1.f;

	while (t < t_max)
	{
		// Output appro frame
		cout << x.transpose() << endl;

		// compute new state
		Eigen::Vector3f a = g - d / m * v;
		x = x + v * h;
		v = v + a * h;

		// update time count
		n = n + 1;
		t = n * h;
	}


	return 0;
}