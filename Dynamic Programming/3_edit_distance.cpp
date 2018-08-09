/*

Given two strings str1 and str2 and below operations that can performed on str1. 
Find minimum number of edits (operations) required to convert ‘str1’ into ‘str2’.

Insert
Remove
Replace

*/

/*

	-	G 	E 	E 	K

-   0	1	2	3	4

G 	1	0 	1 	2 	3

E 	2	1 	0 	1 	2

S 	3 	2 	1 	1 	2

E 	4 	3 	2 	1 	2
	
K 	5 	4 	3 	2 	1

*/


/*

if str_1[i] == str_2[j]
 	dp[i][j] = dp[i-1][j-1]
else
	dp[i][j] = min(dp[i-1][j-1],
					dp[i-1][j],
					dp[i][j-1]) + 1

*/