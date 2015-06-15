/*
 * Copyright (C) 2015 Atmel Corporation
 *			Wenyou.Yang <wenyou.yang@atmel.com>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <malloc.h>
#include <sdhci.h>
#include <asm/arch/clk.h>

int atmel_sdhci_init(void *regbase, int id)
{
	struct sdhci_host *host = NULL;
	unsigned int max_clk;

	host = (struct sdhci_host *)malloc(sizeof(struct sdhci_host));
	if (!host) {
		printf("atmel_sdhci_init: sdhci_host malloc fail\n");
		return 1;
	}

	host->name = "atmel_sdhci";
	host->ioaddr = (void *)regbase;
	host->quirks = 0;
	host->version = sdhci_readw(host, SDHCI_HOST_VERSION);

	host->host_caps = MMC_MODE_HC;

	max_clk = at91_get_generated_clk(id);

	add_sdhci(host, max_clk, 400000);

	return 0;
}
