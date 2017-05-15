# Travelling Jack

<p>After winning the lottery, Jack becomes a rich man. He decides to charter a plane from Fly Airlines to visit the countries he has never been to so far. But the company does not have direct flights to every country; therefore, he may have to visit some auxiliary countries during his travel. Jack is given a list of F possible one-way flights between C countries. He wants to visit the first M countries (numbered as 0, 1, 2, …, M-1). You need to minimize the number of times Jack travels between countries. Jack lives in country 0, so his trip must start and end at country 0. Jack may also visit a country more than once. It is guaranteed that you can always find a path which starts and ends at country 0, and visits countries 0, 1, 2, …, M−1, not necessarily in the given order.</p>

### Sample Case

There are 7 countries in the sample input and Jack wants to travel to only countries

0, 1, 2, 3. If he visits

<p align="center">0 -> 4 -> 3 -> 6 -> 2 -> 6 -> 1 -> 0</p>

he only travels 7 times and this is the shortest possible route which visits countries 0 to 3.

<p align="center">
  <img src="https://lh3.googleusercontent.com/9D5LD6TymTAVPUydaG_NKRNaYlNUEwQ2DRps1DTdboLXYCvBBbHW-TSiLQygF-ap5XK4PJI8Mo_yVj4=w1366-h662">
</p>

### Sample Input file:

7	4	12</br>
0	5	</br>
0	4	</br>
1	0	</br>
1	2	</br>
2	6	</br>
3	0	</br>
3	6	</br>
4	3	</br>
4	5	</br>
6	1	</br>
6	2	</br>
6	5	</br>

where first line gives the number of countries C, the number of first M countries to be visited and the number of directed flights F, respectively. The rest represents the F number of flights from country a to country b.

### Sample Output:

7</br>
0 -> 4 -> 3 -> 6 -> 2 -> 6 -> 1 -> 0

where the first line is the smallest number of times Jack needs to travel between given countries and the second line is the path that achieves this number.

Create an 'input.txt' file with the given sample input and read the data from that file to test your program. However, we will test your program by using the file 'input.txt' with different data inside.


### HINT: 
You need to consider shortest paths for all permutations that Jack can travel to visit the countries he wants and take the one that requires minimum number of flights.
