import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Division_of_Nlogonia{
        public static void main(String args[]) throws IOException{
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                int numQ;
                numQ=Integer.parseInt(br.readLine());
                while(numQ!=0){
                        String[] coordDiv = br.readLine().split(" ");
                        long XD = Long.parseLong(coordDiv[0]);
                        long YD = Long.parseLong(coordDiv[1]);
                        while(numQ-- > 0){
                                String[] coordCasa = br.readLine().split(" ");
                                long X = Long.parseLong(coordCasa[0]);
                                long Y = Long.parseLong(coordCasa[1]);
                                if(X == XD || Y == YD) System.out.println("divisa");
                                else if( X > XD){
                                        if(Y > YD) System.out.println("NE");
                                        else System.out.println("SE");
                                }
                                else{
                                        if(Y > YD) System.out.println("NO");
                                        else System.out.println("SO"); 
                                }
                        }
                        numQ=Integer.parseInt(br.readLine()); 
                }
        }
}