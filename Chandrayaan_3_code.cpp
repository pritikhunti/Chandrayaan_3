#include <stdio.h>

// Enum to represent different directions
typedef enum {
    N, S, E, W, Up, Down
} Direction;

// Structure to represent the spacecraft
typedef struct {
    int x, y, z;
    Direction direction;
} Spacecraft;

// Function to move the spacecraft forward
void move_forward(Spacecraft *craft) {
    switch (craft->direction) {
        case N:
            craft->y += 1;
            break;
        case S:
            craft->y -= 1;
            break;
        case E:
            craft->x += 1;
            break;
        case W:
            craft->x -= 1;
            break;
        default:
            break;
    }
}

// Function to move the spacecraft backward
void move_backward(Spacecraft *craft) {
    switch (craft->direction) {
        case N:
            craft->y -= 1;
            break;
        case S:
            craft->y += 1;
            break;
        case E:
            craft->x -= 1;
            break;
        case W:
            craft->x += 1;
            break;
        default:
            break;
    }
}

// Function to turn the spacecraft left
void turn_left(Spacecraft *craft) {
    switch (craft->direction) {
        case N:
            craft->direction = W;
            break;
        case S:
            craft->direction = E;
            break;
        case E:
            craft->direction = N;
            break;
        case W:
            craft->direction = S;
            break;
        default:
            break;
    }
}

// Function to turn the spacecraft right
void turn_right(Spacecraft *craft) {
    switch (craft->direction) {
        case N:
            craft->direction = E;
            break;
        case S:
            craft->direction = W;
            break;
        case E:
            craft->direction = S;
            break;
        case W:
            craft->direction = N;
            break;
        default:
            break;
    }
}

// Function to turn the spacecraft up
void turn_up(Spacecraft *craft) {
    if (craft->direction != Up) {
        craft->direction = Up;
    }
}

// Function to turn the spacecraft down
void turn_down(Spacecraft *craft) {
    if (craft->direction != Down) {
        craft->direction = Down;
    }
}

int main() {
    Spacecraft spacecraft = {0, 0, 0, N};  // Initialize spacecraft
    char commands[] = {'f', 'r', 'u', 'b', 'l'};
    int num_commands = sizeof(commands) / sizeof(commands[0]);

    for (int i = 0; i < num_commands; i++) {
        switch (commands[i]) {
            case 'f':
                move_forward(&spacecraft);
                break;
            case 'b':
                move_backward(&spacecraft);
                break;
            case 'l':
                turn_left(&spacecraft);
                break;
            case 'r':
                turn_right(&spacecraft);
                break;
            case 'u':
                turn_up(&spacecraft);
                break;
            case 'd':
                turn_down(&spacecraft);
                break;
            default:
                break;
        }
    }

    printf("Final Position: (%d, %d, %d)\n", spacecraft.x, spacecraft.y, spacecraft.z);
    printf("Final Direction: %d\n", spacecraft.direction);

    return 0;
}

