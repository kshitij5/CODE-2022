class Solution {
public:
    // Maths Geometry
    // tc - o(n)
    // sc - o(1)
    
    // this is a easy question but with a trick
    // to solve this program all we needed was to evaluate certain test cases and conclude to a hypotheses that would  have helped us generate the algorithm
    // our aim is to just to ensure that the last direction in which robot is moving is either to the left, right or downward itself
    // towards the origin point
    // in all these cases the robot will be able to return to origin else he will keep moving away from origin point
    bool isRobotBounded(string instructions) {
        vector<vector<int>> dir = {{0,1}, {-1, 0}, {0, -1}, {1,0}};
        int i = 0;
        int x = 0;
        int y = 0;
       
        for(int s = 0; s < instructions.size(); s++){
            if(instructions.at(s) == 'L'){
                i = (i + 1) % 4;
            }
            else if(instructions.at(s) == 'R'){
                i = (i + 3) % 4;
            }
            else{
                x = x + dir[i][0];
                y = y + dir[i][1];
            }
        }
        return x == 0 && y == 0 || i != 0;
    }
};