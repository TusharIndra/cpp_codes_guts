//Currently done with recursion. once i'll do Dynamic programming then i'll revisit it again.


class Solution {
  public:
    long long sum;
    long long numberOfWays(long long N) {
        if(N<=1)return 1;
        sum=numberOfWays(N-1)+numberOfWays(N-2);
        return sum;
    }
};