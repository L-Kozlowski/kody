from hour import Hour


class Day:
    count = 0

    def __init__(self, name):
        """
        :param name: number of the day
        hours: 24 hours in day obj class Hour
        count_day: number of the day in year
        count: static value to count creating obj class day
        """
        self.name = name
        self.hours = []
        for i in range(24):
            self.hours.append(Hour(i))

        Day.count += 1
        self.count_day = Day.count

    def display(self):
        """
        display 24 hours plan in day
        :return: None
        """
        print("Day", self.name, "and It is", self.count_day, "day in year")
        for hour in self.hours:
            hour.display()

    def get_list_day(self):
        """
        :return: list of 24 hours with plans in a day
        """
        list_day = []
        for hour in self.hours:
            list_day.append(hour.get_hour_plan())

        return list_day
