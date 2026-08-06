import java.util.*;

class LFUCache {

    int capacity;
    int minFreq;

    Map<Integer, Integer> keyToValue;
    Map<Integer, Integer> keyToFreq;
    Map<Integer, LinkedHashSet<Integer>> freqToKeys;

    public LFUCache(int capacity) {
        this.capacity = capacity;
        minFreq = 0;

        keyToValue = new HashMap<>();
        keyToFreq = new HashMap<>();
        freqToKeys = new HashMap<>();
    }

    public int get(int key) {

        if (!keyToValue.containsKey(key))
            return -1;

        updateFreq(key);
        return keyToValue.get(key);
    }

    public void put(int key, int value) {

        if (capacity == 0)
            return;

        if (keyToValue.containsKey(key)) {
            keyToValue.put(key, value);
            updateFreq(key);
            return;
        }

        if (keyToValue.size() == capacity) {
            LinkedHashSet<Integer> set = freqToKeys.get(minFreq);
            int removeKey = set.iterator().next();
            set.remove(removeKey);

            keyToValue.remove(removeKey);
            keyToFreq.remove(removeKey);
        }

        keyToValue.put(key, value);
        keyToFreq.put(key, 1);
        freqToKeys.computeIfAbsent(1, k -> new LinkedHashSet<>()).add(key);
        minFreq = 1;
    }

    private void updateFreq(int key) {

        int freq = keyToFreq.get(key);

        freqToKeys.get(freq).remove(key);

        if (freq == minFreq && freqToKeys.get(freq).isEmpty()) {
            minFreq++;
        }

        keyToFreq.put(key, freq + 1);
        freqToKeys.computeIfAbsent(freq + 1, k -> new LinkedHashSet<>()).add(key);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */