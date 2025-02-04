

class RandomizedSet 
{

private:
    vector<int> values;   

public:
    RandomizedSet() 
    {
      
    }
    
    bool insert(int val) 
    {
        // Check if val already exists
        for (int v : values) {
            if (v == val) return false;
        }
        values.push_back(val);  // Add to vector
        return true;
    }
    
    bool remove(int val) 
    {
        for (int i = 0; i < values.size(); i++) 
        {
            if (values[i] == val) 
            {
                values.erase(values.begin() + i);  // Remove element
                return true;
            }
        }
        return false;  // If not found, return false
    }
    
    int getRandom() 
    {
        // Randomly pick an index from the vector and return the value at that index
        int randomIndex = rand() % values.size();  // Generate a random index
        return values[randomIndex];  // Return the element at that random index
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */