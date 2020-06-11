#ifndef BANK_SERVICE_H
#define BANK_SERVICE_H

#include "customer.h"

enum class ServiceType : int
{
    IDLE,
    BUSY
};

class Service
{
private:
    Customer _customer;
    ServiceType serviceType;
    int _serviceStartTime;

public:
    Service() : serviceType(ServiceType::IDLE) {}
    void serverCustomer(Customer customer){
        this->_customer = customer;
    }

    bool isIdle() const{
        if(serviceType == ServiceType::IDLE) return true;

        return false;
    }

    void setBusy(){
        serviceType = ServiceType::BUSY;
    }

    void setIdle(){
        serviceType = ServiceType::IDLE;
    }

    int getCustomerDuration(){
        return _customer.duration;
    }

    int getCustomerArrTime(){
        return _customer.arriveTime;
    }

    int getServiceStartTime(){
        return _serviceStartTime;
    }

    void setServiceStartTime(int ssl){
        _serviceStartTime = ssl;
    }
};
#endif