import java.util.Scanner;
import utils.Scheduler;
import entities.Event;

public class Main
{
	private static Scanner sc;
	private final static String SUBJECTS_EVENTS_LIST_FILE = "/txt_files/skills_and_fixed.txt";
	
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// Determine current use case
		System.out.println("Use Case:\n\nCreate Weekly Schedule = C\nView Weekly Schedule = V\nExit = X");
		
		// Load appropriate file
		String input;
		while (!(input = sc.nextLine()).equals("X"))
			if (input.equals("C") || input.equals("c"))			createNewSchedule();
			else if (input.equals("V") || input.equals("v"))	viewOldSchedule();
			else												System.out.println("Invalid Input");
		
		sc.close();
	}
	
	private static void createNewSchedule()
	{
		// Take filename as input to create new schedule
		// This file contains a specially formatted list of "Subjects to Study" and "Fixed Events"
		Event[][] schedule = Scheduler.create(SUBJECTS_EVENTS_LIST_FILE);
		
		// Display new schedule by day [24 x 7]
		// Can input a specific cell to see specs of event
		for (int i = 0; i < 24; i++)
		{
			if (i > 0) System.out.printf("%-5s", i+"H");
			for (int j = 0; j < 7; j++)
			{
				// print out days at top only once
				if (i == 0 && j == 0)
				{
					System.out.printf("%-5s", "");
					String day = "";
					for (int k = 0; k < 7; k++)
					{
						switch (k)
						{
							case 0: day = "Sunday";		break;
							case 1: day = "Monday";		break;
							case 2: day = "Tuesday";	break;
							case 3: day = "Wednesday";	break;
							case 4: day = "Thursday";	break;
							case 5: day = "Friday";		break;
							case 6: day = "Saturday";	break;
						}
						System.out.printf("%-10S", day);
					}
					System.out.println();
					System.out.printf("%-5s", i+"H");
				}
				// print out activity at correct timeslot on correct day
				if (schedule[i][j] != null)	System.out.printf("%-10s", schedule[i][j].getType());
				else						System.out.printf("%-10s", "");
			}
			System.out.println();
		}
		
	}
	
	private static void viewOldSchedule()
	{
		System.out.println("Old");
	}
}