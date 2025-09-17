class FoodRatings {
public:
    unordered_map<string,string> foodCuisines;
    unordered_map<string,int> foodRatings; 
    unordered_map<string,set<pair<int,string>>> cuisineSet;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; i++) {
            foodCuisines[foods[i]] = cuisines[i];
            foodRatings[foods[i]] = ratings[i];
            cuisineSet[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisines[food];
        int oldRating = foodRatings[food];
        cuisineSet[cuisine].erase({-oldRating, food});
        foodRatings[food] = newRating;
        cuisineSet[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisineSet[cuisine].begin()->second;
    }
};

