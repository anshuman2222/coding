func reverse(x int) int {
    tmp := x
    
    var sum int = 0
    
    for tmp != 0 {
        
        sum = sum * 10 + tmp % 10
        
        tmp /= 10
    }
    
    if sum < (-(int(math.Pow(2, 31)))) || sum > (int(math.Pow(2, 31) - 1)) {
        
        return 0
        
    } else {
        
        return sum
    }
}
