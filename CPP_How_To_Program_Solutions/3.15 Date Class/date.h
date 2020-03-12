class date{
private:
    int day;
    int month;
    int year;
public:
    void controlDay();
    explicit date(int day,int month,int year);
    void setDay(int number);
    int getDay();
    void setMonth(int number);
    int getMonth();
    void setYear(int number);
    int getYear();
    void displayDate();
};