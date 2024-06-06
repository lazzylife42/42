import pygame, sys

# Initialize Pygame
pygame.init()
clock = pygame.time.Clock()

# Set up the display
screen_width = 1280
screen_height = 720

screen = pygame.display.set_mode((screen_width, screen_height))
pygame.display.set_caption('🏓 PONG 🏓')

# Game
ball = pygame.Rect(screen_width / 2 - 10, screen_height / 2 - 10, 20, 20)
player = pygame.Rect(screen_width - 20, screen_height / 2 - 70, 10, 140)
oppenent = pygame.Rect(10, screen_height / 2 - 70, 10, 140)

bg_color = pygame.Color('black')
c_white = (255, 255, 255)

ball_speed_x = 7
ball_speed_y = 7

# Main loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        ball.x += ball_speed_x
        ball.y += ball_speed_y
        if ball.top <= 0 or ball.bottom >= screen_height:
            ball_speed_y *= -1
        if ball.left <= 0 or ball.right > screen_width:
            ball_speed_x *= -1

        # Visuals
        screen.fill(bg_color)
        pygame.draw.rect(screen, c_white, player)
        pygame.draw.rect(screen, c_white, oppenent)
        pygame.draw.rect(screen, c_white, ball)
        pygame.draw.aaline(screen, c_white, (screen_width / 2, 0), (screen_width / 2, screen_height))

        # Updating the window
        pygame.display.flip()
        clock.tick(60)