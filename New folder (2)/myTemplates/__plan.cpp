/* stuff you should look for
 *    ------------------IMPORTANT-----------------------
 *    when u have to check that a bit is present in both the numbers after doing their xor then simply take and with the first number
 *    and take and with the not of second number as if the bit is present in both then theri xor will be zero so taking not will erase
 *    the set bits in b  and taking and with it prooves that this bit was not present in that number if both the ands are sane
 *    for more info u can look to the problem D of educational codeforces round 134
 *              a&(~b)=all set bits in a^b
 *    in that problem what i did was i was checking for the jth bit is present in the xor of 2 numbers or not
 *    i simply did the above stated
 *
 *    ------------------IMPORTANT-----------------------
 * at 1 pe kya hoga wo case bhi soch lo
 * -------custom comparator to use in set or multiset or map or multimap--------
 *
 *      set<data_type,decltype(cmp)>name_of_the_set(cmp)
 *     here cmp is the custom comparator
 *
 * if u want to find the sum of diffrence for all possible 2 pairs its brute would be n^2
       but with some maths u can see that every diffrence is used in total number of its before edges and after edges
       i.e  diff*i*(n-1)
 * mod wala funda kaam na kre to prefix and suffix lga do
 * when u are not able to decide which one to remove then the answer is simply iterate and find the max/min answer for each index
 * if u have to make array increasing by adding 1 to subarray then sum of diffrences(which have to increased) is the answer
 * whenever i want to find the position of first number greater than
     my number then it is good to store all pos of first greater number in prefix
     ans this will help us to achieve our goal
 * sbse pehle question dobara padho sir
 *
 * about lambda function
 *          auto nameOFfunction = [&](what to pass , auto&& nameOFfunction)-> return type{
 *                                  body};
 *
 *
 * if u r multiplying and u have to find equal multipy then u can take 1st and last everytime
 * nlog(log(n)) bhi soch lo sir like jha multiples ka case aya wha pe seive of erathosthenisis ka concept lga do
 * a+b = a^b + 2*a&b
 * a+b = a|b + a&b
 * special cases (n=1?)/ odd/even index
 * sir square wala bhi soch lo
 * follow the basics koi nya try kr rha hai toh uske primitive try kr
 * XOR --> ALWAYS TRY 45132
 */
// *********************************************************************
//--------------------DP Stuff------------------------------------------
// **********************************************************************
/*
dp me 2 case ate hai
1) i can take coins in any order
		iska simple soultion hai
		dp[i]+=dp[i-a[j]];
2) i can take coin in the given order
		isme 2 case ate hai 
	1) i can take coins only ones
		
		iska solution bhi simple hai
			1) using 2d dp
					dp[i][x] = number of ways to find
						 sum x using i coins
				and iska reccurence hai
					dp[i][x]=dp[i-1][x] + dp[i-1][x-a[i]]
					i.e i choose not to take the ith coin
							and now i with i-1 coins and want to 
							find sum x
						+ i choose to take the ith coin 
							and now i m with i-1 coins and 
								want to find sum x-a[i]

			2) using 1d dp
					dp[x] = number of ways to obtain sum x
						and iska reccurence 
					dp[x] = dp[x-a[i]] ---> iterating from x=sum to x>=0
						in order to avoid any chance of taking any coin more than
						one times.



	2) i can take coins any number of times
	
			iska solution bhi simple hai
				
				1) using 2d dp
					dp[i][x]= number of ways to find sum x using i coins
					and iska reccurence 
					dp[i][x]= dp[i-1][x] + dp[i][x-a[i]]
					i.e i choose to not to take ith coin now i want to find
							sum x using i-1 coins
					+  i choose to take it and now i want to find the sum
						x-a[i] from i coins since i can repeat the coins.

			2) using 1d dp
					dp[x] = number of ways to find sum x
						and its reccurence 
						dp[x-a[i]] 
					iterating from sum=0 to sum=given_sum
						since i can use one coin multiple time
			
	
*/