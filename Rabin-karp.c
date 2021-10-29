#include <stdio.h>
#include <string.h>
#define d 256
void numOfPattern (char pattern[], char text[], int q){
    int m = strlen(pattern);
    int n = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    //The value of h would be pow(d,m -1)%q
    for(i = 0; i < m-1; i++)
    {
        h = (h*d)%q;
    }
    for(i = 0; i < m; i++)
    {
        p = (d*p + pattern[i])%q;
        t = (d*t + text[i])%q;
    }
    for(i = 0; i <= n - m; i++){
        /*
           Check the hash values of current window of the text
           and pattern. If the hash value matches then only check
           for characters one by one.

        */
       if(p == t){
           //Check for the characters one by one.
           for(j = 0; j < m; j++){
               if(text[i+j]!=pattern[j]){
                   break;
               }
           }
           //if p == t & pat[0...m-1]=txt[i,i+1,..i+m-1]
           if(j == m){
               printf("Pattern found at position :%d \n",i+1);
           }
       }
       /*
        Calculate hash value for next window of text: 
        remove the leading digit, add the trailing digit.
       */
      if(i < n-m){
          t = (d*(t-text[i]*h)+text[i+m])%q;
          //we might get negative value of t, convert it into positive.
          if(t<0){
              t = t+q;
          }
      }
    }
}
int main() 
{
  char text[] = "DDPPDPDD";
  char pattern[] = "DD";
  int q = 11;
  numOfPattern(pattern, text, q);
}