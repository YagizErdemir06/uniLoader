/* SPDX-License-Identifier: GPL-2.0 */
/*
 *
 *
 * Copyright (c) "YagizErdemir06 <erdemiryagiz@proton.me>"
 */

#include <board.h>
#include <drivers/framework.h>
#include <lib/simplefb.h>

static struct video_info ruby_fb = {
	.format = FB_FORMAT_ARGB8888,
	.width = 1080,
	.height = 2400,
	.stride = 4,
	.address = (void *)0x7ba10000
};

int ruby_drv(void)
{
	REGISTER_DRIVER("simplefb", simplefb_probe, &ruby_fb);
	return 0;
}

struct board_data board_ops = {
	.name = "xiaomi-ruby",
	.ops = {
		.drivers_init = ruby_drv,
	},
	.quirks = 0
};
