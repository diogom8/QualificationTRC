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
    double ElevatorAngle;
	double EngineSpeed;
	double ExhaustGasTemperature;
	double FuelFlow;
	double IndicatedAirspeed;
	double PitchAngle;
	double PitchControllerPosition;
	double PressureAltitude;
	double RateOfClimb;
	double RudderAngle;
	double ThrottleSetting;
	double Thrust;

		
		
	
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
	StreamWriter^ myfile = gcnew StreamWriter("DATA_TESTE_1.txt",true);
	



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
					
					//Write reading data to file                       
					myfile->Write(pS->ElevatorAngle+" ");
					myfile->Write(pS->EngineSpeed+" ");
					myfile->Write(pS->ExhaustGasTemperature+" ");
					myfile->Write(pS->FuelFlow+" ");
					myfile->Write(pS->IndicatedAirspeed+" ");
					myfile->Write(pS->PitchAngle+" ");
					myfile->Write(pS->PitchControllerPosition+" ");
					myfile->Write(pS->PressureAltitude+" ");
					myfile->Write(pS->RateOfClimb+" ");
					myfile->Write(pS->RudderAngle+" ");
					myfile->Write(pS->ThrottleSetting+" ");
					//myfile->Write(pS->Thrust);


					myfile->Write("\n");

						
						
				
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

	myfile->Close();
	
	
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
        hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "ELEVATOR DEFLECTION", "radians"); //Example
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "GENERAL ENG RPM:1", "rpm");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "GENERAL ENG EXHAUST GAS TEMPERATURE:1", "rankine");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "RECIP ENG FUEL FLOW:1", "pounds per hour");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "AIRSPEED INDICATED", "knots");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "PLANE PITCH DEGREES", "radians");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "YOKE Y POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "PRESSURE ALTITUDE", "meters");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "VERTICAL SPEED", "feet per second");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "RUDDER DEFLECTION", "radians");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "GENERAL ENG THROTTLE LEVER POSITION:1", "percent");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "PROP THRUST:1", "pounds");
		
		

      

        // Request an event when the simulation pauses (end of test)
        hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_PAUSED, "Paused");
		
		bQuitTest = false;
        while( bQuitTest == false )
        {
			hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, DataRequest_TEST_1, DataDefinition_TEST_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
            SimConnect_CallDispatch(hSimConnect, GetData_TEST_1, NULL);
            Sleep(200);
        } 
		
        		
		hr = SimConnect_Close(hSimConnect);// Close Server Connection
		//lblDialogProjectDate->Text="\nDisconnected from Prepar3D"
		
		/* Proceed with Test Analysis*/
		//UNDER DEVELOPMENT
    }
	
	return ret;

}

