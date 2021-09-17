import menu
from button import Button
import pygame
from datetime import date
from datetime import datetime

# menu.head_menu()

pygame.display.set_caption("Calendar")
window = pygame.display.set_mode((1000, 1000))
pygame.font.init()
font = pygame.font.SysFont('comicsans', 50)
font2 = pygame.font.SysFont('comicsans', 25)


def draw_date(day, month, x, y):

    if day <= 0:
        month -= 1
        day += year.get_count_day_in_month(month)
        if month < 10:
            text = font.render(str(day) + ".0" + str(month), 1, (0, 0, 0))
        else:
            text = font.render(str(day) + "." + str(month), 1, (0, 0, 0))
    elif 0 < day < 10:
        if month < 10:
            text = font.render("0" + str(day) + ".0" + str(month), 1, (0, 0, 0))
        else:
            text = font.render("0" + str(day) + "." + str(month), 1, (0, 0, 0))
    else:
        if month < 10:
            text = font.render(str(day) + ".0" + str(month), 1, (0, 0, 0))
        else:
            text = font.render(str(day) + "." + str(month), 1, (0, 0, 0))

    window.blit(text, (x, y))


def heading():
    pygame.draw.rect(window, (180, 180, 180), (10, 10, 980, 70))
    today_day = date.today().day
    today_month = date.today().month
    text = font.render("Today: " + str(today_day) + ".0" + str(today_month) + ".2021", 1, (0, 0, 0))
    window.blit(text, (20, 25))

    now = datetime.now()
    current_time = now.strftime("%H:%M:%S")
    time = font.render(current_time, 1, (0, 0, 0))
    window.blit(time, (830, 25))


def draw_columns(x, distance_column, mouse_pos):
    for i in range(24):
        box = pygame.Rect(x, 125 + 30 * (i + 1), 310, 30)
        if box.collidepoint(mouse_pos):
            pygame.draw.rect(window, (0, 100, 0), box)
            marks_list[i + distance_column * 24] = 1
        else:
            marks_list[i + distance_column * 24] = 0
            if i % 2:
                pygame.draw.rect(window, (100, 100, 100), box)
            else:
                pygame.draw.rect(window, (150, 150, 150), box)


def display_3_days(year, days, mouse_pos):
    """
    display 3 days - yesterday, today, tomorrow with hour plan
    :param year: obj class Year
    :return: none
    """
    today_day = date.today().day
    today_month = date.today().month
    if days > 0:
        today_day += days  # > month.day.size
        while True:
            if today_day > year.get_count_day_in_month(today_month) - 1:
                today_day -= year.get_count_day_in_month(today_month)
                today_month += 1
            else:
                break
    if days <= 0:
        today_day += days  # > month.day.size
        while True:
            if today_day <= 0:
                today_month -= 1
                today_day += year.get_count_day_in_month(today_month)
            else:
                break

    if today_day == 1:
        yesterday = year.get_day_plan_list(today_month - 1, 0)
    else:
        yesterday = year.get_day_plan_list(today_month, today_day - 1)

    today = year.get_day_plan_list(today_month, today_day)
    if today_day == year.get_count_day_in_month(today_month):
        tomorrow = year.get_day_plan_list(today_month + 1, 0)
    else:
        tomorrow = year.get_day_plan_list(today_month, today_day + 1)

    draw_date(today_day - 1, today_month, 125, 100)
    draw_date(today_day, today_month, 450, 100)
    draw_date(today_day + 1, today_month, 775, 100)

    # LEFT COLUMN
    draw_columns(10, 0, mouse_pos)
    for i in range(24):
        time = font2.render(yesterday[i][0], 1, (0, 0, 0))
        window.blit(time, (20, 130 + 30 * (i + 1)))
        text = font2.render(yesterday[i][1], 1, (0, 0, 0))
        window.blit(text, (80, 130 + 30 * (i + 1)))

    pygame.draw.line(window, (0, 0, 0), (100, 155), (100, 875))

    # MIDDLE COLUMN
    draw_columns(345, 1, mouse_pos)
    for i in range(24):
        time = font2.render(today[i][0], 1, (0, 0, 0))
        window.blit(time, (355, 130 + 30 * (i + 1)))
        text = font2.render(today[i][1], 1, (0, 0, 0))
        window.blit(text, (415, 130 + 30 * (i + 1)))

    pygame.draw.line(window, (0, 0, 0), (425, 155), (425, 875))

    # RIGHT COLUMN
    draw_columns(680, 2, mouse_pos)
    for i in range(24):
        time = font2.render(tomorrow[i][0], 1, (0, 0, 0))
        window.blit(time, (690, 130 + 30 * (i + 1)))
        text = font2.render(tomorrow[i][1], 1, (0, 0, 0))
        window.blit(text, (740, 130 + 30 * (i + 1)))

    pygame.draw.line(window, (0, 0, 0), (760, 155), (760, 875))


def footer(mouse_pos):
    input_box = pygame.Rect(400, 940, 500, 50)

    if input_box.collidepoint(mouse_pos):
        inp_box_active = True
    else:
        inp_box_active = False

    if inp_box_active:
        pygame.draw.rect(window, inp_box_col_active, input_box, 3)
    else:
        pygame.draw.rect(window, inp_box_col_inactive, input_box, 3)

    show_box = pygame.Rect(100, 940, 200, 50)
    pygame.draw.rect(window, (150, 150, 150), show_box)
    pygame.draw.rect(window, (50, 50, 50), show_box, 3)


def red_raw_game_window(year, mouse_pos):
    window.fill((0, 128, 128))
    display_3_days(year, change_day,mouse_pos)
    heading()
    button_next.draw(window, True)
    button_back.draw(window, True)
    button_today.draw(window, True)
    footer(mouse_pos)
    pygame.display.update()


# main loop

run = True
clock = pygame.time.Clock()
button_next = Button((100, 100, 100), 820, 900, 80, 30, "NEXT")
button_back = Button((100, 100, 100), 100, 900, 80, 30, "BACK")
button_today = Button((100, 100, 100), 470, 900, 80, 30, "TODAY")
year = menu.init_list()
change_day = 0
pos = (0, 0)
marks_list = [0 for _ in range(72)]
inp_box_active = False
inp_box_col_inactive = (0, 100, 100)
inp_box_col_active = (0, 200, 200)

while run:
    clock.tick(27)

    red_raw_game_window(year, pos)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False

        if event.type == pygame.MOUSEBUTTONUP:
            pos = pygame.mouse.get_pos()
            if button_next.isOver(pos):
                change_day += 1
            if button_back.isOver(pos):
                change_day -= 1
            if button_today.isOver(pos):
                change_day = 0

    for idx, mark in enumerate(marks_list):
        if mark:
            print("Mark:", idx )

pygame.quit()
