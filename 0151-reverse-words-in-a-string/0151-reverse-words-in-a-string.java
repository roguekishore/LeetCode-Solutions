class Solution {
    public String reverseWords(String s) {
        s = s.trim();
        String[] arr = s.split("\\s+");
        StringBuilder sb = new StringBuilder();
        for(int i=arr.length-1 ; i>=0 ; i--) {
            System.out.println("\""+arr[i]+"\"");
        }
        for(int i=arr.length-1 ; i>=0 ; i--) {
            if(i==0) {
                sb.append(arr[0]);
                break;
            }
            sb.append(arr[i]);
            sb.append(" ");
        }
        return sb.toString();
    }
}