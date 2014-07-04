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

struct Data_TEST_1 //output data for test 1
{
	//REQUIRED DATA
	double Time;
    double IndicatedAltitude;
	double AirSpeedIndicated;
	//EXTRA DATA TO PLOT
	double ElevatorDeflection;
	double PlanePitch;
	//DATA FOR AUTOMATIC INPUT
	double ElevatorPosition;
	double ElevatorTrimPosition;
	double AileronPosition;
	double RudderPosition;
	double EnginePosition;

	
		
	
};

static enum EVENT_ID{
    EVENT_SIM_PAUSED,
	EVENT_SIM_UNPAUSED,
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
    
	
	StreamWriter^ myfile = gcnew StreamWriter("Plots/DATA_TESTE_1.txt",true);
	
	

    switch(pData->dwID)
    {
        case SIMCONNECT_RECV_ID_EVENT:
        {
            SIMCONNECT_RECV_EVENT *evt = (SIMCONNECT_RECV_EVENT*)pData;

            switch(evt->uEventID)
            {
                case EVENT_SIM_PAUSED:
					
					bQuitTest = true;
					
					break;
				case EVENT_SIM_UNPAUSED:
					
					bTestStarted = true;
					
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
					
                    //check = 3;
					if(bTestStarted == true)//Start if simulator is unpaused
					{
						DWORD ObjectID = pObjData->dwObjectID;
						Data_TEST_1 *pS = (Data_TEST_1*)&pObjData->dwData;
						//check = 4;
					
						//Write reading data to file
						pS->Time = pS->Time - dInitTime;
						
						//REQUIRED DATA
						myfile->Write(pS->Time+" ");
						myfile->Write(pS->AirSpeedIndicated+" ");
						myfile->Write(pS->IndicatedAltitude+" ");
						//EXTRA DATA TO PLOT
						myfile->Write(pS->ElevatorDeflection+" ");
						myfile->Write(pS->PlanePitch+" ");
						//DATA FOR AUTOMATIC INPUT
						myfile->Write(pS->ElevatorPosition+" ");
						myfile->Write(pS->ElevatorTrimPosition+" ");
						myfile->Write(pS->AileronPosition+" ");
						myfile->Write(pS->RudderPosition+" ");
						myfile->Write(pS->EnginePosition+" ");
						

						myfile->Write("\n");
					}
					else
					{
						DWORD ObjectID = pObjData->dwObjectID;
						Data_TEST_1 *pS = (Data_TEST_1*)&pObjData->dwData;
						dInitTime = pS->Time;
						
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
            bQuitTest = true;
			
            break;
        }

        default:
           
            break;
    }

	myfile->Close();
	
	
}


void START_TEST_1 ()
{
	HRESULT hr;
	
        
		
        
        // Set up the data definition, but do not yet do anything with it
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "LOCAL TIME", "seconds"); //Example
		//DATA TO EVALUATE TEST		
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "INDICATED ALTITUDE", "feet");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "AIRSPEED INDICATED", "knots");
		 
		//EXTRA DATA TO PLOT
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "ELEVATOR DEFLECTION", "radians");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "PLANE PITCH DEGREES", "radians");


		//DATA FOR AUTOMATIC INPUT
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "ELEVATOR POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "ELEVATOR TRIM POSITION", "radians");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "AILERON POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "RUDDER POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "GENERAL ENG THROTTLE LEVER POSITION:1", "percent");
		
		
				
		      

        // Request an event when the simulation pauses (end of test)
        hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_PAUSED, "Paused");
		hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_UNPAUSED, "Unpaused");

		//Create a new data file
		StreamWriter^ myfile = gcnew StreamWriter("Plots/DATA_TESTE_1.txt");
		myfile->Close();


		bQuitTest = false;bTestStarted = false;
        while( bQuitTest == false )
        {
			hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, DataRequest_TEST_1, DataDefinition_TEST_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
            SimConnect_CallDispatch(hSimConnect, GetData_TEST_1, NULL);
            Sleep(200);//Time interval between samples (cant be too large due to request)
        } 
		
        		
		
		
		
		/* Proceed with Test Analysis*/
		//UNDER DEVELOPMENT
    
	
	

}

