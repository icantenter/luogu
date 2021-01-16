#include <iostream>
#include <string>
void move_prefix_table(int prefix[], size_t size);
void prefix_table(std::string &pattern, int prefix[], size_t size);
void kmp_search(std::string &text, std::string &pattern);
int main()
{
    std::string pattern, text;

    std::cin >> text >> pattern;
    kmp_search(text, pattern);
    return 0;
}

void kmp_search(std::string &text, std::string &pattern)
{
    size_t n = pattern.length();
    size_t m = text.length();
    int *prefix = new int[n + 1];
    prefix_table(pattern, prefix, n);

    move_prefix_table(prefix, n);
    //len(text) = m
    //len(pattern) = n

    int i = 0, j = 0;
    while (i < m)
    {
        //完全匹配
        if (j == n - 1 && pattern[j] == text[i])
        {
            std::cout << i - j + 1 << std::endl;
            j = prefix[j];
        }
        //当前匹配
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        //不匹配
        else
        {
            //根据prefix_table前滚
            j = prefix[j];
            if (j == -1)
            {
                i++;
                j = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        std::cout << prefix[i] << ' ';
    }
    
}

//prefix_table向右一格，-1补位
void move_prefix_table(int prefix[], size_t size)
{
    for (int i = size; i > 0; i--)
    {
        prefix[i] = prefix[i - 1];
    }
    prefix[0] = -1;
}

//"前缀"指除了最后一个字符以外，一个字符串的全部头部组合；"后缀"指除了第一个字符以外，一个字符串的全部尾部组合
//生成前缀表
void prefix_table(std::string &pattern, int prefix[], size_t size)
{
    prefix[0] = 0;
    int len = 0;
    int i = 1;
    while (i < size)
    {
        //prefix_table存放的是最长公共前后缀。
        //所以也用到了匹配。
        if (pattern[i] == pattern[len])
        {
            len++;
            prefix[i] = len;
            i++;
        }
        else
        {
            //和最长前缀匹配不上。就利用已经求出的prefix_table进行匹配。
            //直到匹配成功，或到prefix_table尽头
            if (len > 0)
            {
                //prefix_table整体还没后移,所以是len - 1
                len = prefix[len - 1];
            }
            else
            {
                prefix[i] = len;
                i++;
            }
        }
    }
}