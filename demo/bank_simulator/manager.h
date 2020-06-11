#ifndef BANK_MANAGER_H
#define BANK_MANAGER_H

#include "queue.h"
#include "service.h"

#define DEFAULT_EVENT_NUM 5

class Manager
{
public:
    Manager(int totalServiceTime, int serviceNum) : _totalServiceTime(totalServiceTime),
                                                    _serviceNum(serviceNum),
                                                    _totalCustomerStayTime(0),
                                                    _totalDealCustomerNum(0){};
    ~Manager() {}

    void simulate(int simulateNum);

    int _getAvgStayTime()
    {
        return _avgStayTime;
    }

    int _getAvgDealCustomerNumInMinute()
    {
        return _avgDealCustomerNumInMinute;
    }

private:
    // 营业时间
    int _totalServiceTime;
    // 服务窗口数量
    int _serviceNum;
    // 客户总共停留时间
    int _totalCustomerStayTime;
    // 处理客户数量
    int _totalDealCustomerNum;
    // 到达时间
    int _generateArrivedTime;
    // 平均停留时间
    double _avgStayTime;
    // 平均每分钟处理客户数量
    double _avgDealCustomerNumInMinute;

    void run();

    void init();

    void end();

    int getIdleServiceIndex();

    void customerArrived();

    void customerDeparture();

    void generateArrivedEvent(int &currentTime);

    void generateDepartureEvent(int serviceIndex, int currentTime);

    Service *_services;

    Queue<Customer> _customerQueue;

    Queue<Event> _eventQueue;

    Event *_curEvent;
};

void Manager::init()
{
    _services = new Service[_serviceNum];
    for (int i = 0; i < _serviceNum; i++)
    {
        *(_services + i) = Service();
    }

    _generateArrivedTime = 0;

    while (_generateArrivedTime < DEFAULT_EVENT_NUM)
    {
        /* code */
        generateArrivedEvent(_generateArrivedTime);
    }
}

void Manager::generateArrivedEvent(int &currentTime)
{
    int randomCustomerNumPerMin = Random::uniform(RANDOM_PER_MINUTE);
    while (randomCustomerNumPerMin > 0)
    {
        /* code */
        Event *event = new Event(currentTime);
        _eventQueue.enqueue(event);
        randomCustomerNumPerMin--;
    }
    currentTime++;
}

int Manager::getIdleServiceIndex()
{
    for (int i = 0; i < _serviceNum; i++)
    {
        if (_services[i].isIdle())
        {
            return i;
        }
    }
    return -1;
}

void Manager::customerArrived()
{
    int idleServiceIndex = getIdleServiceIndex();
    int currentTime = _curEvent->occurTime;
    Customer *customer = new Customer(currentTime);
    _customerQueue.enqueue(customer);
    _eventQueue.dequeue();

    if(idleServiceIndex != -1){
        generateDepartureEvent(idleServiceIndex, currentTime);
    }
}

void Manager::generateDepartureEvent(int serviceIndex, int currentTime){
    _services[serviceIndex].serverCustomer(*_customerQueue.front());
    _services[serviceIndex].setBusy();
    _services[serviceIndex].setServiceStartTime(currentTime);
    int duration = _services[serviceIndex].getCustomerDuration();
    _customerQueue.dequeue();

    Event *event = new Event(currentTime + duration, serviceIndex, EventType::DEPARTURE);
    _eventQueue.enqueue(event);

}

void Manager::customerDeparture()
{
    int currentTime = _curEvent->occurTime;
    int serviceIndex = _curEvent->eventID;
    _totalCustomerStayTime += (currentTime - _services[serviceIndex].getCustomerArrTime());
    _totalDealCustomerNum ++;
    _services[serviceIndex].setIdle();
    _eventQueue.dequeue();

    if(_customerQueue.size() > 0){
        int idleServiceIndex = getIdleServiceIndex();
        generateDepartureEvent(idleServiceIndex, currentTime);
    }
}

void Manager::end(){
    for(int i=0;i<_serviceNum;i++){
        if(!_services[i].isIdle()){
            int arriveTime = _services[i].getCustomerArrTime();
            int serviceStartTime = _services[i].getServiceStartTime();
            int duration = _services[i].getCustomerDuration();
            
            _totalCustomerStayTime += duration + serviceStartTime - arriveTime;
            _totalDealCustomerNum ++;
        }
    }
    _customerQueue.clear();
    _eventQueue.clear();
    delete[] _services;
}

void Manager::run()
{
    while (_eventQueue.size() > 0)
    {
        /* code */
        _curEvent = _eventQueue.front();
        if (_curEvent->occurTime >= _totalServiceTime)
            break;

        if (_customerQueue.size() == 0 && _eventQueue.size() < _serviceNum)
        {
            generateArrivedEvent(_generateArrivedTime);
            _curEvent = _eventQueue.front();
        }

        if (_curEvent->eventType == EventType::ARRIVED)
        {
            customerArrived();
        }

        if (_curEvent->eventType == EventType::DEPARTURE)
        {
            customerDeparture();
        }
    }
}

void Manager::simulate(int simulateNum){
    long long totalServerTime = _totalServiceTime * simulateNum;

    while (simulateNum -- > 0)
    {
        /* code */
        init();

        run();

        end();
    }
    
    _avgStayTime = static_cast<double>(_totalCustomerStayTime) / _totalDealCustomerNum;

    _avgDealCustomerNumInMinute = static_cast<double>(_totalDealCustomerNum) / totalServerTime;
}
#endif