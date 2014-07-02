//Copyright (c) TRC Simulators.  All rights reserved.
//Developed by Diogo Monteiro. 04/06/2014  
//------------------------------------------------------------------------------
//
//  
//  
//	Description:
//				Selects simulation file to load by simconnect
//------------------------------------------------------------------------------

bool LoadFlightFileSimConnect(int iTestNumber)
{
	string str = "FlightFile_TEST_" +  intTOstr(iTestNumber) + ".fxml";
	
	
	return SUCCEEDED(SimConnect_FlightLoad(hSimConnect,str.c_str()));
			
		
}