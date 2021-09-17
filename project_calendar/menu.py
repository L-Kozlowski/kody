import file
from datetime import date
import calendar


def init_list():
    """
    read file "save_file.txt"
    :return: object class Year
    """
    year = file.read_file()
    return year


def display_3_days(year):
    """
    display 3 days - yesterday, today, tomorrow with hour plan 
    :param year: obj class Year
    :return: none
    """
    today_day = date.today().day
    today_month = date.today().month

    yesterday = year.get_day_plan_list(today_month, today_day - 1)
    today = year.get_day_plan_list(today_month, today_day)
    tomorrow = year.get_day_plan_list(today_month, today_day + 1)
    print("YESTERDAY\t\t\t\t\tTODAY\t\t\t\t\tTOMORROW")
    for i in range(24):
        print(f"{yesterday[i]}\t\t\t\t\t{today[i]}\t\t\t\t\t{tomorrow[i]}")


def display_other_day(year):
    """
    display a specific day with hour plan
    :param year: obj class Year
    :return: none
    """
    print(calendar.calendar(2021))
    number_month = input("input a month: ")
    number_day = input("input a day: ")
    year.display_day(int(number_month), int(number_day))


def change_day(year):
    """
    change plan of hour in specific day
    :param year: obj class Year
    :return: none
    """
    print(calendar.calendar(2021))
    number_month = input("input a month: ")
    number_day = input("input a day: ")
    year.display_day(int(number_month), int(number_day))
    while True:
        number_hour = input("Input hour to change ( \"-1\" to quit): ")
        if number_hour == "-1":
            break
        elif int(number_hour) in range(24):
            number_string = input("Write new plan: ")
            year.change_string(int(number_month), int(number_day), int(number_hour), number_string)
        else:
            print("Try again")


def head_menu():
    """
    Main menu
    :return: none
    """
    year = init_list()

    while True:
        print("\t\t\t\t\t\t\tMENU:")
        display_3_days(year)
        print("\nOption")
        print("1 - check plan another day")
        print("2 - change the plan of the day")
        print("3 - quit and save")
        option = input("Input a number: ")

        if option == "1":
            display_other_day(year)
        elif option == "2":
            change_day(year)
        elif option == "3":
            file.write_to_file(year)
            break




