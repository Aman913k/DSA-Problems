class Solution {
public:
    bool parseBoolExpr(string expression) {
        int n=expression.size(); 
        stack<char> boole, opera;
        
        bool achieved;
        string t; 
        for(auto exp: expression){
            if(exp=='!'||exp=='|'||exp=='&') opera.push(exp);
            if(exp=='(' || exp=='f'||exp=='t') boole.push(exp);
            
            if(exp==')'){
                string t;  
                while(boole.top()!='('){
                    t+=boole.top();
                    boole.pop(); 
                }
                boole.pop();  
                char task;
                
                if(!opera.empty()){
                    
                    if(t[0]=='t') achieved=true;
                    else achieved=false;
                    task=opera.top(), opera.pop();
                    
                    if(task=='|') for(auto i: t) if(i=='t') achieved=true;
                    if(task=='&') for(auto i: t) if(i=='f') achieved=false;
                    
                    if(task=='!'){
                        if(t[0]=='f') achieved=true;
                        else achieved=false;
                     
                    }
                    if(achieved==false) boole.push('f');
                    else boole.push('t');
                }
            }
        }
        
        return achieved;  
        
      
    }
};