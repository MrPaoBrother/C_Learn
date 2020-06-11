#ifndef BANK_EVENT_H
#define BANK_EVENT_H

#include "random.h"

enum class EventType : int
{
    ARRIVED,
    DEPARTURE
};

class Event{

public:
    Event():occurTime(Random::uniform(RANDOM_DURATION)), eventID(-1), eventType(EventType::ARRIVED), next(nullptr){}
    Event(int occurTime):occurTime(occurTime), eventID(-1), eventType(EventType::ARRIVED), next(nullptr){}
    Event(int occurTime, int eventID, EventType eventType):occurTime(occurTime), eventID(eventID), eventType(eventType), next(nullptr){}

public:
    int occurTime;
    int eventID;
    EventType eventType;
    Event *next;
};
#endif