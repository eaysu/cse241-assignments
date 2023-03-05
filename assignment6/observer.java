import java.util.ArrayList;

public interface observer
{
    // the observers update method is called when the subject changes
    public void update(ArrayList<entry> e);
}