from year import Year
import calendar


def write_to_file(list_file_year):
    """
    writing all elements to the file
    :param list_file_year:  obj class Year
    :return: Nobe
    """
    with open("save_file.txt", "w") as f:
        f.write(str(list_file_year.number_year) + "\n")
        for month in list_file_year.months:
            f.write("**" + str(month.get_name()) + "**\n")
            for day in month.days:
                f.write("#" + str(day.name) + " ||")
                for hour in day.hours:
                    f.write(str(hour.name) + " | ")
                    f.write(str(hour.str) + "||\t")
                f.write("\n")
            f.write("\n")


def read_file():
    """
    read file and create new obj class Year
    :return: obj class Year
    """
    with open("save_file.txt", "r") as f:
        all_read = f.readlines()
        list_file = []
        for line in all_read:
            line = line.strip()
            line = line.replace('\t', '')
            line = line.split("||")
            list_file.append(line)
        # print(list_file)

        year = Year(2021)
        new_list_file = []
        for i in range(1, len(list_file)):
            if 5 > len(list_file[i][0]) > 1:
                new_list_file.append(list_file[i])  # creating a list with lists of hours + plan in day
        # print(new_list_file)

        start = 0
        finish = 0
        for month in range(1, 13):
            days_in_month = calendar.monthrange(2021, month)[1]
            finish += days_in_month  # read amount days how many days is in the month
            for days in range(start, finish):
                length = int(len(new_list_file[days]))  # value of length is the same of all days
                for hour in range(1, length - 1):  # value of index 0 is number of the day and val of index -1 is empty
                    string = new_list_file[days][hour]  # get string with hour + plan txt
                    string = string.split("|")  # split hour and plan txt ( [0] - hour [1] - plan txt )
                    if string[1] != "":  # change plan txt only when has some text
                        day = new_list_file[days][0]
                        day = day.replace("#", "")  # get number of the day
                        year.change_string(int(month), int(day), int(string[0]), string[1])  # change string
                    # print(string)
            start = finish
            # print()
        return year
