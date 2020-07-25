int c1 = 0, c2 = 1, n = arr.length;
        int currSum = 0;
        long ans = 0;
        int mod = (int)Math.pow(10, 9) + 7;
        for(int i = 0; i < n; i++) {
            currSum += arr[i];
            if(currSum % 2 == 0) {
                ans = (ans + c1) % mod;
                c2++;
            } else {
                ans = (ans + c2) % mod;
                c1++;
            }
        }
        return (int)ans;
