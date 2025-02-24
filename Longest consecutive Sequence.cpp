class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_map<int, int > seqMap;
     int longest = 0;
     for(int num : nums){
        if(seqMap.find(num) == seqMap.end()){    //Ignore Duplicates
         int left = seqMap.count(num -  1) ? seqMap[num - 1] : 0;
         int right = seqMap.count(num + 1) ? seqMap[num + 1] : 0;
         int length = left + 1 + right;
         seqMap[num] = length;
         seqMap[num - left] = length;  //Update left boundary
         seqMap[num + right] = length;  //Update right boundary
         longest = max(longest, length);
        }
     } 
     return longest;  
    }
};