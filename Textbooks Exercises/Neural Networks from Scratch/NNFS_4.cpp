/*
 *--------------------
 * Still buggy
 *--------------------
 */

#include <iostream>
#include <vector>

template<typename T>
Log(T t) { std::cout << t << std::endl; }

double vec_mul(std::vector<double> &r, std::vector <double> &c)
{
	double sum=0;
	for(int i = 0; i < r.size(); i++)
		sum += r[i]*c[i];
	return sum;
}

std::vector<std::vector <double> > dot(std::vector<std::vector <double> > &inputs, std::vector<std::vector <double> > &weights)
{
	std::vector<std::vector <double> > outputs;
	
	// for each row of the inputs
	for (int i = 0; i < inputs.size(); i++)
	{
		for (int j = 0; j < weights.size(); j++)
		{
			// multiply the 
			double output = vec_mul(inputs[i], weights[j]);
			outputs[i][j] = output;
		}
	}
	
	return outputs;
}

std::vector<std::vector <double> > process(std::vector<std::vector <double> > &inputs, std::vector<std::vector <double> > &weights, std::vector<double> &biases)
{
	std::vector<std::vector <double> > outputs;
	outputs = dot(inputs, weights);
	for(int i = 0; i < outputs.size(); i++)
		for(int j = 0; j < outputs.size(); j++)
			outputs[i][j] += biases[i];
	
	return outputs;
}

int main()
{
	// Each neuron has inputs (prev layer's outputs)
	std::vector<std::vector <double> > inputs =	{{1, 2, 3, 2.5},
												{2.0, 5.0, -1.0, 2.0},
												{-1.5, 2.7, 3.3, -0.8}};
	// Each neuron has weights associated with each input connection
	std::vector<std::vector <double> > weights = 	{{0.2, 0.8, -0.5, 1.0},
													{0.5, -0.91, 0.26, -0.5},
													{-0.26, -0.27, 0.17, 0.87}};
	// Each neuron has a unique bias
	std::vector<double> biases = std::vector<double>(3, 0);

	// Output is dot product of weights and inputs plus the bias
	std::vector<std::vector <double> > output = process(weights, inputs, biases);

	for(int i = 0; i < output.size(); i++)
		for(int j = 0; j < output[i].size(); j++)
			Log(output[i][j]);
	
	return 0;
}