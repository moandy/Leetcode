#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, int> tmap;
        int sum = 0;
        queue<int> que;
        for (size_t i = 0; i < employees.size(); i++) {
            tmap[employees[i]->id] = i;
            if (id == employees[i]->id) {
                sum += employees[i]->importance;
                for (auto j : employees[i]->subordinates) {
                    que.push(j);
                }
            }
        }
        while (!que.empty()) {
            auto top = que.front();
            que.pop();
            sum += employees[tmap[top]]->importance;
            for (auto j : employees[tmap[top]]->subordinates) {
                que.push(j);
            }
        }
        return sum;
    }
};
