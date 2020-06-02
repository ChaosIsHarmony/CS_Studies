#Each neuron has inputs (prev layer's outputs)
inputs = [1.2, 5.1, 2.1]
#Each neuron has weights associated with each input connection
weights = [3.1, 2.1, 8.7]
#Each neuron has a unique bias
bias = 3

#Output is vector multiplication of weights and inputs plus the bias
output = inputs[0]*weights[0] + inputs[1]*weights[1] + inputs[2]*weights[2] + bias

print(output)