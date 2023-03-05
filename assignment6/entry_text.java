public class entry_text extends entry implements non_visual, non_playable
{
    //get text name
    public entry_text(String n)
    {
        super(n);
    }

    // we have no info about text except its name 
    @Override
    public void info()
    {
        System.out.println("text: " + get_name());
    }

    
}