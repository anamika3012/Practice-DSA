class Solution {
    public int reverse(int x) {
        long revno = 0;
        while(x !=0){
            int digit = x%10;
            x = x /10;
            revno = revno *10 + digit;
        }
         if(revno > Integer.MAX_VALUE || revno < Integer.MIN_VALUE){
            return 0;
        }
        return (int)revno;
    }
}