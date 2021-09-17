import calendar

import month
from month import Month


class Year:
    def __init__(self, number_year):
        """
        :param number_year: number of year to create specific amount of the days in month
        months: list of obj class Month
        """
        self.number_year = number_year
        self.months = []
        for i in range(1, 13):
            days_in_month = calendar.monthrange(number_year, i)[1]
            self.months.append(Month(i, days_in_month))

    def display(self):
        """
        display all months with the days in the year
        :return: none
        """
        print(self.number_year)
        for month in self.months:
            month.display()

    def change_string(self, number_month, number_day, number_hour, new_string):
        """
        change plan of the hour
        :param number_month: number of the month
        :param number_day: number of the day
        :param number_hour: number of the hour
        :param new_string: new string change the old one
        :return: none
        """
        number_month -= 1
        number_day -= 1
        self.months[number_month].days[number_day].hours[number_hour].change_string(new_string)

    def display_day(self, number_month, number_day):
        """
        display an hour plan of the specific day
        :param number_month: number of the month
        :param number_day: number of the day
        :return:
        """
        number_month -= 1
        number_day -= 1
        print(self.months[number_month].get_name(), self.number_year)
        self.months[number_month].days[number_day].display()

    def get_number_day(self):
        """
        :return: number of all creating obj class Day
        """
        return self.months[1].days[1].count

    def get_day_plan_list(self, month, day):
        """
        :param month: number of the month
        :param day: number of the day
        :return: list of hour plan in specific day
        """
        month -= 1
        day -= 1
        return self.months[month].days[day].get_list_day()

    def get_count_day_in_month(self,number_month):
        return len(self.months[number_month-1].days)