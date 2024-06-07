from flask import Flask, render_template
from flask_socketio import SocketIO, emit

app = Flask(__name__)
socketio = SocketIO(app)

game_state = {
    'ball': {'x': 320, 'y': 180, 'vx': 6, 'vy': 6},
    'player1': {'y': 180, 'speed': 0},
    'player2': {'y': 180, 'speed': 0},
    'player1_score': 0,
    'player2_score': 0,
    'game_over': False,
    'game_started': False
}

@app.route('/')
def index():
    return render_template('index.html')

@socketio.on('connect')
def handle_connect():
    emit('update_state', game_state)

@socketio.on('start_game')
def handle_start_game():
    global game_state
    game_state['game_started'] = True
    game_state['game_over'] = False
    game_state['player1_score'] = 0
    game_state['player2_score'] = 0
    game_state['ball'] = {'x': 320, 'y': 180, 'vx': 6, 'vy': 6}
    game_state['player1'] = {'y': 180, 'speed': 0}
    game_state['player2'] = {'y': 180, 'speed': 0}
    emit('update_state', game_state, broadcast=True)

@socketio.on('update_state')
def handle_update_state(data):
    global game_state
    game_state.update(data)
    emit('update_state', game_state, broadcast=True)

@socketio.on('request_state')
def handle_request_state():
    emit('update_state', game_state)

@socketio.on('stop_game')
def handle_stop_game():
    global game_state
    game_state['game_started'] = False
    game_state['game_over'] = True
    emit('update_state', game_state, broadcast=True)

@socketio.on('player_input')
def handle_player_input(data):
    global game_state
    game_state['player1']['speed'] = data['player1Speed']
    game_state['player2']['speed'] = data['player2Speed']
    emit('update_state', game_state, broadcast=True)

if __name__ == '__main__':
    socketio.run(app, debug=True)
