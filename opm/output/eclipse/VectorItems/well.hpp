/*
  Copyright (c) 2018 Equinor ASA

  This file is part of the Open Porous Media project (OPM).

  OPM is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  OPM is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with OPM.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef OPM_OUTPUT_ECLIPSE_VECTOR_WELL_HPP
#define OPM_OUTPUT_ECLIPSE_VECTOR_WELL_HPP

#include <vector>

namespace Opm { namespace RestartIO { namespace Helpers { namespace VectorItems {

    namespace IWell {
        enum index : std::vector<int>::size_type {
            IHead  =  0, // I-location (one-based) of well head
            JHead  =  1, // J-location (one-based) of well head
            FirstK =  2, // Layer ID (one-based) of top/first connection
            LastK  =  3, // Layer ID (one-based) of bottom/last connection
            NConn  =  4, // Number of active cells connected to well
            Group  =  5, // Index (one-based) of well's current group
            WType  =  6, // Well type
            WCtrl  =  7, // Well control

            item9  =  8,
            item11 = 10,

            VFPTab = 11, // ID (one-based) of well's current VFP table

            item18 = 17, // Unknown
            item25 = 24, // Unknown
            item32 = 31, // Unknown
            item48 = 47, // Unknown
            item50 = 49, // Unknown

            MsWID  = 70, // Multisegment well ID
                         //   Value 0 for regular wells
                         //   Value 1..#MS wells for MS wells
            NWseg  = 71, // Number of well segments
                         //   Value 0 for regular wells
                         //   Value #segments for MS wells

            CompOrd = 98,
        };

        namespace Value {
            enum WellType : int {
                WTUnk    = 0,  // Unknown well type (OPM only)
                Producer = 1,  // Well is producer
                OilInj   = 2,  // Well is oil injector
                WatInj   = 3,  // Well is water injector
                GasInj   = 4,  // Well is gas injector
            };

            enum WellCtrlMode : int {
                WMCtlUnk = -10,  // Unknown well control mode (OPM only)
                Group    = - 1,  // Well under group control
                Shut     =   0,  // Well is shut
                OilRate  =   1,  // Well controlled by oil rate
                WatRate  =   2,  // Well controlled by water rate
                GasRate  =   3,  // Well controlled by gas rate
                LiqRate  =   4,  // Well controlled by liquid rate

                ResVRate =   5,  // Well controlled by
                                 // reservoir voidage rate

                THP      =   6,  // Well controlled by
                                 // tubing head pressure target

                BHP      =   7,  // Well controlled by
                                 // bottom-hole pressure target

                CombRate =   9,  // Well controlled by linearly
                                 // combined rate target
            };

            enum CompOrder : int {
                Track = 0, // Connections ordered along
                           // well track (increasing MD)

                Depth = 1, // Connections ordered by inceasing
                           // true vertical depth.  Not really
                           // supported in OPM Flow.

                Input = 2, // Connections listed in order of
                           // appearance in simulation model's
                           // COMPDAT keyword.
            };
        } // Value
    } // IWell

    namespace SWell {
        enum index : std::vector<float>::size_type {
            OilRateTarget  = 0, // Well's current oil rate production target
            WatRateTarget  = 1, // Well's current water rate production target
            GasRateTarget  = 2, // Well's current gas rate production target
            LiqRateTarget  = 3, // Well's current liquid rate production target
            ResVRateTarget = 4, // Well's current reservoir voidate rate
                                // production target

            THPTarget      = 5, // Well's tubing head pressure target
            BHPTarget      = 6, // Well's bottom hole pressure target

            DatumDepth     = 9, // Well's reference depth for BHP
        };
    } // SWell

    namespace XWell {
        enum index : std::vector<double>::size_type {
            OilPrRate  =  0, // Well's oil production rate
            WatPrRate  =  1, // Well's water production rate
            GasPrRate  =  2, // Well's gas production rate
            LiqPrRate  =  3, // Well's liquid production rate
            VoidPrRate =  4, // Well's reservoir voidage production rate

            FlowBHP    =  6, // Well's flowing/producing bottom hole pressure
            WatCut     =  7, // Well's producing water cut
            GORatio    =  8, // Well's producing gas/oil ratio

            OilPrTotal   = 18, // Well's total cumulative oil production
            WatPrTotal   = 19, // Well's total cumulative water production
            GasPrTotal   = 20, // Well's total cumulative gas production
            VoidPrTotal  = 21, // Well's total cumulative reservoir
                               // voidage production

            WatInjTotal = 23,  // Well's total cumulative water injection
            GasInjTotal = 24,  // Well's total cumulative gas injection

            GasFVF      = 34,  // Well's producing gas formation volume factor.

            item37     = 36,
            item38     = 37,

            BHPTarget  = 41, // Well's current BHP Target/Limit

            item82     = 81,
            item83     = 82,

            WatVoidPrRate = 122, // Well's voidage production rate
            GasVoidPrRate = 123, // Well's voidage production rate
        };
    } // XWell

    namespace ZWell {
        enum index : std::vector<const char*>::size_type {
            WellName = 0, // Well name
        };
    } // ZWell
}}}} // Opm::RestartIO::Helpers::VectorItems

#endif // OPM_OUTPUT_ECLIPSE_VECTOR_WELL_HPP
