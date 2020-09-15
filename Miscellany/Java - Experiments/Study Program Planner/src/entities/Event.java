package entities;

public class Event
{
	private final String category, subject, type;
	private final float duration;
	
	public Event(String category, String subject, String type, float duration)
	{
		this.category = category;
		this.subject = subject;
		this.type = type;
		this.duration = duration;
	}
	
	public String getCategory()	{ return this.category; }
	public String getSubject() 	{ return this.subject; }
	public String getType() 	{ return this.type; }
	public float getDuration() 	{ return this.duration; }
}