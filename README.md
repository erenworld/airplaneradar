# airplaneradar
Collision detection between a large number of flying planes within a 2D space.

# My Radar

## Description

My Radar is a 2D visualization panel simulating air traffic (AT) written in C. It renders aircrafts and control towers, simulating their behavior based on a set of rules.

## Features

- Aircrafts flying from given places to others
- Aircrafts appearing when taking off and disappearing when landing
- Aircrafts moving in straight lines at constant speeds
- Collision detection between aircrafts
- Control areas allowing aircrafts to pass through without destruction
- Stationary control towers with control areas
- Timer display
- Configurable visibility of hitboxes, areas, and sprites

## Compilation

The project uses a Makefile for compilation. Use the following commands:

- make # Compile the project
- make re # Recompile the project
- make clean # Remove object files
- make fclean # Remove object files and the binary

## Usage

./my_radar [script_file]
./my_radar -h

- `script_file`: Path to the simulation script file
- `-h`: Display usage information

## User Interactions

- `L`: Toggle visibility of hitboxes and areas
- `S`: Toggle visibility of entities' sprites

## Error Handling

- The program displays error messages on the error output
- Exits with error code 84 in case of an error, 0 otherwise

## Requirements

- CSFML library
- C compiler (gcc recommended)
- Make

## File Structure

├── Makefile
├── include/
│ └── (header files)
├── src/
│ └── (source files)
├── assets/
│ └── (sprite files)
└── bonus/
└── (bonus features and specific Makefile if any)

## Notes

- The simulation window is 1920x1080 pixels
- Aircrafts have 20x20 square shaped hitboxes
- Control towers have circular control areas
- The program stops when all aircrafts have landed or been destroyed

For more detailed information, please refer to the project documentation.
