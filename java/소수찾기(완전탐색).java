import java.util.*;
class Solution {
    int arr[] ;
    boolean visit[];
    int n,l;
    String s;
    Set<Integer> set = new HashSet<>();
    public void isPrime(int x){
        boolean flag=true;
        if(x==0 ||x==1){
            return ;
        }
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                flag=false;
                break;
            }
        }
        if(flag){
            set.add(x);
        }
    }
    public  void cal(){
        int num=0;
        for(int i=0;i<n;i++){
            int cur = (int)(s.charAt(arr[i])-'0');
            num *= 10;
            num += cur;
        }
        isPrime(num);
    }
    public  void go(int depth){
        if(depth==n){
            cal();
            return ;
        }
        for(int i=0;i<l;i++){
            if(!visit[i]){
                arr[depth]=i;
                visit[i]=true;
                go(depth+1);
                visit[i]=false;
                arr[depth]=0;
            }
        }
        return ;
        
    }
    public int solution(String numbers) {
        int answer = 0;
        s = numbers;
        int len = numbers.length();
        arr = new int[len];
        visit = new boolean[len];
        for(int i=0;i<len;i++){
            visit[i]=false;
        }
        l = len;
        
        
        for(int i=1;i<=len;i++){
            n=i;
            go(0);
        }
        answer = set.size();
            
        
        return answer;
        
    }
}