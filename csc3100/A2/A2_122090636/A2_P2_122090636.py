def maxSlidingWindow(nums, k):
    dq, ans = [], []
    for i in range(len(nums)):
        while dq and dq[0] <= i - k:
            dq.pop(0)
        while dq and nums[dq[-1]] < nums[i]:
            dq.pop(-1)

        dq.append(i)
        if i >= k - 1:
            ans.append(nums[dq[0]])

    return ans

_, k = map(int, input().split())
nums = list(map(int, input().split()))

ans_list = maxSlidingWindow(nums, k)
for ans in ans_list:
    print(ans)
