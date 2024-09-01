#include "resource_manager.h"

#include <stdio.h>
#include <stdlib.h>

int main() {

	char* text = parse_file("resources/text.txt");
	if (text == NULL) return 0;
	printf("%s\n\n", text);
	free(text);

	struct argb_image* image = load_argb_image_from_png("resources/image.png");
	if (image == NULL) return 0;
	printf("image width: %d\nimage height: %d\n", image->width, image->height);
	printf("color values:");
	for (int i = 0; i < image->width * image->height; i++) printf(" %x", image->pixels[i].color_value);
	printf("\n");
	free(image);

	return 0;

}