from sys import maxsize
from itertools import permutations
V = 5

def tsp(graph , s):
    vertex = []
    for i in range(V):
        if i != s:
            vertex.append(i)
    min_cost = maxsize
    next_permutation = permutations(vertex)
    for i in next_permutation:
        curr_cost = 0 
        k = s 
        for j in i:
            curr_cost = curr_cost + graph [k] [j] 
            k = j 
        curr_cost = curr_cost + graph [k] [s]
    min_cost = min(min_cost , curr_cost)
    return min_cost
    
print("Lets now find the minimum distance required to cross the cities: \n Tiruchirapalli \n Thanjavur \n Theni \n Tiruppur \n Tirunelveli")
graph = [[0,48,159,151,254],[48,0,201,199,276],[159,201,0,123,144],[151,199,123,0,267],[254,276,144,267,0]]
s = 0
print( "Minimum distance it takes to travel through the above cities are ", tsp(graph,s) )
