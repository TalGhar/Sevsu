#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>
#include "algorithm"

using namespace std;

class Worker
{
public:
    Worker(const string &name) : name_(name) {}

    void paySalary(int salary)
    {
        salaryHistory_.push_back(salary);
        cout << "Worker " << name_ << " received salary: " << salary << endl;
    }

    void showSalaryHistory()
    {
        cout << "Salary history for worker " << name_ << ":" << endl;
        for (const auto &salary : salaryHistory_)
        {
            cout << salary << endl;
        }
    }

    const string &getName() const
    {
        return name_;
    }

private:
    string name_;
    list<int> salaryHistory_;
};

class WorkerManager
{
public:
    vector<Worker> workers_;

    void addWorker(const string &name)
    {
        workers_.emplace_back(name);
    }

    void removeWorker(const string &name)
    {
        workers_.erase(remove_if(workers_.begin(), workers_.end(),
                                 [&name](const Worker &worker)
                                 { return worker.getName() == name; }),
                       workers_.end());
        cout << "Worker: " << name << " removed" << '\n';
    }

    void paySalary(const string &name, int salary)
    {
        for (auto &worker : workers_)
        {
            if (worker.getName() == name)
            {
                worker.paySalary(salary);
                break;
            }
        }
    }

    void showAllWorkers()
    {
        for (const auto &worker : workers_)
        {
            cout << "Worker: " << worker.getName() << endl;
        }
    }
};

int main()
{
    WorkerManager workerManager;
    workerManager.addWorker("Ivan");
    workerManager.addWorker("Petr");
    workerManager.addWorker("Sidor");

    workerManager.paySalary("Ivan", 50000);
    workerManager.paySalary("Petr", 60000);
    workerManager.paySalary("Sidor", 70000);
    workerManager.paySalary("Petr", 15000);

    workerManager.showAllWorkers();

    workerManager.removeWorker("Ivan");

    workerManager.showAllWorkers();

    workerManager.workers_[0].showSalaryHistory();

    return 0;
}
