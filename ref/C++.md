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
    - insert()
    - size()
    - clear()
    - end()
    - erase()
    - find() なければend()を返す

- #include <algorithm>
    priority_queue<int> PQ;
    push()
    pop()
    top()