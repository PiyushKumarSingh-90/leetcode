class MyHashMap {
public:
    vector<int>Hm;

    MyHashMap() 
    {
      Hm.resize(1000001,-1);
    }
    
    void put(int key, int value) 
    {
        Hm[key] = value;
    }
    
    int get(int key) 
    {
    
        return Hm[key];
    }
    
    void remove(int key) 
    {
        Hm[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */