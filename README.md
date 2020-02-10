# FdF

"Fils de fer" aka a wireframe.

A simple wireframe map viewer using included 42's _minilibX_ graphical library. Able to read ESRI ASCII grid format (e.g. [maps from NOAA](https://maps.ngdc.noaa.gov/viewers/wcs-client/)) when the file headers are removed.

Has mouse rotations, zoom, colour gradients with RGB pulse and two line algorithms implemented. Reads the file into a badly optimized doubly linked list which causes poor performance on bigger maps.

<a href="https://github.com/ehalmkro/FdF/blob/master/elem.fdf.png"><img src="https://github.com/ehalmkro/FdF/blob/master/elem.fdf.png" width="800" height="635"/></a>
