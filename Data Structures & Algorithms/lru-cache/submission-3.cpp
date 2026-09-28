class LRUCache {
public:

    int cap;
    deque<pair<int,int>> d;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {

         auto it = std::find_if(d.begin(), d.end(), [key](const auto& pair) {
        return pair.first == key;
    });
        
        if(it!=d.end()){
        int value = it->second;
        d.erase(it);

        d.push_front({key,value});
        return value;
        }
        return -1;
}
    
    void put(int key, int value) {
       auto it = find_if(d.begin(),d.end(),[key](const auto& p){
        return p.first==key;
       });
    

    if(it!= d.end()){
        d.erase(it);
    }
    d.push_front({key,value});
    if(d.size()>cap)d.pop_back();
}
};
