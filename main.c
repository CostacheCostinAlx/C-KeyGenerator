#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"





int main(void) {


    //(Rectangle){ float x, float y, float width, float height }
    //void GuiSetStyle(int control, int property, int value);
    //void GuiSetFont(Font font);
    //void DrawText(const char *text, int posX, int posY, int fontSize, Color color);

    //float GuiSlider(Rectangle bounds, const char *textLeft, const char *textRight, float *value, float minValue, float maxValue);
    
    //bool GuiCheckBox(Rectangle bounds, const char *text, bool *checked);
    //bool GuiButton(Rectangle bounds, const char *text);


    const int screenWidth = 800;
    const int screenHeight = 450;
    
    float KeyLenghtValue = 0.0f;
    float GroupsValue = 0.0f;

    bool useNumbers = 0;
    InitWindow(screenWidth, screenHeight, "C GUI - Key Generator");

    Font myCleanFont = LoadFont("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf");
    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);
    GuiSetFont(myCleanFont);

    SetTargetFPS(60); 

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE); 
            //DrawText("Gui Created", 150, 200, 20, DARKGRAY);
            GuiSlider((Rectangle){250,50,200,20} ,"Key Group Lenght", TextFormat("%i", (int)KeyLenghtValue), &KeyLenghtValue, 1.0f, 10.0F);
            GuiSlider((Rectangle){250,100,200,20} ,"Number of Groups", TextFormat("%i", (int)GroupsValue), &GroupsValue, 1.0f, 5.0F);
           
            GuiButton((Rectangle){ 350, 200, 300, 50 }, "Generate Key");
            GuiCheckBox((Rectangle){ 250, 150, 24, 24 }, "Use Alphanumeric", &useNumbers);


        EndDrawing();
    }

    UnloadFont(myCleanFont); // Frees the font memory
    CloseWindow();
    return 0;
}