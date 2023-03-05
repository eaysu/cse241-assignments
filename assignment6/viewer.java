import java.util.ArrayList;

public class viewer implements observer
{
    // viewer entry objects stores here
    private ArrayList<non_playable> viewer_entries;
    // we have an index for finding next and previous infos 
    private int index;
    
    // constructor
    public viewer() {index = 0; viewer_entries = new ArrayList<non_playable>();}

    // it shows all non_playable datas and their infos
    public void show_list()
    {
        for(non_playable n: viewer_entries)
        {
            n.info();
        }
    }
    
    // skips next data
    public void next()
    {
        index = (index + 1) % viewer_entries.size();  
    }
    
    // skips previous data
    public void previous()
    {
        index = (index - 1) % viewer_entries.size();
    }

    // shows currently viewing data
    public non_playable currently_viewing()
    {
        return (non_playable)viewer_entries.get(index); 
    }

    // we find non_playable datas from all entries and store
    @Override
    public void update(ArrayList<entry> entries) 
    {
        viewer_entries.clear();

        for(entry e: entries)
        {
            if(e instanceof non_playable)
            {
                viewer_entries.add((non_playable)e);
            }
        }
    }
}