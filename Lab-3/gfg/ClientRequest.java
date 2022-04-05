import java.rmi.*;
public class ClientRequest
{
    public static void main(String args[])
    {
        String answer,value="The Greatest Mind";
        try
        {
            // lookup method to find reference of remote object
            Search access =(Search)Naming.lookup("nspk");
            answer = access.query(value);
            System.out.println("Article on " + value +" " + answer+" at nspk");
        }
        catch(Exception ae)
        {
            System.out.println(ae);
        }
    }
}