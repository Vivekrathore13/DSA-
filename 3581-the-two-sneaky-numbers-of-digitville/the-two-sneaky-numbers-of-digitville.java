import java.util.*;

class Solution {
    public int[] getSneakyNumbers(int[] nums) {
        Map<Integer, Integer> count = new HashMap<>();
        List<Integer> result = new ArrayList<>();

        for (int num : nums) {
            count.put(num, count.getOrDefault(num, 0) + 1);
        }

        for (int key : count.keySet()) {
            if (count.get(key) == 2) {
                result.add(key);
            }
        }

        // convert list to array
        int[] ans = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            ans[i] = result.get(i);
        }

        return ans;
    }
}
