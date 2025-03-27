Key = input("enter your key: ")
K_array=[]
for char in Key:
    if char not in K_array:
        K_array.append(char.upper())

print(K_array)


# # Define the dimensions for the 2D list
# rows = 5
# cols = 5

# # Create a 2D list filled with None (or any placeholder)
# grid_2d_array = [[" " for _ in range(cols)] for _ in range(rows)]

# # Fill the 2D list with elements from the 1D list
# def fill_2d_array(keyArray):
#     index = 0
#     for i in range(rows):
#         for j in range(cols):
#             if index < len(keyArray):
#                 grid_2d_array[i][j] = keyArray[index]
#                 index += 1
#     return grid_2d_array

# print(fill_2d_array(keyList))

# # alphabets = [A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z]
