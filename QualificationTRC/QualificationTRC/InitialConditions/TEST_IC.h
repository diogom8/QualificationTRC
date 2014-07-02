//Copyright (c) TRC Simulators.  All rights reserved.
//Developed by Diogo Monteiro. 26/05/2014  
//------------------------------------------------------------------------------
//
//  SimConnect Data Request to Check Initial Conditions
//  
//	
//
//
//
//------------------------------------------------------------------------------

struct Data_CHECK_IC
{
	double ThSetting;
    double MixSetting;
	double TrimSetting;
	double FlapIndicator;
	double PitchController;
	double RollController;
	double RudderController;
		
};


static enum DATA_DEFINE_ID_CHECK_IC {
    DataDefinition_CHECK_IC,
};

static enum DATA_REQUEST_ID_CHECK_IC {
    DataRequest_CHECK_IC,
};


void CALLBACK GetData_CHECK_IC(SIMCONNECT_RECV* pData, DWORD cbData, void *pContext)
{
    HRESULT hr;
  
	


    switch(pData->dwID)
    {
        
		case SIMCONNECT_RECV_ID_SIMOBJECT_DATA_BYTYPE:
        {
            SIMCONNECT_RECV_SIMOBJECT_DATA_BYTYPE *pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA_BYTYPE*)pData;
            
            switch(pObjData->dwRequestID)
            {
                case DataRequest_CHECK_IC:
                {
					
                    DWORD ObjectID = pObjData->dwObjectID;
                    Data_CHECK_IC *pS = (Data_CHECK_IC*)&pObjData->dwData;
                   
					
					
					if( (pS->ThSetting) >= InitialConditions[0]-5 && (pS->ThSetting) <= InitialConditions[0]+5)//Scale: 0-100%
						fCheckIC |= 0x01;
					
					
					if((pS->MixSetting) >= InitialConditions[1]-5 && (pS->MixSetting) <= InitialConditions[1]+5)//Scale: 0-100%
						fCheckIC |= 0x02;

					//if((pS->TrimSetting) >= InitialConditions[2]*0.95 && (pS->TrimSetting) <= InitialConditions[2]*1.05)//Scale: -1(Full Down) 0(Full Up)
						fCheckIC |= 0x04;

					
					if(pS->FlapIndicator == InitialConditions[4])//Scale: 0-0Deg 1-10Deg 2-20Deg 3-30Deg
						fCheckIC |= 0x08;
					
					if((pS->PitchController) >= InitialConditions[5]-0.1 && (pS->PitchController) <= InitialConditions[5]+0.1)//Scale: 1(Full Up) -1(Full down)
						fCheckIC |= 0x10;
					check = pS->PitchController;
					if((pS->RollController) >= InitialConditions[6]-0.1 && (pS->RollController) <= InitialConditions[6]+0.1)//Scale: 1(Full Right) -1(Full Left)
						fCheckIC |= 0x20;

					if((pS->RudderController) >= InitialConditions[7]-0.1 && (pS->RudderController) <= InitialConditions[7]+0.1)//Scale: 1(Full Right) -1(Full Left)
						fCheckIC |= 0x40;
					
					bQuitTest = true;
						
						
				
                    break;
                }

                default:
                   break;
            }
            break;
        }


        default:
            
            break;
    }

	
	
	
}


bool Start_CHECK_IC ()
{
	HRESULT hr;
	bool ret = false;
	
	



	ret = SUCCEEDED(SimConnect_Open(&hSimConnect, "Request Data", NULL, 0, 0, 0));
	
    if (ret == true)
    {
        
		
        
        // Set up the data definition, but do not yet do anything with it
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_CHECK_IC, "GENERAL ENG THROTTLE LEVER POSITION:1", "percent"); //Example
        hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_CHECK_IC, "GENERAL ENG MIXTURE LEVER POSITION:1", "percent"); 
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_CHECK_IC, "ELEVATOR TRIM INDICATOR", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "FLAPS HANDLE INDEX", "number");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "ELEVATOR POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "AILERON POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "RUDDER POSITION", "position");
		
		
		
	

		
		bQuitTest = false;check = 0;
        while( bQuitTest == false )
        {
			hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, DataRequest_CHECK_IC, DataDefinition_CHECK_IC, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
            SimConnect_CallDispatch(hSimConnect, GetData_CHECK_IC, NULL);
            Sleep(50);
        }

		

		
        		
		hr = SimConnect_Close(hSimConnect);// Close Server Connection
		
		
		/* Proceed with Test Analysis*/
		//UNDER DEVELOPMENT
    }
	
	return ret;

}

