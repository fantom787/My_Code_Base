Okay, so here it goes.
Replace A with 0, U with 1 and N with 2.
The problem is to find no of strings of length N such that there exists a subarray of size 3 having 3 different numbers.

Suppose you have a zeros, b ones and N-(a+b) twos. (Assume N-(a+b) = c for simplicity)

Now first place zeros and ones. Obviously now ur string looks like 00111000...
.Basically there are strips of ones and zeros.

Assume there are k strips in total and first letter is 0. (We will consider the case where first letter is 1 later).

There are ceil(k/2) strips of zeros and floor(k/2) strips of ones.

The number of ways to get such a string is to first place zeros in ceil(k/2) strips. If xi denoes the no of zeros is ith strip then we gotta find no of positive integral solutions of 

x1 + x2...+x(ceil(k/2)) = a
This is choose(a-1,ceil(k/2)-1).

Similarly to place ones there are choose(b-1,floor(k/2)-1).

To form the string of zeros and ones we have 

choose(a-1,ceil(k/2)-1)*choose(b-1,floor(k/2)-1) ways.

Now we gotta insert twos. There has to be exactly one 2 in the (k-1) "gaps" between two strips of zeros and ones. (At least one such "gap" must exist)

000 (gap) 111 00000 (gap)...so on

This can be done with plain inclusion exclusion.

We choose p gaps in which we guarantee to fill it with twos. The no of ways are-
choose(k-1,p) to choose p gaps and fill it with p twos. We have c-p twos remaining.

Now there are a+b-p+1 spaces between letters left to fill in ones and zeros (There are total (a+b+1) spaces out of with k-1 are "special" spaces or "gaps" out of which I have already used p "gaps"/"spaces").

This is no of non negative solutions of 
x1+x2+x3...+x(a+b-p+1)=c-p

Where xi means the no of twos filled in the ith leftover "space" 
This are choose(c+a+b-2p,a+b-p) ways for this.

So if we have choose(k-1,p)*choose(c+a+b-2p,a+b-p) 
ways to fill twos in spaces ensuring that at least p special gaps have exactly one 2 filled inside it. 

So, no of ways in which at least 1 special gap has exactly 1 two inside it is:

Sigma( (-1)^p * choose(k-1,p) * choose(c+a+b-2p,a+b-p)) 

over all p from [0,k-1]. 

The case when strip begins with 1 (instead of 0 that we assumed initially) can be handled similarly.

Finally multiply it by 
choose(a-1,ceil(k/2)-1)*choose(b-1,floor(k/2)-1) ways.

For all k from 2 to N. (This was the no of ways to form string of ones and zeros initially).

That's your answer!