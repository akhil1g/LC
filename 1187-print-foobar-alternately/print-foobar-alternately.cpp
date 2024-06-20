class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    int turn;

public:
    FooBar(int n) {
        this->n = n;
        turn=0;
    }

    void foo(function<void()> printFoo) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(turn%2==1)
            {
                cv.wait(lock);
            }
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ++turn;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        unique_lock<mutex> lock(m);
        for (int i = 0; i < n; i++) {
            while(turn%2==0)
            {
                cv.wait(lock);
            }

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ++turn;
            cv.notify_all();
        }
    }
};