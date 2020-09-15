package utils;

import java.util.Scanner;
import java.io.File;
import entities.Event;
import entities.SkillEvent;
import entities.FixedEvent;

public class Scheduler
{
	private static final String FIXED_SKILL_DELIM = ":";
	private static final String END_ENTRY_DELIM = ";";
	private static final String COMPONENT_DELIM = ",";
	private static final int SKILL_ARR_COMPONENT_LEN = 6;
	private static final int FIXED_ARR_COMPONENT_LEN = 6;
	
	public static Event[][] create(String filename)
	{
		String filepath = new File("").getAbsolutePath()+filename;
		
		try { 
			// load
			Scanner sc = new Scanner(new File(filepath));
			String content = "";
			while(sc.hasNext()) content += sc.nextLine();
			sc.close();
			// parse
			String[] skill_events_str = content.substring(0,content.indexOf(FIXED_SKILL_DELIM)).split(END_ENTRY_DELIM);
			String[] fixed_events_str = content.substring(content.indexOf(FIXED_SKILL_DELIM)+1).split(END_ENTRY_DELIM);	
			// generate events
			Event[] skill_events_obj = new SkillEvent[skill_events_str.length];
			for (int i = 0; i < skill_events_str.length; i++)
			{
				String str = skill_events_str[i].substring(1);
				String[] components = str.split(COMPONENT_DELIM);
				skill_events_obj[i] = new SkillEvent(components[0],components[1],components[2],Float.parseFloat(components[3]),Integer.parseInt(components[4]),Integer.parseInt(components[5]));
				System.out.println(skill_events_obj[i]);
			}
			Event[] fixed_events_obj = new FixedEvent[fixed_events_str.length];
			for (int i = 0; i < fixed_events_str.length; i++)
			{
				String str = fixed_events_str[i].substring(1);
				String[] components = str.split(COMPONENT_DELIM);
				fixed_events_obj[i] = new FixedEvent(components[0],components[1],components[2],components[3],Integer.parseInt(components[4]),Float.parseFloat(components[5]));
				System.out.println(fixed_events_obj[i]);
			}
			// schedule
			return schedule(skill_events_obj, fixed_events_obj);			
			
		} catch (Exception e) { System.out.println(filepath + " not found"); }
		
		return null;
	}
	
	private static Event[][] schedule(Event[] skills, Event[] fixed)
	{
		// TODO
		return null;
	}
	
	// Test suite
	public static void main(String[] args)
	{}
}