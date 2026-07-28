class Solution {
    public int largestInteger(int n, int s) {
        if(n * 9 < s) {
            return -1;
        }
        if(s == 0) {
            return 0;
        }
        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++) {
            int d = Math.min(9, s);
            ans.append(d);
            s -= d;
        }

        return Integer.parseInt(ans.toString());
    }
}