// check the biome at a block position
#include "../cubiomes/finders.c"
#include "../cubiomes/generator.c"
#include "../cubiomes/layers.c"
#include "../cubiomes/util.c"
#include "../cubiomes/noise.c"
#include "../cubiomes/quadbase.c"
#include "../cubiomes/finders.h"
#include "../cubiomes/generator.h"
#include "../cubiomes/layers.h"
#include "../cubiomes/util.h"
#include "../cubiomes/noise.h"
#include "../cubiomes/quadbase.h"

#include <stdio.h>

int cBiomeAtPos(int biome, int64_t seed, int xpos, int ypos, int zpos)
{
    Generator g;
    setupGenerator(&g, MC_1_18, 0);
    Pos pos = {xpos,zpos}; // block position to be checked

    // Apply the seed to the generator for the Overworld dimension.
    applySeed(&g, DIM_OVERWORLD, seed);

    // To get the biome at a single block position, we can use getBiomeAt().
    int scale = 1; // scale=1: block coordinates, scale=4: biome coordinates
    int x = 0, y = 63, z = 0;
    int biomeID = getBiomeAt(&g, scale, x, y, z);
    if (biomeID == plains || biomeID == savanna || biomeID == taiga || biomeID == desert || biomeID == snowy_taiga || biome ID == sunflower_plains)
    {
	    return 1
	    }
    else
    {
	    return 0
	    }		    
    
