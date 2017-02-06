alist = {}
colour = {}
stack = []
tree_edges = []
cross_edges = []
fwd_edges = []
back_edges = []
crs_edges = []

def stillbetterdfs(node):
    colour[node] = 1
    stack.append(node)
    adj = [x for x in alist[stack[-1]] if colour[x] != 1 ]
    adj3 = [x for x in alist[stack[-1]] if colour[x] == 1]
    adj4 = [x for x in alist[stack[-1]] if colour[x] == 2]
    for x in adj4:
        crs_edges.append(node+"-"+x)
    for x in adj3:
        back_edges.append(node+"-"+x)
    for x in adj:
        if (colour[x] != 2):
            colour[x] = 1
            stillbetterdfs(x)
        else:
            cross_edges.append(node+"-"+ x)
    adj2 = [x for x in alist[stack[-1]] if colour[x] != 1]
    fwd_pts = [x for x in adj if x not in adj2]
    for y in fwd_pts:
        fwd_edges.append(node+"-"+y)
    for x in adj2:
        tree_edges.append(node+"-"+x)
    print stack.pop(),
    colour[node] = 2


choice = 1

print "1) Insert a vertex 2) Insert an edge 3) DFS 4) Facts 5) Exit"

while choice != 5:
    choice = input("Choice: ")
    if choice == 1:
        v = raw_input("Vertex label: ")
        if v in alist:
            print "Vertex already present!"
        else:
            alist[v] = []
            colour[v] = 0
    elif choice == 2:
        e = raw_input("Enter the source and the destination of the edge: ")
        temp = e.split()
        if temp[1] in alist[temp[0]]:
            print "Edge already present!"
        else:
            alist[temp[0]].append(temp[1])
    elif choice == 3:
        start = raw_input("Define a starting point: ")
        print "DFS:",
        stillbetterdfs(start)
        print
        colour = [0] * 9
    elif choice == 4:
        print "Tree edges"
        print [x for x in tree_edges if x not in cross_edges]
        print "Back edges"
        print back_edges
    elif choice == 5:
        break
