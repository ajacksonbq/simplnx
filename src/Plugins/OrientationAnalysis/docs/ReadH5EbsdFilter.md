# ReadH5Ebsd

## Group (Subgroup)

IO (Input)

## Description

This **Filter** reads from the .h5ebsd file that was generated with the *Import Orientation File(s) to H5EBSD* **Filter**.

![Read H5Ebsd File User Interface](Images/ReadH5Ebsd_UI.png)

+ The user can use the checkboxes under the *Data Arrays to Read* section to select which specific data arrays they are interested in importing.
+ The user can select a subset of the slices if they do not wish to import the entire volume.
+ The type of transformations that are recommended based on the manufacturer of the data are also listed with a checkbox that allows the user to toggle the recommended transformations on and off.
+ The user should select the Euler angle representation. (This is **only** available if the **Use Recommended Transformations** is turned **on**.)

### Notes About Transformations

The **user** is solely responsible for knowing any sample reference frame transformations, crystal reference frame transformations and how the Euler angles are represented in the file. DREAM.3D provides historically correct transformations from a few of the EBSD manufacturers under the assumption that the EBSD instrument has been setup according to their guidelines. The **user** is strongly encouraged to discuss these topics with the person(s) who were responsible for collecting the data. For example the  IPF images presented below were generated from an H5Ebsd file that was generated using a CTF file. The difference is that the **Incorrect** image did not correctly select the **Angle Representation** combo box on the filter's user interface. The Euler angles were actually in degrees but were treated as if the values were in radians. The correct image is on the right.

If the user does not want the **Read H5Ebsd** filter to perform any transformations then the checkbox can be unchecked and the user can manually perform any desired transformations by inserting the appropriate filters into the pipeline. The suggested filters are:

+ {ref}`Rotate Euler Reference Frame <OrientationAnalysis/RotateEulerRefFrameFilter:Description>`
+ {ref}`Rotate Sample Reference Frame <ComplexCore/RotateSampleRefFrameFilter:Description>`
+ {ref}`Convert Angles to Degrees or Radians <ComplexCore/ChangeAngleRepresentation:Description>`

An excellant reference for this is the following PDF file:
[http://pajarito.materials.cmu.edu/rollett/27750/L17-EBSD-analysis-31Mar16.pdf](http://pajarito.materials.cmu.edu/rollett/27750/L17-EBSD-analysis-31Mar16.pdf)

| Incorrect | Correct |
|---------|---------|
|![Read H5Ebsd File User Interface](Images/ReadH5Ebsd_Wrong.png) | ![Read H5Ebsd File User Interface](Images/ReadH5Ebsd_Right.png) |
| Euler angles were treated as Radians | Euler angles were converted from Degrees to Radians |
|"Interstitial Free (IF) Steel courtesy of [1]"| |

### The Axis Alignment Issue for Hexagonal Symmetry [2]

+ The issue with hexagonal materials is the alignment of the Cartesian coordinate system used for calculations with the crystal coordinate system (the Bravais lattice).
+ In one convention (e.g. EDAX.TSL), the x-axis, i.e. [1,0,0], is aligned with the crystal a1 axis, i.e. the [2,-1,-1,0] direction. In this case, the y-axis is aligned with the [0,1,-1,0] direction. (Green Axis in Figure 1)
+ In the other convention, (e.g. Oxford Instr, Univ. Metz software), the x-axis, i.e. [1,0,0], is aligned with the crystal [1,0,-1,0] direction. In this case, the y-axis is aligned with the [-1,2,-1,0] direction. (Red Axis in Figure 1)
+ This is important because texture analysis can lead to an ambiguity as to the alignment of [2,-1,-1,0] versus [1,0,-1,0], with apparent **30** shifts in the data.
+ Caution: it appears that the axis alignment is a choice that must be made when installing TSL software so determination of which convention is in use must be made on a case-by-case basis. It is fixed to the y-convention in the HKL software.
+ The main clue that something is wrong in a conversion is that either the 2110 & 1010 pole figures are transposed, or that a peak in the inverse pole figure that should be present at 2110 has shifted over to 1010.
+ DREAM.3D uses the TSL/EDAX convention.
+ **The result of this is that the filter will *AUTOMATICALLY* add 30   to phi2 when reading Oxford Instr (.ctf) files or .h5ebsd files denoted with the HKL manufacturer ID. There is no way to turn off this behavior.**

![Figure 1 showing TSL \& Oxford Instr. conventions.](Images/Hexagonal_Axis_Alignment.png)

% Auto generated parameter table will be inserted here

## Example Pipelines

+ 02_Adaptive Alignment - Misorientation - Zero Shifts
+ (10) SmallIN100 Full Reconstruction
+ 03_Adaptive Alignment - Mutual Information - SEM Images
+ 04_Steiner Compact
+ (02) SmallIN100 Initial Visualization
+ (03) SmallIN100 Alignment

## License & Copyright

Please see the description file distributed with this **Plugin**

## References

[1] N. Allain-Bonasso, F. Wagner, S. Berbenni, D.P. Field, A study of the heterogeneity of plastic deformation in IF steel by EBSD, Materials Science and Engineering: A, Volume 548, 30 June 2012, Pages 56-63, ISSN 0921-5093, <http://dx.doi.org/10.1016/j.msea.2012.03.068>.
(<http://www.sciencedirect.com/science/article/pii/S0921509312004388>)

[2] Rollett, A.D. Lecture Slides located at [http://pajarito.materials.cmu.edu/rollett/27750/L17-EBSD-analysis-31Mar16.pdf](http://pajarito.materials.cmu.edu/rollett/27750/L17-EBSD-analysis-31Mar16.pdf)

## DREAM3D-NX Help

If you need help, need to file a bug report or want to request a new feature, please head over to the [DREAM3DNX-Issues](https://github.com/BlueQuartzSoftware/DREAM3DNX-Issues) GItHub site where the community of DREAM3D-NX users can help answer your questions.
