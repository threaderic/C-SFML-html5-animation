Sample code from https://github.com/lamberta/html5-animation ported to C++ and SFML.

State: In-Progress.

SFML Version: 2.4.2

Folder Structure:
- chapter#-example#-examplename
	* CMakeList.txt
	* /deps: Any libraries required by the example (except for SFML)
	* /src: Source Code.
	* /res: stores any assets required by the example (e.g fonts or images).
	* /build: Precompiled Windows Executable x86 File.

- shared-deps
	* /SFML-x.x.x: Current SFML Version being used by all the examples

Note 1: If you want to build any example, just run CMake on their own root folder.

Note 2: I have built all the examples on Windows with CMake; eventually will try to add Linux and OSx support, but I'll be more than happy to recieve any help with this in the meantime :)
--> see below : a newbie try to help for linux users :)

Note 3: Example ch04-12-video-frames uses Visual Studio temporarily.

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
for linux user
SFML Version: 2.4.2

State: In-Progress.

build total folder with scons
1. install scons
2. open terminal in the root folder of this project (same as README.md)
3. tape "scons" <enter>
4. go to the build-scons folder/<folder of desired example>/bin/
5. tape "./<name of the program>
6. enjoy ;)
