/*
 *--------------------
 * 
 *--------------------
 */

#include <iostream>
#include <vector>

template<typename T>
Log(T t) { std::cout << t << std::endl; }

std::vector<double> dot(std::vector<std::vector <double> > &weights, std::vector<double> &inputs)
{
	std::vector<double> outputs(weights.size());
	
	for (int i = 0; i < weights.size(); i++)
	{
		double output = 0;
		for (int j = 0; j < inputs.size(); j++)
			output += weights[i][j] * inputs[j];
		outputs[i] = output;
	}
	
	return outputs;
}

std::vector<double> process(std::vector<std::vector <double> > &weights, std::vector<double> &inputs, std::vector<double> &biases)
{
	std::vector<double> outputs(weights.size());
	outputs = dot(weights,inputs);
	for(int i = 0; i < outputs.size(); i++)
		outputs[i] += biases[i];
	
	return outputs;
}

int main()
{
	// Each neuron has inputs (prev layer's outputs)
	std::vector<double> inputs = {1, 2, 3, 2.5};
	// Each neuron has weights associated with each input connection
	std::vector<std::vector <double> > weights = 	{{0.2, 0.8, -0.5, 1.0},
													{0.5, -0.91, 0.26, -0.5},
													{-0.26, -0.27, 0.17, 0.87}};
	// Each neuron has a unique bias
	std::vector<double> biases = {2.0, 3.0, 0.5};

	// Output is dot product of weights and inputs plus the bias
	std::vector<double> output = process(weights, inputs, biases);

	for(int i = 0; i < 3; i++)
		Log(output[i]);
	
	return 0;
}