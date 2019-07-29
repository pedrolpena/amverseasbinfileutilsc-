/*
 * BinEncoder.cpp
 *
 *  Created on: Jul 27, 2019
 *      Author: pedro
 */

#include "BinEncoder.h"

BinEncoder::BinEncoder() {
	newMessageType = 0;

}

BinEncoder::~BinEncoder() {

}

BinEncoder::BinEncoder(XBTProfile &xBTProfile) {

	newMessageType = xBTProfile.getNewMessageType();

}

/**
 * <strong>(FXY)</strong>-This method flips the "endianes" of a BitSet
 * object and returns a BitSet object with flipped "endianess".
 *
 * @return <strong>(FXY)</strong>-This method flips the "endianes" of a
 * BitSet object and returns a BitSet object with flipped "endianess".
 */
stdex::bitvector BinEncoder::changeEndian(stdex::bitvector b) {
    bool temp;
    int width = b.size();
    for (int i = 0; i < width; i = i + 8) {
        for (int j = 0; j < 4; j++) {
            temp = b.test(i + j);
            b.set(i + j, b.test(i - j + 7));
            b.set(i - j + 7, temp);
        }//end for

    }//end for
    return b;
}

void BinEncoder::setBitWithinBits(stdex::bitvector b, stdex::bitvector subBits, int startPos) {
    for (unsigned int i = 0; i < subBits.size(); i++) {
        if (subBits.test(i)) {
            b.set(i + startPos, true);
        } else {
            b.set(i + startPos, false);
        }
    }
}
