#ifndef TIMESTAMP_HPP
#define TIMESTAMP_HPP

#include <ctime> // time_t
#include <string> // std::string

namespace advcpp {

class Timestamp {
public:
    Timestamp();
    explicit Timestamp(const int a_dummy);
    Timestamp(const int a_second, const int a_minute, const int a_hour, const int a_day, const int a_month, const int a_year);
    ~Timestamp() = default;

    Timestamp(const Timestamp &a_other) = default;
    Timestamp &operator=(const Timestamp &a_other) = default;

    bool operator==(const Timestamp &a_other) const;
    bool operator!=(const Timestamp &a_other) const;

    int GetSecond() const;
    int GetMinute() const;
    int GetHour() const;
    int GetDay() const;
    int GetMonth() const;
    int GetYear() const;
    std::string GetCompleteDateTime() const;

private:
    static constexpr int STARTING_YEAR = 1900;
    static constexpr int INDEX_STARTING_FROM_ZERO = 1;
    static constexpr char DELIMETER = ' ';

private:
    int m_second;
    int m_minute;
    int m_hour;
    int m_day;
    int m_month;
    int m_year;
};

} // advcpp


#endif // TIMESTAMP_HPP