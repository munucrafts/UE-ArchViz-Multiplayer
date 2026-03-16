# Multiplayer Control ArchViz Project

<p align="center">
  <img src="https://github.com/user-attachments/assets/80d23a57-4efd-4092-a4b5-4aafc236e12b" width="400"/>
  <img src="https://github.com/user-attachments/assets/88b366e9-bd22-443b-bc90-06a85fff895e" width="400"/>
</p>

<p align="center">
  <img src="https://github.com/user-attachments/assets/524b17d9-c08d-45fa-8645-fd6738baa5a1" width="400"/>
  <img src="https://github.com/user-attachments/assets/13247384-75d7-424e-a024-701f7d0bb531" width="400"/>
</p>

---

## Features

* The project contains two types of pawns:

  * **Orbital Pawn** for an orbital view of the Villa
  * **First Person Pawn** for an interior view

* Contains a fully functional **widget system** for easy control and view.

* Has multiple **points of view (POVs)** to look at the villa from both outside and inside with smooth **lerping movement**.

* Contains **Color Configurators** and **Layout Modifiers** to customize objects and locations.

* **Color Configurators**

  * Can change the color (materials) of meshes on actors that are assigned to it.

* **Layout Modifier**

  * Can modify layout by two methods such as:

    * Activating multiple Color Configurators that are assigned to it.
    * Loading and unloading streaming levels assigned to it and randomly modifying the visibility of actors present in the loaded streaming level.

* The project contains a **Car Spawner system**

  * Spawns cars uniformly
  * Moves them on the desired path using **spline control**

* Contains a **Day-Night slider**

  * Allows visualization of the real-time **Day-Night cycle**

---

## Multiplayer

* The project contains a **multiplayer mode** with a fully functioning multiplayer menu system.

* The multiplayer menu system contains features like:

  * Session creation
  * Finding sessions
  * Joining sessions
  * Avatar selection mode
  * Session details configuration

* Contains **multiplayer pawn controls**

* Contains **replicated pawn movement**

  * Player movement
  * Lerping POV movement

* Shows **replicated selected avatar color and name** on players in the form of a widget during the session.

---

## How to Run?

1. Clone or download the project to your computer.
2. Right-click on the **.uproject** file and generate the solution.
3. Open the solution and set **"ArchViz"** as the startup project.
4. Run the **.uproject** file to start the project.
5. The project will by default open with the **multiplayer menu level**.
