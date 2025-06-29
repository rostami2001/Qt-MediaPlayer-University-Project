# Qt Media Player (University Project)

A basic media player application built with Qt framework as part of an advanced programming course in January 2022.

## Features

- **Media Playback**:
  - Play/pause/stop controls
  - Volume adjustment with mute option
  - Seek functionality with progress bar
  - 10-second skip forward/backward
  - Playback speed control (0.5x, 1x, 2x)

- **Playlist Management**:
  - Add/remove media files
  - Save/load playlists
  - Reset playlist
  - Track navigation (previous/next)

- **User Interface**:
  - Main menu navigation
  - Video display widget
  - Playlist sidebar
  - Basic settings panel

## Technical Implementation

- Built with **Qt 5** (C++)
- Uses **QMediaPlayer** for core playback functionality
- Implements **QMediaPlaylist** for track management
- Custom playlist model extending **QAbstractItemModel**
- Signal-slot architecture for UI interactions

## Project Context

⚠️ **Note**: This was my first university project using Qt framework (Jan 2022). The code reflects beginner-level implementation.

Key limitations:
- Basic UI without advanced styling
- Limited error handling
- No fullscreen mode implementation
- Minimal settings customization
- Basic playlist persistence

## Building the Project

1. Ensure you have Qt 5+ installed
2. Clone this repository
3. Open `test.pro` in Qt Creator
4. Build and run the project

## Controls

| UI Element       | Functionality                  |
|------------------|--------------------------------|
| Play/Pause       | Toggle playback                |
| Stop             | Stop playback                  |
| Previous/Next    | Navigate playlist              |
| Volume Slider    | Adjust playback volume         |
| Progress Slider  | Seek through media             |
| Forward/Backward | Skip 10 seconds                |
| Speed Controls   | Change playback speed          |
| Add/Remove       | Manage playlist items          |
| Save/Load        | Persist playlist configuration |

## Course Requirements

This project fulfilled the following requirements from the Advanced Programming course:
- Qt framework implementation
- Media playback functionality
- Playlist management
- Basic UI controls
- Object-oriented design

---

### Why This Matters
This project represents my first hands-on experience with:
- Qt framework architecture
- Multimedia programming
- Model-View design patterns
- Event-driven UI development

While the implementation isn't production-grade, it served as an important foundation for my subsequent GUI development projects.
