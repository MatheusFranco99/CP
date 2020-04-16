import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.TreeMap;

/* !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 Resultados estao dando errado - acho que nao consegui perceber bem pelo enunciado
 a ordem das operacoes
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/

public class LoansomeCarBuyer {
        public static void main(String args[]) throws IOException{
                BufferedReader br = new BufferedReader( new InputStreamReader(System.in));
                String[] nums = br.readLine().split(" "); // first line args
                int nMonths = Integer.parseInt(nums[0]); // months to pay
                double payment = Double.parseDouble(nums[1]); // payment per month
                double loan = Double.parseDouble(nums[2]); // loan to pay
                int nDepriciation = Integer.parseInt(nums[3]); // number of Depriciations
                while(nMonths > 0){
                        double depList[][] = new double[nDepriciation][2]; // list to store depriciations
                        for (int i = 0; i < nDepriciation; i++){
                                String[] deps =br.readLine().split(" ");
                                depList[i][0] = Double.parseDouble(deps[0]);
                                depList[i][1] = Double.parseDouble(deps[1]);
                        }
                        int month = 0;
                        int depIndex = 0; // Index to find depriciation ratio
                        double dep = depList[0][1]; // depriciation ratio
                        double carValue = loan;
                        double owes = loan;
                        System.out.println(carValue + " : " + owes + "; dep: " + dep);
                        while(month < nMonths){
                                if(depIndex < nDepriciation-1){
                                        if(month >= depList[depIndex+1][0]){
                                                dep = depList[++depIndex][1];
                                        }
                                }
                                carValue = carValue * ( 1 - dep);
                                owes = owes - payment;
                                month++;
                                System.out.println(carValue + " : " + owes + "; dep: " + dep);
                                if(carValue > owes){
                                        System.out.print(month + " month");
                                        if(month>1) System.out.println("s");
                                        else System.out.println();
                                        break;
                                }
                        }
                        
                        nums = br.readLine().split(" "); // take new parameters
                        nMonths = Integer.parseInt(nums[0]);
                        payment = Double.parseDouble(nums[1]);
                        loan = Double.parseDouble(nums[2]);
                        nDepriciation = Integer.parseInt(nums[3]);
                }
        }
}