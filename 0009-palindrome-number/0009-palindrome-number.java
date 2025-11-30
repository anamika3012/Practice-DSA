class Solution {
    public boolean isPalindrome(int x) {
        int num = x;
        int revno = 0;
        if( num < 0){
            return false;
        }
        while(x !=0){
            int digit = x%10;
            revno = revno*10 + digit;
            x = x/10;
        }
        if(revno == num){
            return true;
        }
        return false;
    }
}