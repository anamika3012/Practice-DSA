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
        return (int)revno;    /// why? because testcase 1036 , no : 1534236469, 
        //the no becomes greater than range of integer during reversal , so java automatically wraps it around int , thus corrupting the value of revno , so we need the ans to be in long , but the return value must be in int , so casting.
    }
}