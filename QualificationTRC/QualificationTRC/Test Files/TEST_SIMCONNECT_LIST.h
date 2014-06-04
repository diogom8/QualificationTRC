//Copyright (c) TRC Simulators.  All rights reserved.
//Developed by Diogo Monteiro. 04/06/2014  
//------------------------------------------------------------------------------
//
//  
//  
//	Description:
//				Selects simulation file to load by simconnect
//------------------------------------------------------------------------------

int LoadFlightFileSimConnect(int iTestNumber)
{
	
	if (SUCCEEDED(SimConnect_Open(&hSimConnect, "Open and Close", NULL, 0, 0, 0)))
	{
		switch (iTestNumber)
		{
			case 1: return SUCCEEDED(SimConnect_FlightLoad(hSimConnect,"FlightFile_TEST_1.fxml"));
				break;
			default: 
				break;
		}	
	}
	else MessageBox::Show("Failed to connect to Prepar3D! Check connection.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	




}