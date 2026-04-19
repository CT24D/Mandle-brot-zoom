#include <raylib.h>
#include <cmath>

int main()
{
  Color blue = {0,20,255,255};
  InitWindow(800,800,"MANDLEBROT PLOT");
  Shader shader = LoadShader(0, "default.frag");
  int resLoc = GetShaderLocation(shader, "iResolution");
  int timeLoc = GetShaderLocation(shader, "iTime");
  float resolution[2] = { (float)GetScreenWidth(), (float)GetScreenHeight() };
  SetShaderValue(shader, resLoc, resolution, SHADER_UNIFORM_VEC2);
  while(!WindowShouldClose())
  {
    float time = (float)GetTime();
    float zoom = pow(time,time/10);

    SetShaderValue(shader, timeLoc, &time, SHADER_UNIFORM_FLOAT);
    BeginDrawing();
    ClearBackground(RAYWHITE);
    BeginShaderMode(shader);
    DrawRectangle(0,0,GetScreenWidth(),GetScreenHeight(),RAYWHITE);
    EndShaderMode();
    DrawText(TextFormat("x%.1E",zoom),20,20,35,RAYWHITE);
    EndDrawing();
    
  }
  UnloadShader(shader);
  CloseWindow();
  return 0;

}
