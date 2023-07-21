#include <bits/stdc++.h>

using namespace std;

#ifdef __MDS_DEBUG__
template <typename Arg, typename... Args>
void mds_debug(std::ostream& out, Arg&& arg, Args&&... args)
{
    stringstream ss(forward<Arg>(arg));
    vector<string> varnames;
    for (string var; getline(ss, var, ','); varnames.push_back(var)) {
        if (var.at(0) == ' ') var.erase(0, 1);
    }
    using expander = int[];
    uint32_t index = 0;
    (void)expander{0, (void(out << (index ? ", " : "Debug: ") << varnames[index++] << " = " << std::forward<Args>(args)), 0)...};
    out << std::endl;
}
#define debug(...) mds_debug(cerr, #__VA_ARGS__, __VA_ARGS__);
#else
#define debug(...)
#endif

/******************    START_CODING   ******************/

const int daysPerMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

const string daysAsString[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

const string monthsAsString[] = {"", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

class Date
{
    public:
    int day, month, year;

    Date(string date)
    {
        this->fromString(date);
    }

    void fromString(const string& date)
    {
        stringstream ss(date);
        string line;
        getline(ss, line, '/');
        day = atoi(line.c_str());
        getline(ss, line, '/');
        month = atoi(line.c_str());
        getline(ss, line, '/');
        year = atoi(line.c_str());
    }

    friend int calcDays(Date date);

    friend ostream& operator<<(ostream &out, const Date& date)
    {
        string dayOfWeek = daysAsString[calcDays(date) % 7];
        string monthStr = monthsAsString[date.month];
        out << monthStr << " " << date.day << ", ";
        out << date.year << " " << dayOfWeek << "\n";
        return out;
    }
};

int calcDays(Date date)
{
    int year = date.year;
    int days = year * 365;
    days += (year / 4) + (year / 400)  - (year / 100);
    for (int i = 0; i < date.month; ++i) {
        days += daysPerMonth[i];
    }
    days += date.day;
    return days;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string inputDate = "29/05/2013";
    Date date(inputDate);
    cout << date;
    return 0;
}
