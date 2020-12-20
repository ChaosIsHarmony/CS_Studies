import numpy as np
import nnfs
from nnfs.datasets import spiral_data


class Layer_Dense:
	
	def __init__(self, n_inputs, n_neurons):
		self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
		self.biases = np.zeros((1, n_neurons))

	def forward(self, inputs):
		# saved for use in backprop
		self.inputs = inputs
		self.outputs = np.dot(inputs, self.weights) + self.biases

	def backward(self, dvalues):
		self.dweights = np.dot(self.inputs.T, dvalues)
		self.dbiases = np.sum(dvalues, axis=0, keepdims=True)
		# why keep this?
		self.dinputs = np.dot(dvalues, self.weights.T)


class Activation_ReLU:

	def forward(self, inputs):
		# saved for use in backprop
		self.inputs = inputs
		self.outputs = np.maximum(0, inputs)

	def backward(self, dvalues):
		# why make a copy?
		self.dinputs = dvalues.copy()
		self.dinputs[self.inputs <= 0] = 0


class Activation_Softmax:

	def forward(self, inputs):
		# saved for use in backprop
		self.inputs = inputs
		# subtract max to force exponent into range of (-inf, 0]
		# this keeps value between (0-1]
		exp_values = np.exp(inputs - np.max(inputs, axis=1, keepdims=True))
		# normalized values
		self.outputs = exp_values / np.sum(exp_values, axis=1, keepdims=True)

	def backward(self, dvalues):
		self.dinputs = np.empty_like(dvalues)
		for index, (single_input, single_dvalues) in enumerate(zip(self.outputs, dvalues)):
			single_outputs = single_outputs.reshape(-1, 1)
			jacobian_matrix = np.diagflat(single_output) - np.dot(single_output, single_output.T)
			self.dinputs[index] = np.dot(jacobian_matrix, single_dvalues)


class Loss:

	def calculate(self, y_hat, y):
		sample_losses = self.forward(y_hat, y)
		batch_loss = np.mean(sample_losses)
		return batch_loss


class Loss_CategoricalCrossEntropy(Loss):

	def forward(self, y_hat, y):
		n_samples = len(y_hat)
		y_hat_clipped = np.clip(y_hat, 1e-7, 1 - 1e-7)
		# for list of labels as indexes
		if len(y.shape) == 1:
			correct_confidences = y_hat_clipped[range(n_samples), y]
		# for matrix of labels as one-hot encoded
		elif len(y.shape) == 2:
			correct_confidences = np.sum(y_hat_clipped * y, axis=1)
		# losses
		return -np.log(correct_confidences)

	def backward(self, dvalues, y):
		n_samples = len(dvalues)
		n_labels = len(y)
		# convert labels to one-hot if needed
		if len(y.shape) == 1:
			y = np.eye(n_labels)[y]
		# gradient
		self.dinputs = -y / dvalues
		# normalized gradient
		self.dinputs = self.dinputs / n_samples


class Activation_Softmax_Loss_CategoricalCrossentropy():
	
	def __init__(self):
		self.activation = Activation_Softmax()
		self.loss = Loss_CategoricalCrossEntropy()

	# Forward pass
	def forward(self, inputs, y):
		# Output layer’s activation function
		self.activation.forward(inputs)
		# Set the output
		self.outputs = self.activation.outputs
		# Calculate and return loss value
		return self.loss.calculate(self.outputs, y)

	# Backward pass
	def backward(self, dvalues, y):
		# Number of samples
		n_samples = len(dvalues)
		# If labels are one-hot encoded,
		# turn them into discrete values
		if len(y.shape) == 2:
			y = np.argmax(y, axis=1)
		# Copy so we can safely modify
		self.dinputs = dvalues.copy()
		# Calculate gradient
		self.dinputs[range(n_samples), y] -= 1
		# Normalize gradient
		self.dinputs = self.dinputs / n_samples

class Optimizer_SGD:
	
	def __init__(self, learning_rate=1.0, decay_rate=0.001):
		self.decay_rate = decay_rate
		self.learning_rate = learning_rate

	def update_params(self, layer):
		layer.weights += -self.learning_rate * layer.dweights
		layer.biases += - self.learning_rate * layer.dbiases

	def decay_learning_rate(self):
		# decays by fixed amt each iteration
		if self.learning_rate - self.decay_rate > 0:
			self.learning_rate -= self.decay_rate

	
# -------------------------------------
# create network
X, y = spiral_data(samples=1000, classes=3)

layer_1 = Layer_Dense(2, 64)
act_func_1 = Activation_ReLU()
layer_2 = Layer_Dense(64, 32)
act_func_2 = Activation_ReLU()
layer_3 = Layer_Dense(32, 3)
act_loss_func = Activation_Softmax_Loss_CategoricalCrossentropy()
optimizer = Optimizer_SGD(1, 0.0001)

for epoch in range(10001):
	# forward pass
	layer_1.forward(X)
	act_func_1.forward(layer_1.outputs)
	layer_2.forward(act_func_1.outputs)
	act_func_2.forward(layer_2.outputs)
	layer_3.forward(act_func_2.outputs)	
	loss = act_loss_func.forward(layer_3.outputs, y)

	# display results
	predictions = np.argmax(act_loss_func.outputs, axis=1)
	if len(y.shape) == 2:
		y = np.argmax(y, axis=1)
	accuracy = np.mean(predictions==y)
	if not epoch % 100:	# updates every 100 epochs
		print(f'epoch: {epoch}, acc: {accuracy:.3f}, loss: {loss:.3f}, eta: {optimizer.learning_rate:.3f}')

	# backward pass
	act_loss_func.backward(act_loss_func.outputs, y)
	layer_3.backward(act_loss_func.dinputs)
	act_func_2.backward(layer_3.dinputs)
	layer_2.backward(act_func_2.dinputs)
	act_func_1.backward(layer_2.dinputs)
	layer_1.backward(act_func_1.dinputs)

	# optimize
	optimizer.update_params(layer_1)
	optimizer.update_params(layer_2)
	optimizer.update_params(layer_3)
	optimizer.decay_learning_rate()
