# Export Pole Figure Images

## Group (Subgroup)

IO (Output)

## Description

This **Filter** creates a standard pole figure image for each **Ensemble** in a selected **Data Container** with an **Image Geometry**. The **Filter** uses Euler angles in radians and requires the crystal structures for each **Ensemble** array and the corresponding **Ensemble** Ids on the **Cells**. The **Filter** also requires a *mask* array to determine which **Cells** are valid for the pole figure computation.

### Algorithm Choice

1: The pole figure algorithm uses a *modified Lambert square* to perform the interpolations onto the circle. This is an alternate type of interpolation that the EBSD OEMs do not perform which may make the output from DREAM.3D look slightly different than output obtained from the OEM programs.

**Only an advanced user with intimate knowledge of the modified Lambert projection should attempt to change the value for the "Lambert Image Size (Pixels)" input parameter.**

2: Discrete Pole Figure

| Lambert Projection | Discrete |
|-----|--------|
| ![Example Pole Figure Using Square Layout](Images/PoleFigure_Example.png) | ![Example Pole Figure Using Square Layout](Images/Pole_Figure_Discrete_Example.png) |

## Parameters

| Name | Type | Description |
|------------|------| --------------------------------- |
| Pole Figure Type | Enumeration: 0=Lambert, 1=Discrete | Controls the type of pole figure |
| Image Format | Enumeration | Image file format to write. Currently supports .tif, .bmp, and .png file formats |
| Lambert Image Size (Pixels) | int32_t | Size of the Lambert square in pixels |
| Number of Colors | int32_t | Number of colors to use to make the pole figure |
| Image Layout | Enumeration | Layout for the resulting pole figure images, either square, horizontal, or vertical |
| Image Prefix | String | Prefix the prepend each pole figure file with |
| Output Path | File Path | Output directory path for images |
| Image Size (Square Pixels) | int32_t | Size of the output image in square pixels |
| Use Mask Array | bool | Specifies whether to use a boolean array to exclude some **Cells**. Only those cells that have a *Mask Array* value of 1 will be used. |

## Required Geometry

NONE

## Required Objects

| Kind                      | Default Name | Type     | Comp Dims | Description                                 |
|---------------------------|--------------|----------|--------|---------------------------------------------|
| Cell Attribute Array | EulerAngles | float | (3)  | Three angles defining the orientation of the **Cell** in Bunge convention (Z-X-Z) |
| Cell Attribute Array | Phases | int32_t | (1) | Specifies to which **Ensemble** each **Cell** belongs |
| Cell Attribute Array | Mask | bool | (1) | Used to define **Cells** as *good* or *bad* |
| Ensemble Attribute Array | CrystalStructures | uint32_t | (1) | Enumeration representing the crystal structure for each Ensemble |

## Created Objects

None

## Example Pipelines

+ TxCopper_Exposed
+ TxCopper_Unexposed

## License & Copyright

Please see the description file distributed with this **Plugin**

## DREAM3D-NX Help

If you need help, need to file a bug report or want to request a new feature, please head over to the [DREAM3DNX-Issues](https://github.com/BlueQuartzSoftware/DREAM3DNX-Issues) GItHub site where the community of DREAM3D-NX users can help answer your questions.
