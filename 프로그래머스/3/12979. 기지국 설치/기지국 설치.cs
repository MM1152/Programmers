using System.Collections.Generic;
    class Solution
    {
        public int solution(int n, int[] stations, int w)
        {
            int answer = 0;
            int index = 1;
            foreach(var a in stations) {
                int cnt = a - w - index ;
                if(cnt > 0) {
                    answer += cnt / (w * 2 + 1);
                    answer += cnt % (w * 2 + 1) == 0 ? 0 : 1;
                }
                index = a + w + 1;
            }
            if(index <= n) {
                int cnt = n - index + 1;
                answer += cnt / (w * 2 + 1);
                answer += cnt % (w * 2 + 1) == 0 ? 0 : 1;
            }
            //Console.WriteLine(answer);
            return answer;
        }
    }