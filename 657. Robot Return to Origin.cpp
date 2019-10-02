class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        int i = 0;
        while(moves[i] != '\0'){
            if(moves[i] == 'U'){
                x--;   
            }
            else if(moves[i] == 'R'){
                y++;
            }
            else if(moves[i] == 'D'){
                x++;
            }
            else if(moves[i] == 'L'){
                y--;
            }
            i++;
        }
        return (x==0&&y==0);
    }
};