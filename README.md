# Multiplayer Control ArchViz Project

## Features
- The project contains two types of pawns an Orbital Pawn for an orbital view of the Villa and a First Person Pawn for an interior view.
- Contains a fully functional widget system for easy control and view.
- Has multiple points of view (POV) to look at the villa from both outside and inside with smooth lerping movement.
- Contains Color Configurators and Layout Modifies to customize objects and locations.
- Color Configurators can change the color of meshes that are assigned to it.
- Layout Modifier can modify layout by two methods such as:
  - By activating multiple Color Changers that are assigned to it
  - By loading and unloading streaming levels assigned to and modifying the visibility of actors present at the loaded streaming level.
- The project contains a Car Spawner system that spawns cars uniformly and moves them around on the desired path.
- Contains a Day-Night slider that allows you to visualize the real-time Day-Night cycle.

## Multiplayer
- The project contains a multiplayer mode with a fully functioning multiplayer menu system.
- The multiplayer menu system contains features like session creation, finding sessions, joining sessions, avatar selection mode, and a few session details to set.
- Contains multiplayer pawn controls.
- Contains replicated pawn movement both in terms of player movement and lerping POV movement.
- Shows replicated selected avatar color and name on players in the form of a widget during the session.

## How to Run?
- Clone or download the project to your computer.
- Run the uproject file to start the project.
- The project will by default open with the multiplayer menu level.
