package entities;

public class Event
{
	public static enum DAY {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
	private final String category, subject, type;
	private final int duration; // only by hours, no half hours
	
	public Event(String category, String subject, String type, int duration)
	{
		this.category = category;
		this.subject = subject;
		this.type = type;
		this.duration = duration;
	}
	
	public String getCategory()	{ return this.category; }
	public String getSubject() 	{ return this.subject; }
	public String getType() 	{ return this.type; }
	public int getDuration() 	{ return this.duration; }
}