import java.util.*;
class Solution {
    HashMap<Character,Integer> map  = new HashMap<>();
    public int solution(String skill, String[] skill_trees) {
        int answer = 0;
        for(int i=0;i<skill.length();i++){
            map.put(skill.charAt(i),i+1);
        }
        for(int i=0;i<skill_trees.length;i++){
            ArrayList<Integer> arr = new ArrayList<>();
            String cur = skill_trees[i];
            for(int j=0;j<cur.length();j++){
                if(map.containsKey(cur.charAt(j))){
                    arr.add(map.get(cur.charAt(j)));
                }
            }
            
            boolean flag=true;
            if(arr.size()>0){
                if(arr.get(0)!=1){
                    flag=false;
                }
            }
            for(int j=1;j<arr.size();j++){
                if(arr.get(j)-arr.get(j-1)!=1){
                    flag=false;
                    break;
                }
            }
            if(flag)
                answer++;
        }
        return answer;
    }
}