struct Task {
    int priority;
    int task;
    int user;
};

struct compare {
    bool operator()(const Task& a, const Task& b) const {
        if (a.priority != b.priority) return a.priority > b.priority;
        return a.task > b.task;
    }
};

class TaskManager {
public:
    set<Task, compare> s; // stores tasks sorted
    unordered_map<int, set<Task>::iterator> pos; // taskId -> iterator in set

    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0], taskId = t[1], priority = t[2];
            auto it = s.insert({priority, taskId, userId}).first;
            pos[taskId] = it;
        }
    }
    
    void add(int userId, int taskId, int priority) {
        auto it = s.insert({priority, taskId, userId}).first;
        pos[taskId] = it;
    }
    
    void edit(int taskId, int newPriority) {
        auto it = pos[taskId];
        Task updated = *it;
        s.erase(it);
        updated.priority = newPriority;
        pos[taskId] = s.insert(updated).first;
    }
    
    void rmv(int taskId) {
        auto it = pos.find(taskId);
        if (it == pos.end()) return;
        s.erase(it->second);
        pos.erase(it);
    }
    
    int execTop() {
        if (s.empty()) return -1;
        auto it = s.begin();
        int userId = it->user;
        pos.erase(it->task);
        s.erase(it);
        return userId;
    }
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */