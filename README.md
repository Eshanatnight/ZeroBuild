# ZeroBuild

Header only library for writing build recipes in C.

## Main idea

The idea is that you should not need anything but a C compiler to build a C project. No make, no cmake, no shell, no cmd, no PowerShell etc. Only C compiler. So with the C compiler you bootstrap your build system and then you use the build system to build everything else.

Try it out right here:

```console
$ gcc ./ZeroBuild.c -o ZeroBuild
$ ./ZeroBuild
```

Explore [ZeroBuild.c](./src/ZeroBuild.c) file to learn more.

## This is an Experimental Project

I'm not sure if this is even a good idea myself. This is why I'm implementing it. This is a research project. I'm not making any claims about suitability of this approach to any project.

It works quite well for me.

## It's likely Not Suitable for Your Project

If you are using [cmake](https://cmake.org/) with tons of modules to manage and find tons of dependencies you probably don't want to use this tool. ZeroBuild is more like writting shell scripts but in C.

## Advantages of ZeroBuild

- Extremely portable builds across variety of systems including (but not limited to) Linux, MacOS, Windows, FreeBSD, etc. This is achieved by reducing the amount of dependencies to just a C compiler, which exists pretty much for any platform these days.
- You end up using the same language for developing and building your project. Which may enable some interesting code reusage strategies. The build system can use the code of the project itself directly and the project can use the code of the build system also directly.
- You get to use C more.
- ...

## Disadvantages of ZeroBuild

- You need to be comfortable with C and implementing things yourself. As mentioned above this is like writing shell scripts but in C.
- It probably does not make any sense outside of C/C++ projects.
- You get to use C more.
- ...


## How to use the library in your own project

Keep in mind that [ZeroBuild.h](./src/ZeroBuild.h) is an [stb-style](https://github.com/nothings/stb/blob/master/docs/stb_howto.txt) header-only library. That means that just including it does not include the implementations of the functions. You have to `#define ZeroBuild_IMPLEMENTATION` before the include. See the [ZeroBuild.c](./src/ZeroBuild.c) for an example.

1. Copy [ZeroBuild.h](./src/ZeroBuild.h) to your project
2. Create `ZeroBuild.c` in your project with the build recipe. See our [ZeroBuild.c](./src/ZeroBuild.c) for an example.
3. Bootstrap the `ZeroBuild` executable:
   - `$ cc ZeroBuild.c -o ZeroBuild` on POSIX systems
   - `$ cl.exe ZeroBuild.c` on Windows with MSVC
4. Run the build: `$ ./ZeroBuild`

If you enable the [Go Rebuild Yourrself] Technology the `ZeroBuild` executable will try to rebootstrap itself every time you modify its source code.

## Dependencies
   1.[minirent](https://github.com/tsoding/minirent)