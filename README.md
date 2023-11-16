Video Link: https://www.youtube.com/watch?v=2Lxx25vszkY&ab_channel=%D9%8B%D9%90WA


# Render Circle in DDNet

This guide will walk you through the process of adding a new feature to your DDNet client that renders a circle around the player.

## Prerequisites

- You should have a copy of the DDNet source code. If not, you can get it from the [DDNet GitHub repository](https://github.com/ddnet/ddnet).
- knowledge about how to add files to cmakelists.txt "easy" 😅

## Steps

1. **Clone the repository**

   Open a command prompt, navigate to the `src/game/client/components` directory of your DDNet source code, and clone the repository:

   ```bash
   cd src\game\client\components
   git clone https://github.com/WAdev0/DDNet-Render-a-Red-Circle
   ```

2. **Update gameclient.h**

   Open `src/game/client/gameclient.h` and add the following lines at the top of the file:

   ```cpp
   #include "components/circle.h"
   ```

   Then, search for the `IGameClient` class and inside the `public` section, add:

   ```cpp
   CRenderCircle m_RenderCircle;
   ```

3. **Update gameclient.cpp**

   Open `src/game/client/gameclient.cpp` and add `m_RenderCircle` to the list of components:

   ```cpp
   m_vpAll.insert(m_vpAll.end(), { ... , &m_RenderCircle, ... });
   ```

4. **Update config_variables.h**

   Open `src/engine/shared/config_variables.h` and add the following lines:

   ```cpp
   MACRO_CONFIG_INT(CircleRadius, circle_radius, 64, 0, 1000, CFGFLAG_CLIENT, "Radius of the circle around the player")
   MACRO_CONFIG_INT(CircleSmoothness, circle_smoothness, 50, 3, 1000, CFGFLAG_CLIENT, "Number of segments used to draw the circle (higher values are smoother)")
   MACRO_CONFIG_INT(CircleThickness, circle_thickness, 1, 1, 100, CFGFLAG_CLIENT, "Thickness of the circle around the player")
   MACRO_CONFIG_INT(CircleRainbow, circle_rainbow, 0, 0, 1, CFGFLAG_CLIENT, "Enable or disable rainbow mode for the circle around the player")
   ```

   This adds new configuration variables for the circle radius, smoothness, thickness, and rainbow mode.

5. **Build the project**

   Finally, build the project using your preferred method (e.g., make, Visual Studio, etc.). If everything is set up correctly, you should now see a circle around the player in your DDNet client!

Good luck with your project! 😊
