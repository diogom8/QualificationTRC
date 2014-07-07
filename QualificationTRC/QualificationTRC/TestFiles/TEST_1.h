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
	double Time;
    double ElevatorAngle;
	double EngineSpeed;
	double ExhaustGasTemperature;
	double FuelFlow;
	double IndicatedAirspeed;
	double PitchAngle;
	double PitchControllerPosition;
	double IndicatedAltitude;
	double RateOfClimb;
	double RudderAngle;
	double ThrottleSetting;
	double Thrust;

		
		
	
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
    
	
	string path = sProjectDirectory + "\\DATA_TESTE_1.txt";
	String^ SYSpath = gcnew String(path.c_str());
	StreamWriter^ myfile = gcnew StreamWriter(SYSpath,true);

	
	

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
						myfile->Write(pS->Time+" ");
						
						
						//myfile->Write(pS->ElevatorAngle+" ");
						//myfile->Write(pS->EngineSpeed+" ");
						//myfile->Write(pS->ExhaustGasTemperature+" ");
						//myfile->Write(pS->FuelFlow+" ");
						myfile->Write(pS->IndicatedAirspeed+" ");
						//myfile->Write(pS->PitchAngle+" ");
						//myfile->Write(pS->PitchControllerPosition+" ");
						myfile->Write(pS->IndicatedAltitude+" ");
						//myfile->Write(pS->RateOfClimb+" ");
						//myfile->Write(pS->RudderAngle+" ");
						//myfile->Write(pS->ThrottleSetting+" ");
						//myfile->Write(pS->Thrust);


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
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "ELEVATOR DEFLECTION", "radians"); 
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "GENERAL ENG RPM:1", "rpm");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "GENERAL ENG EXHAUST GAS TEMPERATURE:1", "rankine");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "RECIP ENG FUEL FLOW:1", "pounds per hour");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "AIRSPEED INDICATED", "knots");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "PLANE PITCH DEGREES", "radians");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "ELEVATOR POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "INDICATED ALTITUDE", "feet");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "VERTICAL SPEED", "feet per second");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "RUDDER DEFLECTION", "radians");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "GENERAL ENG THROTTLE LEVER POSITION:1", "percent");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_1, "PROP THRUST:1", "pounds");
		
		
		
      

        // Request an event when the simulation pauses (end of test)
        hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_PAUSED, "Paused");
		hr = SimConnect_SubscribeToSystemEvent(hSimConnect, EVENT_SIM_UNPAUSED, "Unpaused");
		
		//Create a new data file
		string path = sProjectDirectory + "\\DATA_TEST_2.txt";
		String^ SYSpath = gcnew String(path.c_str());
		StreamWriter^ myfile = gcnew StreamWriter(SYSpath);
		myfile->Close();
		
		
		bQuitTest = false;bTestStarted = false;
        while( bQuitTest == false )
        {
			hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, DataRequest_TEST_1, DataDefinition_TEST_1, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
            SimConnect_CallDispatch(hSimConnect, GetData_TEST_1, NULL);
            Sleep(200);//Time interbal between samples (cant be too large due to request)
        } 
		
        		
		
		
		
		//Give a second to avoid conflicts
		Sleep(1000);
		
			
		//GNUPLOT SHOW PLOTS ON SCREEN
		FILE *pipe = _popen(GNUPLOT_NAME, "w");
		fprintf(pipe, "set term wxt\n");
		//Careful with directory. Different computer will correspond to a different path
		fprintf(pipe, "cd 'C:\\Users\\Diogo\\Documents\\GitHub\\QualificationTRC\\QualificationTRC\\QualificationTRC\\Plots'\n"); // change in the end to put all reference data and gnu plot files in one place
		fprintf(pipe, "load 'GNUPLOT_TEST_2.gp'\n");
		_pclose(pipe);
	
	

}

