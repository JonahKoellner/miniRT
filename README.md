# miniRT (Raytracing) project

**made by** Jonah Köllner, Maximilian Reidenbach

<br>
<br>
<br>


<img width="801" alt="Screen Shot 2023-10-27 at 3 24 47 PM" src="https://github.com/JonahKoellner/miniRT/assets/33061141/209997d8-1ce5-4a3a-811e-6fcc8805f365">

#Overview
#### - [Prerequisites](#prerequisites)
#### - [How to use the Raytracer](#how-to-use-the-raytracer)
- [Start the Raytracer](##start-the-raytracer)
- [What are .rt files ?](##what-are-rt-files)
#### - [Testing](#test-files)

<br>
<br>
<br>

## Prerequisites

🍺 brew / homebrew :
: https://brew.sh/
or
	```bash
	user@pc:~$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
	```

cmake :
: https://cmake.org/
or
	```bash
	user@pc:~$ brew install cmake
	```
<br>

## How to use the Raytracer
### Start the Raytracer :

```bash
user@pc:~/miniRT$ git clone https://github.com/JonahKoellner/miniRT.git
user@pc:~/miniRT$ cd miniRT
user@pc:~/miniRT$ make
...
user@pc:~/miniRT$ ./miniRT <path_to_.rt_file>
```

### What are .rt files ?
<font size="1">

The file format is **not** and official format. It is a custom made one by us / the task given.
<font size="3">

For a raytacer to work we need to define, what the **scene** should look like.
<font size="3">

* Format:
	* **doubles** are seperated by only "."
	* **(x,y,z)** can have no spaces, but can have doubles
	* **seperation** of values / items can only contain spaces
<br>

* Objects:
	* **A** = Ambient Light
	* **L** = Light source;
	* **C** = Camera;
	* **sp** = Sphere;
	* **pl** = Plane;
	* **cy** = Cylinder;
	* **co** = Cone;
<br>

* Values:
	* **p** = position;
	* **i** = intensity;
	* **d** = direction;
	* **m** = material;
	* **c** = color;
	* **r** = radius;
	* **fov** = field of view (in degree)
	* **cm** = colormap
	* **bm** = bumpmap
<br>

* Restraints:
	* **Must have** at least a **Camera** and **Ambient Light**
	* **Values** are restrained to there sensible area
		* color(x,y,z): 0-255,0-255,0-255
		* Intensity: 0-1
		* position/direction(x,y,z): -inf-inf,-inf-inf,-inf-inf
		* radius: 0-inf;
		* material type: lambertian, plastic, metal


````
Strcture
<obj> <values...>
A i p
L d i p
C d p fov

sp p r c m //normal sphere with color
sp p r cm bm m

pl
````

### Test Files
	In case you dont want to create your own files and just test the Raytracer,
	we have provided you with some test examples.

	Our suggestions are:
	- show_case_rt/book.rt (little longer)
	- rt_files/Hall.rt (a lot longer)
	- show_case_rt/ball_pyramind (fast)

	or every other file
	- rt_files/*.rt
	- show_case_rt/*.rt

	! Keep in mind some may take longer than others, due to the complexity of the scene and in rt_files are some that dont work (on purpose to show missconfigurations) !





