#include <stdio.h>

// the blocks are important here to the degree that myvar could create a naming conflict
#define swap(t,x,y) {t myvar = x; x = y; y = myvar;}

