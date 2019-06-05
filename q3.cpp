/*Question 3:  Use the most efficient algorithm to find the longest common substring between 2 strings, and complete the following function, 
 * 
 * please write a main() to test your function. 
 * #include <string>
 * string longestCommonSubstring(string* string1, string* string2)
 * {
 * }
 * 
 */ 

#include <bits/stdc++.h> 

using namespace std; 

string longestCommonSubstring(string* string1, string* string2)
{ 
	/*Get strings*/
	string str1 = *string1;
	string str2 = *string2;
	
    /* Get length of both the strings.*/
    int m = str1.length(); 
    int n = str2.length();
  
    /* Variable to store length of longest common substring.*/
    int result = 0; 
  
    /* Variable to store ending point of longest common substring in X.*/
    int end; 
  
    /* Matrix to store result of two consecutive rows at a time.*/
    int len[2][n]; 
  
    /* Variable to represent which row of matrix is current row.*/
    int currRow = 0; 
  
    /* For a particular value of i and j, len[currRow][j] stores length of longest common substring in string X[0..i] and Y[0..j]. */
    for (int i = 0; i <= m; i++) { 
        for (int j = 0; j <= n; j++) { 
            if (i == 0 || j == 0) { 
                len[currRow][j] = 0; 
            } 
            else if (str1[i - 1] == str2[j - 1]) { 
                len[currRow][j] = len[1 - currRow][j - 1] + 1; 
                if (len[currRow][j] > result) { 
                    result = len[currRow][j]; 
                    end = i - 1; 
                } 
            } 
            else { 
                len[currRow][j] = 0; 
            } 
        } 
        /* Make current row as previous row and previous row as new current row. */
        currRow = 1 - currRow; 
    } 
  
    /* If there is no common substring, print -1.*/
    if (result == 0) { 
        return "No common substring"; 
    } 
  
    /*Longest common substring is from index end - result + 1 to index end in X.*/
    return str1.substr(end - result + 1, result); 
} 

/*Main function to test longestCommonSubstring*/
int main()
{
	string stringA, stringB, longsubstr;
	
	/*Input strings*/
	cout<<"Enter first string: ";
	getline(cin, stringA);
	cout<<"Enter second string: ";
	getline(cin, stringB);
	
	/*Call function to find longest common substring*/
	longsubstr = longestCommonSubstring(&stringA, &stringB);
	
	cout<<"Longest substring is: ";
	cout<<longsubstr<<endl;

	return 0;
}
