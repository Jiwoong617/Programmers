using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;

namespace Programmers
{
    class 신고_결과_받기
    {
        public int[] solution(string[] id_list, string[] report, int k)
        {
            int[] answer = new int[id_list.Length];
            string[] report2 = report.Distinct().ToArray();
            int count = 0;

            Dictionary<string, int> dict = new Dictionary<string, int>();
            Dictionary<string, int> ans = new Dictionary<string, int>();

            for(int i = 0; i<report2.Length; i++)
            {
                string[] s = report2[i].Split();
                if (dict.ContainsKey(s[1]))
                    dict[s[1]]++;
                else
                    dict.Add(s[1], 1);
            }

            for (int i = 0; i < report2.Length; i++)
            {
                string[] s = report2[i].Split();
                if (dict[s[1]] >= k)
                {
                    if (ans.ContainsKey(s[0]))
                        ans[s[0]]++;
                    else
                        ans.Add(s[0], 1);
                }
            }

            foreach(string s in id_list)
            {
                if (ans.ContainsKey(s))
                    answer[count] = ans[s];
                else
                    answer[count] = 0;
                count++;
            }

            return answer;
        }

    }
}
