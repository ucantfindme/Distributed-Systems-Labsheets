import java.rmi.*;  
import java.util.*;
public class MyClient{  
public static void main(String args[]){  
try{  
Adder stub=(Adder)Naming.lookup("rmi://localhost:5767/nspk");  
int a,b;
Scanner sc= new Scanner(System.in);
System.out.print("Enter Two Numbers: ");
a=sc.nextInt();
b=sc.nextInt();
System.out.println(stub.add(a,b));  
}catch(Exception e){}  
}  
}  