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


class Board:
    def __init__(self):
        self.year = menu.init_list()
        self.today_day = date.today().day
        self.today_month = date.today().month
        self.display_day = self.today_day
        self.display_month = self.today_month
        self.change_day = 0
        self.marks_list = [0 for _ in range(72)]
        self.inp_box_active = False
        self.inp_box_col_inactive = (0, 100, 100)
        self.inp_box_col_active = (0, 200, 200)
        self.save_index_marks = -1
        self.marks_day = -10

    def convert_date(self, day, month):
        if day > self.year.get_count_day_in_month(month):
            day -= self.year.get_count_day_in_month(month)
            month += 1

        if day <= 0:
            month -= 1
            day += self.year.get_count_day_in_month(month)
            if month < 10:
                text = str(day) + ".0" + str(month)
            else:
                text = str(day) + "." + str(month)
        elif 0 < day < 10:
            if month < 10:
                text = "0" + str(day) + ".0" + str(month)
            else:
                text = "0" + str(day) + "." + str(month)
        else:
            if month < 10:
                text = str(day) + ".0" + str(month)
            else:
                text = str(day) + "." + str(month)

        return str(text)

    def draw_date(self, day, month, x, y):
        black_color = (0, 0, 0)
        text = Board.convert_date(self, day, month)
        text = font.render(text, True, black_color)
        window.blit(text, (x, y))

    def heading(self):
        black_color = (0, 0, 0)
        pygame.draw.rect(window, (180, 180, 180), (10, 10, 980, 70))
        text = font.render("Today: " + str(self.today_day) + ".0" + str(self.today_month) + ".2021", True, black_color)
        window.blit(text, (20, 25))
    
        now = datetime.now()
        current_time = now.strftime("%H:%M:%S")
        time = font.render(current_time, True, black_color)
        window.blit(time, (830, 25))
    
    def draw_columns(self, x, distance_column, mouse_pos):
        for i in range(24):
            box = pygame.Rect(x, 125 + 30 * (i + 1), 310, 30)
            if box.collidepoint(mouse_pos):
                self.marks_list[i + distance_column * 24] = 1
                self.save_index_marks = i + distance_column * 24
            else:
                self.marks_list[i + distance_column * 24] = 0
                if i % 2:
                    pygame.draw.rect(window, (100, 100, 100), box)
                else:
                    pygame.draw.rect(window, (150, 150, 150), box)

            if self.save_index_marks == i and distance_column == 0:
                pygame.draw.rect(window, (0, 100, 0), box)
            elif self.save_index_marks == i + 24 and distance_column == 1:
                pygame.draw.rect(window, (0, 100, 0), box)
            elif self.save_index_marks == i + 48 and distance_column == 2:
                pygame.draw.rect(window, (0, 100, 0), box)

    def display_3_days(self, mouse_pos):
        """
        display 3 days - yesterday, today, tomorrow with hour plan
        :param mouse_pos: save mouse position
        :return: none
        """
        self.display_day = self.today_day
        self.display_month = self.today_month
        black_color = (0, 0, 0)
        if self.change_day > 0:
            self.display_day += self.change_day  # > month.day.size
            while True:
                if self.display_day > self.year.get_count_day_in_month(self.display_month) - 1:
                    self.display_day -= self.year.get_count_day_in_month(self.display_month)
                    self.display_month += 1
                else:
                    break
        if self.change_day <= 0:
            self.display_day += self.change_day  # > month.day.size
            while True:
                if self.display_day <= 0:
                    self.display_month -= 1
                    self.display_day += self.year.get_count_day_in_month(self.display_month)
                else:
                    break

        if self.display_day == 1:
            yesterday = self.year.get_day_plan_list(self.display_month - 1, 0)
        else:
            yesterday = self.year.get_day_plan_list(self.display_month, self.display_day - 1)

        today = self.year.get_day_plan_list(self.display_month, self.display_day)
        if self.display_day == self.year.get_count_day_in_month(self.display_month):
            tomorrow = self.year.get_day_plan_list(self.display_month + 1, 0)
        else:
            tomorrow = self.year.get_day_plan_list(self.display_month, self.display_day + 1)

        Board.draw_date(self, self.display_day - 1, self.display_month, 125, 100)
        Board.draw_date(self, self.display_day, self.display_month, 450, 100)
        Board.draw_date(self, self.display_day + 1, self.display_month, 775, 100)

        # LEFT COLUMN
        Board.draw_columns(self, 10, 0, mouse_pos)
        for i in range(24):
            time = font2.render(yesterday[i][0], True, black_color)
            window.blit(time, (20, 130 + 30 * (i + 1)))
            text = font2.render(yesterday[i][1], True, black_color)
            window.blit(text, (80, 130 + 30 * (i + 1)))

        pygame.draw.line(window, black_color, (100, 155), (100, 875))

        # MIDDLE COLUMN
        Board.draw_columns(self, 345, 1, mouse_pos)
        for i in range(24):
            time = font2.render(today[i][0], True, black_color)
            window.blit(time, (355, 130 + 30 * (i + 1)))
            text = font2.render(today[i][1], True, black_color)
            window.blit(text, (415, 130 + 30 * (i + 1)))

        pygame.draw.line(window, black_color, (425, 155), (425, 875))

        # RIGHT COLUMN
        Board.draw_columns(self, 680, 2, mouse_pos)
        for i in range(24):
            time = font2.render(tomorrow[i][0], True, black_color)
            window.blit(time, (690, 130 + 30 * (i + 1)))
            text = font2.render(tomorrow[i][1], True, black_color)
            window.blit(text, (740, 130 + 30 * (i + 1)))

        pygame.draw.line(window, black_color, (760, 155), (760, 875))

    def footer(self, mouse_pos):
        input_box = pygame.Rect(400, 940, 500, 50)

        if input_box.collidepoint(mouse_pos):
            inp_box_active = True
        else:
            inp_box_active = False

        if inp_box_active:
            pygame.draw.rect(window, self.inp_box_col_active, input_box, 3)
        else:
            pygame.draw.rect(window, self.inp_box_col_inactive, input_box, 3)

        show_box = pygame.Rect(100, 940, 200, 50)
        pygame.draw.rect(window, (150, 150, 150), show_box)
        pygame.draw.rect(window, (50, 50, 50), show_box, 3)

        if self.save_index_marks < 0:
            chosen_date = ""
            self.marks_day = -10
        elif self.save_index_marks < 24:
            chosen_date = Board.convert_date(board, self.display_day - 1, self.display_month)
            chosen_date = chosen_date + " " + str(self.save_index_marks) + ":00"
            self.marks_day = self.display_day - 1
        elif self.save_index_marks < 48:
            chosen_date = Board.convert_date(board, self.display_day, self.display_month)
            time = self.save_index_marks - 24
            chosen_date = chosen_date + " " + str(time) + ":00"
            self.marks_day = self.display_day
        elif self.save_index_marks < 72:
            chosen_date = Board.convert_date(board, self.display_day + 1, self.display_month)
            time = self.save_index_marks - 48
            chosen_date = chosen_date + " " + str(time) + ":00"
            self.marks_day = self.display_day + 1
        else:
            chosen_date = ""
            self.marks_day = -10

        black_color = (0, 0, 0)
        chosen_date = font.render(chosen_date, True, black_color)
        window.blit(chosen_date, (show_box.x + 5, show_box.y + 5))

    def display_marks(self):
        for idx, mark in enumerate(self.marks_list):
            if mark:
                print("Mark:", idx)


def red_raw_game_window(obj, mouse_pos):
    window.fill((0, 128, 128))
    Board.display_3_days(obj, pos)
    Board.heading(obj)
    button_next.draw(window, True)
    button_back.draw(window, True)
    button_today.draw(window, True)
    Board.footer(obj, mouse_pos)
    # Board.display_marks(board)
    pygame.display.update()


# main loop

run = True
clock = pygame.time.Clock()
button_next = Button((100, 100, 100), 820, 900, 80, 30, "NEXT")
button_back = Button((100, 100, 100), 100, 900, 80, 30, "BACK")
button_today = Button((100, 100, 100), 470, 900, 80, 30, "TODAY")
pos = (0, 0)
board = Board()

while run:
    clock.tick(27)

    red_raw_game_window(board, pos)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False

        if event.type == pygame.MOUSEBUTTONUP:
            pos = pygame.mouse.get_pos()
            if button_next.isOver(pos):
                board.change_day += 1
                board.save_index_marks -= 24
            if button_back.isOver(pos):
                board.change_day -= 1
                board.save_index_marks += 24
            if button_today.isOver(pos):
                board.change_day = 0
                board.save_index_marks = -1


pygame.quit()
