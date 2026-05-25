#include <iostream>
#include <deque>
#include <list>
#include <stack>
#include <algorithm>

using namespace std;



void addMaxToEnd(deque<double>& d) {
    if (d.empty()) return;
    double mx = *max_element(d.begin(), d.end());
    d.push_back(mx);
}

void printDeque(const deque<double>& d) {
    for (double x : d) cout << x << " ";
    cout << endl;
}



struct Pair {
    int key;
    double value;

    bool operator<(const Pair& other) const {
        return key < other.key;
    }
};

void addPair(deque<Pair>& d, Pair p) {
    d.push_back(p);
}

void removePairByKey(deque<Pair>& d, int key) {
    d.erase(remove_if(d.begin(), d.end(),
        [&](const Pair& p) { return p.key == key; }),
        d.end());
}

void addMaxPair(deque<Pair>& d) {
    if (d.empty()) return;
    Pair mx = *max_element(d.begin(), d.end());
    d.push_back(mx);
}

void printPairs(const deque<Pair>& d) {
    for (auto& p : d)
        cout << "(" << p.key << "," << p.value << ") ";
    cout << endl;
}


template <typename T>
class MyList {
private:
    list<T> lst;

public:
    void fill(initializer_list<T> init) {
        lst = init;
    }

    void add(const T& value) {
        lst.push_back(value);
    }

    void remove(const T& value) {
        lst.remove(value);
    }

    T getMax() {
        return *max_element(lst.begin(), lst.end());
    }

    void addMaxToEnd() {
        lst.push_back(getMax());
    }

    void print() {
        for (auto& x : lst) cout << x << " ";
        cout << endl;
    }
};


void removeByRange(stack<Pair>& st, int left, int right) {
    stack<Pair> temp;

    while (!st.empty()) {
        Pair p = st.top();
        st.pop();

        if (!(p.key >= left && p.key <= right)) {
            temp.push(p);
        }
    }

    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
}

void printStack(stack<Pair> st) {
    while (!st.empty()) {
        auto p = st.top();
        cout << "(" << p.key << "," << p.value << ") ";
        st.pop();
    }
    cout << endl;
}



template <typename T>
class StackList {
private:
    stack<T> st;

public:
    void push(const T& value) {
        st.push(value);
    }

    double average() {
        stack<T> temp = st;
        double sum = 0;
        int count = 0;

        while (!temp.empty()) {
            sum += temp.top();
            temp.pop();
            count++;
        }
        return (count ? sum / count : 0);
    }

    void addAverageToEach() {
        double avg = average();
        stack<T> temp;

        while (!st.empty()) {
            temp.push(st.top() + avg);
            st.pop();
        }

        while (!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
    }

    void print() {
        stack<T> temp = st;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};



int main() {

    cout << "================ TASK 1 ================\n";
    deque<double> d1 = { 1.5, 3.2, 7.8, 2.1 };
    addMaxToEnd(d1);
    printDeque(d1);

    cout << "\n================ TASK 2 ================\n";
    deque<Pair> d2 = { {1, 10.5}, {5, 20.0}, {3, 15.2} };
    addMaxPair(d2);
    removePairByKey(d2, 5);
    printPairs(d2);

    cout << "\n================ TASK 3 ================\n";
    MyList<int> l;
    l.fill({ 1, 4, 7, 2, 9 });
    l.addMaxToEnd();
    l.print();

    cout << "\n================ TASK 4 ================\n";
    stack<Pair> st;
    st.push({ 1, 10 });
    st.push({ 5, 20 });
    st.push({ 3, 30 });
    st.push({ 7, 40 });

    removeByRange(st, 2, 5);
    printStack(st);

    cout << "\n================ TASK 5 ================\n";
    StackList<double> sl;
    sl.push(10);
    sl.push(20);
    sl.push(30);
    sl.addAverageToEach();
    sl.print();

    return 0;
}