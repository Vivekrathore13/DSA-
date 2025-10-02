class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drank = numBottles;       // total bottles drunk
        int empty = numBottles;       // empty bottles after drinking
        
        while (empty >= numExchange) {
            empty -= numExchange;   
            numExchange++;           
            drank++;                  
            empty++;                  
        }
        
        return drank;
    }
};
