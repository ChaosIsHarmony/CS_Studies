#--------------------
#NNFS_1.py modified to model three neurons
#--------------------

#Each neuron has inputs (prev layer's outputs)
inputs = [1, 2, 3, 2.5]
#Each layer has weights associated with each input connections unique to its neurons
weights1 = [0.2, 0.8, -0.5, 1.0]
weights2 = [0.5, -0.91, 0.26, -0.5]
weights3 = [-0.26, -0.27, 0.17, 0.87]
#Each neuron with the layer has a bias unique bias
bias1 = 2.0
bias2 = 3.0
bias3 = 0.5

#Output is matrix-vector multiplication of weights and inputs plus the bias
output = 	[inputs[0]*weights1[0] + inputs[1]*weights1[1] + inputs[2]*weights1[2] + inputs[3]*weights1[3] + bias1, 
			inputs[0]*weights2[0] + inputs[1]*weights2[1] + inputs[2]*weights2[2] + inputs[3]*weights2[3] + bias2, 
			inputs[0]*weights3[0] + inputs[1]*weights3[1] + inputs[2]*weights3[2] + inputs[3]*weights3[3] + bias3]

print(output)
