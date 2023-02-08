#include <iostream>
#include <stack>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    char s;
    stack<int> st;
    stack<pair<int, int> > st2;
    int count = 0;

    while (scanf("%c", &s) != EOF) {
        if (s == '/') {
            // cout << "slash" << endl;
            if (st.size() != 0) {
                int index = st.top();                
                st.pop();
                int sum = count - index;
                //int minIndex = index;
                if (st2.size() != 0) {
                    while (st2.top().first > index) {
                        int tmp = st2.top().second;
                        //minIndex = st2.top().first;
                        st2.pop();
                        sum += tmp;
                        if (st2.size() == 0) break;
                    }
                }                
                st2.push(make_pair(index, sum));
            }

        } else if (s == '\\') {
            // cout << "back" << endl;
            st.push(count);
        }
        count += 1;
    }
    int* ans = new int[st2.size()];
    int sum = 0;
    int num = st2.size();
    // cout << "num: " << num << endl;
    for (int i = 0; i < num; i++) {
        ans[num - i - 1] = st2.top().second;
        sum += st2.top().second;
        st2.pop();
    }
    cout << sum << endl;
    cout << num;

    for (int i = 0; i < num; i++) {
        cout << " " << ans[i];
    }
    cout << endl;

    delete[] ans;
    return 0;
}