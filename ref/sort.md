# 挿入ソート
- arrayの左側から順に、適切な場所に挿入していく。この挿入は、sort済みを右から左に比べていくため、他のメモリが必要とならず、安定である。よって左側がsort済、右側が未ソートとなる

# バブルソート
- arrayの右側から順に、比較していき左に最小値を送る。よって左から右にソートされていく。（左から右に最大値を送っても良い）この入れ替えの数を転倒数といい、列の乱れを表す。

# 選択ソート
- arrayの中から最小値を見つけ、それと一番左を交換する。最小値が二つある場合は安定なソートとはならない。

# merge sort
- len = nの配列をn/2で分割し、それらをまたmergesortする。n=1の時はその値を返す。分割数がlog2nで、各階層で合計n回の比較->値詰め直しをするためO(nlog2n)。整列済みの２つの配列を、整列すみの１つの配列にするのはO(n1+n2)で可能となる。（小さい方から詰めていく）
```
void mergeSort(int* A, int n, int left, int right) {
    if (n > 1) {
        int mid = (left + right) / 2;
        int n1 = mid - left;
        int n2 = right - mid;
        mergeSort(A, n1, left, mid);
        mergeSort(A, n2, mid, right);

        rep(i, n1) { L[i] = A[left + i]; }
        L[n1] = INT32_MAX;
        rep(i, n2) { R[i] = A[mid + i]; }
        R[n2] = INT32_MAX;
        int i = 0;
        int j = 0;
        for (int index = 0; index < n; index++) {
            cnt += 1;
            if (L[i] <= R[j]) {
                A[left + index] = L[i++];
            } else {
                A[left + index] = R[j++];
            }
        }
    }
}
```

# quick sort
- partitionによって、配列を基準より大きいものと、小さいものに分ける。その後分割された配列をquicksortする。一般的にはO(nlog2n)
- 基準によっては分割数が増え、O(n^2)になる、基準を中央値にするなどの工夫が必要

```
int partition(Card *array, int left, int right) {
    int len = right - left;
    int base = array[right - 1].num;
    int i = 0, j = 0;
    rep(index, len - 1) {
        if (array[left + index].num <= base) {
            swap(array[left + i], array[left + index]);
            j += 1;
            i += 1;
        } else {
            j += 1;
        }
    }
    swap(array[left + i], array[right - 1]);
    return i;
}
void quickSort(Card *array, int left, int right) {
    int len = right - left;
    if (len != 1) {
        // cout << "left: " << left << "right: " << right << endl;
        int index = partition(array, left, right);
        quickSort(array, left, left + index);
        quickSort(array, left + index, right);
    }
}
```

# Counting Sort
- 要素の最小値、最大値がわかっている場合に用いる。要素の種類ごとに何回登場するかをcountした配列を作り、その配列から和を求めることで、要素の格納場所を決める。
- O(n+k)
```
void counttingSort(int* array, int n, int* dst) {
    int* CounterArray = new int[MAXNUM + 1];
    rep(i, MAXNUM + 1) { CounterArray[i] = 0; }

    rep(i, n) { CounterArray[array[i]] += 1; }

    rep(i, MAXNUM + 1) {
        if (i != 0) {
            CounterArray[i] = CounterArray[i - 1] + CounterArray[i];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        int tmp = array[i];
        dst[CounterArray[tmp] - 1] = tmp;
        CounterArray[tmp] -= 1;
    }
}
```

# c++組み込みsort
- quick sort
- 安定ではないので注意が必要
```
vector<int> v;
int v2;
sort(v.begin(), v.end);
sort(v2, v2 + n);


```
class内組み込み
bool operator<(const Node &another) const { return id < another.id; }
bool operator<(const Point& p) const {
    return x != p.x ? x < p.x : y < p.y;
}
bool operator==(const Point& p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
}

随時
bool lessX(const Node &node0, const Node &node1) { return node0.x < node1.x; }
bool lessY(const Node &node0, const Node &node1) { return node0.y < node1.y; }
bool lessNode(Node *node0, const Node *node1) { return node0->id < node1->id; }
```

