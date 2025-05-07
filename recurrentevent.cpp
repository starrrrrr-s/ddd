#include "setting.h"
#include "recurrentevent.h"

// 复发事件类构造函数
RecurrentEvent::RecurrentEvent(const QDate& begin, const QDate& end) :
    AbstractEvent(begin, end),  // 调用基类构造函数
    interval(1),               // 默认间隔为1
    month_weekday(0),          // 默认月工作日为0
    repeat_end(end)            // 默认重复结束日期为end
{
    color = Setting::RecurrentEventColor;  // 使用设置中的复发事件颜色
}

// 判断日期是否在复发事件列表中
bool RecurrentEvent::InList(const QDate& date) const
{
    // 检查日期是否在有效范围内
    if (date < begin || date > repeat_end) return false;
    // 检查是否在跳过日期集合中
    if (skip_set.find(date) != skip_set.end()) return false;

    // 根据复发类型进行判断
    switch (type)
    {
    case Day:  // 每日复发
        if (begin.daysTo(date) % interval) return false;
        return true;

    case Week:  // 每周复发
    {
        int x;
        // 计算下一周的第一天(根据设置中的周首日)
        QDate nextWeekFirstDay = begin.addDays((Setting::WeekFirstDay - begin.dayOfWeek() + Const::WEEK_DAYS) % Const::WEEK_DAYS);
        if (nextWeekFirstDay > date) x = 0;
        else x = nextWeekFirstDay.daysTo(date) / Const::WEEK_DAYS + 1;
        if (x % interval) return false;

        // 检查是否在设置的星期标记中
        return (day_mark >> date.dayOfWeek()) & 1;
    }

    case Year:  // 每年复发
        if ((date.year() - begin.year()) % interval) return false;
        if (date.month() != year_month) return false;
        // 注意：这里没有break，会继续执行Month的逻辑

    case Month:  // 每月复发
        if (type == Month)
        {
            // 计算月份间隔
            int x = date.month() - begin.month() + (date.year() - begin.year()) * 12;
            if (x % interval) return false;
        }

        if (!month_weekday) // 情况1：按具体日期
        {
            if (!month_day) return date.day() == date.daysInMonth();  // 月末
            else return date.day() == month_day;  // 指定日期
        }
        else  // 情况2：按工作日(如每月第二个星期一)
        {
            if (date.dayOfWeek() != month_weekday) return false;
            if (!month_weekday_num) return date.addDays(7).month() != date.month();  // 最后一周
            int x = 0;
            // 计算是第几个指定的工作日
            for (QDate i = date; i.month() == date.month(); i = i.addDays(-7), x++);
            return x == month_weekday_num;
        }

    default:
        return false;
    }
}

// 设置重复次数
void RecurrentEvent::SetRepeatTimes(int x)
{
    repeat_times = x;
    // 计算重复结束日期
    for (repeat_end = begin; x; repeat_end = repeat_end.addDays(1))
        if (InList(repeat_end)) x--;
    repeat_end.addDays(-1);
}

// 保存复发事件数据
void RecurrentEvent::save(QDataStream &dataStream) const
{
    dataStream << (int)type;  // 复发类型
    dataStream << interval << day_mark << end_times;  // 间隔、星期标记、结束次数
    dataStream << month_day << month_weekday << month_weekday_num;  // 月日、月工作日、月工作日序号
    dataStream << year_month;  // 年月
    dataStream << end_type << repeat_times;  // 结束类型、重复次数
    dataStream << repeat_end;  // 重复结束日期
    // 保存跳过日期集合
    dataStream << (int)skip_set.size();
    for (auto i : skip_set) dataStream << i;
}

// 加载复发事件数据
void RecurrentEvent::load(QDataStream &dataStream)
{
    int x;
    dataStream >> x;
    type = (RecurrentType)x;  // 读取复发类型
    dataStream >> interval >> day_mark >> end_times;  // 读取间隔、星期标记、结束次数
    dataStream >> month_day >> month_weekday >> month_weekday_num;  // 读取月日、月工作日、月工作日序号
    dataStream >> year_month;  // 读取年月
    dataStream >> end_type >> repeat_times;  // 读取结束类型、重复次数
    dataStream >> repeat_end;  // 读取重复结束日期
    // 读取跳过日期集合
    int size;
    dataStream >> size;
    skip_set.clear();
    for (int i = 0; i < size; i++)
    {
        QDate date;
        dataStream >> date;
        skip_set.insert(date);
    }
}
