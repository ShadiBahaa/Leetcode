4 5 6 7 8 9 0 1 2 3
l       m         r
m > r => l = m + 1
4 5 6 7 8 9 0 1 2 3
          l   m   r
m < r => r = m
4 5 6 7 8 9 0 1 2 3
          l m r
m < r => r = m
4 5 6 7 8 9 0 1 2 3
          l r
m > r => l = m + 1
7 8 0 1 2 3 4 5 6
            lr
r >= l => return l

7 8 0 1 2 3 4 5 6
l       m       r
m < r => r = m
7 8 0 1 2 3 4 5 6
l m     m
m > r => l = m + 1
7 8 0 1 2 3 4 5 6
    l m r
m < l => r = m
7 8 0 1 2 3 4 5 6
    l r
m < r => r = m
7 8 0 1 2 3 4 5 6
    lr
r >= l => return l

8 0 1 2 3 4 5 6 7
l       m       r
m < r => r = m
8 0 1 2 3 4 5 6 7
l   m   r
m < r => r = m
8 0 1 2 3 4 5 6 7
l m r
m < r => r = m
8 0 1 2 3 4 5 6 7
l r
m > r => l = m + 1
8 0 1 2 3 4 5 6 7
  lr
r >=l => return l

0 1 2 3 4
l   m   r
m < r => r = m
0 1 2 3 4
l m r
m < r => r = m
0 1 2 3 4
l r
m < r => r = m
0 1 2 3 4
lr
r >= l => return l