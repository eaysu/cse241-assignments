public class entry_audio extends entry implements playable, non_visual
{
    // audio entry has duration info
    private double duration;

    // get audio name
    public entry_audio(String n, double duration)
    {
        super(n);
        this.duration = duration;
    }

    // get duration time
    @Override
    public double get_duration()
    {
        return duration;
    }

    // prints info about audio entry
    @Override
    public void info()
    {
        System.out.println("audio: " + get_name());
        System.out.println("duration: " + get_duration());
    }    
}