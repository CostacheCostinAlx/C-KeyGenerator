#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include <stdlib.h> // For rand(), srand()
#include <time.h>   // For time()




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
    
    float GroupLenght = 0.0f;
    float GroupNumber = 0.0f;

    char generatedKey[256]="NULL";

    bool useNumbers = 0;
    
    srand((unsigned int)time(NULL));
 
    InitWindow(screenWidth, screenHeight, "Key Generator");
    
   // Load the font at 48px or 64px to make it ultra-crisp
    Font myCleanFont = LoadFontEx("/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf", 64, 0, 0);
    GenTextureMipmaps(&myCleanFont.texture); // Optional: makes it look even better when scaled
    SetTextureFilter(myCleanFont.texture, TEXTURE_FILTER_BILINEAR);


    GuiSetStyle(DEFAULT, TEXT_SIZE, 24);
    GuiSetFont(myCleanFont);

    SetTargetFPS(60); 

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(RAYWHITE); 
            //DrawText("Gui Created", 150, 200, 20, DARKGRAY);
            GuiSlider((Rectangle){250,50,200,20} ,"Group Lenght", TextFormat("%i", (int)GroupLenght), &GroupLenght, 1.0f, 10.0F);
            GuiSlider((Rectangle){250,100,200,20} ,"Number of Groups", TextFormat("%i", (int)GroupNumber), &GroupNumber, 1.0f, 5.0F);
    
            GuiCheckBox((Rectangle){ 250, 150, 24, 24 }, "Use Alphanumeric", &useNumbers);
            if(GuiButton((Rectangle){ 350, 200, 300, 50 }, "Generate Key")){
                if(useNumbers == true)
                {
                    const char Key[256] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
                    char c;
                    
                    
                    int size = 63;
                    int counter =0;

                    
                    for(int i=0; i<GroupNumber; i++)
                    {
                        for(int j=0; j<GroupLenght; j++)
                        {
                            int random_char_index = rand() % 62;
                            c=Key[random_char_index];
                            generatedKey[counter++]=c;
                        }
                        if (i < GroupNumber - 1) 
                        generatedKey[counter++] = '-';
                    }
                    generatedKey[counter]='\0';
                }
                else{
                    const char Key[256] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                    
                    char c;
                    
                    int size = 53;
                    int counter =0;

                    for(int i=0; i<GroupNumber; i++)
                    {
                        for(int j=0; j<GroupLenght; j++)
                        {
                            int random_char_index = rand() % 53;
                            c=Key[random_char_index];
                            generatedKey[counter++]=c;
                        }
                        if (i < GroupNumber - 1) 
                        generatedKey[counter++] = '-';
                    }
                    generatedKey[counter]='\0';   
                }  
            }
            DrawText(generatedKey, 100, 300, 30, BLACK);
        EndDrawing();
    }

    UnloadFont(myCleanFont); // Frees the font memory
    CloseWindow();
    return 0;
}