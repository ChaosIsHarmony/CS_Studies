import java.util.Scanner;
import utils.Scheduler;
import entities.Event;

public class Main
{
	private static Scanner sc;
	private final static String SUBJECTS_EVENTS_LIST_FILE = "\\txt_files\\subj_and_events.txt";
	
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
		
		
	}
	
	private static void viewOldSchedule()
	{
		System.out.println("Old");
	}
}