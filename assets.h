#ifndef ASSETS_H
#define ASSETS_H

#include "header.h"

int propeler1[][2]={
	{28,18},
	{23,18},{25,19},{27,19},{28,18},
	{27,17},{27,15},{28,13},{28,18},
	{29,17},{31,17},{33,18},{28,18},
	{29,19},{29,21},{28,23},{28,18}
};

int propeler2[][2]={
	{57,18},{59,19},{61,19},{62,18},
	{61,17},{61,15},{62,13},{62,18},
	{63,17},{65,17},{67,18},{62,18},
	{63,19},{63,21},{62,23},{62,18}
};


int plane[][2] = {
	{1,13},{2,15},{41,18},{41,16},{42,15},{30,13},{43,14},
	{47,14},{60,13},{48,15},{49,16},{49,18},{88,15},{89,13},
	{88,16},{49,20},{47,21},{43,21},{41,20},{2,16}
}; // dimensi 90 x 23

int parachute[][2] = {
	{22,1},{23,1},{29,2},{33,4},{37,7},{39,10},{41,13},{43,18},{44,21},{44,25},
	{22,62},{44,25},{43,23},{42,21},{40,21},{38,23},{37,25},
	{22,62},{37,25},{36,22},{34,20},{32,20},{30,21},{28,25},
	{22,62},{28,25},{27,21},{25,20},{23,20},{21,21},{19,24},
	{22,62},{19,24},{18,21},{16,20},{14,20},{12,21},{11,23},{10,25},
	{22,62},{10,25},{9,22},{7,20},{5,20},{3,21},{2,23},{1,25},
	{22,62},{1,25},{1,21},{2,18},{4,13},{6,10},{8,7},{12,4},{17,2},{22,1}
}; //dimensi 44x62


int ship1[][2] = {
	{7,22},{69,22},{90,24},{82,28},{7,26}
}; //dimensi 91x38

int ship2[][2] = {
	{7,26},{78,27},{82,28},{84,29},{86,30},{87,32},{87,33},{86,35},{85,36},{84,37},{3,37},{2,36},{2,35},{3,33}
	}; //dimensi 91x38

int ship3[][2] = {
	{27,22},{28,14},{55,14},{56,15},{57,22}
}; //dimensi 91x38

int ship4[][2] = {
	{28,14},{30,3},{36,3},{37,8},{52,8},{52,14}
}; //dimensi 91x38

int people[][2] = {
	{10,1},{11,1},{12,2},{13,4},{12,6},{13,6},{19,1},{20,2},
	{14,9},{14,26},{13,27},{12,26},{12,19},{10,19},{10,26},{9,27},{8,26},
	{8,9},{1,2},{2,1},{8,6},{9,6},{8,4},{9,2},{10,1}
}; //dimensi 20x27

int explode[][2] = {
	{7,8},{13,12},{14,11},{12,6},{17,9},{18,8},{17,3},{22,9},{22,4},{24,7},{26,5},{27,1},{29,10},{32,6},{32,9},
	{33,8},{36,10},{44,3},{43,8},{44,9},{51,8},{49,10},{54,9},{52,12},{54,12},{51,15},{50,18},{55,21},{53,23},{55,24},
	{53,25},{55,26},{50,28},{54,32},{49,31},{47,32},{53,40},{41,35},{40,36},{43,40},{40,39},{40,41},{36,37},{36,40},
	{33,38},{30,42},{28,40},{24,44},{24,41},{21,42},{20,40},{16,44},{16,40},{12,42},{12,38},{3,39},{8,35},{6,33},
	{8,31},{2,29},{7,27},{5,25},{7,23},{1,19},{5,19},{7,18},{5,16},{8,16},{6,14},{8,14},{7,8}
}; //dimensi 55x44

#endif