class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        for(int i=1; i<=8; i++){
            if((c+i)==e && (d+i)==f){
                for(int j=1; j<i; j++){
                    if((c+j)==a && (d+j)==b) return 2;
                }
                return 1;
            }
            if((c+i)==e && (d-i)==f){
                for(int j=1; j<i; j++){
                    if((c+j)==a && (d-j)==b) return 2;
                }
                return 1;
            }
            if((c-i)==e && (d-i)==f){
                for(int j=1; j<i; j++){
                    if((c-j)==a && (d-j)==b) return 2;
                }
                return 1;
            } 
            if((c-i)==e && (d+i)==f){
                for(int j=1; j<i; j++){
                    if((c-j)==a && (d+j)==b) return 2;
                }
                return 1;
            }
        }
        
        if(a==e){
            if(b>f) swap(b,f); 
            if(a==c && (d<b || d>f)) return 1;
            else if(a!=c) return 1; 
        }
        if(b==f){
            if(e>a) swap(e,a); 
            if(b==d && (c<e || c>a)) return 1;
            else if(b!=d) return 1;  
        }
        
        return 2; 
    }
};