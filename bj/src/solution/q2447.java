package solution;
//2447������ �ڹ� ���� �ð��ʰ��� �н�. �Ȱ��� �˰����ε� �ڹٴ� �ȵǰ� C�� �ȴ�. �ڹٶ� ���� �ù�.
import java.util.*;

public class q2447 {
	char pane[][];
	public void stars(int x,int y, int r) {
		if(3<=r) {
			for(int j = 0 ; j < 3 ; j ++) {
				for(int i = 0 ; i < 3 ; i ++) {
					if(i==1 && j ==1) {
						continue;
					}
					stars(x+(i*r/3),y+(j*r/3),r/3);
				}
			}
			
			//remove center
		}
		else {
			this.pane[x-1][y-1]='*';
		}
		
	}
	public void main(String args[]) {
		q2447 qst = new q2447();
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		qst.pane=new char[a][a];
		for(int i = 0 ; i < a ; i ++) {
			Arrays.fill(qst.pane[i],' ');
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
