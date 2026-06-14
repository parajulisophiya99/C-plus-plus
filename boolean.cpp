#include <iostream>

int main()

{

int num1 = 11; /* 11 = 00001011 */

int num2 = 22; /* 22 = 00010110 */

int result = 0;

result = num1 & num2;

cout <<"num1 & num2: "<<result<<;

result = num1 | num2;

cout<<"num1 | num2: "<<result<<;//for OR, if at least one of the bits is 1, the result is 1; if both bits are 0, the result is 0.

result = num1^ num2;//for XOR, if the bits are different, the result is 1; if the bits are the same, the result is 0.

cout<<"num1 ^ num2: "<<result<<endl;//for NOT, it inverts the bits of the number. If the bit is 0, it becomes 1; if the bit is 1, it becomes 0.

result = -num1;//for negation, it changes the sign of the number. If the number is positive, it becomes negative; if the number is negative, it becomes positive.

cout<<"-num1: "<<result<<endl;//for left shift, it shifts the bits of the number to the left by a specified number of positions. The empty positions on the right are filled with 0s. For example, if we left shift num1 by 2 positions, the result will be 44 (00001011 << 2 = 00010110).

result = num1 << 2;

cout<<"num1 << 2: "<<result<<endl;

result = num1 >> 2;

cout<<"num1 >> 2: "<<result;

return 0;
}