public class NNFS_1
{
	public static void main(String[] args)
	{
		//Each neuron has inputs (prev layer's outputs)
		double[] d_arr_inputs = {1.2, 5.1, 2.1};
		//Each neuron has weights associated with each input connection
		double[] d_arr_weights = {3.1, 2.1, 8.7};
		//Each neuron has a unique bias
		double d_bias = 3.0;

		//Output is vector multiplication of weights and inputs plus the bias
		double d_output = d_arr_inputs[0]*d_arr_weights[0] + d_arr_inputs[1]*d_arr_weights[1] + d_arr_inputs[2]*d_arr_weights[2] + d_bias;

		System.out.println(d_output);
	}
}