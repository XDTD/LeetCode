def lengthOfLongestSubstring(s: str) -> int:
    if len(s) < 1:
        return 0
    res = 1
    left ,right=0,0
    while right < (len(s)):
        if s[right] not in s[left:right]:
            if right - left + 1 > res:
                res = right - left + 1
        else:
            left = s[left:].index(s[right])+1+left
            right = right -1
        right = right + 1
    return res


if __name__ == '__main__':
    a = lengthOfLongestSubstring("pwwkew")
    print(a)