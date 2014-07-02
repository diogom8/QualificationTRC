//Copyright (c) TRC Simulators.  All rights reserved.
//Developed by Diogo Monteiro. 01/07/2014  
//------------------------------------------------------------------------------
//
//  
//  
//	Description:
//				Selects START function for selected test
//------------------------------------------------------------------------------
#include "TestFiles/TEST_1.h"



bool StartTestSimConnect(int iTestNumber)
{
	if(SUCCEEDED(SimConnect_Open(&hSimConnect, "Connect", NULL, 0, 0, 0)))
	{
		switch(iTestNumber)
		{
			case 1:
				START_TEST_1();
				break;
			default:
				break;
		}		
	
		return true;
	}
	else
		return false;

	SimConnect_Close(hSimConnect);// Close Server Connection

}