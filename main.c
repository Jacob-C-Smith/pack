/** !
 * Pack example
 * 
 * @file main.c
 * 
 * @author Jacob Smith
 */

// pack module
#include <pack/pack.h>

// Entry point
int main ( int argc, const char *argv[] )
{

    // Initialized data
    char _buffer[512] = { 0 };
    FILE *p_f = fopen("../output.bin", "w+");
    size_t written = 0;
    
    // Pack some data
    written = pack_pack(
        &_buffer,
        "%3i8 %i16 %i32 %i64 %2f32 %2f64",
        'a', 'b', 'c',
        31415,
        2718281,
        1618033988749,
        3.1415927f, 6.2831855f,
        3.141592653589793, 6.283185307179586
    );

    // Write the binary data to the output file
    fwrite(&_buffer, 1, written, p_f);

    // Close the file
    fclose(p_f);

    // Success
    return EXIT_SUCCESS;
}

