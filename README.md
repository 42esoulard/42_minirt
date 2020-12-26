# 42_minirt

**My own little Raytracer!**

Generate images using the Raytracing protocol. Those computer generated images will each represent a scene, as seen from a specific angle and position, defined by simple geometric objects, and each with its own lighting system.

**WHAT'S IN A .rt FILE?**
  - R(esolution) xRenderSize yRenderSize
  - A(mbientLightning) ratio(0.0-1.0) R, G, B
  - C(amera) x, y, z(coordinatesOfViewPoint) 0,0,1(3dNormalizedVector[-1,1]forEach x,y,z axis) FOV(0-180)
  - l(ight) x, y, z(coordinatesOfLightPoint) Brightness[0.0-1.0] R, G, B
  - sp(ere) x, y, z(coordinatesOfCenter) Diameter R, G, B
  - pl(ane) x, y, z(coordinates) 0,0,1(3dNormalizedVector[-1,1]forEach x,y,z axis) R, G, B
  - sq(uare) x, y, z(coordinatesOfCenter) 0,0,1(3dNormalizedVector[-1,1]forEach x,y,z axis) sideSize R, G, B
  - cy(linder) x, y, z(coordinatesOfCenter) 0,0,1(3dNormalizedVector[-1,1]forEach x,y,z axis) diameter height R, G, B
  - tr(iangle) x, y, z(coordinatesOfPoint1) x, y, z(coordinatesOfPoint2) x, y, z(coordinatesOfPoint3) R, G, B

(There's a few sample .rt files in the RT_FILES folder.)

**KEYBINDINGS (on macOS) :**
  - any key = 				  	open snippet view !
  - press 'end' = 				switch btw elements;
  - c = 						      camera1;
  - v = 						      camera2;
  - 12 on top = 				  light_size++ / light_size--;
  - 12 on the right = 		object_size++ / object_size--;
  - adws = 						    translation control for obj && camera;
  - arrows = 					    rotation control for obj && camera;
  - jlik = 						    height and diameter augmentation/reduction;
  - +- = 						      camera or obj forward/backward;
  - m  =						      ambiant light
  - rgbs =						    red/blue/green/sepia filter
  - return = 					    load image;

Prerequisite: have minilibx installed.

./miniRT rt_file.rt [-save to save image as .bmp] 


Many thanks to Nicolas Boneel for his wonderful raytracing course : https://www.youtube.com/watch?v=1HYhrx9bzP8

Written in december 2019/january 2020.

[My image](https://github.com/42esoulard/42_minirt/blob/main/screenshots/Screen%20Shot%202019-11-27%20at%205.21.53%20PM.png)


Screen Shot 2019-11-27 at 5.37.16 PM.png

Screen Shot 2019-11-27 at 5.43.42 PM.png

Screen Shot 2019-11-27 at 5.56.11 PM.png

Screen Shot 2019-11-28 at 1.24.02 PM.png

Screen Shot 2019-11-28 at 12.34.11 PM.png

Screen Shot 2019-12-02 at 7.25.13 PM.png

Screen Shot 2019-12-03 at 2.37.35 PM.png

Screen Shot 2019-12-03 at 4.59.09 PM.png

Screen Shot 2019-12-06 at 3.13.49 PM.png

Screen Shot 2019-12-12 at 4.43.24 PM.png

Screen Shot 2019-12-12 at 5.29.10 PM.png
