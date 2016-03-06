/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void rev_word(char *str, int x, int y);
void str_words_in_rev(char *input, int len){
	int i,  l, j = 0;
	char temp;
	l = len - 1;
	for (i = 0; i < l; i++, l--){
		temp = input[i];
		input[i] = input[l];
		input[l] = temp;
	}
	for (i = 0; input[i]; i++){
		if (input[i] == ' '){
			rev_word(input, i - 1, j);
			j = i + 1;

		}
		if (input[i + 1] == '\0')
			rev_word(input, i, j);

	}
}
void rev_word(char *str, int x, int y){
	int i;
	char temp;
	for (i = y; i < x; i++, x--){
		temp = str[i];
		str[i] = str[x];
		str[x] = temp;
	}

}