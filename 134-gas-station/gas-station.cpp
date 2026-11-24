class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totgas = 0;
        int totcost = 0;
        
        
        int st = 0 , currGas = 0;

        for(int i = 0 ; i < gas.size(); i++){
            totgas += gas[i];
            totcost += cost[i];
            currGas += (gas[i] - cost[i]);
            if(currGas < 0 ){
                st = i + 1;
                currGas = 0;
            }
        }
        return totgas < totcost ? -1 : st;
    }
};