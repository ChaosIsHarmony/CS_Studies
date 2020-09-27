import java.util.Scanner;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import utils.Scheduler;
import entities.Event;
import entities.FixedEvent;
import entities.SkillEvent;

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
		System.out.println("Create Weekly Schedule = C\nView Weekly Schedule = V\nExit = X");
		
		// Load appropriate file
		String input;
		while (!(input = sc.nextLine()).equals("X"))
			if (input.equals("C") || input.equals("c"))			createNewSchedule(1);
			else if (input.equals("V") || input.equals("v"))	viewOldSchedule();
			else												System.out.println("Invalid Input [Main]");
		
		sc.close();
	}
	
	private static void createNewSchedule(int skip)
	{
		// Take filename as input to create new schedule
		// This file contains a specially formatted list of "Subjects to Study" and "Fixed Events"
		Event[][] schedule = Scheduler.create(SUBJECTS_EVENTS_LIST_FILE,skip);
		
		// Display
		display(schedule);
		
		System.out.println("Save [s], Try a new pattern [c], Previous pattern [p], or Back to Main [b], Exchange spots manually [e], Input event manually [m]?");
		while (true){
			String input = sc.nextLine();
			switch (input)
			{
				case "S":
				case "s": try { save(schedule); } catch (Exception e) {} break;
				case "C":
				case "c": createNewSchedule(skip*2); break;
				case "P":
				case "p": createNewSchedule(((skip>1)? skip/2 : skip)); break;
				case "B":
				case "b": System.out.println("\n\nCreate Weekly Schedule = C\nView Weekly Schedule = V\nExit = X"); break;
				case "E":
				case "e": moveManually(schedule); break;
				case "M":
				case "m": inputEventManually(schedule); break;
				default: System.out.println("Invalid Input [Create New Schedule]"); continue;
			}
			break;
		}
	}
	
	private static void viewOldSchedule()
	{
		// TODO enforce format
		System.out.println("What was Sunday's date? [YYYY-MM-DD]");
		String date = sc.nextLine();

		String filepath = new File("").getAbsolutePath()+SCHEDULES_FILE;

		try { 
			Scanner sc_2 = new Scanner(new File(filepath));

			Event[][] schedule = new Event[24][7];
			boolean found = false;
			
			// TODO: finish parser
			while (sc_2.hasNext())
			{
				// looks only for start entry of date
				if (sc_2.nextLine().contains(date))	found = true;
				
				if (found)
				{
					String line = sc_2.nextLine();
					int cnt = 0;
					// parse out events until second occurrence of date
					for(int i = 0; i < 24; i++, line = sc_2.nextLine())
					{
						String[] events = line.split(","); // splits line into events
						for (int j = 0; j < 7; j++)
						{
							if (events[j].equals("null")) continue; // if no event slotted for that time

							String[] fields = events[j].split(" "); //splits events into fields
							// is a skill
							if (Boolean.parseBoolean(fields[0]))
							{
								SkillEvent e = new SkillEvent(fields[1], fields[2], fields[3], Integer.parseInt(fields[4]), Integer.parseInt(fields[5]), Integer.parseInt(fields[6]));
								schedule[i][j] = e;
							}
							// is fixed 
							else
							{
								FixedEvent e = new FixedEvent(fields[1], fields[2], fields[3], Integer.parseInt(fields[4]), Integer.parseInt(fields[5]), Integer.parseInt(fields[6]));
								schedule[i][j] = e;
							}
							
						}
					}
					break; // finished loading relevant entries from the schedule
				}
			}
			display(schedule);
			// Determine current use case
			System.out.println("\n\nCreate Weekly Schedule = C\nView Weekly Schedule = V\nExit = X");
		} catch (Exception e) { System.out.println("Failed to load: " + filepath); }
	}

	// Helper Methods
	private static void display(Event[][] schedule)
	{
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

	private static void save(Event[][] schedule) throws IOException
	{
		// TODO: enforce format
		System.out.println("What is Sunday's date? [YYYY-MM-DD]");
		String date = sc.nextLine();
		
		String filepath = new File("").getAbsolutePath()+SCHEDULES_FILE;
		
        try (FileWriter fileWriter = new FileWriter(filepath, true)) {
			fileWriter.write("[/"+date+"]\n");
            for (int i = 0; i < 24; i++)
			{
				String line = "";
				for (int j = 0; j < 7; j++)
					line += schedule[i][j]+",";
				fileWriter.write(line+"\n");
			}
			fileWriter.write("["+date+"/]\n");
			
			System.out.println("Save successful");
			System.out.println("\n\nCreate Weekly Schedule = C\nView Weekly Schedule = V\nExit = X");
        } catch (Exception e) { System.out.println("Save unsuccessful"); }
	}
	
	private static void moveManually(Event[][] schedule)
	{
		// Prompt user to insert space separated pairs to swap
		System.out.println("List hour [0-23] and day [0-7] indexes for as many pairs you want to swap (e.g., 11 0 11 1 <- moves Event at 11,0 to 11,1)\n-1 to stop");

		int hour_1, day_1, hour_2, day_2;
		while(sc.hasNext())
		{
			if ((hour_1 = sc.nextInt()) < 0) break; // breaks on sentinel value of -1
			day_1 = sc.nextInt();
			hour_2 = sc.nextInt();
			day_2 = sc.nextInt();
			
			Event tmp = schedule[hour_1][day_1];
			schedule[hour_1][day_1] = schedule[hour_2][day_2];
			schedule[hour_2][day_2] = tmp;
		}
		System.out.println("\n\nNew Schedule");
		display(schedule);
	}

	private static void inputEventManually(Event[][] schedule)
	{
		// TODO: handle manually event creation
	}
}