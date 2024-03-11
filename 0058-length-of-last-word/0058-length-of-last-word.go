func lengthOfLastWord(s string) int {
    
    n := len(s)
    i := n-1 
    var cnt int
    
    for i>=0 && s[i]==' '{
        i--
    }
    
    for i>=0 {
        cnt++
    
        if s[i]==' '{
            cnt--
            break
        }
        
        i--
    }
    
    return cnt
    
}