while(True):
    n = input()
    if(n==0):
        break
    nums = raw_input().split()
    for i in range(0, len(nums)):
        nums[i] = int(nums[i])
    nums.sort()
    if(n%2==0):
        ans = (nums[n/2]+nums[(n/2)-1])/2.0
        print "%0.1f" % ans
    else:
        print "%0.1f" % nums[len(nums)//2]