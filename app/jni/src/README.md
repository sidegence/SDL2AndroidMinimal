1) assets (your loadables)
2) Android.mk (local make file used by gradle to build/link your project)
3) CMakeLists.txt (local cmake file used to develop you project, under your favorite ide)
4) main.cpp (your entry point)

notes:
1) Remember to copy your assets into the java assets folder (../../app/src/main/assets)
2) If you are loading, say a json file, remember fopen wont work. Use SDL_RWFromFile.
