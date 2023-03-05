import java.util.ArrayList;

public class dataset implements subject
{
    // creating arrays for observer and entry objects
    private ArrayList<observer> observe;
    private ArrayList<entry> entries;

    // storing observer and entry objects to their arrays
    public dataset()
    {
        observe = new ArrayList<observer>();
        entries = new ArrayList<entry>();
    }
    
    // we add an observer and notify
    public void register(observer new_observer)
    {
        observe.add(new_observer);
        notify_observer();
    }

    // we remove an observer and give deleted message
    public void unregister(observer remove_observer)
    {
        int index_observer = observe.indexOf(remove_observer);
        System.out.println("\nObserver " + (index_observer + 1) + " removed\n");
        observe.remove(index_observer);
    }

    // we have to notify observers from updates
    public void notify_observer()
    {
        for(observer observer : observe)
        {
            observer.update(entries);
        }
    }

    // we get a entry object and notify
    public void add(entry new_entry) 
    {
        entries.add(new_entry);
        notify_observer();
    }

    // we remove entry
    public void remove(entry remove_entry)
    {
        entries.remove(remove_entry);
        notify_observer();
    }
}