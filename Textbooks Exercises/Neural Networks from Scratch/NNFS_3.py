#--------------------
# Modified NNFS_2.py#--------------------
import numpy as np

#Each neuron has inputs (prev layer's outputs)
inputs = [1, 2, 3, 2.5]
#Each layer has weights associated with each input connections unique to its neurons
weights = [[0.2, 0.8, -0.5, 1.0],
			[0.5, -0.91, 0.26, -0.5],
			[-0.26, -0.27, 0.17, 0.87]]
#Each neuron with the layer has a bias unique bias
biases = [2.0, 3.0, 0.5]

#Output is matrix-vector multiplication of weights and inputs plus the bias
output = np.dot(weights,inputs) + biases

print(output)