// check the biome at a block position
#include "../cubiomes/finders.c"
#include "../cubiomes/generator.c"
#include "../cubiomes/layers.c"
#include "../cubiomes/util.c"
#include "../cubiomes/noise.c"
#include "../cubiomes/quadbase.c"

#include <stdio.h>

int cBiomeAtPos(int biome, int64_t seed, int xpos, int zpos, int version)
{
    LayerStack g;
    setupGenerator(&g, version);
    Pos pos = {xpos,zpos}; // block position to be checked


        // Go through the layers in the layer stack and initialize the seed
        // dependent aspects of the generator.
    applySeed(&g, seed);

        // To get the biome at single block position we can use getBiomeAtPos().
    int biomeID = getBiomeAtPos(&g, pos);
    if (biomeID == biome)
        return 1;
	else return 0;

}
int cBiomesInArea(int* biomes, int64_t seed, int x1, int z1, int x2, int z2, int version)
{
    LayerStack g;
    BiomeFilter filter;

    setupGenerator(&g, version);

    // Define the required biomes.
    int* wanted=biomes;

    filter = setupBiomeFilter(wanted, sizeof(wanted) / sizeof(int));


    int x = x1, z = z1, w=x2-x1, h=z2-z1;
    int entry = L_VORONOI_ZOOM_1;
    int *area = allocCache(&g.layers[entry], w, h);

    if (checkForBiomes(&g, entry, area, seed, x, z, w, h, filter, 1) > 0){
		free(area);
		return 1;
	}
    free(area);
    return 0;
}

Pos cGetSpawn(int64_t seed, int version){
	LayerStack g;
    setupGenerator(&g, version);
    applySeed(&g, seed);
	Pos pos;
	pos=getSpawn(version, &g, NULL, seed);
	return pos;
}

int cSaveMap(int64_t seed, int areaX, int areaZ, int areaWidth, int areaHeight, int scale, int version, char* filename)
{
    unsigned char biomeColours[256][3];

    // Initialize a colour map for biomes.
    initBiomeColours(biomeColours);

    // Initialize a stack of biome layers.
    LayerStack g;
    setupGenerator(&g, version);
    // Extract the desired layer.
    Layer *layer = &g.layers[L_SHORE_16];

    unsigned int imgWidth = areaWidth*scale, imgHeight = areaHeight*scale;

    // Allocate a sufficient buffer for the biomes and for the image pixels.
    int *biomeIds = allocCache(layer, areaWidth, areaHeight);
    unsigned char *rgb = (unsigned char *) malloc(3*imgWidth*imgHeight);

    // Apply the seed only for the required layers and generate the area.
    setLayerSeed(layer, seed);
    genArea(layer, biomeIds, areaX, areaZ, areaWidth, areaHeight);

    // Map the biomes to a color buffer and save to an image.
    biomesToImage(rgb, biomeColours, biomeIds, areaWidth, areaHeight, scale, 2);
    savePPM(strcat(filename, ".ppm"), rgb, imgWidth, imgHeight);

    // Clean up.
    free(biomeIds);
    free(rgb);

    return 0;
}
