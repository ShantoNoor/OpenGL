#version 330
out vec4 colour;
in vec3 position;
void main()
{
    float a = position.x * 2;
    float b = position.y * 2;
    float n = 0.0f;

    float aa = (a * a) - (b * b) + a;
    float bb = 2 * (a * b) + b;

    float cc = 0.0f;
    float dd = 0.0f;

    while(abs(aa * aa + bb * bb) < 4) {
        n += 0.05;
        if(n > 1.0f) break;

        cc = aa;
        dd = bb;
        aa = cc * cc - dd * dd + a;
        bb = 2 * cc * dd + b;
    }

    colour = vec4(n, n, n, n);
    
    
}