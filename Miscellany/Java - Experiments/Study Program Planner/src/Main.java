import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import utils.Scheduler;
import entities.Event;

public class Main
{
	private static Scanner sc;
	private final static String SUBJECTS_EVENTS_LIST_FILE;
	private final static String SCHEDULES_FILE;
	static {
		String os = System.getProperty("os.name");
		System.out.println(os);
		if (os.contains("Windows"))
		{
			SUBJECTS_EVENTS_LIST_FILE = "\\txt_files\\skills_and_fixed.txt";
			SCHEDULES_FILE = "\\txt_files\\schedules.txt";
		} else
		{
			SUBJECTS_EVENTS_LIST_FILE = "/txt_files/skills_and_fixed.txt";
			SCHEDULES_FILE = "/txt_files/schedules.txt";
		}
	}
	public static void main(String[] args)
	{
		sc = new Scanner(System.in);
		
		// Determine current use case
		System.out.println("Use Case:\n\nCreate Weekly Schedule = C\nView Weekly Schedule = V\nExit = X");
		
		// Load appropriate file
		String input;
		while (!(input = sc.nextLine()).equals("X"))
			if (input.equals("C") || input.equals("c"))			createNewSchedule(1);
			else if (input.equals("V") || input.equals("v"))	viewOldSchedule();
			else												System.out.println("Invalid Input");
		
		sc.close();
	}
	
	private static void createNewSchedule(int skip)
	{
		// Take filename as input to create new schedule
		// This file contains a specially formatted list of "Subjects to Study" and "Fixed Events"
		Event[][] schedule = Scheduler.create(SUBJECTS_EVENTS_LIST_FILE,skip);
		
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
		
		System.out.println("Save [s], Try a new pattern [c], or Back to Main [b]?");
		while (true){
			String input = sc.nextLine();
			switch (input)
			{
				case "S":
				case "s": try { save(schedule); } catch (Exception e) {} break;
				case "C":
				case "c": createNewSchedule(skip*2); break;
				case "B":
				case "b": System.out.println("Use Case:\n\nCreate Weekly Schedule = C\nView Weekly Schedule = V\nExit = X"); break;
				default: System.out.println("Invalid Input"); continue;
			}
			break;
		}
	}
	
	private static void save(Event[][] schedule) throws IOException
	{
		// TODO: enforce format
		System.out.println("What is Sunday's date? [YYYY-MM-DD]");
		String date = sc.nextLine();
		
		String filepath = new File("").getAbsolutePath()+SCHEDULES_FILE;
		
        try (FileWriter fileWriter = new FileWriter(filepath, true)) {
			fileWriter.write("[/"+date+"]");
            for (int i = 0; i < 24; i++)
			{
				String line = "";
				for (int j = 0; j < 7; j++)
					line += schedule[i][j]+",";
				fileWriter.write(line+"\n");
			}
			fileWriter.write("["+date+"/]");
			
			System.out.println("Save successful");
        } catch (Exception e) { System.out.println("Save unsuccessful"); }
	}
	
	private static void viewOldSchedule()
	{
		System.out.println("Old");
	}
}