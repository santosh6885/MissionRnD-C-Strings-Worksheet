/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
int power_of_ten(int n);


void number_to_str(float number, char *str,int afterdecimal){
	int inum,inumtemp, i = 0 ,j=0,len,templen,mul,limit,check=0;
	char temp;
	float fnum;
	
	if (number < 0){
		str[i++] = '-';
		number = -(number);
	}
	j = i;
	inum = int(number);
	fnum = number - float(inum);
	limit = afterdecimal;
	while (inum != 0){
		str[i] = (inum % 10)+'0';
		inum = inum / 10;
		i++;

	}
	str[i] = '\0';
	len = i;
	templen = i - 1;
	
	for (i = j; i<templen; i++,templen--){
		temp = str[i];
		str[i] = str[templen];
		str[templen] = temp;

	}
	if (afterdecimal != 0){
		str[len++] = '.';
		fnum = fnum * power_of_ten(limit);
		inum = int(fnum);
		inumtemp = inum;
		while (inumtemp != 0){
			inumtemp /= 10;
			check++;

		}
		while (check < limit){
			str[len++] = '0';
			check++;
			limit--;
			afterdecimal--;
		}
		limit--;
		for (i = 0; i < afterdecimal; i++){

			inumtemp = inum;
			str[len++] = inumtemp / power_of_ten(limit) + '0';
			inum = inum % power_of_ten(limit);
			limit--;
		}
	}
	str[len] = '\0';


	
	
}
int power_of_ten(int n){
	int i, r = 1;
	for (i = 0; i < n; i++)
		r = r * 10;
	return r;
}
