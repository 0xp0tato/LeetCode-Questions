class Solution:
    def check(self, nums: List[int]) -> bool:
        flag = False;
        
        for i in range(1, len(nums)):
            if nums[i] < nums[i-1]:
                if flag == False:
                    flag = True
                else:
                    return False
                
        if nums[-1] > nums[0] and flag:
            return False
                
        return True
                