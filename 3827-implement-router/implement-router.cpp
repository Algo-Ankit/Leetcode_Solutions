class Router {
public:
    int limit;
    deque<tuple<int,int,int>> dq; // queue of packets {src,dest,timestamp}
    unordered_set<long long> seen; // to check duplicates
    unordered_map<int, vector<int>> destMap; // dest->{timestamps} currently in router
    unordered_map<int,int> startIdx; // dest->index of first valid timestamp in vector

    Router(int memoryLimit) {
        limit = memoryLimit;
    }
    
    long long encode(int src,int dest,int timest){
        // Encode (source,destination,timestamp) into one number for hashing
        //Rather than writing a custom hash for a tuple, we pack all three values into one number. 
        return ((long long)src << 48) ^ ((long long)dest << 30) ^ (long long)timest;
    }

    bool addPacket(int src, int dest, int timest) {
        long long key = encode(src,dest,timest);
        if(seen.count(key)) return false; // dont add duplicate

        if((int)dq.size()==limit){
            auto[s,d,t]=dq.front();
            dq.pop_front();
            seen.erase(encode(s,d,t));
            // lazy removal: mark by increasing startIdx
            if(!destMap[d].empty() && startIdx[d] < (int)destMap[d].size() && destMap[d][startIdx[d]]==t)
                startIdx[d]++;
        }

        dq.emplace_back(src,dest,timest);
        seen.insert(key);
        destMap[dest].push_back(timest);
        return true;
    }
    
    vector<int> forwardPacket() {
        if(dq.empty()) return {};
        auto[s,d,t]=dq.front();
        dq.pop_front();

        seen.erase(encode(s,d,t));
        if(!destMap[d].empty() && startIdx[d] < (int)destMap[d].size() && destMap[d][startIdx[d]]==t)
            startIdx[d]++;
        return {s,d,t};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        if (!destMap.count(destination)) return 0;
        auto &v = destMap[destination];
        int start = startIdx[destination];
        auto it1 = lower_bound(v.begin()+start, v.end(), startTime);
        auto it2 = upper_bound(v.begin()+start, v.end(), endTime);
        return (int)(it2 - it1);
    }
};


/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */