#include <iostream>
#include <string>
const int MAX = 20000010; //字符串长度最大值
int next[MAX], extend[MAX];
void EXKMP(std::string &text, std::string &pattern);
int main()
{
    std::string a, b;
    std::cin >> a >> b;
    EXKMP(a, b);
    int ans = 0;
    for (int i = 0; i < b.length(); i++) 
    {
        ans ^= 1ll * (i + 1) * (next[i] + 1);
    }
    std::cout << ans << std::endl;
    ans = 0;
    for (int i = 0; i < a.length(); i++) 
    {
        ans ^= 1ll * (i + 1) * (extend[i] + 1);
    }
    std::cout << ans;
    return 0;
}



//预处理计算Next数组
void getNext(std::string str)
{
    int i = 0, j, po, len = str.length();
    next[0] = len; //初始化next[0]
    while (str[i] == str[i + 1] && i + 1 < len)
        i++;
    next[1] = i; //计算next[1]
    po = 1;      //初始化po的位置
    for (i = 2; i < len; i++)
    {
        if (next[i - po] + i < next[po] + po) //第一种情况，可以直接得到next[i]的值
            next[i] = next[i - po];
        else //第二种情况，要继续匹配才能得到next[i]的值
        {
            j = next[po] + po - i;
            if (j < 0)
                j = 0; //如果i>po+next[po],则要从头开始匹配
            while (i + j < len && str[j] == str[j + i])
                j++;
            next[i] = j;
            po = i; //更新po的位置
        }
    }
}


//计算extend数组
void EXKMP(std::string &text, std::string &pattern)
{
    int i = 0, j, po, text_len = text.length(), pattern_len = pattern.length();
    getNext(pattern); //计算子串的next数组
    
    while (text[i] == pattern[i] && i < pattern_len && i < text_len)
        i++;
    extend[0] = i;
    po = 0; //初始化po的位置
    for (i = 1; i < text_len; i++)
    {
        if (next[i - po] + i < extend[po] + po) //第一种情况，直接可以得到extend[i]的值
            next[i] = next[i - po];
        else //第二种情况，要继续匹配才能得到extend[i]的值
        {
            j = extend[po] + po - i;
            if (j < 0)
                j = 0; //如果i>extend[po]+po则要从头开始匹配
            while (i + j < text_len && j < pattern_len && text[j + i] == pattern[j])
                j++;
            extend[i] = j;
            po = i; //更新po的位置
        }
    }
}
/*
#include<bits/stdc++.h>

#define N 20000010 

using namespace std;

int q,nxt[N],extend[N];
int slen,tlen;
char s[N],t[N];

void getnxt()
{
    nxt[0]=tlen;//nxt[0]一定是T的长度
    int now=0;
    while(t[now]==t[1+now]&&now+1<tlen)now++;//这就是从1开始暴力
    nxt[1]=now;
    int p0=1;
    for(register int i=2;i<tlen;i++)
    {
        if(i+nxt[i-p0]<nxt[p0]+p0)nxt[i]=nxt[i-p0];//第一种情况
        else
        {//第二种情况
            int now=nxt[p0]+p0-i;
            now=max(now,0);//这里是为了防止i>p的情况
            while(t[now]==t[i+now]&&i+now<tlen)now++;//暴力
            nxt[i]=now;
            p0=i;//更新p0
        }
    }
}

void exkmp()
{
    getnxt();
    int now=0;
    while(s[now]==t[now]&&now<min(slen,tlen))now++;//暴力
    extend[0]=now;
    int p0=0;
    for(register int i=1;i<slen;i++)
    {
        if(i+nxt[i-p0]<extend[p0]+p0)extend[i]=nxt[i-p0];//第一种情况
        else
        {//第二种情况
            int now=extend[p0]+p0-i;
            now=max(now,0);//这里是为了防止i>p的情况
            while(t[now]==s[i+now]&&now<tlen&&now+i<slen)now++;//暴力
            extend[i]=now;
            p0=i;//更新p0
        }
    }
}

int main()
{
    scanf("%s%s",s,t);
    slen=strlen(s),tlen=strlen(t);
    exkmp();
    long long z=0,p=0;
    for(register int i=0;i<tlen;i++)z^=1ll*(i+1)*(nxt[i]+1);//输出nxt
    for(register int i=0;i<slen;i++)p^=1ll*(i+1)*(extend[i]+1);//输出extend
    printf("%lld\n%lld\n",z,p);
    return 0;
}
*/