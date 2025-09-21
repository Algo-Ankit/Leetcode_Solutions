class MovieRentingSystem {
    unordered_map<int, set<pair<int,int>>> available;
    unordered_map<long long,int> priceMap;
    set<tuple<int,int,int>> rented;

    long long encode(int shop,int movie){ 
        return ((long long)shop<<20) | movie; 
    }

public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e: entries) {
            int shop=e[0], movie=e[1], price=e[2];
            priceMap[encode(shop,movie)] = price;
            available[movie].insert({price,shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!available.count(movie)) return res;
        for (auto &p : available[movie]) {
            if (res.size()==5) break;
            res.push_back(p.second);
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceMap[encode(shop,movie)];
        available[movie].erase({price,shop});
        rented.insert({price,shop,movie});
    }

    void drop(int shop, int movie) {
        int price = priceMap[encode(shop,movie)];
        rented.erase({price,shop,movie});
        available[movie].insert({price,shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto &t : rented) {
            if (res.size()==5) break;
            auto [price,shop,movie] = t;
            res.push_back({shop,movie});
        }
        return res;
    }
};


/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */