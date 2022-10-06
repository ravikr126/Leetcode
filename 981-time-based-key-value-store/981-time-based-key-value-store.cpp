class TimeMap 
{
	private:
    unordered_map<string, map<int,string>> data;

	public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) 
    {
        if (!data.count(key))    // New key insertion
        {
            data[key] = {{timestamp, value}};
            return;
        }
		// If the same timestamp repeats for any key, replace it. We dont really need this line because of constraint but no harm
        if (data[key].count(timestamp)) data[key].erase(timestamp);
		// Finally insert in ordered map
        data[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) 
    {
        if (!data.count(key)) return "";    // key not found
        auto it = data[key].lower_bound(timestamp);
        if (it != data[key].end() && (*it).first==timestamp)    // Exact timestamp found
            return (*it).second;
        if (it == data[key].begin()) return "";    // timestamp asked is before first time set
        --it;    // it now points to the last time it was set before "timestamp"
        return (*it).second;    // finally return value
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */