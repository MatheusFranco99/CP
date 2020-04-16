import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
public class Cost_Cutting {
        public static void main(String agrs[]) throws IOException{
                BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
                int N = Integer.parseInt(br.readLine());
                int a,b,c;
                int i = 0;
                while(i++ < N){
                        String[] nums = br.readLine().split(" ");
                        a = Integer.parseInt(nums[0]);
                        b = Integer.parseInt(nums[1]);
                        c = Integer.parseInt(nums[2]);
                        ArrayList<Integer> arr = new ArrayList<Integer>();
                        arr.add(a); arr.add(b); arr.add(c);
                        Collections.sort(arr);
                        System.out.println("Case " + i + ": " + arr.get(1));
                }
        }
}