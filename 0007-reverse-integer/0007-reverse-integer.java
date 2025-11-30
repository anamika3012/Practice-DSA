class Solution {
    public int reverse(int x) {
        int revno = 0;
        int num = x;
        while(num !=0){
            int digit = num%10;
            num = num /10;
            revno = revno *10 + digit;
        }
         if(revno > Integer.MAX_VALUE || revno < Integer.MIN_VALUE){
            return 0;
        }
        return revno;
    }
}