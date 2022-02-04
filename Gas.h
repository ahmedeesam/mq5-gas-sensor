/*
 * Gas.h
 *
 * Created: 26/11/2021 01:29:47 ص
 *  Author: ahmed essam
 */ 


#ifndef GAS_H_
#define GAS_H_




int  GetPercentage(float rs_ro_ratio, float *pcurve);
int  GetGasPercentage(float rs_ro_ratio, int gas_id);
float ReadSensor();
float ResistanceCalculation(int raw_adc);
float SensorCalibration();



#endif /* GAS_H_ */