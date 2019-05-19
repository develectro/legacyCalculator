/****************************************************************************/
/*          This program is written by: github.com/develectro               */
/****************************************************************************/



#include <iostream>
#include <stdio.h>

using namespace std;
float voltage();
float current();
float resistance();
float capacitance();
float charge();
float capacitor_voltage();
float resistors_series();
float resistors_parallel();
float capacitance_series();
float capacitance_parallel();
float simple_series();
float simple_parallel();
float series_and_paralle();
void select();
void documintation();


  int   main(){

    printf("\a");

    while(true){

        select();
    }


   return 0;
}

//Simple Voltage
float voltage(){
    float i;
    float r;
cout<<"Enter Current value: \n";
cin>> i;
cout<<"Enter Resistance value: \n ";
cin>>r;

float v = i*r;
cout<< " Voltage is: " << v <<" Volts \n";
return v;

}
//Simple Current
float current(){
float i;
float v;
float r;
 cout<<"Enter Voltage value: \n";
 cin>> v;
 cout<<"Enter Resistance value: \n ";
 cin>> r;
 i= v/r;
 cout<< "Current is: "<< i << " Ampere";
 return i;
}
//Simple Resistor
float resistance(){
float i;
float v;
float r;
 cout<<"Enter Voltage value: \n";
 cin>> v;
 cout<<"Enter Current value: \n ";
 cin>> i;
 r= v/i;
 cout<< "Resistance is "<< i << " Ohm \n";
 return r;
}

//Simple Capacitance
float capacitance(){

float c;
float q;
float v;
 cout<<"Enter Voltage value: \n";
 cin>> v;
 cout<<"Enter Charges Value: \n ";
 cin>> q;
 c = q/v;
 cout<< "Capacitance is "<< c << " Farad \n";


return c;}
// simple charge
float charge(){
float c;
float q;
float v;
 cout<<"Enter Voltage value: \n";
 cin>> v;
 cout<<"Enter Capacitance Value: \n ";
 cin>> q;
 q = c*v;
 cout<< "Capacitance is"<< c << "Coulomb \n";

return q;
}
//simple voltage
float capacitor_voltage(){
float c;
float q;
float v;
 cout<<"Enter Capacitance value: \n";
 cin>> c;
 cout<<"Enter Charge value: \n ";
 cin>> q;
 v = q/c;
 cout<< "Capacitor voltage is "<< v << " Volts \n";

return v;

}



float resistors_series(){

int input;
cout<<"Enter the Number of series Elements: \n";
cin>>input;
float Arr[input];
float resVal=0;
float equivalentRes=0;
int deci;
float sourceV=0;
float current=0;
float single_resistor_voltage[input];

    for(int i= 0; i<input; i++){

   cout<<"Enter the "<< i <<" Resistor value: \n";
   cin >> resVal;
    Arr[i] = resVal;

    }

    for(int i =0; i< input; i++){
    equivalentRes += Arr[i];

    }

    cout << equivalentRes <<" Ohm \n";

    cout<<"Do you want to calculate current on each resistor?[Yes 1/ No 0]:\n";
    cin>>deci;

    if(deci == 1){
        cout<<"Enter Source's Voltage: \n";
        cin>>sourceV;
         current = sourceV/ equivalentRes;
        cout<<"Current on each Resister equals" <<current<< "Ampere \n";
   }else if(deci == 0){
        cout<<"Do you want to calculate voltage on each resistor?[Yes 1/ No 0]: \n";
             cin>>deci;
             if(deci == 1){
             cout<<"Enter Source's Voltage: \n";
             cin>>sourceV;
             current = sourceV/ equivalentRes;
             for (int p =0; p < input; p++){

             single_resistor_voltage[p] = Arr[p]*current;
        }

        for (int p =0; p < input; p++)
        cout<<"Your"<<p<< "voltage value is: " <<single_resistor_voltage[p]<<  "Volt \n";
    }
    }else if (deci == 0)
     goto endline;

     endline: return equivalentRes;
}//print f(" your total resistor is: %f", equivalentRes);

float resistors_parallel(){
int input;
int deci;
float sourceV =0;
cout<<"Enter the Number of parallel Elements: \n";
cin >>input;
float Arr[input];
float resVal=0;
float equivalentRes=0;
float single_resistor_current[input];
float current=0;


    for(int i= 0; i<input; i++){

    cout<<"Enter the" << i << " Resistor value: \n ";
    cin>>resVal;
    Arr[i] = resVal;

    }
    for(int i=0; i< input; i++)
    equivalentRes += 1/(Arr[i]);
    equivalentRes = 1/equivalentRes;
    cout<< equivalentRes << " Ohm \n";
    //
    cout<<"Do you want to calculate current on each resistor?[Yes 1/ No 0]:\n";
    cin>> deci;
    if(deci == 1){

             cout<<"Enter source Voltage value: ";
             cin >> sourceV;
             for (int p =0; p < input; p++)
             single_resistor_current[p]= sourceV/ Arr[p];

             for (int p =0; p < input; p++)
             cout<<"Your: " << p << " Resistor's Current value is: " << single_resistor_current[p]<<  " Ampere \n";
    }else if (deci == 0){
     goto endline;}
    endline: return equivalentRes;
}

float capacitance_series(){
int input;
int deci;
cout<<"Enter the Number of series Elements: \n";
cin>>input;
float Arr[input];
float capVal=0;
float equivalentCap=0;
float sourceV=0;
float charge=0;
float cap_voltage[input];

    for(int i= 0; i<input; i++){

    cout<<"Enter the " <<i<< " Capacitor value: ";
    cin>> capVal;
    Arr[i] = capVal;

    }
    for(int i=0; i< input; i++)
    equivalentCap += 1/(Arr[i]);
    equivalentCap = 1/equivalentCap;
//////////////
    cout<<equivalentCap<< " Farad \n";
    cout<<"Do you want to calculate the Equivalent Charge value ? [Yes 1/No 0]";

    cin>>deci;
    if(deci == 1){
        cout<<"Enter the Source voltage: ";
        cin>>sourceV;
        charge = equivalentCap * sourceV;
        cout<<"The total charge is: "<< charge<< "Coulomb\n";
    }
    else if(deci == 0){
       cout<<"Do you want to calculate the voltage on each Capacitor ? [Yes 1/No 0]";
       cin>>deci;
       if(deci == 1){
        cout<<"Enter the Source voltage: ";
        cin>>sourceV;
        charge = equivalentCap * sourceV;
        for(int p=0; p<input; p++){
        cap_voltage[p] =  charge/ Arr[p];}
        for(int p=0; p<input; p++){
        cout<<"Your "<<p<<" Capacitor's Voltage is: " <<cap_voltage[p]<<  "Volt";}
       }
    }else
    goto endline;
    endline: return equivalentCap;
}

float capacitance_parallel(){
int input;
int deci;
cout<<"Enter the Number of series Elements: \n";
cin>>input;
float Arr[input];
float capVal=0;
float equivalentCap=0;
float sourceV=0;
float charge=0;
float cap_charge[input];

    for(int i= 0; i<input; i++){

    cout<<"Enter the "<<i<< "Capacitor value: ";
    cin>>capVal;
    Arr[i] = capVal;

    }
    for(int i=0; i< input; i++)
    equivalentCap += Arr[i];

    cout<<equivalentCap<<  " Farad \n";

    cout<<"Do you want to calculate the charge on each Capacitor ? [Yes 1/No 0]";
       cin>>deci;
       if(deci == 1){
        cout<<"Enter the Source voltage: ";
        cin>>sourceV;
        for(int p=0; p<input; p++){
        cap_charge[p] =  sourceV * Arr[p];}
        for(int p=0; p<input; p++){
        cout<<"Your" <<p<< "Capacitor's Charge  is "<<cap_charge[p]<< " Coulomb \n";}
       }else{
       goto endline;
       }


    endline: return equivalentCap;
}

float simple_series(int S ){
//int num;
float val;
float Stotal;
//printf("Enter the number of Series Resistors: ");
//scanf("%d", &num);
float Arr[S];

for(int i=0; i<S; i++){
        cout<<"Enter " <<i<< "Resistor value: ";
        cin>>val;
        Arr[i] = val;
}
for(int i=0; i<S; i++){
  Stotal += Arr[i]; //Summation of resistors

}
return Stotal;
}

float simple_parallel(int P){
float Ptotal;

float Arr[P];
float val;


for(int i=0; i<P; i++){
        cout<<"Enter "<<i<<" Resistor value: ";
        cin>>val;
        Arr[i] = val;
}


for(int i=0; i<P; i++){
  Ptotal +=  1/(Arr[i]);
  //Summation of resistors
} Ptotal = 1/Ptotal;
  return Ptotal;
}

float series_and_paralle(){

int input;
int totla_res;
float tempo_res;
cout<<"For more information read the Manual : \n";
cin>>totla_res;
float Arr[totla_res];

float counter =0;
int for_while =0;

cout<<"NOTE: To terminate this calculator enter: 0 \n";


do{



cout<< "Do you want to calculate Series or Parallel [Series 1/ Parallel 2] \n";
cin>>input;

if(input == 1){
    cout<<"How many Resistors? \n";
int simpleS;
cin>>simpleS;

counter += simple_series(simpleS);

}

else if(input == 2){
        cout<<"How many Resistors? \n";
        int simpleP;
        cin>> simpleP;
        counter += simple_parallel(simpleP);

}else{
    cout<<"Equivalent resistance =  "<<counter<< " Ohm\n";
goto endline;}

}while(input != 0 );
    cout<<"Equivalent resistance = " <<counter<< " Ohm \n";
endline: return counter;
}

void documintation(){

cout<<"                :::User Quick Guide::: \n ";
cout<<" Welcome to the Simple prompt Electrical calculator \n";
cout<<" This calculator dose not involve DELTA or STAR connections, Neither KVL or KCL. \n";
cout<<" To start calculation you need to select one of the possible options. \n";
cout<<" Options: \n";
cout<<" Current: to calculate current by knowing the resistance and voltage.(Ohm's law) \n";
cout<<" Voltage: similar to current, but calculates the voltage.(Ohm's law) \n";
cout<<" Resistance: similar to current but calculates resistance.(Ohm's law)  \n";
cout<<" Capacitance: to calculate the the capacitance subjected to certain voltage and charge. \n";
cout<<" Charge: doing the same of Capacitance but to find charge.\n";
cout<<" Capacitor voltage: to find the voltage applied on a capacitor. \n";
cout<<" Resistance parallel mode: to calculate parallel resistors with ability to calculate currents and voltage. \n";
cout<<" Resistance series mode: to calculate series resistors with ability to calculate currents and voltage. \n";
cout<<" this mode allows you to calculate the equivalent resistance of the circuit in which the user have to predetermined the nodes of calculating resistance in order to obtain correct results. \n";

}

void select(){

int indicator;
line: cout<<" please enter the option number: \n";
cout<<"  for: Voltage: enter 0\n";
cout<<"  for: Current : enter 1\n";
cout<<"  for: Resistance: enter 2  \n";
cout<<"  for: Capacitance: enter 3 \n";
cout<<"  for: Charge of capacitor: enter 4 \n";
cout<<"  for: Voltage of capacitor: enter 5\n";
cout<<"  for: Resistors series connections: enter 6 \n";
cout<<"  for: Resistors parallel connections: enter 7 \n";
cout<<"  for: Capacitors series connections: enter 8 \n";
cout<<"  for: Capacitors parallel connections: enter 9\n";
cout<<"  for: Series and parallel resistors: enter 10  \n";
cout<< " for: Manual: enter 11\n";
cin >> indicator;

if(indicator == 0){
   voltage();
   goto line;
}
else if(indicator == 1){
    current();
    goto line;
}
else if(indicator == 2){
    resistance();
    goto line;
}
else if(indicator == 3){
    capacitance();
    goto line;
}
else if(indicator == 4){
    charge();
    goto line;
}
else if(indicator == 5){
    capacitor_voltage();

}
else if(indicator == 6){
    resistors_series();

}
else if(indicator == 7){
    resistors_parallel();
}
else if(indicator == 8){
    capacitance_series();

}
else if(indicator == 9){
    capacitance_parallel();

}
else if(indicator == 10){

    series_and_paralle();

}
else if(indicator == 11){

    documintation();

}

else{
    goto line;
}

}









