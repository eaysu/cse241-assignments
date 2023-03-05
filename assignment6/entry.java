abstract class entry // base class
{
    private String name;

    public entry(String n)
    {
        name = n;
    }

    // get entry names
    public String get_name()
    {
        return name;
    }

    abstract public void info();
}   