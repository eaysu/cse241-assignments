public class test
{    
    public static void main(String[] args) 
    {
        // this is our dataset. we have only one dataset.
        dataset ds = new dataset();

        // lets create different observers.
        media_player p1 = new media_player();
        media_player p2 = new media_player();
        viewer v1 = new viewer();
        viewer v2 = new viewer();

        // lets register them to our dataset so that they can reach to data and updates.
        // you can also register them to the dataset when you create them.
        // ds has to figure out the type of the observer.
        // it should not send unrelated information.
        
        // for example, viewer objects don't want to know anything about playable objects.
        ds.register(p1);
        ds.register(p2);
        ds.register(v1);
        ds.register(v2);
        
        // dataset should also support un-registering.
        ds.unregister(p1);
        // p1 no longer receives any update or list of items.
        
        // here we create different objects.
        ds.add(new entry_image("imagename1", 500));
        ds.add(new entry_image("imagename2", 600));
        ds.add(new entry_image("imagename3", 700));
        ds.add(new entry_image("imagename4", 800));
        ds.add(new entry_image("imagename5", 900));
        ds.add(new entry_audio("audioname1", 4.5));
        ds.add(new entry_audio("audioname2", 3.5));
        ds.add(new entry_audio("audioname3", 2.5));
        ds.add(new entry_video("videoname1", 10.0, 480));
        ds.add(new entry_video("videoname2", 12.0, 720));
        ds.add(new entry_video("videoname3", 14.0, 1080));
        ds.add(new entry_text("textname1"));
        ds.add(new entry_text("textname2"));
        ds.add(new entry_text("textname3"));
        

        // testing
        System.out.println("--- Visual Data ---");
        v1.show_list();

        System.out.println("\n--- Next and Previous Operations ---\n");
        v1.next();
        v1.currently_viewing().info();
        v1.next();
        v1.currently_viewing().info();
        v1.previous();
        v1.currently_viewing().info();

        System.out.println("\n*****************************\n");
        System.out.println("--- Playable Data ---");
        p2.show_list();

        System.out.println("\n--- Next and Previous Operations ---\n");
        p2.next();
        p2.currently_playing().info();
        p2.next();
        p2.currently_playing().info();
        p2.previous();
        p2.currently_playing().info();

        System.out.println("\n*****************************\n");
        // lets use two players objects.
        playable po = p2.currently_playing();
        non_playable vo = v1.currently_viewing();

        // these print info about the playing and viewing objects.
        po.info();
        vo.info();

        System.out.println("\n*****************************\n");
        // we can remove these objects from the dataset
        ds.remove((entry)po);
        ds.remove((entry)vo);

        // po and vo are no longer in the dataset. all of the interested observers will get this update.
        non_playable np = v1.currently_viewing();
        playable p = p2.currently_playing();

        // these print info about the object being viewed and played.
        np.info();
        p.info(); 
    }
}