# max min方法

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:
            return ""
        else:
            s1 = max(strs)
            s2 = min(strs)
            for i,s in enumerate(s1):
                if len(s2)>i and s is s2[i]:
                    pass
                else:
                    return s1[:i]
            return s1