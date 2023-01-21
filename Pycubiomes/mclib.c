// check the biome at a block position

#include "../cubiomes/rng.h"
#include "../cubiomes/finders.h"
#include "../cubiomes/generator.h"
#include "../cubiomes/layers.h"
#include "../cubiomes/util.h"
#include "../cubiomes/noise.h"
#include "../cubiomes/quadbase.h"

#include "../cubiomes/biome_tree.c"
#include "../cubiomes/finders.c"
#include "../cubiomes/generator.c"
#include "../cubiomes/layers.c"
#include "../cubiomes/util.c"
#include "../cubiomes/noise.c"
#include "../cubiomes/quadbase.c"

#include <stdio.h>

int isvillage(long seed, int xpos, int ypos, int zpos)
{
    Generator g;
    setupGenerator(&g, MC_1_18, 0);

    // Apply the seed to the generator for the Overworld dimension.
    applySeed(&g, DIM_OVERWORLD, seed);

    // To get the biome at a single block position, we can use getBiomeAt().
    int scale = 1; // scale=1: block coordinates, scale=4: biome coordinates
    
    int biomeID = getBiomeAt(&g, scale, xpos, ypos, zpos);
    if (biomeID == plains || biomeID == savanna || biomeID == taiga || biomeID == desert || biomeID == snowy_taiga || biomeID == sunflower_plains)
    {
	    return 1;
    }
    else
    {
	    return 0;
    };
};

int isvillagecheck(long seed, int xpos, int zpos)
{
    Generator g;
    setupGenerator(&g, MC_1_18, 0);
    applySeed(&g, DIM_OVERWORLD, seed);
	
    if (isViableStructurePos(Village, &g, xpos, zpos, 0))
    {
            return 1;
    }
    else
    {
            return 0;
    };
};
    
