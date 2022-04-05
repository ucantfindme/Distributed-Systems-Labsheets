import java.rmi.Remote;
import java.rmi.RemoteException;
public interface Lamport extends Remote{
    // Declaring the method prototype
    void event(int c) throws RemoteException;
}