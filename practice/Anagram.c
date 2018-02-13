/*Check if anagram*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[]="listen";
    char str2[]="silent";
    int track[26]={0};
    int not_anagram = 0;
    int c = 0;
    int length = strlen(str1);
    for(int i = 0;i<length;i++)
    {
        c=(int)(str1[i]-97);
        track[c]+=1;
    }
    for(int i = 0;i<length;i++)
    {
        c=(int)(str2[i]-97);
        track[c]-=1;
    }
    for(int i = 0;i<length;i++)
    {
        if(track[i]!=0)
        {
           not_anagram = 1;
           break;
        }
    }
    if(!not_anagram)
    {
        printf("Anagrams");
    }
}
