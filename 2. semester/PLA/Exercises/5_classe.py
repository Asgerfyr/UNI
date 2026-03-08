import numpy as np


def mathix_mult(A_,B_):

    """

    A = [
        [   [
        1,  4
        2,  5
        3,  6
        4,  8
        ]   ]
        ]
  
    B = [
        [   [   [
        7, 9, 11
        8, 10, 12
        ]   ]   ]
        ]
    """


    A = A_.T
    B = B_

    new_matrix = np.zeros((len(B),len(A)))

    #for vector i inde i matrix A
    for i in range(len(A)):
        v_a = A[i]
        #find vector j inde i matrix B
        for j in range(len(B)):
            v_b = B[j]
            
            #gang de to matrixer sammen og læg det ind i den nye matrix
            for k in range(len(v_a)):
                new_matrix[j][i] += v_a[k]*v_b[k]

    print(new_matrix)
    return new_matrix


A = np.array([[1,2,3, 8],[4,5,6, 8]])
B = np.array([[7,8],[9,10],[11,12]])

res = mathix_mult(A,B)
print(B@A)

print(np.array_equal(res,B@A))






        



