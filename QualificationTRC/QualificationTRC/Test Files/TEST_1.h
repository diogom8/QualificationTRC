//Copyright (c) TRC Simulators.  All rights reserved.
//Developed by Diogo Monteiro. 26/05/2014  
//------------------------------------------------------------------------------
//
//  SimConnect Data Request for Test 1: Normal Climb Engine Operating (1c1)
//  
//	Description:
//				After a flight has loaded, request the lat/lon/alt of the user 
//				aircraft
//
//
//
//
//	Note: In order to adapt to other test start by replacing TEST_1 to TEST_*
//------------------------------------------------------------------------------

struct Data_TEST_1
{
    double Altitude;
	double SimTime;
};

static enum EVENT_ID{
    EVENT_SIM_START,
};

static enum DATA_DEFINE_ID_TEST_1 {
    DataDefinition_TEST_1,
};

static enum DATA_REQUEST_ID_TEST_1 {
    DataRequest_TEST_1,
};


void CALLBACK GetData_TEST_1(SIMCONNECT_RECV* pData, DWORD cbData, void *pContext)
{
    HRESULT hr;
    
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
                    if () // security check (CHANGE TO DIFFERENTE SECURITY CHECK
                    {
                        //Write to File
                    } 
                    break;
                }

                default:
                   break;
            }
            break;
        }


        case SIMCONNECT_RECV_ID_QUIT:
        {
            QuitTest = 1;
            break;
        }

        default:
            //printf("\nReceived:%d",pData->dwID);
            break;
    }
}


void Start_TEST_1 ()
{
	HRESULT hr;
	QuitTest = 0; //Should be Global Bool and can be included before Start_TEST is called
    if (SUCCEEDED(SimConnect_Open(&hSimConnect, "Request Data", NULL, 0, 0, 0)))
    {
        printf("\nConnected to Prepar3D!");   
        
        // Set up the data definition, but do not yet do anything with it
        hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "Plane Altitude", "feet"); //Example
       

        // Request an event when the simulation starts
        hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_START, "SimStart");

        while( QuitTest == 0 )
        {
            SimConnect_CallDispatch(hSimConnect, GetData_TEST_1, NULL);
            Sleep(1);
        } 

        /*Pause Simulator*/ //not necessary but elegant
		//UNDER DEVELOPMENT
		
		hr = SimConnect_Close(hSimConnect);// Close Server Connection
		
		/* Proceed with Test Analysis*/
		//UNDER DEVELOPMENT
    }

}

