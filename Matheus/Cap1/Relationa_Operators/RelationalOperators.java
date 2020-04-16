import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class RelationalOperators{
        public static void main(String args[]) throws IOException{
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                int N = Integer.parseInt(br.readLine());
                int i = 2;
                while(N-- > 0 ){
                        String[] nums = br.readLine().split(" ");
                        int a = Integer.parseInt(nums[0]);
                        int b = Integer.parseInt(nums[1]);
                        if(a==b) System.out.println("=");
                        else if(a>b) System.out.println(">");
                        else System.out.println("<");
                }
        }
}