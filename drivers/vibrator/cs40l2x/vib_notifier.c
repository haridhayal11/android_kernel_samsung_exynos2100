/*
 * drivers/motor/vib_notifier.c
 *
 * Copyright (C) 2019 Samsung Electronics
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 */

#include <linux/device.h>
#include <linux/module.h>
#include <linux/notifier.h>
#include "vib_notifier.h"

static struct blocking_notifier_head vib_nb_head =
	BLOCKING_NOTIFIER_INIT(vib_nb_head);

int vib_notifier_register(struct notifier_block *n)
{
	int ret = 0;

	pr_info("%s\n", __func__);

	ret = blocking_notifier_chain_register(&vib_nb_head, n);
	if (ret < 0)
		pr_err("%s: failed(%d)\n", __func__, ret);

	return ret;
}
EXPORT_SYMBOL_GPL(vib_notifier_register);

int vib_notifier_unregister(struct notifier_block *nb)
{
	int ret = 0;

	pr_info("%s\n", __func__);

	ret = blocking_notifier_chain_unregister(&vib_nb_head, nb);
	if (ret < 0)
		pr_err("%s: failed(%d)\n", __func__, ret);

	return ret;
}
EXPORT_SYMBOL_GPL(vib_notifier_unregister);

int vib_notifier_notify(void)
{
	int ret = 0;

	ret = blocking_notifier_call_chain(&vib_nb_head,
			VIB_NOTIFIER_ON, NULL);

	switch (ret) {
	case NOTIFY_DONE:
	case NOTIFY_OK:
		pr_info("%s done(0x%x)\n", __func__, ret);
		break;
	default:
		pr_info("%s failed(0x%x)\n", __func__, ret);
		break;
	}

	return ret;
}

