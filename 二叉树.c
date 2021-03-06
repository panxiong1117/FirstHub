Problem Description
 


    如上所示，由正整数1，2，3……组成了一颗特殊二叉树。我们已知这个二叉树的最后一个结点是n。现在的问题是，结点m所在的子树中一共包括多少个结点。

    比如，n = 12，m = 3那么上图中的结点13，14，15以及后面的结点都是不存在的，结点m所在子树中包括的结点有3，6，7，12，因此结点m的所在子树中共有4个结点。

Input Description
输入数据包括多行，每行给出一组测试数据，包括两个整数m，n (1 <= m <= n <= 1000000000)。最后一组测试数据中包括两个0，表示输入的结束，这组数据不用处理。

Output Description
 对于每一组测试数据，输出一行，该行包含一个整数，给出结点m所在子树中包括的结点的数目。

Sample Input
3 7
142 6574
2 754
0 0
Sample Output
3
63
498


#include<stdio.h>

int leaf(int a,int b)
{
    if(a + a + 1 - b <= 0)
        return 2+leaf(a*2,b)+leaf(a*2+1,b);
    else if(a + a - b <= 0)
        return 1+leaf(a + a, b);
    return 0;
}

int main()
{
    int a,b;
    int sum;
    while((scanf("%d %d",&a,&b))){
        if(a==0 && b==0) break;
        sum = 1;
        sum += leaf(a,b);
        printf("%d\n",sum);
    }
    return 0;
}
