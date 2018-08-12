/*
在一个二维数组中（每个一维数组的长度相同），
每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

//从左下角开始搜索
class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        int x = row-1;
        int y = 0; 
        while(x >= 0 && y < col) {
            if (target < array[x][y]) {
                x--;
            } else if (target > array[x][y]) {
                y++;
            } else {
                return true;
            }
        }
        return false;
    }
};