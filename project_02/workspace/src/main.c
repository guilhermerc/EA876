#include "../lib/image_processing.h"

image img = open_image("../tests/aesthetics_vaporwave.jpg");
image tmp = img;

int main(int argc, char ** argv)
{

	save_image("aesthetics_vaporwave-out.jpg", &img);
	free_image(&img);
	return 0;
}
