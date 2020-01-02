package solution;

import java.util.*;

public class q2447 {
	char pane[][];
	public void stars(int x,int y, int r) {
		if(3<=r) {
			stars(x,y,r/3);
			stars(x+r/3,y,r/3);
			stars(x+2*r/3,y,r/3);
			
			stars(x,y+r/3,r/3);
			stars(x+2*r/3,y+r/3,r/3);
			
			stars(x,y+2*r/3,r/3);
			stars(x+r/3,y+2*r/3,r/3);
			stars(x+2*r/3,y+2*r/3,r/3);
			
			//remove center
			for(int i = y+r/3 ; i < y+2*r/3; i ++) {
				for(int j = x+r/3 ; j < x+2*r/3 ; j ++) {
						this.pane[j-1][i-1]=' ';
				}
			}
		}
		
	}
	public static void main(String args[]) {
		q2447 qst = new q2447();
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		qst.pane=new char[a][a];
		for(int i = 0 ; i < a ; i ++) {
			Arrays.fill(qst.pane[i],'*');
		}
		
		
		qst.stars(1,1,a);
		for(int i = 0 ; i < a ; i ++) {
			for(int j = 0 ; j < a ; j ++) {
			 System.out.printf("%c",qst.pane[j][i]);
			}
			System.out.printf("\n");
		}
	}
}
