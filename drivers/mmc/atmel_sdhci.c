/*
 * Copyright (C) 2015 Atmel Corporation
 *			Wenyou.Yang <wenyou.yang@atmel.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <malloc.h>
#include <sdhci.h>

int atmel_sdhci_init(void *regbase)
{
	struct sdhci_host *host = NULL;

	host = (struct sdhci_host *)malloc(sizeof(struct sdhci_host));
	if (!host) {
		printf("atmel_sdhci_init: sdhci_host malloc fail\n");
		return 1;
	}

	host->name = "atmel_sdhci";
	host->ioaddr = (void *)regbase;
	host->quirks = 0;
	host->version = sdhci_readw(host, SDHCI_HOST_VERSION);
	host->voltages = MMC_VDD_32_33 | MMC_VDD_33_34 | MMC_VDD_165_195;

	host->host_caps = MMC_MODE_HC;

	add_sdhci(host, 0, 0);

	return 0;
}
