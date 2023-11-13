# miniRT (Raytracing) project

**made by** Jonah Köllner, Maximilian Reidenbach

<br>
<br>
<br>


<img width="801" alt="Screen Shot 2023-10-27 at 3 24 47 PM" src="https://github.com/JonahKoellner/miniRT/assets/33061141/209997d8-1ce5-4a3a-811e-6fcc8805f365">

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
#### Start the Raytracer :

```bash
user@pc:~/miniRT$ git clone https://github.com/JonahKoellner/miniRT.git
user@pc:~/miniRT$ cd miniRT
user@pc:~/miniRT$ make
...
user@pc:~/miniRT$ ./miniRT <path_to_.rt_file>
```

#### What are .rt files ?
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
sp p r c

````


L 2,10,10 0.6 100,100,100

C 0,0,2 0,0,-1 90

sp 0,-100.5,-1 100.0 147,212,237

sp 0,0.2,-1 0.5 240,150,48 lambertian

sp 1.5,0.15,-1 0.5 240,150,48 plastic

sp -1.5,0.15,-1 0.5 240,150,48 metal

sp -0.8,1,-1 0.5 81,214,174 plastic

sp 0.8,1,-1 0.5 81,214,174 lambertian

sp 0,2,-1 0.5 148,81,214 metal
````
