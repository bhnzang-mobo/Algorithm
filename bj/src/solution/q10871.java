package solution;

import java.util.*;

public class q10871 {
	public static void main (String args[]) {
		Scanner sc = new Scanner (System.in);
		int N = sc.nextInt();
		int X = sc.nextInt();
		int num[]=new int[N];
		for(int i = 0 ; i < N ; i ++) {
			int com = sc.nextInt();
			if(com<X) {
				System.out.printf("%d ",com);
			}
		}
		
	}
}
