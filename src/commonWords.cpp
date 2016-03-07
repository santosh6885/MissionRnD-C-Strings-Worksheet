/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>

#include <malloc.h>

#define SIZE 31
int check_common(char *str1, char *str2, int x, int y);

char ** commonWords(char *str1, char *str2) {
	int i,j=0,k,check,x=0,y=0,m,flag=0;
	if (str1 == '\0' || str2 == '\0' || str1 == " " || str2 == " ")
		return NULL;
	char **com_words = (char **)malloc(SIZE*sizeof(char));
	for (i = 0; str1[i]; i++){
		if (str1[i] == ' ' && i>0){
			
			k = i - 1;
			
			check = check_common(str1, str2, j,k);
		if (check == 1){
				flag = 1;
				com_words[x] = (char *)malloc(SIZE*sizeof(char));
				for (m = j; m < i; m++){
					com_words[x][y] = str1[m];
					y++;
				}
				com_words[x][y] = '\0';
				y = 0;
				x++;

			}
			j = i + 1;
		}
		if (str1[i + 1] == '\0'){
			k = i;
			check = check_common(str1, str2, j, k);
			if (check == 1){
				flag = 1;
				com_words[x] = (char *)malloc(SIZE*sizeof(char));
				for (m = j; m < i; m++){
					com_words[x][y] = str1[m];
					y++;
				}
				com_words[x][y] = '\0';
				

			}
		}

		
	}
	if (flag == 0)
		return NULL;
	else 
		return com_words;

	//return NULL;
}
int check_common(char *str1, char *str2, int x, int y){
	int i, j,count=0,k;
	k = x;
	if (str1[x] == ' ')
		return 0;
	for (i = 0; str2[i]; i++){
		if ((str2[i] == str1[k])){
			k++;
			count++;
		}
		else{
			k = x;
			count = 0;
		}
		if (count>0 && count == ((y - x)+1))
			return 1;
	}
	return 0;
}