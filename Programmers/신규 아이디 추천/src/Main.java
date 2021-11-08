import java.lang.*;
//2021-11-09
class Solution {
    public String solution(String new_id) {
        String answer = new String(new_id);
        answer=answer.toLowerCase();
        answer=answer.replaceAll("[^\\w-.]","");
        //���� : "[^-_.a-z0-9]"
        //���⼭ �� �κ��� Ʋ�ȴ�.
        //������ ���������� -�� _�� .�� �ҹ��ڿ� ���ڸ� �����ߴ�.
        //���� character �Ǵ� ������ �Ǵ� ��ħǥ�� �ƴѰ�츦 �����ϰ��� �ߴ�.
        //[^\\w\\-\\.]����
        //[^(\\w\\-\\.)]Ʋ��
        //[](���ڼ�) �ȿ��� ������ ��ȣ�� ��ȹ��ȣ ������ ���� �ʴ´�.
        //��, [^(\\w|\\-|\\.)]�� ���� (, ���� ), ���� | �� ���ܽ�Ű���� �ϴ� ���ڿ� ���Խ�Ų ���̴�.
        //���� ���� �� �ǵ���� \w�� -�� .�� ������ ���� ���� ������ ���ڿ� ���� ���Խ��� ǥ���Ϸ��� ������ ���� �ۼ��ؾ��Ѵ�.
        //���� : [^[\\w\\-\\.]]
        answer=answer.replaceAll("\\.{2,}+", ".");
        answer=answer.replaceAll("^\\.", "");
        answer=answer.replaceAll("\\.$", "");
        if(answer.isBlank()) answer = answer.concat("a");
        if(answer.length()>=16) {
        	answer=answer.substring(0, 16);
            answer=answer.replaceAll("\\.$", "");
        }
        while(answer.length()<=2) {
        	answer=answer.concat(Character.toString(answer.charAt(answer.length()-1)));
        }
        System.out.println(answer);
        return answer;
       
    }
}

public class Main {
	public static void main(String args[]) {
		Solution test = new Solution();
		test.solution("(|)f0923..jisd-f_.");
	}
	
}
