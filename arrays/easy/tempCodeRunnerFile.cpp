int longestSubarray(vector<int> &arr, int k)
// {
//     int cnt1 = 0;
//     int cnt2 = 0;
//     int i = 0;
//     int sum = 0;
//     for (int j = i + 1; j < arr.size(); j++)
//     {
//         sum += arr[j];
//         if (sum == k)
//         {
//             cnt2 = j - i + 1;
//             if (cnt2 > cnt1)
//             {
//                 cnt1 = cnt2;
//             }
//             i++;
//         }
//     }

//     return cnt1;
// }