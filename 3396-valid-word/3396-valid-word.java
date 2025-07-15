class Solution {
    public boolean isValid(String word) {
        int size = word.length();

        if(size<3) {
            return false;
        }
        word = word.toLowerCase();
        String vowels = "aeiou";
        String consonants = "bcdfghjklmnpqrstvwxyz";
        boolean v = false;
        boolean c = false;

        for(char s : word.toCharArray()) {
            if(Character.isDigit(s)) {
                continue;
            } else if( vowels.indexOf(s) != -1 ) {
                v = true;
            } else if( consonants.indexOf(s) != -1 ) {
                c = true;
            } else {
                return false;
            }
        }

        return (v && c);
    }
}