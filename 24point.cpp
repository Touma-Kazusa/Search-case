#include <cstdio>
#include <cstdlib>
#include <stack>
#define epx 1e-4
using namespace std;
// struct mistar//4444
// {
//     char num;
//     char card[4];
// };
// 12+
int inf;
int s[6] = {0, 1, 1, 1, 1, 0}, number[5], sulotion = 0;
char equation[10];     //1-13 +-*/
char min_equa[20][10]; //min_equa[0]-min_equa[19]
void print()
{
    printf("%d:\n", sulotion);
    // for(int i=0;i<7;i++)
    // {
    //     if (1 <= equation[i] && 13 >= equation[i])
    //         printf("%d ",equation[i]);
    //     else
    //         printf("%c ",equation[i]);
    // }
    double tmp1, tmp2;
    char x[10], y[10], z[10];
    int step = 0;
    stack<double> S;
    for (int i = 0; i < 7; i++)
    {
        if (1 <= equation[i] && 13 >= equation[i])
        {
            tmp1 = (double)equation[i];
            S.push(tmp1);
        }
        else
        {
            step++;
            switch (equation[i])
            {
            case '+':
            {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                S.push(tmp2 + tmp1);
                printf("\t%d.%.1lf+%.1lf=%.1lf\n", step, tmp2, tmp1, tmp2 + tmp1);
                break;
            }
            case '-':
            {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                S.push(tmp2 - tmp1);
                printf("\t%d.%.1lf-%.1lf=%.1lf\n", step, tmp2, tmp1, tmp2 - tmp1);
                break;
            }
            case '*':
            {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                S.push(tmp2 * tmp1);
                printf("\t%d.%.1lf*%.1lf=%.1lf\n", step, tmp2, tmp1, tmp2 * tmp1);
                break;
            }
            case '/':
            {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                S.push(tmp2 / tmp1);
                printf("\t%d.%.1lf/%.1lf=%.1lf\n", step, tmp2, tmp1, tmp2 / tmp1);
                break;
            }
            default:
                printf("error2\n");
                // print();
                break;
            }
        }
    }
    printf("\n");
    return;
}
int judge(char s[])
{
    // print();
    double tmp1, tmp2;
    stack<double> S;
    for (int i = 0; i < 7; i++)
    {
        if (1 <= s[i] && 13 >= s[i])
        {
            tmp1 = (double)s[i];
            S.push(tmp1);
        }
        else
        {
            switch (s[i])
            {
            case '+':
            {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                S.push(tmp2 + tmp1);
                break;
            }
            case '-':
            {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                S.push(tmp2 - tmp1);
                break;
            }
            case '*':
            {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                S.push(tmp2 * tmp1);
                break;
            }
            case '/':
            {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                S.push(tmp2 / tmp1);
                break;
            }
            default:
                printf("error1\n");
                print();
                break;
            }
        }
    }
    tmp1 = S.top();
    if ((tmp1 - epx) <= 24.0 && (tmp1 + epx) >= 24.0)
        return 1;
    else
        return 0;
}
void search(int n)
{
    // printf("%d\n",n);
    if (sulotion >= inf)
        return;
    if (n == 7)
    {
        if (judge(equation))
        {
            sulotion++;
            print();
        }
        return;
    }
    else
    {
        if (s[0] <= s[5] - 2) //put operater
        {
            equation[n] = '+';
            s[0]++;
            search(n + 1);
            s[0]--;

            equation[n] = '-';
            s[0]++;
            search(n + 1);
            s[0]--;

            equation[n] = '*';
            s[0]++;
            search(n + 1);
            s[0]--;

            equation[n] = '/';
            s[0]++;
            search(n + 1);
            s[0]--;
        }
        if (s[5] < 4)
            for (int i = 1; i <= 4; i++) //put number
            {
                if (s[i])
                {
                    s[i] = 0;
                    equation[n] = number[i];
                    s[5]++;
                    search(n + 1);
                    s[5]--;
                    s[i] = 1;
                }
            }
    }
    return;
}

int main()
{
    printf("welcome to ues 24point calculator V1.0 \ncoded by @±ù¶³µÄÂÞ·ÇÓã \nEmall 3204096613@qq.com\n");
    int flag = 0, numflag = 0;
    while (!numflag)
    {
        if (flag)
            printf("illegal input!\n");

        printf("please put your four numbers between 1 to 13\n");
        scanf("%d%d%d%d", &number[1], &number[2], &number[3], &number[4]);

        numflag = 1;
        for (int i = 1; i <= 4; i++)
            if (number[i] > 13 || number[i] < 0)
                numflag = 0;

        flag = 1;
    }
    flag = 0;
    while (inf <= 0)
    {
        if (flag)
            printf("illegal input!\n");
        printf("please tell me how many sulotions you want find most\n");
        scanf("%d", &inf);
        flag = 1;
    }
    search(0);
    if (!sulotion)
        printf("sorry,this question have not sulotion\n");
    system("pause");
    // printf("233\n");
    return 0;
}
