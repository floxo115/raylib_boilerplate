#include <iostream>
#include <raylib.h>

int main() {
    InitWindow(800, 600, "Raylib Window");
    SetTargetFPS(60);

    InitAudioDevice();
    Music music = LoadMusicStream("../media/music.mp3");
    PlayMusicStream(music);
    int textPos = 0;
    Color colorPallette[] {RED, LIGHTGRAY, BLUE, GREEN, YELLOW, MAGENTA};
    while (!WindowShouldClose()) {
        UpdateMusicStream(music);

        textPos = textPos % 800;
        BeginDrawing();
        ClearBackground(DARKPURPLE);
        DrawFPS(30, 30);


        DrawText("Hello, Raylib!", textPos++, 300, 70, colorPallette[textPos % std::size(colorPallette)]);
        DrawText("Hello, Raylib!", textPos++ - 800, 300, 70, colorPallette[textPos % std::size(colorPallette)]);
        EndDrawing();
    }
}
