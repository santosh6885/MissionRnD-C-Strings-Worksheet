/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/

char KthIndexFromEnd(char *str, int K) {
	int i=0, len,index=0;
	char temp;
	if (str == '\0' || str == "" || K<0)
		return '\0';

	for (len = 0; str[len]; len++);
	if (K > len)
		return '\0';
	len--;
	for (i = len; i >= 0; i--){
		if (K == index)
			return str[i];
		index++;
	}
	
	
	

	

	//return '\0';
}