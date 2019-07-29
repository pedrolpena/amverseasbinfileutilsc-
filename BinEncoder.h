/*
 * BinEncoder.h
 *
 *  Created on: Jul 27, 2019
 *      Author: pedro
 */
#include "XBTProfile.h"
#include "bitvector.h"

#ifndef BINENCODER_H_
#define BINENCODER_H_

class BinEncoder {
public:
	stdex::bitvector bits; //holds bits from file
	int newMessageType;
	stdex::bitvector changeEndian(stdex::bitvector);
	void setBitWithinBits(stdex::bitvector, stdex::bitvector,int);
	BinEncoder(XBTProfile &xBTProfile);
	BinEncoder();
	virtual ~BinEncoder();
};

#endif /* BINENCODER_H_ */
