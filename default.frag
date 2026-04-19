#version 400 core
#extension GL_ARB_gpu_shader_fp64 : enable
out vec4 finalColor;

uniform vec2 iResolution;
uniform float iTime;
void main()
{
    dvec2 uv = gl_FragCoord.xy/iResolution *2.0 -1.0;
    float i;
    double zoom = pow(iTime, iTime/10);
    uv /= zoom;
    dvec2 z = dvec2(0.0);
    dvec2 c = uv-dvec2(0.743643887037151,0.131825904205330);
    for(i = 0.0; i < 2000; i++)
    {
        
        z = dvec2(z.x*z.x-z.y*z.y, 2*z.x*z.y)+c;
        if(dot(z,z) > 4.0)break;
    }
    float si = i+1-log(log(float(z.x*z.x+z.y*z.y)));
    dvec3 col = dvec3(sin(si/200),sin(si/50),sin(si/100));
    finalColor = vec4(col,1.0);    
}