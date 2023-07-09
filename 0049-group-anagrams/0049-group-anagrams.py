class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        mapping = {}

        for i, word in enumerate(strs):
            sorted_word = "".join(sorted(word))
            if sorted_word not in mapping:
                mapping[sorted_word] = []
            mapping[sorted_word].append(i)

        result = []
        for indices in mapping.values():
            group = [strs[i] for i in indices]
            result.append(group)

        return result        