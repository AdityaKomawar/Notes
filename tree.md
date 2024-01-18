## Tree - Tree is the collection of nodes where one of the node is taken as root node and rest of the nodes are divided into disjoint subsets where each subset is a subtree.
if n nodes then n-1 edges

<div><img style="float:right;" src="https://github.com/AdityaKomawar/Notes/blob/main/basic_tree.drawio1.png" /></div>

1. Root
2. Parent
3. Child - Descendents of a parent node
4. Siblings - Descendents of a same parent node
5. Descendents - set of nodes under that node reached thorugh a path
6. Ancestors - Form a node all the nodes from that node to a root node along a path
7. Degree of a node - Number of direct children
8. Degree of a tree - Tree with a node with max number of children
9. Internal/External nodes - (leaf/non-leaf nodes) leaf: Nodes with degree 0
10. Levels - Level starts from 1. Root is at level 1. i.e number of nodes along a path
11. Height - Height starts from 0. Root is at height 0. i.e. Height at a node is the number of edges took to read a node
12. Forest - Collection of trees

### Binary Tree - Tree with degree 2
#### 1. Number of Binary tree using N nodes
This numbers is also called as Catalan Number.
Formula (Unlabelled): T(n) = 2nCn/n+1
Formula (Labelled): T(n) = (2nCn/n+1) * n!
#### 2. Number of binary trees with Max Height from N nodes
Formula: T(n) = 2*pow(n-1)

#### 3. Min and Max number of nodes required to create binary tree with Height H
Min Nodes N = H + 1
Max Nodes N = 2*pow(h+1) - 1

#### 4. Min and Max height for given number of nodes
Min Height H = log2(n + 1) - 1
Max Height H = n - 1

#### 5. Relation between Internal and External Nodes (Leaf Nodes vs Non-Leaf Nodes)
Leaf Nodes - Nodes with Degree 0
Non Leaf Nodes - Nodes with Degree > 0
degree(0) = degree(1) + 1

#### 6. Strict Binary Tree (Proper/Complete)
In strict binary tree every node has either degree(0) or degree(2). so there is no node with degree(1).

Height vs Nodes of Strict Binary tree
if height 'h' of strict binary tree is given,
then, min nodes n = 2 * h + 1
max nodes n = 2*pow(h+1) - 1

if nodes 'n' of strict binary tree is given,
then, min height h = log2(n+1) - 1
max height h = (n - 1) / 2

Internal vs External nodes of Strict Binary tree
E = I + 1


#### 7. n-ary Trees
Here n is degree of a tree. Each node of a tree can have degree 0 to n.

min nodes = n * h + 1
max nodes = (n*pow(h+1) - 1)/(n - 1)

min height = logn[N*(n - 1) + 1]
max height = (N - 1) / n

E = (n - 1)*i + 1


#### 8. Representation of Tree
Array can be represented Level by Level using an Array or using linked nodes.

Full Vs Complete Binary Tree
Full Binary Tree - Tree with Height h having maximum number of nodes i.e 2*pow(h+1)-1
Complete Binary Tree - A complete binary tree of height h will be a full binary tree upto height h-1 and on the last level elements will be filled from left to right. i.e if a binary tree is represented using an Array then there should not be any blank places present in between the elements.

Strict vs Complete Binary Tree
Strict Binary Tree - Every node can have either 0 or 2 degree.
So Complete binary tree can be Strict but not every Strict binary tree is complete.


### Tree Traversals
#### PreOrder - Visit(node), PreOrder(left subtree), PreOrder(right subtree)
#### InOrder - InOrder(left subtree), Visit(node), InOrder(right subtree)
#### PostOrder - PostOrder(left subtree), PostOrder(right subtree), Visit(node)
#### LevelOrder - Level by Level

#### For Tree
PreOrder - A, B, D, E, C, F, G
InOrder - D, B, E, A, F, C, G
PostOrder - D, E, B, F, G, C, A
LevelOrder - A, B, C, D, E, F, G

