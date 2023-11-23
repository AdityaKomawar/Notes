## Tree - Tree is the collection of nodes where one of the node is taken as root node and rest of the nodes are divided into disjoint subsets where each subset is a subtree.
```mermaid
flowchart LR;
  subgraph Tree;
  direction TB;
    A-->B;
    A-->C;
    A-->D;
    B-->E;
    B-->F;
    D-->G;
    D-->H;
    D-->I;
    F-->J;
    F-->K;
    H-->L;
    J-->M;
    L-->N;
    L-->O;
  end;
```
```mermaid
flowchart LR
    c1-.->a1
    subgraph ide1 [one]
    direction TB
    a1-->a2
    end
```
```mermaid
flowchart LR
  subgraph TOP
    direction TB
    subgraph B1
        direction RL
        i1 -->f1
    end
    subgraph B2
        direction BT
        i2 -->f2
    end
  end
  A --> f1 --> B
  B1 --> B2
```
1. Root
2. Parent
3. Child
4. Siblings
5. Descendents
6. Ancestors
7. Degree of a node
8. Internal/External nodes
9. Levels
10. Height
11. Forest
