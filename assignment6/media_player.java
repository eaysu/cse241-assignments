import java.util.ArrayList;

public class media_player implements observer
{
    // player entry objects stores here
    private ArrayList<playable> player_entries;
    // we have an index for finding next and previous infos
    private int index;
    
    // constructor
    public media_player() {index = 0; player_entries = new ArrayList<playable>();}
    
    // it shows all playable datas and their infos
    public void show_list()
    {
        for(playable p: player_entries)
        {  
            p.info();
        }
    }

    // skips next data
    public void next()
    {
        index = (index + 1) % player_entries.size();  
    }
    
    // skips previous data
    public void previous()
    {
        index = (index - 1) % player_entries.size();
    }

    // shows currently playing data 
    public playable currently_playing()
    {
        return (playable)player_entries.get(index); 
    }

    // we find playable datas from all entries and store  
    @Override
    public void update(ArrayList<entry> entries) 
    {
        player_entries.clear();

        for(entry e: entries)
        {
            if(e instanceof playable)
            {
                player_entries.add((playable)e);
            }
        }
    }
}    