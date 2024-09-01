#include "platform.h"
#include <stdio.h>

void Entry() {

	int width = 500;
	int height = 300;

	struct window_state* window = create_window(100, 100, width, height, "NAME");

	unsigned int* pixels = malloc(sizeof(unsigned int) * window->window_height * window->window_width);

	while (get_key_state(KEY_ESCAPE) == 0 && is_window_active(window)) {

		if (width != window->window_width || height != window->window_height) {
			height = window->window_height;
			width = window->window_width;
			free(pixels);
			pixels = malloc(sizeof(unsigned int) * height * width);
			for (int i = 0; i < height * width; i++) pixels[i] = 0x12345;
		}

		struct point2d_int p = get_mouse_cursor_position(window);

		if (p.x >= 0 && p.x < width && p.y >= 0 && p.y < height && get_key_state(KEY_MOUSE_LEFT) & 0b1) pixels[p.x + width * p.y] = 0xffff0000;

		draw_to_window(window, pixels, width, height);

		sleep_for_ms(10);
	}

	close_window(window);

	return;

}