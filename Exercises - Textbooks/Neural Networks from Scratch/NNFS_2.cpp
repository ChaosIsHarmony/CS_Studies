/*
 *--------------------
 * NNFS_1.cpp modified to model three neurons
 *--------------------
 */

#include <iostream>

template<typename T>
Log(T t) { std::cout << t << std::endl; }

int main()
{
	// Each neuron has inputs (prev layer's outputs)
	double inputs[] = {1, 2, 3, 2.5};
	// Each neuron has weights associated with each input connection
	double weights1[] = {0.2, 0.8, -0.5, 1.0};
	double weights2[] = {0.5, -0.91, 0.26, -0.5};
	double weights3[] = {-0.26, -0.27, 0.17, 0.87};
	// Each neuron has a unique bias
	double bias1 = 2.0;
	double bias2 = 3.0;
	double bias3 = 0.5;

	// Output is vector multiplication of weights and inputs plus the bias
	double output[] = {inputs[0]*weights1[0] + inputs[1]*weights1[1] + inputs[2]*weights1[2] + bias1,
						inputs[0]*weights2[0] + inputs[1]*weights2[1] + inputs[2]*weights2[2] + bias2,
						inputs[0]*weights3[0] + inputs[1]*weights3[1] + inputs[2]*weights3[2] + bias3};

	for(int i = 0; i < 3; i++)
		Log(output[i]);
	
	return 0;
}