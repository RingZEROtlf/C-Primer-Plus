// rand0.c -- generate random numbers
// using ANSI C portable algorithm
static unsigned long int next = 1;  // seed
unsigned int rand0(void)
{
    // magic formula which generates pseudo random numbers
    next = next * 1103515245 + 12345;
    return (unsigned int) (next / 65536) % 32768;
}