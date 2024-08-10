/** !
 * Pack example
 * 
 * @file main.c
 * 
 * @author Jacob Smith
 */

// pack module
#include <pack/pack.h>

typedef struct
{
    float x, y, z;
} vec3;

typedef struct
{
    vec3 loc, rot, sca;
} transform;

int transform_pack ( transform _transform, char *p_buffer );

// Entry point
int main ( int argc, const char *argv[] )
{

    // Initialized data
    char _buf[512] = { 0 };
    FILE *p_f = fopen("../output.bin", "w+");
    size_t i = 0;
    transform _transform = 
    {
        .loc = { .x = 4.f , .y =   3.f, .z = 5.f },
        .rot = { .x = 90.f, .y = -30.f, .z = -45.f },
        .sca = { .x = 1.f , .y =   1.f, .z = 1.f }
    };
    
    // Pack some data
    i += pack_pack(&_buf[i], "%3s"           , "Hello, World!", "Hi Mom!", "Hi Dad");
    i += pack_pack(&_buf[i], "%3i8"          , 'a', 'b', 'c');
    i += pack_pack(&_buf[i], "%i16 %i32 %i64", 31415, 2718281, 1618033988749);
    i += pack_pack(&_buf[i], "%2f32"         , 3.1415927f, 6.2831855f);
    i += pack_pack(&_buf[i], "%2f64"         , 3.141592653589793, 6.283185307179586);
    
    // Write the binary data to the output file
    fwrite(&_buf, 1, i, p_f);

    // Close the file
    fclose(p_f);

    // Reset
    i = 0, p_f = fopen("../transform.bin", "w+");

    // Pack a struct using a function
    i = transform_pack(_transform, &_buf);

    // Write the binary data to the output file
    fwrite(&_buf, 1, i, p_f);

    // Close the file
    fclose(p_f);

    // Success
    return EXIT_SUCCESS;
}

int vec3_pack ( vec3 _vec3, char *p_buffer )
{
    
    // Done
    return pack_pack(p_buffer, "%3f32", _vec3.x, _vec3.y, _vec3.z);
}

int transform_pack ( transform _transform, char *p_buffer )
{
    
    // Initialized data
    size_t i = 0;

    // Pack some data
    i += vec3_pack(_transform.loc, &p_buffer[i]);
    i += vec3_pack(_transform.rot, &p_buffer[i]);
    i += vec3_pack(_transform.sca, &p_buffer[i]);

    // Done
    return i;
}