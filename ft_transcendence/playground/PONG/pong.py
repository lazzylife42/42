import pygame, sys, random

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

ball_speed_x = 7 * random.choice((1, -1))
ball_speed_y = 7 * random.choice((1, -1))
player_speed = 0
oppenent_speed = 7

# Scores
player_score = 0
oppenent_score = 0
game_over = False

font = pygame.font.Font(None, 74)

# Game Logic
def ball_animation():
    global ball_speed_x, ball_speed_y, player_score, oppenent_score, game_over
    ball.x += ball_speed_x
    ball.y += ball_speed_y
    if ball.top <= 0 or ball.bottom >= screen_height:
        ball_speed_y *= -1
    if ball.left <= 0:
        player_score += 1
        if player_score == 5:
            game_over = True
        ball_restart()
    if ball.right >= screen_width:
        oppenent_score += 1
        if oppenent_score == 5:
            game_over = True
        ball_restart()

    if ball.colliderect(player):
        ball_speed_x *= -1
        ball.right = player.left

    if ball.colliderect(oppenent):
        ball_speed_x *= -1
        ball.left = oppenent.right

def player_animation():
    player.y += player_speed
    if player.top <= 0:
        player.top = 0
    if player.bottom >= screen_height:
        player.bottom = screen_height

def opponent_animation():
    if oppenent.top < ball.y:
        oppenent.top += oppenent_speed
    if oppenent.bottom > ball.y:
        oppenent.bottom -= oppenent_speed
    if oppenent.top <= 0:
        oppenent.top = 0
    if oppenent.bottom >= screen_height:
        oppenent.bottom = screen_height

def ball_restart():
    global ball_speed_x, ball_speed_y
    ball.center = (screen_width / 2, screen_height / 2)
    ball_speed_x *= random.choice((1, -1))
    ball_speed_y *= random.choice((1, -1))

def display_score():
    player_text = font.render(f"{player_score}", True, c_white)
    oppenent_text = font.render(f"{oppenent_score}", True, c_white)
    screen.blit(player_text, (screen_width / 2 + 20, screen_height / 2))
    screen.blit(oppenent_text, (screen_width / 2 - 40, screen_height / 2))

def display_winner(winner):
    winner_text = font.render(f"{winner} Wins!", True, c_white)
    screen.blit(winner_text, (screen_width / 2 - 140, screen_height / 2 - 50))

# Main loop
while True:
    # Game Logic
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_DOWN:
                player_speed += 7
            if event.key == pygame.K_UP:
                player_speed -= 7
            if event.key == pygame.K_ESCAPE:
                pygame.quit()
                sys.exit()
        if event.type == pygame.KEYUP:
            if event.key == pygame.K_DOWN:
                player_speed -= 7
            if event.key == pygame.K_UP:
                player_speed += 7

    if not game_over:
        # Animations
        ball_animation()
        player_animation()
        opponent_animation()

    # Visuals
    screen.fill(bg_color)
    pygame.draw.rect(screen, c_white, player)
    pygame.draw.rect(screen, c_white, oppenent)
    pygame.draw.rect(screen, c_white, ball)
    pygame.draw.aaline(screen, c_white, (screen_width / 2, 0), (screen_width / 2, screen_height))

    display_score()

    if game_over:
        winner = "Player" if player_score == 5 else "Opponent"
        screen.fill(bg_color)
        display_winner(winner)

    # Updating the window
    pygame.display.flip()
    clock.tick(60)
