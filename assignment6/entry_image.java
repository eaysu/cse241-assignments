public class entry_image extends entry implements visual, non_playable
{
    // image entry has dimension info
    private double dimension;

    // get image name
    public entry_image(String n, double dimension)
    {
        super(n);
        this.dimension = dimension;
    }

    // get dimension size
    @Override
    public double get_dimension()
    {
        return dimension;
    }

    // print info about image entry
    @Override
    public void info()
    {
        System.out.println("image: " + get_name());
        System.out.println("dimension: " + get_dimension());
    }
}