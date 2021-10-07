from day import Day


class Month:
    name = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]

    def __init__(self, number_month, number_day):
        """
        :param number_month: number of a month
        :param number_day: number of a day
        """
        self.number_month = number_month
        self.number_day = number_day
        self.days = []
        for i in range(1, number_day + 1):
            self.days.append(Day(i))

    def get_name(self):
        """
        :return: name of the month
        """
        return self.name[self.number_month - 1]

    def get_number_day(self):
        """
        :return: number of all creating obj class Day
        """
        return self.days[1].count

    def get_day_list_plan(self, day):
        """
        :param day: number of the day which hour plan will be returned
        :return: hour plan of the day
        """
        return self.days[day].get_list_day()
