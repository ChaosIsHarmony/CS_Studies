/**
 * MazeGenerator.java
 *
 * Generates mazes for MazeSolver.java to solve.
 * Not all mazes are guaranteed to have a solution!
 * Takes three command line arguments:
 * 		r = # rows
 *		c = # colums
 * 		open_spaces = (approx.) # of open spaces in maze
 *
 * Use: java MazeGenerator 20 20 350 > maze_20x20.txt
 *
 * @EC
 * @09-2020
 * For AP CS A
 */
package utils;

public class MazeGenerator
{
	public MazeGenerator(String[] args)
	{
		// Setup
		int r = Integer.parseInt(args[0]);
		int c = Integer.parseInt(args[1]);
		double open_space_prob = Integer.parseInt(args[2])/(double) (r*c);	// prob empty space
		boolean start_set = false;
		boolean goal_set = false;
		
		// Create maze and print to standard output
		// # = obstacles
		// \s = open space
		// A = start
		// B = goal
		char type;
		int chance_start_goal = 1;
		for (int i = 0; i < r; i++)
		{
			for (int j =0; j < c; j++)
			{
				// determine space type
				type = (Math.random() <= open_space_prob) ? ' ' : '#';
				if (!start_set && type == ' ' && Math.random() <= (chance_start_goal/(double) (r*c)))
				{
					type = 'A';
					start_set = true;
					chance_start_goal = 1;
				} else if (!goal_set && type == '#' && Math.random() <= (chance_start_goal/(double) (r*c)))
				{
					type = 'B';
					goal_set = true;
					chance_start_goal = 1;
				} else
				{
					if (Math.random() < 0.1)	chance_start_goal++;
				}
				System.out.print(type);
			}
			System.out.println();
		}		
	}
}