import java.lang.*;
//2021-11-09
class Solution {
    public String solution(String new_id) {
        String answer = new String(new_id);
        answer=answer.toLowerCase();
        answer=answer.replaceAll("[^\\w-.]","");
        //정답 : "[^-_.a-z0-9]"
        //여기서 이 부분이 틀렸다.
        //정답은 직관적으로 -와 _와 .와 소문자와 숫자를 제외했다.
        //나는 character 또는 하이픈 또는 마침표가 아닌경우를 상정하고자 했다.
        //[^\\w\\-\\.]맞음
        //[^(\\w\\-\\.)]틀림
        //[](문자셋) 안에서 정의한 괄호는 포획괄호 역할을 하지 않는다.
        //즉, [^(\\w|\\-|\\.)]는 문자 (, 문자 ), 문자 | 를 제외시키고자 하는 문자에 포함시킨 격이다.
        //따라서 원래 내 의도대로 \w와 -와 .를 포함한 문자 셋을 제외한 문자에 대한 정규식을 표현하려면 다음과 같이 작성해야한다.
        //정답 : [^[\\w\\-\\.]]
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
