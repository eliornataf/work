#include "../inc/timestamp.hpp" // TImestamp Header

using namespace advcpp;

Timestamp::Timestamp()
{   
    time_t initializeTime = time(nullptr);
    struct tm *time = localtime(&initializeTime);

    m_second = time->tm_sec;
    m_minute = time->tm_min;
    m_hour = time->tm_hour;
    m_day = time->tm_mday;
    m_month = time->tm_mon + INDEX_STARTING_FROM_ZERO;
    m_year = time->tm_year + STARTING_YEAR;
}

Timestamp::Timestamp(const int a_dummy)
{
}

Timestamp::Timestamp(const int a_second, const int a_minute, const int a_hour, const int a_day, const int a_month, const int a_year)
: m_second(a_second)
, m_minute(a_minute)
, m_hour(a_hour)
, m_day(a_day)
, m_month(a_month)
, m_year(a_year)
{
}

bool Timestamp::operator==(const Timestamp &a_other) const
{
    return (GetCompleteDateTime() == a_other.GetCompleteDateTime());
}

bool Timestamp::operator!=(const Timestamp &a_other) const
{
    return (GetCompleteDateTime() != a_other.GetCompleteDateTime());
}

int Timestamp::GetSecond() const
{
    return m_second;
}

int Timestamp::GetMinute() const
{
    return m_minute;
}

int Timestamp::GetHour() const
{
    return m_hour;
}

int Timestamp::GetDay() const
{
    return m_day;
}

int Timestamp::GetMonth() const
{
    return m_month;
}

int Timestamp::GetYear() const
{
    return m_year;
}

std::string Timestamp::GetCompleteDateTime() const
{
    return std::string(std::to_string(m_second) + DELIMETER
                        + std::to_string(m_minute) + DELIMETER
                            + std::to_string(m_hour) + DELIMETER
                                + std::to_string(m_day) + DELIMETER
                                    + std::to_string(m_month) + DELIMETER
                                        + std::to_string(m_year));
}
