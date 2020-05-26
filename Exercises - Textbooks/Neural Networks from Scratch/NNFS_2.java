/*--------------------
 * NNFS_1.java modified to model three neurons
 *--------------------
 */

public class NNFS_2
{
	public static void main(String[] args)
	{
		//Each neuron has inputs (prev layer's outputs)
		double[] d_arr_inputs = {1, 2, 3, 2.5};
		//Each layer has weights associated with each input connections unique to its neurons
		double[] d_arr_weights1 = {0.2, 0.8, -0.5, 1.0};
		double[] d_arr_weights2 = {0.5, -0.91, 0.26, -0.5};
		double[] d_arr_weights3 = {-0.26, -0.27, 0.17, 0.87};
		//Each neuron with the layer has a bias unique bias
		double d_bias1 = 2.0;
		double d_bias2 = 3.0;
		double d_bias3 = 0.5;

		//Output is matrix-vector multiplication of weights and inputs plus the bias
		double[] d_arr_output = 	{d_arr_inputs[0]*d_arr_weights1[0] + d_arr_inputs[1]*d_arr_weights1[1] + 
									d_arr_inputs[2]*d_arr_weights1[2] + d_arr_inputs[3]*d_arr_weights1[3] + d_bias1, 
									d_arr_inputs[0]*d_arr_weights2[0] + d_arr_inputs[1]*d_arr_weights2[1] + d_arr_inputs[2]*d_arr_weights2[2] + d_arr_inputs[3]*d_arr_weights2[3] + d_bias2, 
									d_arr_inputs[0]*d_arr_weights3[0] + d_arr_inputs[1]*d_arr_weights3[1] + d_arr_inputs[2]*d_arr_weights3[2] + d_arr_inputs[3]*d_arr_weights3[3] + d_bias3};

		for (double d : d_arr_output)
			System.out.println(d);
	}
}