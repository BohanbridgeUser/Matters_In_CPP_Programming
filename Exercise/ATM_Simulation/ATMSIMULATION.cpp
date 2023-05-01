#include <iostream>
#include "QUEUEMY.h"
#include "Customer.h"

const int MIN_PER_HR = 60;

bool Newcustomer(double x) // 平均x分钟来一个顾客
{
    return (std::rand() * x / RAND_MAX < 1);
}

int main()
{
    std::srand(std::time(0));
    using std::cin;
    using std::cout;
    using std::endl;
    using std::ios_base;

    cout << "Cast Study:Bank of Heather Automatic Teller\n";
    cout << "Enter Maxinum size of Queue:";
    int qs;
    cin >> qs;
    Queue<Customers> line(qs);

    cout << "Enter the number of simulation hours:";
    int hours;
    cin >> hours;
    long timelimit = MIN_PER_HR * hours;

    cout << "Enter the average number of customers per hour:";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;

    Customers temp;
    long turnaway = 0;  // 因队满离开的人数
    long customers = 0; // 来到ATM，但没有离开的人数
    long served = 0;    // 服务过的人数
    long sum_line = 0;  // 排队总人数
    int wait_time = 0;  // 当前ATM服务的人剩余服务的时间
    long line_wait = 0; // 
    long cnt = 0;
    for (int time = 0; time < timelimit; time++) {
        if (Newcustomer(min_per_cust)) {
            if (!line.IsFullQ()) {
                temp.set(time);
                line.InQueue(temp);
                customers++;
            }
            else {
                turnaway++;
            }
        }
        if (wait_time <= 0 && !line.IsEmptyQ()) {
            line.DeQueue(temp);
            wait_time = temp.stime();
            line_wait += time - temp.when();
            served++;
        }
        if (wait_time > 0)
            wait_time--;
        sum_line += line.count();
    }
    if (customers > 0) {
        cout << "Customers accepted:" << customers << endl;
        cout << "Customers served:" << served << endl;
        cout << "\tturnaways:" << turnaway << endl;
        cout << "averange queue size:";
        cout.precision(2);
        cout.setf(ios_base::fixed, ios_base::floatfield);
        cout << (double)sum_line / timelimit << endl;
        cout << "average wait time:" << (double)line_wait / served << endl;
    }
    else {
        cout << "No customers\n";
    }
    cout << "Done\n";
    return 0;
}

