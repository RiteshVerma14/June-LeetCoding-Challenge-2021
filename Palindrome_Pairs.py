class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        a=[]
        for i,j in enumerate(words):
            for k in range(i+1,len(words)):
                if i!=k:
                    r=j+words[k]
                    s=words[k]+j
                    if r==r[::-1]:
                        a.append([i,k])
                    if s==s[::-1]:
                        a.append([k,i])
        return a