class Solution {
public:
    double average(vector<int>& salary) {
        int mini=*min_element(salary.begin(), salary.end());
        int maxi=*max_element(salary.begin(), salary.end());
        
        double sum=0;
        for(auto i: salary) sum+=i;
        
        double n=salary.size()-2;
        return (sum/n)-(mini/n)-(maxi/n); 
    }
};