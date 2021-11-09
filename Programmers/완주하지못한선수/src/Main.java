import java.util.*;
import java.io.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
		HashMap<String,Integer> map = new HashMap<String,Integer>();
		for(String name : participant) {
//			if(map.containsKey(name)) {
//				map.put(name, map.get(name)+1);
//			}
//			else {
//				map.put(name, 1);
//			}
			map.put(name,map.getOrDefault(name, 1));
		}
		//�߰� : map.getOrDefault(name,0)
		//Ű�� �ش��ϴ� ���� �����ϸ� �� ���� �������� ������ defaultValue�� ��ȯ�ϵ��� ��.
		for(String name : completion) {
//			if(map.get(name)>=2) {
//				map.put(name, map.get(name)-1);
//			}
//			else {
//				map.remove(name);
//			}
			map.put(name, map.get(name)-1);
		}
		String answer="";
		for(String name : map.keySet()) {
			if(map.get(name)!=0) {
				answer=name;
			}
		}
        return answer;
    }
}
public class Main {
	
	public static void main(String args[]) throws Exception{
		//System.setIn(new FileInputStream("input.txt"));
		
	}
}
