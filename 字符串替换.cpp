/*
请实现一个函数，将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
*/

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int count = 0;
        for (int i = 0; i< length; i++) {
            if (str[i] == ' ') {
                count++;
            }
        }
        int newlength = length+2*count;
        str[newlength] = '\0';
        for (int i = length-1, j = newlength-1; i >= 0; i--) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
            } else {
                str[j--] = str[i];
            }
        }
	}
};
