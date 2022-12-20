#include <iostream>
#include <stack>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main() {
    char s;
    stack<double> st;
    double sum = 0;
    int num = 0;
    int alt = 0;
    int count = 0;

    while (scanf("%c", &s) != EOF) {
        if (s == '/') {
            cout << "slash" << endl;
            if (alt < 0) {
                alt += 1;
                st.push(-alt + 0.5);
                cout << -alt + 0.5 << endl;
                count += 1;
                if (alt == 0) {
                    double tmp = 0;
                    for (int i = 0; i < count; i++) {
                        tmp += st.top();
                        st.pop();
                    }
                    cout << "count " << count << " " << tmp << endl;
                    st.push(tmp);
                    sum += tmp;
                    num += 1;
                    count = 0;
                }
            }
        } else if (s == '_') {
            cout << "flat" << endl;
            if (alt < 0) {
                st.push(-alt);
                count += 1;
            }
        } else {
            cout << "back" << endl;
            alt -= 1;
            st.push(-alt - 1 + 0.5);
            cout << -alt - 1 + 0.5 << endl;
            count += 1;
        }
        cout << "alt: " << alt << endl;
    }

    double tmp = 0;
    if (alt < 0) {
        cout << "alt down: " << alt << endl;
        for (int i = 0; i < count + alt; i++) {
            tmp += st.top() + alt;
            st.pop();
        }
        for (int i = 0; i < -alt; i++) {
            st.pop();
        }
        st.push(tmp);
        cout << "count " << count << " " << tmp << " " << st.size() << endl;
        sum += tmp;
        num += 1;
    }

    cout << "sum " << sum << endl;
    cout << "num" << num << endl;
    for (int i = 0; i < num; i++) {
        cout << st.top();
        if (i == num - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
        st.pop();
    }
    return 0;
}