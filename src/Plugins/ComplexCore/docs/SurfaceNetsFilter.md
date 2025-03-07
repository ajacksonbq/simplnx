# SurfaceNets Filter

## Group (Subgroup)

Surface Meshing (Generation)

## Description

This filter uses the algorithm from {1} to produce a triangle surface mesh. The code is directly based on the sample code from the paper but has been modified to
work with the complex library classes. This filter uses a different algorithm that aims to produce a mush that keeps sharp edges
while still producing a mesh superior to marching cubes or QuickMesh.

From the abstract of the paper:

        We extend 3D SurfaceNets to generate surfaces of segmented 3D medical images composed
        of multiple materials represented as indexed labels. Our extension generates smooth, high-
        quality triangle meshes suitable for rendering and tetrahedralization, preserves topology and
        sharp boundaries between materials, guarantees a user-specified accuracy, and is fast enough
        that users can interactively explore the trade-off between accuracy and surface smoothness.

This filter will ensure that the smallest of the 2 **FaceLabel** values will always be in the first component (component[0]). This will allow assumptions made in
downstream filters to continue to work correctly.

---------------

![Example SurfaceNets Output](Images/SurfaceNets_Output.png)

SurfaceNets without the built-in smoothing applied

---------------

![Example SurfaceNets Output](Images/SurfaceNets_Smooth_Output.png)

SurfaceNets output **with** the built-in smoothing operation applied.

---------------

% Auto generated parameter table will be inserted here

## Example Pipelines

        Pipelines/ComplexCore/SurfaceNets_Demo.d3dpipeline

## Citations

{1}[SurfaceNets for Multi-Label Segmentations with Preservation of Sharp Boundaries](https://jcgt.org/published/0011/01/03/paper.pdf)

## License & Copyright

`Sarah F. Frisken, SurfaceNets for Multi-Label Segmentations with Preservation of Sharp
Boundaries, Journal of Computer Graphics Techniques (JCGT), vol. 11, no. 1, 34–54, 2022`
[http://jcgt.org/published/0011/01/03](http://jcgt.org/published/0011/01/03)

## DREAM.3D Mailing Lists

If you need more help with a **Filter**, please consider asking your question on
the [DREAM.3D Users Google group!](https://groups.google.com/forum/?hl=en#!forum/dream3d-users)
