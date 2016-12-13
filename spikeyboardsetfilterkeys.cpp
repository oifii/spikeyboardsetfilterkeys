/*
 * Copyright (c) 2010-2016 Stephane Poirier
 *
 * stephane.poirier@oifii.org
 *
 * Stephane Poirier
 * 3532 rue Ste-Famille, #3
 * Montreal, QC, H2X 2L1
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/////////////////////////////////////////////////////////////////////////////////////
// spikeyboardsetfilterkeys.cpp : Defines the entry point for the console application.
//
//https://msdn.microsoft.com/en-us/library/windows/desktop/dd318079%28v=vs.85%29.aspx
/////////////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	FILTERKEYS keys = { sizeof(FILTERKEYS) };
	keys.cbSize = sizeof(FILTERKEYS);

	/* //spi's default
	keys.dwFlags = 126;
	keys.iBounceMSec = 0;
	keys.iDelayMSec = 1000;
	keys.iRepeatMSec = 500;
	keys.iWaitMSec = 1000;
	*/
	
	//repeat off ?
	keys.dwFlags = 126;
	keys.dwFlags = keys.dwFlags | FKF_FILTERKEYSON; //add flag
	keys.dwFlags = keys.dwFlags & ~FKF_CLICKON; //remove flag
	keys.dwFlags = keys.dwFlags & ~FKF_HOTKEYSOUND; //remove flag
	keys.iBounceMSec = 20;
	keys.iDelayMSec = 0;
	keys.iRepeatMSec = 0;
	keys.iWaitMSec = 0;
	

	/*
	//repeat ultra slow ?
	keys.dwFlags = 126 | FKF_FILTERKEYSON;
	keys.iBounceMSec = 0;
	keys.iDelayMSec = 1000;
	keys.iRepeatMSec = 20000;
	keys.iWaitMSec = 1000;
	*/

    if (!SystemParametersInfo (SPI_SETFILTERKEYS, 0, (LPVOID) &keys, 0))
    {
        printf("System call failed. Unable to set FILTERKEYS.\n");
    }
	else
	{
        printf("System call success. new FILTERKEYS dwFlags =%ld\n", keys.dwFlags);
        printf("System call success. new FILTERKEYS iBounceMSec =%ld\n", keys.iBounceMSec);
        printf("System call success. new FILTERKEYS iDelayMSec =%ld\n", keys.iDelayMSec);
        printf("System call success. new FILTERKEYS iRepeatMSec =%ld\n", keys.iRepeatMSec);
        printf("System call success. new FILTERKEYS iWaitMSec =%ld\n", keys.iWaitMSec);

		printf("\nFILTERKEYS dwFlags is:\n\n");

		printf("FKF_AVAILABLE is ");
		if((FKF_AVAILABLE & keys.dwFlags) == FKF_AVAILABLE)
		{
			printf("enabled\n");
		}
		else
		{
			printf("disabled\n");
		}

		printf("FKF_CLICKON is ");
		if((FKF_CLICKON & keys.dwFlags) == FKF_CLICKON)
		{
			printf("enabled\n");
		}
		else
		{
			printf("disabled\n");
		}

		printf("FKF_CONFIRMHOTKEY is ");
		if((FKF_CONFIRMHOTKEY & keys.dwFlags) == FKF_CONFIRMHOTKEY)
		{
			printf("enabled\n");
		}
		else
		{
			printf("disabled\n");
		}

		printf("FKF_FILTERKEYSON is ");
		if((FKF_FILTERKEYSON & keys.dwFlags) == FKF_FILTERKEYSON)
		{
			printf("enabled\n");
		}
		else
		{
			printf("disabled\n");
		}

		printf("FKF_HOTKEYACTIVE is ");
		if((FKF_HOTKEYACTIVE & keys.dwFlags) == FKF_HOTKEYACTIVE)
		{
			printf("enabled\n");
		}
		else
		{
			printf("disabled\n");
		}

		printf("FKF_HOTKEYSOUND is ");
		if((FKF_HOTKEYSOUND & keys.dwFlags) == FKF_HOTKEYSOUND)
		{
			printf("enabled\n");
		}
		else
		{
			printf("disabled\n");
		}

		printf("FKF_INDICATOR is ");
		if((FKF_INDICATOR & keys.dwFlags) == FKF_INDICATOR)
		{
			printf("enabled\n");
		}
		else
		{
			printf("disabled\n");
		}

	}
	return 0;
}

