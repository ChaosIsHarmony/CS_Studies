/*--------------------
 * NNFS_2.java modified to model three neurons
 *--------------------
 */

public class NNFS_3
{
	private static double[] dot(double[][] d_2darr_weights, double[] d_arr_inputs)
	{
		double[] d_arr_result = new double[d_2darr_weights.length];
		for(int r = 0; r < d_2darr_weights.length; r++)
		{
			double sum = 0;
			for (int i = 0; i < d_2darr_weights[r].length; i++)
				sum += d_2darr_weights[r][i]*d_arr_inputs[i];
			d_arr_result[r] = sum;
		}
		return d_arr_result;
	}
	
	private static double[] gen_output(double[] d_arr_mat, double[] d_arr_biases)
	{
		double[] d_arr_output = new double[d_arr_mat.length];
		for (int i = 0; i < d_arr_output.length; i++)
			d_arr_output[i] = d_arr_mat[i] + d_arr_biases[i];
		return d_arr_output;
	}
	
	public static void main(String[] args)
	{
		//Each neuron has inputs (prev layer's outputs)
		double[] d_arr_inputs = {1, 2, 3, 2.5};
		//Each layer has weights associated with each input connections unique to its neurons
		double[][] d_2darr_weights =	{{0.2, 0.8, -0.5, 1.0},
										{0.5, -0.91, 0.26, -0.5},
										{-0.26, -0.27, 0.17, 0.87}};
		//Each neuron with the layer has a bias unique bias
		double[] d_arr_biases = {2.0, 3.0, 0.5};
		
		//Output is matrix-vector multiplication of weights and inputs plus the bias
		double[] d_arr_output = gen_output(dot(d_2darr_weights, d_arr_inputs), d_arr_biases);
		
		for (double d : d_arr_output)
			System.out.println(d);
	}
}