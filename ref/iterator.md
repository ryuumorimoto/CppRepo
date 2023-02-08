vector<int>::iterator it;
for(it = array.begin();it != array.end();it++) 

*itで要素にアクセスできる


# 二分探索
int A[N]// sorted
int *pos;
int index;
int key;

pos = lower_bound(A, A+N, key);
index = distance(A, pos);

-> *posで値、indexにkeyを初めて超える（以上）のindex
lower_boundで以上のindex
upper_boundでより大きいになる
binary_searchは含まれているかどうかのbool


