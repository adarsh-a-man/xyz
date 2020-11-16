/*
You are given a string s,an array roll where roll[i] represents rolling first roll[i] characters in string.
you have to apply every roll[i] on string and output final string.rolling means increasing ASCII value of character. like rolling ‘z’ would result in ‘a’,rolling ‘b’ would result in ‘c’,etc.
constraints: 1<=|s|<=10^5
1<=roll[i]<=10^5
For eg: Input:
bca
3
1 2 3
Output:
eeb
*/

// CPP program to find final
// string after roll operations
#include <stdio.h>
// return the final string
// after performing roll operation
// on characters of string
char* findRollOut(char *s, int *roll, int roll_count){
    int i=0;
	int brr[roll_count+1];
	for(i=0; i<roll_count+1; i++) brr[i] = 0;
	for(i = 0; i < roll_count; i++){
		brr[0] += 1;
		brr[roll[i]] -= 1;
	}
	for(i = 1; i < roll_count; i++){
		brr[i] += brr[i-1];
	}

	// change the string according to number
	// of roll operations in brr array

	// s[i] to rolled brr[i] times
	char ch[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	for(int i = 0; i < roll_count; i++){
		int x = brr[i] % 26;
		int y = s[i] - 97;
		s[i] = ch[(x+y)%26];
	}
	return s;
}

// driver program
int main(void){
	char s[] = "zcza";
	int n = 4;

	// roll array
	int roll[] = {1,1,3,4};
	char* res = findRollOut(s, roll, n);
	printf("%s", res);
	return 0;
}
