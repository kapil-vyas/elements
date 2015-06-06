class IsUnique {
        public static void main(String[] args) {
                char[] input = {'h','2','l','w','2'};
                System.out.println(isUnique(input));
        }

        public static Boolean isUnique(char[] input) {
                int[] char_set = new int[256];
                for(int i=0; i < input.length; i++) {
                        char_set[input[i]]++;
                        System.out.printf("%d:%c - %d\n", i, input[i], char_set[input[i]]);
                        if( char_set[input[i]]  == 2 )
                                return false;
                }
                return true;
        }
}
