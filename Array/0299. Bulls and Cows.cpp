// 299. Bulls and Cows
// Easy

// You are playing the following Bulls and Cows game with your friend: You write down a number and ask your friend to guess what the number is. Each time your friend makes a guess, you provide a hint that indicates how many digits in said guess match your secret number exactly in both digit and position (called "bulls") and how many digits match the secret number but locate in the wrong position (called "cows"). Your friend will use successive guesses and hints to eventually derive the secret number.

// Write a function to return a hint according to the secret number and friend's guess, use A to indicate the bulls and B to indicate the cows. 

// Please note that both secret number and friend's guess may contain duplicate digits.

// Example 1:

// Input: secret = "1807", guess = "7810"

// Output: "1A3B"

// Explanation: 1 bull and 3 cows. The bull is 8, the cows are 0, 1 and 7.
// Example 2:

// Input: secret = "1123", guess = "0111"

// Output: "1A1B"

// Explanation: The 1st 1 in friend's guess is a bull, the 2nd or 3rd 1 is a cow.
// Note: You may assume that the secret number and your friend's guess only contain digits, and their lengths are always equal.
#include<sstream>

class Solution {
public:
    string getHint(string secret, string guess) {
        int digit_secret[10] = {0}, digit_guess[10] = {0};
        int A = 0, B = 0;

        for (int i = 0; i < secret.size(); ++i)
        {
        	if (secret[i] == guess[i])
        		A++;
        	else
        	{
        		int a = secret[i] - '0';
        		int b = guess[i] - '0';

        		if (digit_secret[b] > 0)
        		{
        			B++;
        			digit_secret[b]--;
        		}
        		else
        			digit_guess[b]++;

        		if (digit_guess[a] > 0)
        		{
        			B++;
        			digit_guess[a]--;
        		}
        		else
        			digit_secret[a]++;
        	}
        }

        return to_string(A) + "A" + to_string(B) + "B";
    }
};


// Runtime: 4 ms, faster than 94.75% of C++ online submissions for Bulls and Cows.
// Memory Usage: 6.6 MB, less than 100.00% of C++ online submissions for Bulls and Cows.