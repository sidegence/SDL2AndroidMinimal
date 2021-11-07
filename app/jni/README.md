1) Create directory: SDL (copy all SDL2 full sources https://www.libsdl.org/download-2.0.php )
2) Create directory: SDL_image (copy all SDL2_image full sources https://www.libsdl.org/projects/SDL_image/ )
3) src (the c++ game)
4) Android.mk (top level make file used by gradle to build/link SDL, SDL_image and your project)
5) Application.mk (top level options used by gradle to call the compiler, including which STL to use)

notes:
1) make is not as modern as cmake but SDL_image doesnt contain a cmake file yet.
