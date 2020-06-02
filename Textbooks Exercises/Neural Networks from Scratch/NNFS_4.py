#--------------------
# 
#--------------------
import numpy as np

np.random.seed(0)

#X is the standard name for input data
#would typically normalize data to be between [-1,1]
X = [[1, 2, 3, 2.5],
	[2.0, 5.0, -1.0, 2.0],
	[-1.5, 2.7, 3.3, -0.8]]

#If 0 is propagated throughout the network, can lead to 'dead net'
#If so, randomly initialize biases

#Neuron Layer
class Layer_Dense:
	def __init__(self, n_inputs, n_neurons):
		#want initialized to between [-1,1]
		self.weights = 0.10 * np.random.randn(n_inputs, n_neurons)
		self.biases = np.zeros((1, n_neurons))
	def forward(self, inputs):
		self.output = np.dot(inputs, self.weights) + self.biases


#create two layers and forward pass
layer_1 = Layer_Dense(len(X[0]), 5)	
layer_2 = Layer_Dense(5, 2)

layer_1.forward(X)
layer_2.forward(layer_1.output)
print(layer_2.output)