import java.rmi.Naming;
public class RmiClient {
    public static void main(String args[]) throws Exception {
        RmiServerIntf server = (RmiServerIntf)Naming.lookup("//localhost/RmiServer");
        System.out.println(server.getMessage());
    }
}