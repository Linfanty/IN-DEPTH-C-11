#include <iostream>
#include <functional>
#include <memory>
#include <future>
#include <thread>
using namespace std;

int main() {

    std::promise<int> pr;
    std::thread t([] (std::promise<int>& p) { p.set_value_at_thread_exit(9); }, std::ref(pr)) ;
    std::future<int> f = pr.get_future();

    auto r = f.get();
    cout << r << endl;

    std::packaged_task<int()> task([](){return 7;} );
    std::thread t1(std::ref(task));
    std::future<int> f1 = task.get_future();

    auto r1 = f1.get();
    cout << r1 << endl;

    t.join();
    t1.join();



    std::future<int> f3 = std::async(std::launch::async, [](){return 8;});
    cout << f3.get() << endl;
    std::future<void> f2 = std::async(std::launch::async, [](){ cout << 8 << endl;});
    f2.wait();

    std::future<int> future = std::async(std::launch::async, [](){
                                        std::this_thread::sleep_for(std::chrono::seconds(3));
                                        return 8;
                                        });
    cout << "waiting...\n";
    std::future_status status;
    do{
        status = future.wait_for(std::chrono::seconds(1));
        if(status == future_status::deferred) cout << "deferred\n";
        if(status == future_status::timeout) cout << "timeout\n";
        if(status == future_status::ready) cout << "ready\n";

    } while(status != std::future_status::ready);
    cout << "result is " << future.get() << "\n";

}
