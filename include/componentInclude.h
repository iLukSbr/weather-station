#pragma once

/* Comment the header to disable or uncomment to enable the component */
#include "ESP01.h"
#include "Encoder.h"
#include "GYNEO6MV2.h"
#include "INA219.h"
#include "KY015.h"
#include "KY021.h"
#include "MHRD.h"
#include "MHRTC2.h"
#include "MPL3115A2.h"
// #include "Relay.h"
#include "SDReaderWriter.h"
#include "SolarTracker.h"
#include "TEMT6000.h"
#include "TTP223B.h"
#include "UV.h"
#include "WindVane.h"

#define N_MULTIMETERS 2// Quantity of INA219
#define READING_DELAY 3000// (ms) Delay between readings

#include <Vector.h>

#ifndef _ENCODER_
   #define _ENCODER_ 0
#endif
#ifndef _GYNEO6MV2_
   #define _GYNEO6MV2_ 0
#endif
#ifndef _INA219_
   #define _INA219_ 0
#endif
#ifndef _KY015_
   #define _KY015_ 0
#endif
#ifndef _KY021_
   #define _KY021_ 0
#endif
#ifndef _MHRD_
   #define _MHRD_ 0
#endif
#ifndef _MPL3115A2_
   #define _MPL3115A2_ 0
#endif
#ifndef _SOLAR_TRACKER_
   #define _SOLAR_TRACKER_ 0
#endif
#ifndef _TEMT6000_
   #define _TEMT6000_ 0
#endif
#ifndef _UV_
   #define _UV_ 0
#endif
#ifndef _WIND_VANE_
   #define _WIND_VANE_ 0
#endif

#define QUANTITY_OF_COMPONENTS (_ENCODER_ + _GYNEO6MV2_ + N_MULTIMETERS*_INA219_ + _KY015_ + _KY021_ + _MHRD_ + _MPL3115A2_ + _SOLAR_TRACKER_ + _TEMT6000_ + _UV_ + _WIND_VANE_)