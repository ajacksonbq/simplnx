# Neighbor Orientation Correlation

## Group (Subgroup)

Processing (Cleanup)

## Description

This **Filter** first identifies all **Cells** that have a *confidence index* below the minimum set by the user.  Then, for each of those **Cells**, their neighboring **Cells** are checked to determine the number of neighbor **Cells** with orientations different than the reference **Cell** by more than the user defined *misorientation tolerance*.  In addition the neighboring **Cells** are compared with each other to determine the number of neighboring **Cells** that have the same orientation (again within the user defined tolerance). The *Cleanup Level* set by the user is then used to determine which **Cells** are replaced.  If a level of 5 is set, then at least 5 of the neighboring **Cells** must be different than the reference **Cell** and at least 5 of the neighboring **Cells** must be the same as each other (and so on for other *Cleanup Level*). If a **Cell** meets the replacement criteria, then all of its attributes are replaced with the attributes of one of the neighboring **Cells** that are the same as each other.

*Note:* The **Filter** will iteratively reduce the *Cleanup Level* from 6 until it reaches the user defined number. So, if the user selects a level of 4, then the **Filter** will run with a level of 6, then 5, then 4 before finishing.

Neighbors are defined as a the "nearest neighbors" which share a "face". For 3D structures it is 6 neighbors that share a common face with the current cell.

### Example

|   | 0 | 1 | 2 |
|---|---|---|---|
| 0 |   | (14.0, 0.0, 0.0) CI=0.2 |  |
| 1 | (13.0, 0.0, 0.0) CI=0.2   | (0.0, 0.0, 0.0) CI=0.05 | (12.0, 0.0, 0.0) CI=0.2 |
| 2 |   | (15.0, 0.0, 0.0) CI=0.2 |   |

Schematic layout of the neighboring cells. Only the In-Plane neighbors are shown.

In this example cell (1,1) has a confidence index < 0.1 and the surrounding cells all have a misorientation tolerance not greater than 5 degrees. Comparing cell (1,1) with its neighbor cells we can see that the misorientation is greater than 5 Degrees. In this case the central cell (1,1) would have all of its attributes replaced with the "best" neighbor based on the phase of a neighbor cell matching the central cell.

% Auto generated parameter table will be inserted here

## Example Pipelines

+ (10) SmallIN100 Full Reconstruction
+ (04) SmallIN100 Presegmentation Processing
+ INL Export
+ 04_Steiner Compact

## License & Copyright

Please see the description file distributed with this **Plugin**

## DREAM3D-NX Help

If you need help, need to file a bug report or want to request a new feature, please head over to the [DREAM3DNX-Issues](https://github.com/BlueQuartzSoftware/DREAM3DNX-Issues) GItHub site where the community of DREAM3D-NX users can help answer your questions.
