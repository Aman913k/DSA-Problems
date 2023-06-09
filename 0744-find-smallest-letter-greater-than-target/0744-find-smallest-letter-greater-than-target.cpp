class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int low=0, high=n-1;
        int mid=0;
        
        if(letters[n-1]<=target) return letters[0];
        else target++;
        
        while(low<=high){
            mid=low+(high-low)/2;
            
            if(letters[mid]==target) return letters[mid];  
            if(letters[mid]<=target) low=mid+1;
            else high=mid-1;
        }
        
        return letters[low];  
        
        
    }
};