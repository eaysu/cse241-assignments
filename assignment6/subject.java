public interface subject
{
    // subject interface handles adding, deleting and updating all observers
    public void register(observer obs);
    public void unregister(observer obs);
    public void notify_observer();
}