package entities;

public class SkillEvent extends Event
{
	private final int priority, frequency;
	
	public SkillEvent(String category, String subject, String type, float duration, int frequency, int priority)
	{
		super(category, subject, type, duration);
		this.frequency = frequency;
		this.priority = priority;
	}
	
	public int getPriority()	{ return this.priority; }
	public int getFrequency()	{ return this.frequency; }
	
	public String toString()	{ return getCategory() + " " + getSubject() + " " + getType() + " " + getDuration() + " " + frequency + " " + priority; }
}