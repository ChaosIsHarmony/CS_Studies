class Layer_Dense:

	def __init__(self, n_inputs, n_neurons, w_reg_l1=0, w_reg_l2=0, b_reg_l1=0, b_reg_l2=0):
		# initialize weights
        self.weights = 0.01 * np.random.randn(n_inputs, n_neurons)
        self.biases = np.zeros([1, n_neurons])
        # set regularization strength
        self.w_reg_l1 = w_reg_l1
        self.w_reg_l2 = w_reg_l2
        self.b_reg_l1 = b_reg_l1
        self.b_reg_l2 = b_reg_l2