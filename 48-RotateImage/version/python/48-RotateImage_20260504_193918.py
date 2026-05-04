# Last updated: 4/5/2026, 7:39:18 pm
1class Solution(object):
2    def rotate(self, matrix):
3        """
4        :type matrix: List[List[int]]
5        :rtype: None Do not return anything, modify matrix in-place instead.
6        """
7        n=len(matrix)
8        i=0
9        j=n-1
10        while i<j:
11            matrix[i],matrix[j]=matrix[j],matrix[i]
12            i+=1
13            j-=1
14        for i in range(n):
15            for j in range(i+1,n):
16                if i!=j:
17                    matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
18        