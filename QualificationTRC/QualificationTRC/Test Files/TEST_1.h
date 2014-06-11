//Copyright (c) TRC Simulators.  All rights reserved.
//Developed by Diogo Monteiro. 26/05/2014  
//------------------------------------------------------------------------------
//
//  SimConnect Data Request for Test 1: Normal Climb Engine Operating (1c1)
//  
//	Description:
//				After a flight has loaded, request the DEFINE SIMULATIONVARIABLES of the user 
//				aircraft
//
//
//
//
//	Note: In order to adapt to other test start by replacing TEST_1 to TEST_*
//------------------------------------------------------------------------------

struct Data_TEST_1
{
    double ElevatorPosition;
	
};

static enum EVENT_ID{
    EVENT_SIM_START,
	EVENT_SIM_PAUSED,
};

static enum DATA_DEFINE_ID_TEST_1 {
    DataDefinition_TEST_1,
};

static enum DATA_REQUEST_ID_TEST_1 {
    DataRequest_TEST_1,
};

static enum PAUSESTATE
{
	UNPAUSED=0,
	PAUSED
};


void CALLBACK GetData_TEST_1(SIMCONNECT_RECV* pData, DWORD cbData, void *pContext)
{
    HRESULT hr;
    //ofstream myfile;
	
	//myfile.open ("DATA_TESTE_1.txt",ios::out | ios::app);
	



    switch(pData->dwID)
    {
        case SIMCONNECT_RECV_ID_EVENT:
        {
            SIMCONNECT_RECV_EVENT *evt = (SIMCONNECT_RECV_EVENT*)pData;

            switch(evt->uEventID)
            {
                case EVENT_SIM_START:
                    
					// Now the sim is running, request information on the user aircraft
                    hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, DataRequest_TEST_1, DataDefinition_TEST_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
                    check = -1;
					break;
					
				case EVENT_SIM_PAUSED:
					
					bQuitTest = true;
					
					break;

                default:
                   break;
            }
            break;
        }

        case SIMCONNECT_RECV_ID_SIMOBJECT_DATA_BYTYPE:
        {
            SIMCONNECT_RECV_SIMOBJECT_DATA_BYTYPE *pObjData = (SIMCONNECT_RECV_SIMOBJECT_DATA_BYTYPE*)pData;
            
            switch(pObjData->dwRequestID)
            {
                case DataRequest_TEST_1:
                {
					
                    DWORD ObjectID = pObjData->dwObjectID;
                    Data_TEST_1 *pS = (Data_TEST_1*)&pObjData->dwData;
                    check = 4;
					
					//if () // security check (CHANGE TO DIFFERENTE SECURITY CHECK
                    //{
                        
						
						//myfile << pS->ElevatorPosition << "\n";
						
						
						
						
						//Write to File
                    //} 
                    break;
                }

                default:
                   break;
            }
            break;
        }


        case SIMCONNECT_RECV_ID_QUIT:
        {
            bQuitTest = true;
			
            break;
        }

        default:
            //printf("\nReceived:%d",pData->dwID);
            break;
    }

	//myfile.close();	
	
	
	
}


bool Start_TEST_1 ()
{
	HRESULT hr;
	bool ret = false;
	
	ret = SUCCEEDED(SimConnect_Open(&hSimConnect, "Request Data", NULL, 0, 0, 0));
	
    if (ret == true)
    {
        
		//lblDialogProjectDate->Text="\nConnected to Prepar3D!";
        
        // Set up the data definition, but do not yet do anything with it
        hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "Plane Altitude", "feet"); //Example
       

        // Request an event when the simulation starts
        hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_START, "SimStart");
		hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_PAUSED, "Paused");
		
		bQuitTest = false;
        while( bQuitTest == false )
        {
			hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, DataRequest_TEST_1, DataDefinition_TEST_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
            SimConnect_CallDispatch(hSimConnect, GetData_TEST_1, NULL);
            Sleep(1);
        } 
		
        /*Pause Simulator*/ //not necessary but elegant
		//UNDER DEVELOPMENT
		
		hr = SimConnect_Close(hSimConnect);// Close Server Connection
		 //lblDialogProjectDate->Text="\nDisconnected from Prepar3D"
		
		/* Proceed with Test Analysis*/
		//UNDER DEVELOPMENT
    }
	
	return ret;

}

