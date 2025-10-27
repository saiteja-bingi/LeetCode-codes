# Last updated: 10/27/2025, 7:09:55 PM
class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        n=len(matrix)
        i=0
        j=n-1
        while i<j:
            matrix[i],matrix[j]=matrix[j],matrix[i]
            i+=1
            j-=1
        for i in range(n):
            for j in range(i+1,n):
                if i!=j:
                    matrix[i][j],matrix[j][i]=matrix[j][i],matrix[i][j]
        