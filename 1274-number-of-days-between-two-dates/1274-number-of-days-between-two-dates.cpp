class Solution {
public:
    time_t convert(const string&date){
        struct tm time_struct{};
        stringstream ss(date);
        char dash;
        ss>>time_struct.tm_year>>dash>>time_struct.tm_mon>>dash>>time_struct.tm_mday;
        time_struct.tm_year -= 1900;
        time_struct.tm_mon -= 1;
        return mktime(&time_struct) / (60 * 60 * 24);
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(convert(date1)-convert(date2));}
};