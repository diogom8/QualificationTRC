//Copyright (c) TRC Simulators.  All rights reserved.
//Developed by Diogo Monteiro. 07/07/2014  
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
//	Note: In order to adapt to other test start by replacing TEST_2 to TEST_*
//------------------------------------------------------------------------------

//[STEP 1] - Replace all 1's for test number #

//Structure definition for test data[STEP 2]
struct Data_TEST_2 
{
	//REQUIRED DATA
	double Time;
    double IndicatedAltitude;
	double AirSpeedIndicated;
	double RateOfClimb;
	//EXTRA DATA TO PLOT
	//double ElevatorDeflection;
	//double PlanePitch;
	double EngineFuelFlow;
	double EngineRPM;		//engine speed
	double EngineBrakePower;
	double PropellerThrust;
	double EGT;
	
	
	
	//DATA FOR AUTOMATIC INPUT
	double ElevatorPosition;
	double ElevatorTrimPosition;
	double AileronPosition;
	double RudderPosition;
	double EnginePosition;

	
};


static enum DATA_DEFINE_ID_TEST_2 {
    DataDefinition_TEST_2,
};

static enum DATA_REQUEST_ID_TEST_2 {
    DataRequest_TEST_2,
};


void CALLBACK GetData_TEST_2(SIMCONNECT_RECV* pData, DWORD cbData, void *pContext)
{
    HRESULT hr;
    
	string path = sProjectDirectory + "\\DATA_TEST_2.txt";
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
                case DataRequest_TEST_2:
                {
					
                    //check = 3;
					if(bTestStarted == true)//Start if simulator is unpaused
					{
						DWORD ObjectID = pObjData->dwObjectID;
						Data_TEST_2 *pS = (Data_TEST_2*)&pObjData->dwData;
						//check = 4;
					
						//Write reading data to file
						pS->Time = pS->Time - dInitTime;
						
						//REQUIRED DATA
						myfile->Write(pS->Time+" ");
						myfile->Write(pS->AirSpeedIndicated+" ");
						myfile->Write(pS->IndicatedAltitude+" ");
						myfile->Write(pS->RateOfClimb+" "),
						//EXTRA DATA TO PLOT
						myfile->Write(pS->EngineFuelFlow+" ");
						myfile->Write(pS->EngineRPM+" ");
						myfile->Write(pS->EngineBrakePower+" ");
						myfile->Write(pS->PropellerThrust+" ");
						myfile->Write(pS->EGT+" ");
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
						Data_TEST_2 *pS = (Data_TEST_2*)&pObjData->dwData;
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


void START_TEST_2 ()
{
	HRESULT hr;
	
        
		
        
        // Set the data definition
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "LOCAL TIME", "seconds"); //Example
		//DATA TO EVALUATE TEST		
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "INDICATED ALTITUDE", "feet");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "AIRSPEED INDICATED", "knots");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "VERTICAL SPEED", "Feet per second"); //rate of climb
		 
		//EXTRA DATA TO PLOT
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "RECIP ENG FUEL FLOW:1", "Pounds per hour");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "GENERAL ENGINE RPM", "Rpm");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "RECIP ENG BRAKE POWER:1", "Foot pounds per second");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "PROP THRUST:1", "Pounds");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "GENERAL ENG EXHAUST GAS TEMPERATURE:1", "Rankine");
		//DATA FOR AUTOMATIC INPUT
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "ELEVATOR POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "ELEVATOR TRIM POSITION", "radians");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "AILERON POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "RUDDER POSITION", "position");
		hr = SimConnect_AddToDataDefinition(hSimConnect, DataDefinition_TEST_2, "GENERAL ENG THROTTLE LEVER POSITION:1", "percent");
		
		
				
		      

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
			hr = SimConnect_RequestDataOnSimObjectType(hSimConnect, DataRequest_TEST_2, DataDefinition_TEST_2, 0, SIMCONNECT_SIMOBJECT_TYPE_USER);
            SimConnect_CallDispatch(hSimConnect, GetData_TEST_2, NULL);
            Sleep(100);//Time interval between samples (cant be too low due to request)
        }
		
        		
		//Give a second to avoid conflicts
		Sleep(1000);
		
			
		//GNUPLOT SHOW PLOTS ON SCREEN
		FILE *pipe = _popen(GNUPLOT_NAME, "w");
		fprintf(pipe, "set term wxt\n");
		//Careful with directory. Different computer will correspond to a different path
		fprintf(pipe, "cd 'C:\\Users\\Diogo\\Documents\\GitHub\\QualificationTRC\\QualificationTRC\\QualificationTRC\\Plots'\n");
		fprintf(pipe, "load 'GNUPLOT_TEST_2.gp'\n");
		_pclose(pipe);
	
	

}

