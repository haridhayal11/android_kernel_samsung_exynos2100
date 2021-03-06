/* include/uapi/sound/isounddev_abox.h
 *
 * ALSA SoC Audio Layer - Samsung Abox WDMA driver
 *
 * Copyright (c) 2018 Samsung Electronics Co. Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __SND_DEV_ABOX_H
#define __SND_DEV_ABOX_H

#include <linux/types.h>
#include <linux/magic.h>

struct snd_pcm_mmap_fd {
	int dir;
	int fd;
	int size;
	int actual_size;
};

#define SNDRV_PCM_IOCTL_MMAP_DATA_FD    _IOWR('U', 0xd2, struct snd_pcm_mmap_fd)

#endif

