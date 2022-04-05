import java.rmi.Naming;
import java.rmi.RemoteException;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.registry.*;
import java.util.*;
public class M3 extends UnicastRemoteObject implements Lamport{
    public static int clk = 0;
    public M3() throws RemoteException{
        super(0);
    }
    synchronized public void event(int c) throws RemoteException{
        clk=Math.max(clk,c)+1;
        System.out.println("M3 recieved an event at "+clk);
    }
    public static class Client extends Thread{
        public void run(){
            System.out.println("C3 started!");
            try{
                Thread.sleep(2000);
            }
            catch(Exception e){
                System.out.println("Failed to Sleep");
            }
            Random r=new Random();
            while(true){
                int t=r.nextInt(5);
                if(t==0){
                    
                    try{
                        int s=r.nextInt(5);
                        if(s==0 || s==3){
                            continue;
                        }
                        synchronized(this){
                            clk++;
                            Lamport server=(Lamport)Naming.lookup("//localhost/M"+s);
                            server.event(clk);
                            System.out.println("C3 sent an external event at "+clk+" to M"+s);
                        }
                        
                        Thread.sleep(2000);
                    }
                    catch(Exception e){
                        System.out.println("C3 failed to send an external event at "+clk);
                    }
                }
                else if(t==1){
                    synchronized(this){
                        clk++;
                        System.out.println("C3 has performed an internal event at "+clk);
                    }
                }
                else{
                    try{
                        Thread.sleep(2000);
                    }
                    catch(Exception e){
                        System.out.println("Failed to Sleep");
                    }
                }
            }
        }
    }
    public static void main(String args[]) throws Exception {
        System.out.println("M3 started!");
        try { //special exception handler for registry creation
            LocateRegistry.createRegistry(1902);
            System.out.println("java RMI registry for M3 created at 1902");
        } catch (RemoteException e) {
            System.out.println("java RMI registry already exists.");
        }
        M3 server = new M3();
        System.out.println("Test");
        Naming.rebind("//localhost/M3", server);
        System.out.println("PeerServer bound in registry");
        Client cli=new Client();
        cli.start();
    }
}