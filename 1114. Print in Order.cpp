class Foo {
    bool firstPrinted = false;
    bool secondPrinted = false;
    mutex m;
    condition_variable cv;
public:
    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstPrinted = true;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock guard(m);
        cv.wait(guard, [this]{ return this->firstPrinted == true; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondPrinted = true;
        guard.unlock();
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock guard(m);
        cv.wait(guard, [this]{ return this->secondPrinted == true; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};