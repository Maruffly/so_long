<p align="center">
    <img src="https://img.shields.io/badge/Score-125%2F100-success?style=for-the-badge&logo=42" alt="Score 125/100">
    <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c" alt="Language C">
</p>

# 🍄 so_long - The Smurfs' Adventure

**so_long** is a 2D top-down game developed as part of the 42 school curriculum. In this version, you play as a Smurf who must collect all the mushrooms scattered across the map and reach the exit while avoiding obstacles.



## 🎮 Gameplay

* **Objective**: Collect every Mushroom (**C**) on the map and escape through the Exit (**E**).
* **Move Counter**: Your total number of moves is displayed in real-time in the shell and/or the game window.
* **Victory**: The exit only opens/works once all Smurf-berries/Mushrooms are collected.
* **Controls**:
    * `W` or `Up Arrow` : Move Up
    * `S` or `Down Arrow` : Move Down
    * `A` or `Left Arrow` : Move Left
    * `D` or `Right Arrow` : Move Right
    * `ESC` or `Close Window` : Quit the game

---

## 🛠️ Technical Implementation

* **Graphics**: Built using the **MiniLibX** library.
* **Map Parsing**:
    * Reads and parses `.ber` files.
    * Checks for rectangularity and valid characters (`0`, `1`, `C`, `E`, `P`).
    * Validates that the map is fully enclosed by walls (`1`).
* **Pathfinding (Flood Fill)**:
    * Before the game starts, the program uses a **Flood Fill algorithm** to ensure there is a valid path from the Smurf to every collectible and the exit.
    * If a mushroom or the exit is unreachable, the game refuses to launch to prevent impossible levels.
* **Memory Management**:
    * All heap-allocated memory is properly freed upon exit.
    * MLX images and window pointers are safely destroyed to prevent memory leaks.

---

## Installation & Usage

### 1. Build the project
Compile the game using the `Makefile`:
```bash
make
#Or
make bonus
```
### 2. Run the game
Execute the program by providing a map file from the maps folder:
```
./so_long maps/map.ber
```


