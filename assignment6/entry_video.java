public class entry_video extends entry implements playable, visual
{
    // image entry has both dimension and duration info
    private double duration;
    private double dimension;

    // get video name
    public entry_video(String n, double duration, double dimension)
    {
        super(n);
        this.duration = duration;
        this.dimension = dimension;
    }

    // get duration time
    @Override
    public double get_duration() 
    {
        return duration;
    }

    // get dimension size
    @Override
    public double get_dimension()
    {
        return dimension;
    }
    
    // print info about video entry
    @Override
    public void info()
    {
        System.out.println("video: " + get_name());
        System.out.println("duration: " + get_duration());
        System.out.println("dimension: " + get_dimension());
    } 
}