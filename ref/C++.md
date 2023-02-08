# stack
- #include <stack>
    - size()
    - top()
    - pop()
    - push(x)
    - empty()

- #include <queue>
    - size()
    - front()
    - pop()
    - push(x)
    - empty()

- #include <vector>
    - size()
    - push_back(x)
    - pop_back()
    - begin()
    - end() 最後の要素ではないのが注意
    - insert(p, x)
    - erase(p)
    - clear()
    - 変数名[]でアクセス可能   
    - front(), back()で要素取得 
    - resize(n, 0)で初期化した(vector<int> vなど)をresizeできる

- #include <list>
    - size()
    - begin()
    - end()
    - push_front(x)
    - push_back()
    - pop_front()
    - pop_back()
    - insert(p, x)
    - erase(p)
    - clear()

- #include <utility>(pair)
    - stack<pair<int, int> >のように初期化
    - make_pair(x, y)
    - first,secondeで要素取得

- #include <map>
    - map<string, bool> mp;(init)
    - mp["key"]で値の取得、代入
    - keyに対応するものがないときは0がかえる
    - 探索はlog2n

- #include <set>
要素が値によってソートされている集合で、重複した値は存在しない。ある値域の内の個数を調べる際は、set<int>::iterator x = lower_bound(S.begin(), S.end(), left)(以上)とupper_bound(S.begin(), S.end(), right)(より大きい)で得られたイテレーターをdistance()で距離を得ることで得る。
    - insert()
    - size()
    - clear()
    - end()
    - erase()
    - find() なければend()を返す
    ```
    set<int>::iterator it = S.find(n);
    if(it == S.end()) {not founc}
    distance(S.begin(), it);
    ```

- #include <algorithm>(priority_queue)
    priority_queue<int> PQ;
    push()
    pop()
    top()
    priority_queue<Puzzle33, decltype(Puzzle33::lessHeuristic)>でoperator指定


atan2(y, x)