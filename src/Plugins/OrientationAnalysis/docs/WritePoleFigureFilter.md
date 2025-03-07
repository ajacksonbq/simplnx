# Export Pole Figure Images

## Group (Subgroup)

IO (Output)

## Description

This **Filter** creates a standard pole figure image for each **Ensemble** in a selected **Data Container** with an **Image Geometry**. The **Filter** uses Euler angles in radians and requires the crystal structures for each **Ensemble** array and the corresponding **Ensemble** Ids on the **Cells**. The **Filter** also optionally can use a *mask* array to determine which **Cells** are valid for the pole figure computation.

### Algorithm Choice

1: The pole figure algorithm uses a *modified Lambert square* to perform the interpolations onto the unit circle. This is an alternate type of interpolation that the EBSD OEMs do not perform which may make the output from DREAM.3D look slightly different than output obtained from the OEM programs.

**Only an advanced user with intimate knowledge of the modified Lambert projection should attempt to change the value for the "Lambert Image Size (Pixels)" input parameter.**

2: Discrete Pole figure. The algorithm will simply mark each pixel that had at least 1 count as a black pixel.

### Layout

The 3 pole figures can be laid out in a Square, Horizontal row or vertical column. Supporting informatio (including the color bar legend for color pole figures) will also be printed on the image.

| Lambert Projection | Discrete |
|--------------------|----------|
| ![Example Pole Figure Using Square Layout](Images/PoleFigure_Example.png) | ![Example Pole Figure Using Square Layout](Images/Pole_Figure_Discrete_Example.png) |

% Auto generated parameter table will be inserted here

## Example Pipelines

+ TxCopper_Exposed
+ TxCopper_Unexposed

## License & Copyright

Please see the description file distributed with this **Plugin**

## DREAM3D-NX Help

If you need help, need to file a bug report or want to request a new feature, please head over to the [DREAM3DNX-Issues](https://github.com/BlueQuartzSoftware/DREAM3DNX-Issues) GItHub site where the community of DREAM3D-NX users can help answer your questions.
