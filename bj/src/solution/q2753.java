package solution;
import java.util.*;

public class q2753 {
	public void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		if(a%4!=0) {
			System.out.printf("0");
		}
		else {
			if(a%100==0) {
				if(a%400==0) {
				System.out.printf("1");
				}
				else {
					System.out.printf("0");
				}
			}
			else {
				System.out.printf("1");
			}
		}
	}
}
