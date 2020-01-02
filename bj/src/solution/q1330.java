package solution;

import java.util.*;

public class q1330 {
	public void main(String args []) {
		int a, b;
		Scanner sc = new Scanner(System.in);
		a=sc.nextInt();
		b=sc.nextInt();
		if(a<b) {
			System.out.println("<");
		}
		else if (a>b) {
			System.out.println(">");
		}
		else if (a==b) {
			System.out.println("==");
		}//System.out.print(a>b?">":a<b?"<":"==");try this.
	}
}
