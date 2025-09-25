# CUB3D - 3D Raycasting Game Engine

A 42 School project that recreates a classic Wolfenstein 3D-style game using raycasting techniques with the MiniLibX graphics library.

**Contributors**: [@BeAzarym](https://github.com/BeAzarym) & [@Bengschor](https://github.com/Bengschor)

## Overview

**Cub3D** is a 3D game engine built from scratch using the raycasting technique, similar to the original Wolfenstein 3D (1992). This project demonstrates advanced C programming skills, mathematical concepts for 3D rendering, and real-time graphics programming.

The engine renders a 3D maze from a 2D map perspective, creating an immersive first-person experience with textured walls, smooth player movement, and collision detection.

## Features

### Core Functionality
- **3D Raycasting Engine**: Real-time 3D rendering from 2D map data
- **Textured Walls**: Support for different textures on each wall direction (North, South, East, West)
- **First-Person Movement**: Smooth player movement with WASD controls
- **Mouse Look**: Camera rotation with arrow keys
- **Collision Detection**: Prevents walking through walls
- **Map Parsing**: Robust `.cub` file format parser with error handling

### Visual Features
- **Floor and Ceiling Colors**: Customizable RGB colors
- **Texture Mapping**: XPM texture support for wall rendering
- **Interactive Minimap**: Real-time minimap with player position indicator
- **Fullscreen Map View**: Toggle between small and fullscreen map modes
- **Cross-Platform Compatibility**: Works on both Linux and macOS
- **Optimized Rendering**: Fast math operations for smooth gameplay

## Installation

### Prerequisites
- **GCC** compiler
- **Make**
- **X11 development libraries** (Linux only)
- **Xcode Command Line Tools** (macOS only)

### Linux Setup
```bash
# Install required packages (Ubuntu/Debian)
sudo apt-get update
sudo apt-get install gcc make xorg libxext-dev libbsd-dev

# Clone and build
git clone https://github.com/BeAzarym/42-Cub3d_m8.git
cd 42-Cub3d_m8
make
```

### macOS Setup
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Clone and build
git clone https://github.com/BeAzarym/42-CUB3D.git
cd 42-CUB3D
make
```

## Usage

### Running the Game
```bash
./cub3d maps/correct_map.cub
```

### Controls
- **W, A, S, D**: Move forward, left, backward, right
- **Left/Right Arrow Keys**: Rotate camera left/right
- **Up Arrow**: Show minimap
- **Down Arrow**: Hide minimap
- **M**: Toggle fullscreen map view (hold for fullscreen)
- **ESC**: Exit the game
- **Red X**: Close window

### Map Format (.cub files)

The game uses a specific map format with the following structure:

```
NO ./assets/north_texture.xpm
SO ./assets/south_texture.xpm
WE ./assets/west_texture.xpm  
EA ./assets/east_texture.xpm

F 220,100,0    # Floor color (R,G,B)
C 225,30,0     # Ceiling color (R,G,B)

111111111
100000001
10N000001    # N = Player starting position (North-facing)
100000001
111111111
```

**Map Elements**:
- `0`: Empty space (walkable)
- `1`: Wall
- `N/S/E/W`: Player starting position and orientation
- Must be surrounded by walls (closed map)

## Project Structure

```
Cub3d_With_M8/
├── Makefile              # Build configuration
├── includes/             # Header files
│   ├── cub3d.h          # Main header
│   └── cub3d_bonus.h    # Bonus features header
├── srcs/                # Source code
│   ├── main.c           # Main game loop
│   ├── debug/           # Debugging utilities
│   ├── hooks/           # Event handlers
│   ├── parsing/         # Map and config parsing
│   ├── raycasting/      # 3D rendering engine
│   └── utils/           # Utility functions
├── maps/                # Sample maps
│   ├── correct_map.cub  # Valid test map
│   └── *.cub           # Various test cases
├── assets/              # Texture files
│   └── *.xpm           # Wall textures
└── minilibx/            # Graphics library
    ├── minilinux/       # Linux version
    └── minimac/         # macOS version
```

## Technical Implementation

### Raycasting Algorithm
The engine uses the **DDA (Digital Differential Analyzer)** algorithm to cast rays from the player position and calculate wall intersections:

1. **Ray Casting**: Cast rays from player position for each screen column
2. **DDA Algorithm**: Step through grid to find wall intersections
3. **Distance Calculation**: Calculate perpendicular wall distance
4. **Texture Mapping**: Map wall textures based on hit position
5. **Rendering**: Draw vertical wall strips with proper height

### Key Components
- **Parser**: Validates and loads `.cub` map files
- **Raycasting Engine**: Handles 3D projection mathematics  
- **Texture System**: Manages XPM texture loading and mapping
- **Minimap System**: Real-time 2D map overlay with player tracking
- **Input System**: Processes keyboard events for movement
- **Collision Detection**: Prevents invalid player movement

## Minimap Feature

The bonus version includes an interactive minimap system that enhances gameplay navigation:

### Minimap Display
- **Real-time Updates**: Shows current player position and orientation
- **Color-coded Elements**:
  - **Blue**: Walls and obstacles
  - **White**: Walkable floor space  
  - **Pink**: Player starting position
  - **Purple**: Current player position with orientation indicator

### Map Controls
- **Up Arrow**: Toggle minimap visibility on/off
- **M Key**: Hold to view fullscreen map overlay
- **Dynamic Sizing**: Automatically scales based on map dimensions
- **Corner Positioning**: Minimap positioned in screen corner for non-intrusive gameplay

### Technical Implementation
- Renders 2D grid representation of the 3D world
- Real-time player position tracking with smooth updates
- Efficient drawing system using square-based rendering
- Responsive scaling for different map sizes

## Error Handling

The engine includes comprehensive error checking for:
- Invalid map format or missing elements
- Inaccessible texture files
- Invalid color values
- Unclosed maps or invalid characters
- Multiple or missing player positions
- Memory allocation failures

## Development Commands

```bash
make          # Build the project
make clean    # Remove object files  
make fclean   # Remove all build files
make re       # Rebuild from scratch
```

## Sample Maps

The project includes various test maps:
- `correct_map.cub`: Basic valid map for testing
- `custom.cub`: Complex maze layout
- `bad_*.cub`: Invalid maps for error testing
- `simple.cub`: Minimal map example

## Contributing

This project was developed collaboratively by:
- **[@BeAzarym](https://github.com/BeAzarym)**
- **[@Bengschor](https://github.com/Bengschor)**

---
