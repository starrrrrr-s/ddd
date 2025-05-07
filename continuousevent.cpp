#include "setting.h"
#include "continuousevent.h"
//连续事件类
ContinuousEvent::ContinuousEvent(const QDate& begin, const QDate& end) :
    AbstractEvent(begin, end)
{
    color = Setting::ContinuousEventColor;
}

bool ContinuousEvent::InList(const QDate& date) const
{
    return begin <= date && date <= end;
}

void ContinuousEvent::save(QDataStream &dataStream) const
{

}

void ContinuousEvent::load(QDataStream &dataStream)
{

}
