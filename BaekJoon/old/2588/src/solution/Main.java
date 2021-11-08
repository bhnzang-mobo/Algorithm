package solution;
import java.util.Scanner;

public class Main {
	public static void main (String [] args) {
		int A,B;
		Scanner sc = new Scanner(System.in);
		A=sc.nextInt();
		B=sc.nextInt();
		System.out.println(A*(B%10));
		System.out.println(A*((B%100)/10));
		System.out.println(A*(B/100));
		System.out.println(A*B);
	}
}