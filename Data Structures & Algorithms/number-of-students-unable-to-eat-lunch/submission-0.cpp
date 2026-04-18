class Solution {
public:
    queue<int> san;
    queue<int> stu;
    int attempts = 0;
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int i = 0 ; i< sandwiches.size(); i++){
            san.push(sandwiches[i]);
            stu.push(students[i]);
        }
        while(!san.empty() && attempts < stu.size()){
            int u = san.front();
            int v = stu.front();
            if(u == v){
                san.pop();
                stu.pop();
                attempts = 0;
            }
            else{
                stu.pop();
                stu.emplace(v);
                attempts++;
            }
        }
        return stu.size();
    }
};