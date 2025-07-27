/*
You have n processes forming a rooted tree structure. You are given two integer arrays pid and ppid, where pid[i] is the ID of the ith process and ppid[i] is the ID of the ith process's parent process.

Each process has only one parent process but may have multiple children processes. Only one process has ppid[i] = 0, which means this process has no parent process (the root of the tree).

When a process is killed, all of its children processes will also be killed.

Given an integer kill representing the ID of a process you want to kill, return a list of the IDs of the processes that will be killed. You may return the answer in any order.
*/
class Solution {
    vector<int>ans;
    void dfs(int node,unordered_map<int,set<int>>& mp){
        ans.push_back(node);
        for(auto& child:mp[node]){
            dfs(child,mp);
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,set<int>>mp;
        for(int i=0;i<pid.size();i++){
            mp[ppid[i]].insert(pid[i]);
        }
        dfs(kill,mp);
        return ans;
    }
};
