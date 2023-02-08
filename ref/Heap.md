# Heapの特徴
親のindexは/2で得られる。逆に左の子供は*2, 右は*2+1で得られる。

# Heapの構成
要素数Hのヒープを構成するとする。１オリジンの配列を用いる。H/2(つまり最後の要素の親＝子供を持つ親の中で一番indexが大きいnode)から順にmaxheapifyを行う。
maxheapifyとはそのnodeより下の階層全てで、親より子供が大きければ入れ替える作業を行う。
これの計算量はO(H)となる。これの証明はアルゴリズムとデータ構造(P238)

#　要素の取り出し、追加
取り出しはindex=1を取り出し、その後swap(A[1], A[H])を行い、maxHeapify(A[1])を行う。これはA[1]以外は既にheapとなっているので、maxHeapify(A[1])だけやればheap化できる。計算量はO(logH)
追加はA[H+1]に新しい要素を追加する。その後親と比較し、親より小さくなるまでswapすることで、heap化できる。