class Solution {
    public String smallestPalindrome(String s) {
        int half=s.length()/2;
        char[] halfchars=s.substring(0,half).toCharArray();
        Arrays.sort(halfchars);
        String first_half=new String(halfchars);
        String second_half=new StringBuilder(first_half).reverse().toString();
        if(s.length()%2!=0)
        {
            char mid=s.charAt(half);
            return first_half+mid+second_half;
        }
        return first_half+second_half;
    }
}