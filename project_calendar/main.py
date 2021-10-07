import file
from button import Button
from board import Board
import pygame


def red_raw_game_window(obj, mouse_pos):
    board.window.fill((0, 128, 128))
    Board.display_3_days(obj, mouse_pos)
    Board.heading(obj)
    button_next.draw(board.window, True)
    button_back.draw(board.window, True)
    button_today.draw(board.window, True)
    button_clear.draw(board.window, True)
    board.footer()
    pygame.display.update()


# main loop
run = True
clock = pygame.time.Clock()
button_next = Button((100, 100, 100), 820, 895, 80, 30, "NEXT")
button_back = Button((100, 100, 100), 100, 895, 80, 30, "BACK")
button_today = Button((100, 100, 100), 470, 895, 80, 30, "TODAY")
button_clear = Button((100, 100, 100), 50, 945, 80, 40, "CLEAR")
pos = (0, 0)
board = Board()

while run:
    clock.tick(27)

    red_raw_game_window(board, pos)

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            file.write_to_file(board.year)
            run = False

        if event.type == pygame.MOUSEBUTTONUP:
            pos = pygame.mouse.get_pos()
            if button_next.is_clicked(pos):
                board.change_day += 1
                board.save_index_marks -= 24
            if button_back.is_clicked(pos):
                board.change_day -= 1
                board.save_index_marks += 24
            if button_today.is_clicked(pos):
                board.change_day = 0
                board.save_index_marks = -1
            if button_clear.is_clicked(pos):
                board.save_index_marks = -1
                board.input_text = ""
                board.inp_box_active = False
        board.get_input_text(event)

pygame.quit()
